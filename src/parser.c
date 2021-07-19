#include "parser.h"

statement get_statement(tokenizer *tknzr)
{
	statement stmt;
	token current_token = get_next_token(tknzr);
	if (current_token.type == TOKEN_END)
	{
		stmt.type = STMT_END;
	}
	else if (current_token.type == TOKEN_ERROR)
	{
		stmt.type = STMT_ERROR;
	}
	else if (current_token.type < 7)
	{
		stmt.type = (statement_type)current_token.type;
		current_token = get_next_token(tknzr);
		switch (stmt.type)
		{
		case STMT_PUSH:
		// TODO: adding to statement.data
			if (current_token.type == TOKEN_WHITESPACE)
			{
				current_token = get_next_token(tknzr);
			}
			else
			{
				stmt.type = STMT_ERROR;
				break;
			}
			if (current_token.type == TOKEN_NUM)
			{
				// TODO: convert string to int
				current_token = get_next_token(tknzr);
			}
			else
			{
				stmt.type = STMT_ERROR;
				break;
			}
			if (current_token.type == TOKEN_WHITESPACE)
			{
				current_token = get_next_token(tknzr);
			}
			if (current_token.type != TOKEN_NEWLINE && current_token.type != TOKEN_END)
			{
				stmt.type = STMT_ERROR;
			}
			break;
		// case STMT_POP:
		// 	break;
		// case STMT_DUP:
		// 	break;
		// case STMT_ADD:
		// 	break;
		// case STMT_IFEQ:
		// 	break;
		// case STMT_JUMP:
		// 	break;
		// case STMT_PRINT:
		// 	break;
		default:
			stmt.type = STMT_ERROR;
			break;
		}
	}
	else
	{
		stmt.type = STMT_ERROR;
	}
	return stmt;
}

/*
tokenizer *tok = init_tokenizer(line_buffer);
token t = get_next_token(tok);
while (t.type != TOKEN_END)
{
	fprintf(stdout, "\n%d %s\n", t.type, t.text);
	t = get_next_token(tok);
}
*/