// BST: Bin Search Tree

//--------------------LuvU4ever-----------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

tree_t search(key_t x[], tree_t root)
{
    if (root == NULL)
        return NULL;
    if (!strcmp(root->data.email, x))
        return root;
    return strcmp(root->data.email, x) < 0 ? search(x, root->right) : search(x, root->left);
}

void insertNode(data_t x, tree_t *pRoot)
{
    if (*pRoot == NULL)
    {
        *pRoot = (node_t *)malloc(sizeof(node_t));
        (*pRoot)->data = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
        return;
    }
    if (strcmp(x.email, (*pRoot)->data.email) < 0)
        insertNode(x, &((*pRoot)->left));
    else
        insertNode(x, &((*pRoot)->right));
}

// Find the left-most node of right sub tree
data_t deleteMin(tree_t *root)
{
    if ((*root)->left != NULL)
        return deleteMin(&(*root)->left);
    data_t k = (*root)->data;
    (*root) = (*root)->right;
    return k;
}

// Delete a node from a BST
void deleteNode(key_t x[], tree_t *root)
{
    if ((*root) == NULL)
        return;
    if (strcmp(x, (*root)->data.email) < 0)
        deleteNode(x, &(*root)->left);
    else if (strcmp(x, (*root)->data.email) > 0)
        deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
        *root = NULL;
    else
    {
        if ((*root)->left == NULL)
            *root = (*root)->right;
        else if ((*root)->right == NULL)
            *root = (*root)->left;
        else
            (*root)->data = deleteMin(&(*root)->right);
    }
}

void prettyPrint(tree_t tree)
{
    static char prefix[200] = "    ";
    char *prefixend = prefix + strlen(prefix);
    if (tree != NULL)
    {
        printf("'%04s'", tree->data.email); // <===
        if (tree->left != NULL)
            if (tree->right == NULL)
            {
                printf("\304");
                strcat(prefix, "     ");
            }
            else
            {
                printf("\302");
                strcat(prefix, "\263    ");
            }
        prettyPrint(tree->left);
        *prefixend = '\0';
        if (tree->right != NULL)
            if (tree->left != NULL)
            {
                printf("\n%s", prefix);
                printf("\300");
            }
            else
                printf("\304");
        strcat(prefix, "     ");
        prettyPrint(tree->right);
    }
}

void freeTree(tree_t tree)
{
    if (tree != NULL)
    {
        freeTree(tree->left);
        freeTree(tree->right);
        free((void *)tree);
    }
}