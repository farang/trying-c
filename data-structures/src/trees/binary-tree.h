struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode *createBinaryTreeNode(int value);

void insertIntoBinaryTreeLeft(struct BinaryTreeNode *rootTree, int value);

void insertIntoBinaryTreeRight(struct BinaryTreeNode *rootTree, int value);
