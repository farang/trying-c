struct LinkedListNode
{
    int value;
    struct LinkedListNode *next;
};

struct LinkedList
{
    struct LinkedListNode *head;
    int size;
};

struct LinkedList *createLinkedList();
void pushToLinkedList(struct LinkedList *linkedList, int value);
void unshiftToLinkedList(struct LinkedList *linkedList, int value);
void freeLinkedList(struct LinkedList *linkedList);