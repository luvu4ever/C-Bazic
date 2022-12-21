#ifndef __BST_H__
#define __BST_H__

typedef struct phoneAddr_s {
  char name[20];
  char tel[12];
  char email[28];
} phoneAddr_t;
typedef char *key_t;

typedef phoneAddr_t data_t;  // specify a type for the data

typedef struct node_s {
  data_t data;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t search(key_t x, tree_t root);
void insertNode(data_t x, tree_t *pRoot);
data_t deleteMin(tree_t *pRoot);
void deleteNode(key_t x, tree_t *pRoot);
//tree_t deleteNode(key_t x, tree_t *pRoot);
void prettyPrint(tree_t tree);
void freeTree(tree_t tree);

#endif