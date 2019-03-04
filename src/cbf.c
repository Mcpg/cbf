#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_BUFFER_SIZE 16*1024
#define LOOP_STACK_SIZE 512
#define TAPE_SIZE 10000
#define TAPE_DATATYPE char

void run_bf(char* buf)
{
    struct stack_data* loop_stack = stack_create(LOOP_STACK_SIZE);
    TAPE_DATATYPE* tape = malloc(sizeof(TAPE_DATATYPE) * TAPE_SIZE);
    size_t tape_pointer = 0;

    for (int i = 0; buf[i]; i++)
    {
        switch (buf[i])
        {
            case '+':
                tape[tape_pointer]++;
                break;
            case '-':
                tape[tape_pointer]--;
                break;
            case '>':
                tape_pointer++;
                break;
            case '<':
                tape_pointer--;
                break;
            case ',':
                tape[tape_pointer] = fgetc(stdin);
                break;
            case '.':
                fputc(tape[tape_pointer], stdout);
                break;
            case '[':
                if (tape[tape_pointer] == 0)
                {
                    int nested_loop_amount = 0;
                    while (buf[i])
                    {
                        i++;
                        if (buf[i] == '[')
                            nested_loop_amount++;
                        if (buf[i] == ']')
                        {
                            if (nested_loop_amount == 0)
                                break;
                            nested_loop_amount--;
                        }
                    }
                    break;
                }
                if (!stack_push(loop_stack, i))
                {
                    fprintf(stderr, "Loop stack overflow\n");
                    exit(1);
                }
                break;
            case ']':
                if (tape[tape_pointer] == 0)
                    stack_pop(loop_stack);
                else
                    i = stack_peek(loop_stack);
                break;
        }
    }

    free(tape);
    stack_delete(loop_stack);
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    if (!fgets(buffer, MAX_BUFFER_SIZE, stdin))
    {
        fprintf(stderr, "Couldn't read from stdin!\n");
        return 1;
    }

    run_bf(buffer);
    printf("\n");
    return 0;
}