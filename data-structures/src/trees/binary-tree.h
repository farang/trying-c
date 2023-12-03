struct BinaryTree
{
    int value;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

struct BinaryTree *createBinaryTreeNode(int value);

struct BinaryTree *insertIntoBinaryTree(struct BinaryTree *rootTree, int value);
