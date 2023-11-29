
struct HashMapNode
{
    int value;
};

struct HashMap
{
    struct HashMapNode **nodes;
    int size;
};

struct HashMapNode *createNode(int value);

int hashFunction(char *key, int size);

struct HashMap *createHashMap(int size);

int getHashMapValue(struct HashMap *map, char *key);

int setHashMapValue(struct HashMap *map, char *key, int value);

int deleteHashMapValue(struct HashMap *map, char *key);

void freeHashMap(struct HashMap *map);
