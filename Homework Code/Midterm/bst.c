//------------LuvU4ever-------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

tree_t Search(tree_t Root, key_t x)
{
  if (Root == NULL)
    return NULL;
  if (strcmp(Root->data.word, x) == 0)
    return Root;
  if (strcmp(Root->data.word, x) > 0)
    return Search(Root->left, x);
  return Search(Root->right, x);
}

void insertNode(data_t x, tree_t *pRoot)
{
  if (*pRoot == NULL)
  {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    memcpy(&((*pRoot)->data), &x, sizeof(data_t)); // <===
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  }
  else if (strcmp(x.word, (*pRoot)->data.word) < 0) // <===
    insertNode(x, &((*pRoot)->left));
  else if (strcmp(x.word, (*pRoot)->data.word) > 0) // <===
    insertNode(x, &((*pRoot)->right));
}

void printTree(tree_t tree, FILE *const fout)
{
  if (tree != NULL)
  {
    printTree(tree->left, fout);
    fprintf(fout, "%s %d\n", tree->data.word, tree->data.count);
    printTree(tree->right, fout);
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
