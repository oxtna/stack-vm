#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static const char *const token_texts[] = {
	"push",
	"pop",
	"dup",
	"add",
	"ifeq",
	"jump",
	"print"
};

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

token get_next_token(tokenizer *tokenizer)
{
	token tok;
	memset(tok.text, 0, TOKEN_STRING_LENGTH + 1);
	size_t current_buffer_index = 0;

	int c = *tokenizer->current_position;
	// TOKEN_END
	if (c == '\0')
	{
		tok.type = TOKEN_END;
	}
	// TOKEN_WHITESPACE
	else if (isblank(c))
	{
		c = *(++(tokenizer->current_position));

		// skip all other continuous whitespace characters
		while (isblank(c))
		{
			c = *(++(tokenizer->current_position));
		}

		tok.type = TOKEN_WHITESPACE;
	}
	// TOKEN_NUM
	else if (isdigit(c))
	{
		tok.text[current_buffer_index] = (char)c;
		current_buffer_index++;
		c = *(++(tokenizer->current_position));
		while (isdigit(c) && current_buffer_index < TOKEN_STRING_LENGTH)
		{
			tok.text[current_buffer_index] = (char)c;
			current_buffer_index++;
			c = *(++(tokenizer->current_position));
		}
		if (isblank(c) || c == '\0')
		{
			tok.type = TOKEN_NUM;
		}
		else
		{
			tok.type = TOKEN_ERROR;
		}
	}
	// other text tokens
	else if (islower(c))
	{
		//strncpy(tok.text, tokenizer->current_position, TOKEN_STRING_LENGTH);
		tok.text[current_buffer_index] = (char)c;
		current_buffer_index++;
		c = *(++(tokenizer->current_position));
		while (islower(c) && current_buffer_index < TOKEN_STRING_LENGTH)
		{
			tok.text[current_buffer_index] = (char)c;
			current_buffer_index++;
			c = *(++(tokenizer->current_position));
		}
		if (isblank(c) || c == '\0')
		{
			for (size_t i = 0; i < sizeof(token_texts) / sizeof(char *); i++)
			{
				if (!strcmp(tok.text, token_texts[i]))
				{
					tok.type = (token_type)i;
					break;
				}
				tok.type = TOKEN_ERROR;
			}
		}
		else
		{
			tok.type = TOKEN_ERROR;
		}
	}
	// token not recognized
	else
	{
		tok.type = TOKEN_ERROR;
	}

	return tok;
}
