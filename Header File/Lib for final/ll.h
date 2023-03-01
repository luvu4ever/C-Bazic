//---------------LuvU4ever--------------

#ifndef __LLIST_H__
#define __LLIST_H__

#include <string.h>

typedef struct data_s{
    int data;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
} node_t, *root_t, Node;

root_t llInit();
node_t *llCreateNewNode(const  data_t data);
void llShowData(data_t data);
root_t llPrintAll(root_t root);

root_t llInsertHead(root_t root, const data_t data);
root_t llInsertTail(root_t root, const data_t data);
root_t llInsertTailContinue(root_t root, const data_t data);
root_t llInsertAfter(root_t root, node_t * prev, const data_t data);
root_t llInsertAfterNode(root_t root, node_t *prev, const data_t data);

root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);
root_t llDeleteAfter(root_t root, node_t *prev);

root_t llClearAll(root_t root);

int llLength(root_t root);
root_t llReverse(root_t root);


#endif