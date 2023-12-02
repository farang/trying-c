#include "queue.h"
#include <stdlib.h>

struct Queue *createQueue(int size)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = size;
    return queue;
}

void addToQueue(struct Queue *queue, int value)
{
    struct QueueNode *node = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    node->value = value;
    node->prev = NULL;

    if (queue->tail == NULL)
    {
        queue->tail = node;
    }
    else
    {
        queue->tail->prev = node;
        queue->tail = node;
    }

    if (queue->head == NULL)
    {
        queue->head = node;
    }

    queue->size++;
}

int getFromQueue(struct Queue *queue)
{
    struct QueueNode *head = queue->head;

    if (head != NULL)
    {
        queue->head = queue->head->prev;
    }

    return head->value;
}

void freeQueue(struct Queue *queue)
{
    struct QueueNode *current = queue->head;

    while (current != NULL)
    {
        struct QueueNode *tmp = current;
        current = tmp->prev;
        free(tmp);
    }

    queue->size = 0;
}