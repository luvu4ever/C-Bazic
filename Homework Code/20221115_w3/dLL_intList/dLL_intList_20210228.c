// Author: Mai Viet Dung - 20210228
// Finish: 18/11/2022
// This program is used for me to learn about DLL
//---------------------<3-------------------------

#include<stdio.h>
#include<stdlib.h>

#define new(type) (type*) malloc(sizeof(type))
#define delete(x) free(x)
//C++ -> C

typedef struct data_s{
    int id;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *prev;
    struct node_s *next;
} node_t, *root_t;

root_t dllInit(){
    return NULL;
}

node_t *createNode(data_t x){
    node_t *newNode = new(node_t);
    if(newNode == NULL)
        return NULL;
    newNode -> data = x;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

//-------Insert-------
root_t dllInsertHead(root_t root, data_t data){
    node_t *head = createNode(data);
    root -> prev = head;
    head -> next = root;
    return head;
}

root_t dllInsertTail(root_t root, data_t data){
    node_t *tail = createNode(data);
    if(root == NULL) return tail;
    
    node_t *trav = root;
    while(trav->next != NULL)
        trav = trav -> next;
    
    trav -> next = tail;
    tail -> prev = trav;
    return root;
}

root_t dllInsertAfter(root_t root, node_t *pAElem, data_t data){
    node_t *newNode = createNode(data);
    if(pAElem == NULL) return root;
    newNode -> next = pAElem -> next;
    newNode -> prev = pAElem;
    if(pAElem -> next != NULL)
        pAElem -> next -> prev = newNode;
    pAElem -> next = newNode;
    return newNode;
}

root_t dllInsertBefore(root_t root, node_t *pBElem, data_t data){
    if(pBElem == NULL) return root;
    node_t *newNode = createNode(data);
    newNode -> prev = pBElem -> prev;
    newNode -> next = pBElem;
    pBElem -> prev -> next = newNode;
    pBElem -> prev = newNode;

    return root;
}


//------Delete----------
root_t dllDeleteHead(root_t root){
    if(root == NULL) return NULL;
    node_t *temp = root -> next;
    temp -> prev = NULL;
    delete(root);
    return temp;
}

root_t dllDeleteTail(root_t root){
    if(root == NULL) return NULL;
    if(root -> next == NULL) {
        delete(root);
        return NULL;
    }

    node_t *tail = root;
    while(tail -> next != NULL)
        tail = tail -> next;
    node_t *temp = tail -> prev;
    temp -> next = NULL;
    delete(tail);
    return root;
}

root_t dllDelete(root_t root, node_t *pCur){
    if(pCur == NULL || pCur -> prev == NULL) 
        return root;
    node_t *prev = pCur -> prev;
    node_t *next = pCur -> next;
    prev -> next = next;
    next -> prev = prev;
    delete(pCur);
    return root;
}

root_t dllDeleteAll(root_t root){
    node_t *p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        delete(root);
    }
    return NULL;
}

void showData(data_t *curNode){
    printf("%d ", curNode -> id);
}

void PrintDLL(root_t root){
    node_t *trav = root;
    while(trav != NULL){
        showData(&(trav -> data));
        trav = trav -> next;
    }
    printf("\n");
    return;
}

int main(){
    node_t *root = dllInit();
    node_t *p = root;
    int n = 5;
    data_t temp;
    int arr[5] = {0,1,2,3,4};
    for(int i=0; i<n; i++){
        //scanf("%d", &temp.id);
        temp.id = arr[i];
        if(i==0) {
            root = dllInsertTail(root, temp);
            p = root;
        }
        else p = dllInsertAfter(root, p, temp);
    }
    PrintDLL(root);
    node_t *nodethu3=root;
    int k = 3;
    for(int i=0; i<k-1; i++){
        nodethu3 = nodethu3->next;
    }
    showData(nodethu3);
    printf("\n");
    dllDelete(root, nodethu3->prev);
    dllDelete(root, nodethu3 -> next);
    PrintDLL(root);
    root = dllDeleteAll(root);
    return 0;
}