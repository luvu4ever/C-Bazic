//-----------------LuvU4ever-----------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ll.h"

root_t llInit(){
    return NULL;
}

node_t *llCreateNewNode(const data_t data){
    node_t *newNode = (node_t*) malloc(sizeof(node_t));
    if(newNode == NULL)
        return NULL;
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

void llShowData(data_t data){
    printf("%d\n", data.data);
}

root_t llPrintAll(root_t root){
    for(node_t *p = root; p != NULL; p = p-> next)
        llShowData(p -> data);
    printf("\n");
    return root;
}

//============================

root_t llInsertHead(root_t root, const data_t data){
    //return new root
    node_t *pNewNode = llCreateNewNode(data);
    pNewNode -> next = root;
    return pNewNode;
}

root_t llInsertTail(root_t root, const data_t data){
    //return root
    node_t *pNewNode = llCreateNewNode(data);
    if(root == NULL)
        return pNewNode;
    node_t *cur = NULL;
    
    for(cur = root; cur -> next != NULL; cur = cur->next)
    ;

    cur -> next = pNewNode;
    return root;
}

root_t llInsertTailContinue(root_t root, const data_t data){
    //return new tail
    node_t *pNewNode = llCreateNewNode(data);
    if(root == NULL)
        return pNewNode;
    node_t *cur = NULL;
    
    for(cur = root; cur -> next != NULL; cur = cur->next)
    ;

    cur -> next = pNewNode;
    return pNewNode;
}

root_t llInsertAfter(root_t root, node_t *prev, const data_t data){
    //return root
    if(prev == NULL)
        return llInsertHead(root, data);
    node_t *pNewNode = llCreateNewNode(data);
    pNewNode -> next = prev -> next;
    prev -> next = pNewNode;

    return root;
}

root_t llInsertAfterNode(root_t root, node_t *prev, const data_t data){
    //return root
    if(prev == NULL)
        return llInsertHead(root, data);
    node_t *pNewNode = llCreateNewNode(data);
    pNewNode -> next = prev -> next;
    prev -> next = pNewNode;

    return pNewNode;
}

//=============================

root_t llDeleteHead(root_t root){
    if(root == NULL)
        return NULL;
    node_t *p = root->next;
    free(root);

    return p;
}

root_t llDeleteTail(root_t root){
    if(root == NULL)
        return NULL;
    if(root -> next == NULL){
        free(root);
        return NULL;
    }

    node_t *p;
    for(p = root; p-> next -> next != NULL; p = p -> next)
    ;

    free(p -> next);
    p -> next = NULL;
    return root;
}

root_t llDeleteAfter(root_t root, node_t *prev) {
    if(prev == NULL || prev -> next == NULL)
        return root;
    node_t *pDel = prev -> next;
    prev -> next = prev -> next -> next;

    free(pDel);
    return root;
}

root_t llClearAll(root_t root){
    node_t *p = NULL;
    for(; root != NULL; root = p){
        p = root -> next;
        free(root);
    }
    return NULL;
}


int llLength(root_t root){
    int count = 0;
    node_t *p;
    for(p = root; p != NULL; p = p-> next)
        count++;
    return count;
}

root_t llReverse(root_t root){
    node_t *cur, *prev;

    for(cur = prev = NULL; root != NULL;){
        cur = root;
        root = root-> next;
        cur -> next = prev;
        prev = cur;
    }
    return root;
}