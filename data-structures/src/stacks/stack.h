struct StackNode
{
    int value;
    struct StackNode *prev;
};

struct Stack
{
    struct StackNode *head;
    int size;
};

struct Stack *createStack(int size);

void addToStack(struct Stack *stack, int value);

int getFromToStack(struct Stack *stack);

void freeStack(struct Stack *stack);