#ifndef __STACK_H
#define __STACK_H

#include <stddef.h>
#include <stdbool.h>

struct stack_data
{
    int* stack_top;
    int* stack_bottom;
    size_t stack_max_size;
};

struct stack_data* stack_create(size_t max_size);
void stack_delete(struct stack_data* stack);

size_t stack_size(struct stack_data* stack);
bool stack_push(struct stack_data* stack, int val);
int stack_peek(struct stack_data* stack);
int stack_pop(struct stack_data* stack);

#endif