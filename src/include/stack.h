#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _stack stack;

// Create a stack allocated on the heap and initialize its values.
stack *s_create();

// Push a new value onto the stack.
void s_push(stack *s, int value);

// Pop a value off the stack and return it.
int s_pop(stack *s);

// Peek at the value on top of the stack and return it.
int s_peek(stack *s);

// Return true if the stack is empty, false if it is not.
bool s_is_empty(stack *s);

#endif