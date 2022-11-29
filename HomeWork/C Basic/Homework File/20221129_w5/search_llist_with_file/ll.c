#include<stdio.h>
#include<stdlib.h>

#include"ll.h"
#include"data_t.h"

root_t llInit(){
    return NULL;
}

node_t *createNewNode(const data_t data){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    if(newNode == NULL)
        return NULL;

    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

root_t llInsert(node_t *p, const data_t x){
    node_t *newNode = createNewNode(x);
    if(p == NULL)
        return newNode;
    p-> next = newNode;
    return newNode;
}

root_t llInsertHead(root_t root, const data_t x){
    node_t *newNode = createNewNode(x);
    newNode -> next = root;
    return newNode;
}

root_t llDeleteAll(root_t root) {
  node_t* p = NULL;
  for (; root != NULL; root = p) {
    p = root->next;
    free(root);
  }
  return NULL;
}

node_t *llSeek(root_t root, int index){
    node_t *p;
    for (p = root; index > 0 && (p != NULL); index--) p = p->next;
        return p;
}