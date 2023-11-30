#include <stdlib.h>
#include "stack.h"

struct Stack *createStack(int size)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->size = size;
    return stack;
}

void addToStack(struct Stack *stack, int value)
{
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));
    node->value = value;

    if (stack->head != NULL)
    {
        node->prev = stack->head;
    }

    stack->head = node;
}

int getFromToStack(struct Stack *stack)
{
    struct StackNode *node = stack->head;

    if (node != NULL)
    {
        stack->head = node->prev;
    }
    else
    {
        stack->head = NULL;
    }

    return node->value;
}

void freeStack(struct Stack *stack)
{
    struct StackNode *current = stack->head;

    while (current != NULL)
    {
        struct StackNode *tmp = current;
        current = tmp->prev;
        free(tmp);
    }

    stack->size = 0;
}