// BST: Bin Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

tree_t search(key_t x, tree_t root) {
  if (root == NULL)
    return NULL;           // not found
  else if ( strcmp(root->data.email , x) == 0) /* found x */
    return root;
  else if (strcmp(root->data.email , x ) < 0 )
    // continue searching in the right sub tree
    return search(x, root->right);
  else {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

void insertNode(data_t x, tree_t *pRoot) {
  if (*pRoot == NULL) {
    /* Create a new node for key x */
    *pRoot = (node_t *)malloc(sizeof(node_t));
    (*pRoot)->data = x;
    (*pRoot)->left = NULL;
    (*pRoot)->right = NULL;
  } else if (strcmp( x.email , (*pRoot)->data.email ) < 0 )
    insertNode(x, &((*pRoot)->left));
  else if (strcmp( x.email , (*pRoot)->data.email ) > 0 )
    insertNode(x, &((*pRoot)->right));
}

// Find the left-most node of right sub tree
data_t deleteMin(tree_t *root) {
  if ((*root)->left == NULL) {
    data_t k = (*root)->data;
    (*root) = (*root)->right;
    return k;
  } else
    return deleteMin(&(*root)->left);
}

// Delete a node from a BST
void deleteNode(key_t x, tree_t *root) {
  if (*root != NULL)
    if (strcmp( x , (*root)->data.email) < 0)
      deleteNode(x, &(*root)->left);
    else if (strcmp( x , (*root)->data.email) > 0)
      deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
      *root = NULL;
    else if ((*root)->left == NULL)
      *root = (*root)->right;
    else if ((*root)->right == NULL)
      *root = (*root)->left;
    else
      (*root)->data = deleteMin(&(*root)->right);
}

// tree_t deleteNode(key_t x, tree_t *pRoot)
// {
//     // base case
//     if (pRoot == NULL)
//         return (*pRoot);
 
//     // If the key to be deleted
//     // is smaller than the root's
//     // key, then it lies in left subtree
//     if (strcmp( x , (*pRoot)->data.email) < 0)
//         (*pRoot)->left = deleteNode(x, &(*pRoot)->left);
 
//     // If the key to be deleted
//     // is greater than the root's
//     // key, then it lies in right subtree
//     else if (strcmp( x , (*pRoot)->data.email) > 0)
//         (*pRoot)->right = deleteNode(x, &(*pRoot)->right);
 
//     // if key is same as root's key,
//     // then This is the node
//     // to be deleted
//     else {
//         // node with only one child or no child
//         if ((*pRoot)->left == NULL) {
//             tree_t temp = (*pRoot)->right;
//             free((*pRoot));
//             return temp;
//         }
//         else if ((*pRoot)->right == NULL) {
//             tree_t temp = (*pRoot)->left;
//             free((*pRoot));
//             return temp;
//         }
 
//         // node with two children:
//         // Get the inorder successor
//         // (smallest in the right subtree)
//         data_t temp = deleteMin(&(*pRoot)->right);
 
//         // Copy the inorder
//         // successor's content to this node
//         temp = (*pRoot)->data;
 
//         // Delete the inorder successor
//         (*pRoot)->right = deleteNode(temp.email, &(*pRoot)->right);
//     }
//     return (*pRoot);
// }


void prettyPrint(tree_t tree) {
  static char prefix[200] = "    ";
  char *prefixend = prefix + strlen(prefix);
  if (tree != NULL) {
    printf("'%04s'", tree->data.email);       // <===
    if (tree->left != NULL)
      if (tree->right == NULL) {
        printf("\304");
        strcat(prefix, "     ");
      } else {
        printf("\302");
        strcat(prefix, "\263    ");
      }
    prettyPrint(tree->left);
    *prefixend = '\0';
    if (tree->right != NULL)
      if (tree->left != NULL) {
        printf("\n%s", prefix);
        printf("\300");
      } else
        printf("\304");
    strcat(prefix, "     ");
    prettyPrint(tree->right);
  }
}

void freeTree(tree_t tree) {
  if (tree != NULL) {
    freeTree(tree->left);
    freeTree(tree->right);
    free((void *)tree);
  }
}