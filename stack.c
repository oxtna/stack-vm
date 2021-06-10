#include "stack.h"
#include <stdlib.h>

void _push(stack s, int value)
{
	// sanity check
	if (s == NULL)
	{
		return;
	}

	while (s->next != NULL)
	{
		s = s->next;
	}

	s->next = malloc(sizeof(node));
	if (s->next != NULL)
	{
		s = s->next;
		s->next = NULL;
		s->value = value;
	}
}

int _pop(stack s)
{
	// sanity check
	if (s == NULL)
	{
		return 0;
	}

	node* previous;

	while (s->next != NULL)
	{
		previous = s;
		s = s->next;
	}

	int value = s->value;
	previous->next = NULL;
	free(s);
	return value;
}

int _peek(stack s)
{
	// sanity check
	if (s == NULL)
	{
		return 0;
	}

	while (s->next != NULL)
	{
		s = s->next;
	}

	return s->value;
}

bool _is_empty(stack s)
{
	// sanity check
	if (s == NULL)
	{
		return false;
	}

	return (s->next == NULL ? true : false);
}