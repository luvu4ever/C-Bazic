//------------LuvU4ever-------------

#ifndef __BST_wordcount_H__
#define __BST_wordcount_H__

#define MAX_WORD_LENGTH 105

typedef char* key_t;  // specify a type for the data

typedef struct data_type{
  int count;
  char word[MAX_WORD_LENGTH];
} data_t;

typedef struct node_s {
  data_t data;
  struct node_s *left;
  struct node_s *right;
} node_t;

typedef node_t *tree_t;

tree_t Search(tree_t Root, key_t x);
void insertNode(data_t x, tree_t *pRoot);
void printTree(tree_t tree, FILE* const fout);
void freeTree(tree_t tree);

#endif