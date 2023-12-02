struct QueueNode
{
    int value;
    struct QueueNode *prev;
};

struct Queue
{
    int size;
    struct QueueNode *tail;
    struct QueueNode *head;
};

struct Queue *createQueue(int size);
void addToQueue(struct Queue *queue, int value);
int getFromQueue(struct Queue *queue);
void freeQueue(struct Queue *queue);