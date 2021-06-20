#include <stdbool.h>
#include <limits.h>

#define ERROR INT_MIN
#define BOOL_ERROR CHAR_MIN
#define SUCCESS 0

typedef struct _stack stack;

// Create a stack allocated on the heap and initialize its values.
stack *s_create();

// Push a new value onto the stack. Returns ERROR on failure and SUCCESS on success.
int s_push(stack *s, int value);

// Pop a value off the stack. Returns ERROR on failure and the value on success.
int s_pop(stack *s);

// Peek at the value on top of the stack. Returns ERROR on failure and the value on success.
int s_peek(stack *s);

// Returns true if the stack is empty, false if it is not, and BOOL_ERROR on failure.
bool s_is_empty(stack *s);
