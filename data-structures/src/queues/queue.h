struct QueueNode
{
    int value;
    struct Queue *next;
};

struct Queue
{
    int size;
    struct QueueNode *head;
};

void addToQueue(struct Queue *queue, int value);
int getFromQueue(struct Queue *queue);