#include "stack.h"
#include <stdlib.h>

struct _node
{
	struct _node *next;
	struct _node *previous;
	int value;
};

struct _stack
{
	struct _node *top;
	struct _node *bottom;
};

stack *s_create()
{
	stack *new_stack = malloc(sizeof(stack));
	if (new_stack != NULL)
	{
		new_stack->bottom = NULL;
		new_stack->top = NULL;
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	return new_stack;
}

void s_push(stack *s, int value)
{
	// sanity check
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}

	struct _node *new_node = malloc(sizeof(struct _node));
	if (new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	new_node->next = NULL;

	if (s->bottom == NULL)
	{
		s->bottom = new_node;
		s->top = new_node;
		new_node->previous = NULL;
	}
	else
	{
		s->top->next = new_node;
		new_node->previous = s->top;
		s->top = new_node;
	}
}

int s_pop(stack *s)
{
	// sanity check
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (s->top == NULL)
	{
		exit(EXIT_FAILURE);
	}
	int value = s->top->value;
	s->top->previous->next = NULL;
	free(s->top);
	return value;
}

int s_peek(stack *s)
{
	// sanity check
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}

	return s->top->value;
}

bool s_is_empty(stack *s)
{
	// sanity check
	if (s == NULL)
	{
		exit(EXIT_FAILURE);
	}

	return (s->top == NULL ? true : false);
}