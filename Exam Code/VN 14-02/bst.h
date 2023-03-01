//-----------LuvU4ever----------------
#ifndef __BST_H__
#define __BST_H__

typedef char* key_t;

typedef struct data_s{
    char key[50];
    int sum;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *left, *right;
} node_t;

typedef node_t *tree_t;

tree_t makeTreeNode(data_t data);
tree_t search(key_t key, tree_t node);
tree_t insertNode(data_t data, tree_t node);

tree_t findMinValNode(tree_t node);
tree_t deleteNode(key_t key, tree_t root);

void freeTree(tree_t tree);

void printOrder(tree_t node);

#endif