#include <stdio.h>
#include "src/hash-maps/hash-map.h"
#include "src/linked-lists/linked-list.h"

// try data structures usage
int main()
{
    /*
        Try hash-map
    */
    struct HashMap *map = createHashMap(10);
    setHashMapValue(map, "key1", 12);

    int value1 = getHashMapValue(map, "key1");

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

    return 0;
}
