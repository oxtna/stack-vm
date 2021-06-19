#include <stdbool.h>
#include <limits.h>

#define ERROR INT_MIN
#define BOOL_ERROR CHAR_MIN
#define SUCCESS 0

typedef struct _stack stack;

stack *s_create();
int s_push(stack *s, int value);
int s_pop(stack *s);
int s_peek(stack *s);
bool s_is_empty(stack *s);
