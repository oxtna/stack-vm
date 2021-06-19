#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define MAXIMUM_LINE_LENGTH 255

int main(int argc, char *argv[])
{
	if (argc > 1) // TODO: process the arguments
	{
	}
	else // run as a REPL
	{
		char line_buffer[MAXIMUM_LINE_LENGTH + 1]; // 1 extra char for the null characters
		unsigned int command_counter = 1;
		while (true)
		{
			printf("(%u)STACK_VM >> ", command_counter);
			if (fgets(line_buffer, sizeof(line_buffer), stdin) != NULL)
			{
				// remove trailing newline character
				line_buffer[strcspn(line_buffer, "\n")] = 0;
				char *token = line_buffer;
				while ((token = strtok(token, " ")) != NULL)
				{
					// TODO: change this if else if chain
					if (!strcmp(token, "push"))
					{

					}
					else if (!strcmp(token, "pop"))
						;
					else if (!strcmp(token, "dup"))
						;
					else if (!strcmp(token, "add"))
						;
					else if (!strcmp(token, "ifeq"))
						;
					else if (!strcmp(token, "jump"))
						;
					else if (!strcmp(token, "print"))
						;
					else
					{
						fprintf(stderr, "\nInstruction \"%s\" was not recognized", token);
					}
					token = NULL;
				}
				printf("\n");
			}
			command_counter++;
			// TODO: catch errors
		}
	}
	return 0;
}