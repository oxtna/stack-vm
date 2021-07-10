#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include "tokenizer.h"

#define MAXIMUM_LINE_LENGTH 255

int main(int argc, char *argv[])
{
	if (argc > 1) // TODO: process the arguments
	{
		for (int i = 1; i < argc; i++)
		{
			fprintf(stdout, "arg #%d: `%s`\n", i, argv[i]);
		}
	}
	else // run as a REPL
	{
		char line_buffer[MAXIMUM_LINE_LENGTH + 1]; // 1 extra char for the null characters
		while (true)
		{
			fprintf(stdout, "\nSTACK_VM >> ");
			fflush(stdout);
			if (fgets(line_buffer, sizeof(line_buffer), stdin) != NULL)
			{
				// remove trailing newline character
				line_buffer[strcspn(line_buffer, "\n")] = 0;
				tokenizer *tok = init_tokenizer(line_buffer);
				token t = get_next_token(tok);
				while (t.type != TOKEN_END && t.type != TOKEN_ERROR)
				{
					fprintf(stdout, "\n%d %s\n", t.type, t.text);
					t = get_next_token(tok);
				}
			}
			// TODO: catch errors
		}
	}
	return 0;
}
