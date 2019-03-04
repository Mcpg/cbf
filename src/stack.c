#include "stack.h"
#include <stdlib.h>
#include <string.h>

struct stack_data* stack_create(size_t max_size)
{
    struct stack_data* result = malloc(sizeof(struct stack_data));
    result->stack_top = malloc(max_size * sizeof(int));
    result->stack_bottom = result->stack_top;
    result->stack_max_size = max_size;
    return result;
}

void stack_delete(struct stack_data* stack)
{
    free(stack->stack_top);
    free(stack);
}

size_t stack_size(struct stack_data* stack)
{
    return ((size_t) stack->stack_bottom - (size_t) stack->stack_top) / sizeof(int);
}

bool stack_push(struct stack_data* stack, int val)
{
    if ((stack_size(stack) + 1) > stack->stack_max_size)
        return false;
    
    *stack->stack_bottom = val;
    stack->stack_bottom++;
    return true;
}

int stack_peek(struct stack_data* stack)
{
    if (stack_size(stack) == 0)
        return -1;
    
    return *(stack->stack_bottom - 1);
}

int stack_pop(struct stack_data* stack)
{
    if (stack_size(stack) == 0)
        return -1;

    int val = *(stack->stack_bottom - 1);
    stack->stack_bottom--;
    return val;
}
