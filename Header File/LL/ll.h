#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include<stdio.h>

#define MAX_LENGTH 100

typedef struct data_s{
    char id[20];
    char name[32];
    int grade;
} student_t;

typedef student_t data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
} node_t, *root_t;

root_t llInit();
node_t *createNewNode(const data_t data);

//---------Insert-----------
root_t llInsert(node_t *p, const data_t data);
root_t llInsertHead(root_t root, const data_t x);
root_t llInsertTail(root_t root, const data_t x);
root_t llInsertByDecreaseOrder(root_t root, data_t data);
root_t llRootInsertAfter(root_t root, node_t *p, data_t data);

//---------Delete-----------
root_t llDeleteAll(root_t root);
root_t llDeleteHead(root_t root);
root_t llDeleteTail(root_t root);

//---------Show Data----------
void llPrint(root_t root);

#endif