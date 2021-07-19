#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"

typedef enum statement_type
{
	STMT_ERROR = -1,
	STMT_PUSH,
	STMT_POP,
	STMT_DUP,
	STMT_ADD,
	STMT_IFEQ,
	STMT_JUMP,
	STMT_PRINT,
	STMT_END
} statement_type;

typedef struct statement
{
	statement_type type;
	void *data;
} statement;

statement get_statement(tokenizer *tknr);

#endif