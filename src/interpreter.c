#include "interpreter.h"
#include "tokenizer.h"
#include "parser.h"
#include <stdio.h>

void interpret_string(char *s)
{
	tokenizer *tknr = init_tokenizer(s);
	statement st = get_statement(tknr);
	fprintf(stdout, "%d\n", st.type);
}