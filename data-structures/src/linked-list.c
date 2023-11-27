#include <stdlib.h>

struct LinkedListNode
{
    int value;
    struct LinkedListNode *next;
};

struct LinkedList
{
    struct LinkedListNode **values;
    struct LinkedListNode *current;
    int size;
};

struct LinkedList *createLinkedList(int size)
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->values = (struct LinkedListNode **)malloc(size * sizeof(struct LinkedListNode));
    list->size = size;
    return list;
}

void addToLinkedList(struct LinkedList *linkedList, int index, int value)
{
    if (index < linkedList->size - 1)
    {
        linkedList->values[index] = value;
    }
}
