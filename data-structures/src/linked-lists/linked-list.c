#include <stdlib.h>
#include "linked-list.h"

struct LinkedList *createLinkedList()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void unshiftToLinkedList(struct LinkedList *linkedList, int value)
{
    struct LinkedListNode *node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    node->value = value;
    node->next = linkedList->head;
    linkedList->size++;
    linkedList->head = node;
}

void pushToLinkedList(struct LinkedList *linkedList, int value)
{
    struct LinkedListNode *node = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    node->value = value;
    node->next = NULL;
    linkedList->size++;

    struct LinkedListNode *current = linkedList->head;

    if (current == NULL)
    {
        linkedList->head = node;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
}

void freeLinkedList(struct LinkedList *linkedList)
{
    struct LinkedListNode *current = linkedList->head;

    while (current != NULL)
    {
        struct LinkedListNode *tmpCurrent = current;
        current = current->next;
        free(tmpCurrent);
    }

    linkedList->size = 0;
    linkedList->head = NULL;
    free(linkedList);
}