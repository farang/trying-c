#include <stdio.h>
#include "src/hash-maps/hash-map.h"
#include "src/linked-lists/linked-list.h"
#include "src/stacks/stack.h"
#include "src/queues/queue.h"
#include "src/trees/binary-tree.h"

// try data structures usage
int main()
{
    /*
        Try hash-map
    */
    struct HashMap *map = createHashMap(10);
    setHashMapValue(map, "key1", 12);

    int value1 = getHashMapValue(map, "key1");

    printf("HASH MAP\n");
    printf("value by key 1: %d\n", value1);

    deleteHashMapValue(map, "key1");
    freeHashMap(map);

    /*
        Try linked list
    */
    struct LinkedList *tabsChain = createLinkedList();
    unshiftToLinkedList(tabsChain, 18);
    pushToLinkedList(tabsChain, 14);
    pushToLinkedList(tabsChain, 17);
    pushToLinkedList(tabsChain, 3);
    pushToLinkedList(tabsChain, 11);
    unshiftToLinkedList(tabsChain, 33);

    struct LinkedListNode *currentTab = tabsChain->head;
    printf("LINKED LIST\n");
    printf("tab 1: %d\n", currentTab->value);

    currentTab = currentTab->next;
    printf("tab 2: %d\n", currentTab->value);

    currentTab = currentTab->next;
    printf("tab 3: %d\n", currentTab->value);

    currentTab = currentTab->next;
    printf("tab 4: %d\n", currentTab->value);

    currentTab = currentTab->next;
    printf("tab 5: %d\n", currentTab->value);

    currentTab = currentTab->next;
    printf("tab 6: %d\n", currentTab->value);

    freeLinkedList(tabsChain);

    /*
        Try stack
    */
    struct Stack *pages = createStack(5);

    addToStack(pages, 1);
    addToStack(pages, 2);
    addToStack(pages, 3);
    addToStack(pages, 4);
    addToStack(pages, 5);

    printf("STACK\n");
    printf("page: %d\n", getFromToStack(pages));
    printf("page: %d\n", getFromToStack(pages));
    printf("page: %d\n", getFromToStack(pages));
    printf("page: %d\n", getFromToStack(pages));
    printf("page: %d\n", getFromToStack(pages));

    freeStack(pages);

    /*
        Try Queue
    */
    struct Queue *processingQueue = createQueue(3);

    addToQueue(processingQueue, -1);
    addToQueue(processingQueue, 0);
    addToQueue(processingQueue, 1);

    printf("QUEUE\n");
    printf("process: %d\n", getFromQueue(processingQueue));
    printf("process: %d\n", getFromQueue(processingQueue));
    printf("process: %d\n", getFromQueue(processingQueue));

    freeQueue(processingQueue);

    /*
        Binary tree
    */
    struct BinaryTreeNode *rootBinaryTreeNode = createBinaryTreeNode(12);

    insertIntoBinaryTreeLeft(rootBinaryTreeNode, 1);
    insertIntoBinaryTreeRight(rootBinaryTreeNode, 15);

    struct BinaryTreeNode *leftBinaryTreeNode1 = rootBinaryTreeNode->left;
    struct BinaryTreeNode *rightBinaryTreeNode1 = rootBinaryTreeNode->right;

    insertIntoBinaryTreeRight(rightBinaryTreeNode1, 3);

    struct BinaryTreeNode *rightBinaryTreeNode2 = rightBinaryTreeNode1->right;

    insertIntoBinaryTreeRight(rightBinaryTreeNode2, 99);
    insertIntoBinaryTreeLeft(rightBinaryTreeNode2, 69);

    struct BinaryTreeNode *rightBinaryTreeNode3 = rightBinaryTreeNode2->right;

    insertIntoBinaryTreeRight(rightBinaryTreeNode3, 100);
    insertIntoBinaryTreeLeft(rightBinaryTreeNode3, 13);

    int binaryTreeSize = getBinaryTreeSize(rootBinaryTreeNode);
    int binaryTreeHeight = getBinaryTreeHeight(rootBinaryTreeNode);

    printf("Tree\n");
    printf("smallest value: %d\n", leftBinaryTreeNode1->value);
    printf("highest value: %d\n", rightBinaryTreeNode3->value);
    printf("tree size: %d \n", binaryTreeSize);
    printf("tree height: %d \n", binaryTreeHeight);

    return 0;
}
