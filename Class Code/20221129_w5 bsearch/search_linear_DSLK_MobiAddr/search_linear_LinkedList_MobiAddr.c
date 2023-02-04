#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define new(type) (type*)malloc(sizeof(type))
#define delete(x) free(x)

typedef struct data_s{
    char name[32];
    char phonenum[10];
    char emailaddress[32];   
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
} node_t, *root_t;

root_t llInit(){
    return NULL;
}

void showData(data_t *curAddr){
    printf("%-20s%-20s%-20s", curAddr->name, curAddr->phonenum, curAddr->emailaddress);
}

node_t *createNode(data_t x){
    node_t *newNode = new(node_t);
    if(newNode == NULL)
        return NULL;
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

root_t llInsert(node_t *p, data_t x){
    node_t *newNode = createNode(x);
    if(p == NULL) return newNode;
    p -> next = newNode;
    return newNode;
}

root_t llInsertHead(root_t root, data_t x){
    node_t *newNode = createNode(x);
    newNode -> next = root;
    return newNode;
}

// node_t *llFindStudentByName(root_t root, char name[]){
//     node_t *trav = root;
//     while(trav != NULL){
//         if(!strcmp(trav -> data.name, name))
//             return trav;
//         trav = trav -> next;
//     }
//     return NULL;
// }

//Delete head node
root_t llDeleteHead(root_t root){
    if(root == NULL) return NULL;

    node_t *trav = root-> next;
    delete(root);
    return trav;
}

//Delete last node
root_t llDeleteTail(root_t root){
    if(root == NULL) return NULL;
    if(root -> next == NULL){
        delete(root);
        return NULL;
    }

    node_t *p = root;
    while(p->next->next!= NULL)
        p = p -> next;
    delete(p -> next);
    p -> next = NULL;
    return root;
}

//Delete node after node p
root_t llDeleteAfter(root_t root, node_t* p){
    if(p == NULL || p-> next == NULL) return root;

    node_t *ptoDel = p -> next;
    p->next = ptoDel -> next;
    delete(ptoDel);
    return root;
}

root_t llMoveStudentToTop(root_t root, char name[]){
    if(root == NULL) return NULL;
    node_t *trav = root;
    node_t *prev = root;
    while(trav != NULL){
        if(!strcmp(name, trav->data.name)){
            root = llInsertHead(root, trav-> data);
            //showData(&(root->data));
            if(trav == root)
                return llDeleteHead(root);
            if(trav -> next == NULL)
                return llDeleteTail(root);
            return llDeleteAfter(root, prev);
        }
        prev = trav;
        trav = trav -> next;
    }
    return root;
}
root_t llDeleteAll(root_t root){
    node_t* p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        delete(root);
    }
    return NULL;
}

char inputFile[] = "LL_mobiaddr.inp";

int main(){

    root_t root = llInit();
    node_t *p = root;
    FILE *f = fopen(inputFile, "r");
    int n;
    fscanf(f, "%d", &n);
    for(int i=0; i<n; i++){
        data_t data;
        fscanf(f, "%s %s %s", data.name, data.phonenum, data.emailaddress);
        printf("%s %s %s", data.name, data.phonenum, data.emailaddress);
        if(!i){
            root = llInsertHead(root, data);
            p = root;
            continue;
        }
        p = llInsert(p, data);
    }
    char Asked[32];
    fscanf(f, "%s", Asked);
    node_t *trav = root;
    root = llMoveStudentToTop(root, Asked);

    showData(&(root->data));
    return 0;
}