#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// This array is ordered so that the `push`'s index is equal to the TOKEN_PUSH value,
// `pop`'s index is equal to the TOKEN_POP value, and so on.
static const char *const token_texts[] = {
	"push",
	"pop",
	"dup",
	"add",
	"ifeq",
	"jump",
	"print"};

struct _tokenizer_state
{
	const char *input_buffer;
	char *current_position;
};

tokenizer *init_tokenizer(char *input)
{
	tokenizer *tok_state = malloc(sizeof(tokenizer));
	tok_state->input_buffer = input;
	tok_state->current_position = input;
	return tok_state;
}

token get_next_token(tokenizer *tok)
{
	token t;
	memset(t.text, 0, TOKEN_STRING_LENGTH + 1);
	size_t current_buffer_index = 0;

	int c = *tok->current_position;
	// TOKEN_END
	if (c == '\0')
	{
		t.type = TOKEN_END;
	}
	// TOKEN_NEWLINE
	else if (c == '\n')
	{
		t.type = TOKEN_NEWLINE;
		c = *(++(tok->current_position));
	}
	// TOKEN_WHITESPACE
	else if (isblank(c))
	{
		c = *(++(tok->current_position));

		// skip all other continuous whitespace characters
		while (isblank(c))
		{
			c = *(++(tok->current_position));
		}

		t.type = TOKEN_WHITESPACE;
	}
	// TOKEN_NUM
	else if (isdigit(c))
	{
		t.text[current_buffer_index] = (char)c;
		current_buffer_index++;
		c = *(++(tok->current_position));
		while (isdigit(c) && current_buffer_index < TOKEN_STRING_LENGTH)
		{
			t.text[current_buffer_index] = (char)c;
			current_buffer_index++;
			c = *(++(tok->current_position));
		}
		if (isblank(c) || c == '\0' || c == '\n')
		{
			t.type = TOKEN_NUM;
		}
		else
		{
			t.type = TOKEN_ERROR;
		}
	}
	// other text tokens
	else if (islower(c))
	{
		t.text[current_buffer_index] = (char)c;
		current_buffer_index++;
		c = *(++(tok->current_position));
		while (islower(c) && current_buffer_index < TOKEN_STRING_LENGTH)
		{
			t.text[current_buffer_index] = (char)c;
			current_buffer_index++;
			c = *(++(tok->current_position));
		}
		if (isblank(c) || c == '\0' || c == '\n')
		{
			// set token type to TOKEN_ERROR in advance so it will have the correct
			// type if it's not overwritten after it finds a match
			t.type = TOKEN_ERROR;
			for (size_t i = 0; i < sizeof(token_texts) / sizeof(char *); i++)
			{
				if (!strcmp(t.text, token_texts[i]))
				{
					t.type = (token_type)i;
					break;
				}
			}
		}
		else
		{
			t.type = TOKEN_ERROR;
		}
	}
	// token not recognized
	else
	{
		t.type = TOKEN_ERROR;
	}

	return t;
}
