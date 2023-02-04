#ifndef __LL_H__
#define __LL_H__

#include "data_t.h"

root_t llInit();
node_t *createNewNode(const data_t data);
root_t llInsert(node_t *p, const data_t data);
root_t llInsertHead(root_t root, const data_t x);
root_t llDeleteAll(root_t root);
node_t *llSeek(root_t root, int index);

#endif