#include <stdio.h>
#include <stdlib.h>
#include "hash-map.h"

struct HashMapNode *createNode(int value)
{
    struct HashMapNode *node = (struct HashMapNode *)malloc(sizeof(struct HashMapNode));
    node->value = value;
    return node;
}

int hashFunction(char *key, int size)
{
    unsigned int initialIndex = 0;

    while (*key)
    {
        initialIndex = (initialIndex << 5) + *key++;
    }

    return initialIndex % size;
}

struct HashMap *createHashMap(int size)
{
    struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));

    map->nodes = (struct HashMapNode **)malloc(size * sizeof(struct HashMapNode *));
    for (int i = 0; i < size; i++)
    {
        map->nodes[i] = NULL;
    }

    map->size = size;

    return map;
}

int getHashMapValue(struct HashMap *map, char *key)
{
    int mapSize = map->size;
    int index = hashFunction(key, mapSize);

    struct HashMapNode *node = map->nodes[index];

    return node->value;
}

int setHashMapValue(struct HashMap *map, char *key, int value)
{
    int mapSize = map->size;
    int index = hashFunction(key, mapSize);

    struct HashMapNode *node = createNode(value);
    map->nodes[index] = node;

    return 0;
}

int deleteHashMapValue(struct HashMap *map, char *key)
{
    int mapSize = map->size;
    int index = hashFunction(key, mapSize);

    map->nodes[index] = NULL;

    return 0;
}

void freeHashMap(struct HashMap *map)
{
    for (int i = 0; i < map->size; i++)
    {
        if (map->nodes[i] != NULL)
        {
            free(map->nodes[i]);
        }
    }
    free(map->nodes);
    free(map);
}