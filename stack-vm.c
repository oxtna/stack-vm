#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

#define MAXIMUM_LINE_LENGTH 255

int main(int argc, char *argv[])
{
	if (argc > 1) // TODO: process the arguments
	{
	}
	else // run as a REPL
	{
		char line_buffer[MAXIMUM_LINE_LENGTH + 1]; // 1 extra char for the null characters
		while (true)
		{
			errno = 0;
			printf("STACK_VM >> ");
			if (fgets(line_buffer, sizeof(line_buffer), stdin) != NULL)
			{
				char *token = line_buffer;
				while ((token = strtok(token, " ")) != NULL)
				{
					// TODO: change this if else if chain
					if (!strcmp(token, "push"))
						;
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
					token = NULL;
				}
				printf("\n");
			}
			//if (errno); // TODO: catch errors
		}
	}
	return 0;
}