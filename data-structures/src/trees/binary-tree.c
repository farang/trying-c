#include <stdlib.h>
#include <stdio.h>
#include "binary-tree.h"

struct BinaryTreeNode *createBinaryTreeNode(int value)
{
    struct BinaryTreeNode *treeNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode *));
    treeNode->value = value;

    return treeNode;
}

void insertIntoBinaryTreeLeft(struct BinaryTreeNode *rootTree, int value)
{
    struct BinaryTreeNode *treeNode = createBinaryTreeNode(value);
    rootTree->left = treeNode;
}

void insertIntoBinaryTreeRight(struct BinaryTreeNode *rootTree, int value)
{
    struct BinaryTreeNode *treeNode = createBinaryTreeNode(value);
    rootTree->right = treeNode;
}
