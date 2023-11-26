#include <stdio.h>
#include "./src/hash-map.h"

// try data structures usage
int main()
{
    struct HashMap *map = createHashMap(10);
    setHashMapValue(map, "key1", 12);

    int value1 = getHashMapValue(map, "key1");

    printf("value by key 1: %d\n", value1);

    deleteHashMapValue(map, "key1");
    freeHashMap(map);

    return 0;
}
