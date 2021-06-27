#include "stack.h"
#include <stdlib.h>

struct _node
{
	struct _node *next;
	int value;
};

struct _stack
{
	struct _node *top;
};

stack *s_create()
{
	stack *new_stack = calloc(1, sizeof(stack));
	if (new_stack == NULL)
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
	new_node->next = s->top;
	s->top = new_node;
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
	struct _node* next_node = s->top->next;
	free(s->top);
	s->top = next_node;
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

	return (s->top == NULL);
}