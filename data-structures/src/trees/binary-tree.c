#include <stdlib.h>
#include <stdio.h>
#include "binary-tree.h"

struct BinaryTreeNode *createBinaryTreeNode(int value)
{
    struct BinaryTreeNode *treeNode = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    treeNode->value = value;

    return treeNode;
}

void insertIntoBinaryTreeLeft(struct BinaryTreeNode *tree, int value)
{
    struct BinaryTreeNode *treeNode = createBinaryTreeNode(value);
    tree->left = treeNode;
}

void insertIntoBinaryTreeRight(struct BinaryTreeNode *tree, int value)
{
    struct BinaryTreeNode *treeNode = createBinaryTreeNode(value);
    tree->right = treeNode;
}

int getBinaryTreeSize(struct BinaryTreeNode *rootTree)
{
    int size = 0;
    if (rootTree->left == NULL && rootTree->right == NULL)
    {
        return size;
    }
    if (rootTree->left != NULL)
    {
        size += 1;
        size += getBinaryTreeSize(rootTree->left);
    }

    if (rootTree->right != NULL)
    {
        size += 1;
        size += getBinaryTreeSize(rootTree->right);
    }

    return size;
}

int getBinaryTreeHeight(struct BinaryTreeNode *rootTree)
{
    if (rootTree == NULL)
    {
        return 0;
    }

    int heightOfLeft = getBinaryTreeHeight(rootTree->left);
    int heightOfRight = getBinaryTreeHeight(rootTree->right);

    if (heightOfLeft > heightOfRight)
    {
        return heightOfLeft + 1;
    }
    else
    {
        return heightOfRight + 1;
    }
}
