//----------LuvU4ever--------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"ll.h"

#define new(type) (type*) malloc(sizeof(type))
#define delete(x) free(x)
//C++ -> C

root_t llInit(){
    return NULL;
}

node_t *createNewNode(const data_t data){
    node_t *newNode = new (node_t);
    if(newNode == NULL)
        return NULL;

    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

//-------Insert------------
root_t llInsertHead(root_t root, const data_t data){
    node_t *newNode = createNewNode(data);
    newNode -> next = root;
    return newNode;
}

root_t llInsertTail(root_t root, const data_t data){
    node_t *newNode = createNewNode(data);
    if(root == NULL)
        return newNode;
    node_t *trav = root;
    while(trav -> next != NULL)
        trav = trav -> next;
    trav -> next = newNode;

    return root;
}

//Insert after node p, return the new node
root_t llInsertAfter(node_t *p, data_t data){
    node_t *newNode = createNewNode(data);
    if(p == NULL)
        return newNode;
    newNode -> next = p -> next;
    p -> next = newNode;
    return newNode;
}

root_t llRootInsertAfter(root_t root, node_t *p, data_t data){
    if(p == NULL) 
        return root;
    node_t *newNode = createNewNode(data);
    newNode -> next = p -> next;
    p -> next = newNode;
    return root;
}

// root_t llInsertByDecreaseOrder(root_t root, data_t data){
//     if(root == NULL) 
//         return llInsertHead(root, data);
//     node_t *trav = root;
//     node_t *prev = NULL;
//     while(trav != NULL && data.grade < (trav->data).grade){
//         prev = trav;
//         trav = trav -> next;
//     }
//     if(prev == NULL)
//         return llInsertHead(root, data);
//     return llRootInsertAfter(root, prev, data);
// }

//-------Delete-------------

//-------Show data-----------

void showData(data_t *curStudent){
    //data_t curStudent = trav -> studentData;
    printf("%-10s%-20s%d\n", curStudent->id, curStudent->name, curStudent->grade);
}

void llPrint(root_t root){
    //printf("------------------\n");
    //printf("In danh sach sinh vien\n");

    node_t *trav = root;
    while(trav != NULL){
        showData(&(trav->data));
        trav = trav -> next;
    }
    printf("------------------\n");
    return;
}