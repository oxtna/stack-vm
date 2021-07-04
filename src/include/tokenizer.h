#ifndef TOKENIZER_H
#define TOKENIZER_H

#define TOKEN_STRING_LENGTH 11

typedef enum token_type
{
	TOKEN_ERROR = -1,
	TOKEN_PUSH,
	TOKEN_POP,
	TOKEN_DUP,
	TOKEN_ADD,
	TOKEN_IFEQ,
	TOKEN_JUMP,
	TOKEN_PRINT,
	TOKEN_NUM,
	TOKEN_WHITESPACE,
	TOKEN_END
} token_type;

typedef struct
{
	token_type type;
	char text[TOKEN_STRING_LENGTH + 1];
} token;

typedef struct _tokenizer_state tokenizer;

// Create a dynamically allocated tokenizer struct and return a pointer to the caller.
tokenizer *init_tokenizer(char *input);

// Get the next token from the tokenizer. If the tokenizer doesn't recognize
// a correct token, it will return a token with type ERROR.
token get_next_token(tokenizer *tokenizer);

#endif