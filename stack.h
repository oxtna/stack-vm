#include <stdbool.h>

typedef struct node
{
	struct node *next;
	int value;
} node;

typedef node *stack;

void _push(stack s, int value);
int _pop(stack s);
int _peek(stack s);
bool _is_empty(stack s);
