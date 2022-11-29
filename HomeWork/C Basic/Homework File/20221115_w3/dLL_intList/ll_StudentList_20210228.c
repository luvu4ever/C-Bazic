// Author: Mai Viet Dung - 20210228
// Finish: 15/11/2022
// This program can be used to manage a list of student by LL
//---------------------<3-------------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define new(type) (type*) malloc(sizeof(type))
#define delete(x) free(x)
//C++ -> C

typedef struct {
    char id[10];
    char name[32];
    int grade;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
} node_t, *root_t;
//------prefix _t stands for datatype

//Create new LL
root_t llInit(){
    return NULL;
}

//Show data of a node
void showData(data_t *curStudent){
    //data_t curStudent = trav -> studentData;
    printf("%-10s%-20s%d\n", curStudent->id, curStudent->name, curStudent->grade);
}

//Print out all nodes
void printLL(root_t root){
    //printf("------------------\n");
    printf("In danh sach sinh vien\n");

    node_t *trav = root;
    while(trav != NULL){
        showData(&(trav->data));
        trav = trav -> next;
    }
    printf("------------------\n");
    return;
}

//Create a new node first, then connect after
node_t *createNode(data_t x){
    node_t* newNode = new(node_t);
    if(newNode == NULL) 
        return NULL;
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

//-------Insert-------

//Insert node to the head
root_t llInsertHead(root_t root, data_t data){
    node_t *newNode = createNode(data);
    newNode -> next = root;
    return newNode;
}

//Insert last node
root_t llInsertTail(root_t root, data_t data){
    node_t *newNode = createNode(data);
    if(root == NULL) return newNode;

    node_t *trav = root;
    while(trav != NULL)
        trav = trav -> next;

    trav -> next = newNode;
    return root;
}

//Insert node after node p
root_t llInsertAfter(root_t root, node_t *p, data_t data){
    if(p == NULL) return root;
    node_t *newNode = createNode(data);
    newNode -> next = p -> next;
    p -> next = newNode;
    return root;
}

// Requirement:
//     root mean the first node of LL
//     data store student infomation
root_t llInsertStudent(root_t root, data_t data){
    //printf("check check%s %s %d\n", data.id, data.name, data.grade);
    if(root == NULL || data.grade > root->data.grade){
        return llInsertHead(root, data);
    }
    node_t *trav = root-> next;
    node_t *prev = root;
    while(trav != NULL){
        if(data.grade > trav -> data.grade)
            return llInsertAfter(root, prev, data);
        prev = trav;
        trav = trav -> next;
    }
    return llInsertTail(root, data);
}

//--------Find----------

//Find node with id is the number of the student
node_t *llFindStudentByID(root_t root, char id[]){
    node_t *trav = root;
    while(trav != NULL){
        if(!strcmp(trav->data.id, id))
            return trav;
        trav = trav -> next;
    }
    return NULL;
}
//This program used a lot find by id, but i dont really know how to use this
//function better to find both the node i need, and the prev node of it.
//Hope u can give me some feedback.

//Find node with id is the number of the student
data_t *llFindStudent(root_t root, char id[]){
    node_t *trav = llFindStudentByID(root, id);
    if(trav == NULL) return NULL;
    return &(trav -> data);
}

//------Delete----------
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

// Requirement:
//     root mean the first node of LL
//     id of the student we need to delete
root_t llDeleteStudent(root_t root, char id[]){
    if(root == NULL) return NULL;
    node_t *trav = root;
    node_t *prev = root;
    while(trav != NULL){
        if(!strcmp(id, trav->data.id)){
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

//--------Change grade---------

// Requirement:
//     root mean the first node of LL
//     data store student infomation
//     newGrade is the grade we want to change to
root_t llChangeGrade(root_t root, char id[], int newGrade){
    node_t *temp = llFindStudentByID(root, id);
    temp -> data.grade = newGrade;
    data_t dataTemp = temp -> data;
    root = llDeleteStudent(root, id);
    root = llInsertStudent(root, dataTemp);
    //have to delete and then re-insert because need to sort them out
    return root;
}

//release memory
root_t llDeleteAll(root_t root){
    node_t* p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        delete(root);
    }
    return NULL;
}

char inputFile[] = "ll_student_list.inp";

int main(){

    root_t root = llInit();
    data_t student[] = { {"001", "sv1", 3}, {"002", "sv2", 5}, {"003","sv3",7},{"004","sv4",8},{"005","sv5",10} };
    
    // //Incase u want to use input output
    // // input file demo:
    // // 001 sv1 3
    // // 002 sv2 5
    // // 003 sv3 7
    // // 004 sv4 8
    // // 005 sv5 9

    // FILE *f = fopen(inputFile, "r");
    // data_t student[5];
    // int n = 5;
    // for(int i=0; i<n; i++){
    //     fscanf(f,"%s %s %d", student[i].id, student[i].name, &student[i].grade);
    // }

    for(int i=0; i<5; i++)
        root = llInsertStudent(root, student[i]);
    printLL(root);
    
    char id1[] = "002";
    printf("Tim sinh vien co ma so %s\n", id1);
    data_t *temp = llFindStudent(root, id1);
    if(temp == NULL)
        printf("Not found\n");
    else
        showData(temp);
    //printLL(root);

    char id2[] = "002";
    int newGrade = 9;
    root = llChangeGrade(root, id2, newGrade);

    printf("Doi diem sinh vien %s\n", id2);
    printLL(root);

    char id3[] = "001";
    root = llDeleteStudent(root, id3);
    printf("Xoa sinh vien %s\n", id3);

    printLL(root);

    root = llDeleteAll(root);
    return 0;

}