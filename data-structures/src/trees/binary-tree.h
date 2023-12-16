struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode *createBinaryTreeNode(int value);

void insertIntoBinaryTreeLeft(struct BinaryTreeNode *treeNode, int value);

void insertIntoBinaryTreeRight(struct BinaryTreeNode *treeNode, int value);

int getBinaryTreeSize(struct BinaryTreeNode *rootTree);

int getBinaryTreeHeight(struct BinaryTreeNode *rootTree);
