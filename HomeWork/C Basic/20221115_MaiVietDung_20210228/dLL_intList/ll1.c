//Ho va ten: Mai Viet Dung
//MSSV: 20210228
//--------------<3---------------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define new(type) (type*) malloc(sizeof(type))
#define delete(x) free(x)
//C++ -> C

char inputFile[] = "ll_student_list.inp";

typedef struct{
    char id[10];
    char name[32];
    int grade;
} data_t;

typedef struct node_t{
    data_t studentData;
    struct node *next;
} node_t, *root_t, node;

node *createNode(data_t data){
    node *newNode = new(node);
    newNode -> studentData = data;
    newNode -> next = NULL;

    // if(root != NULL)
    //     newNode -> next = root;
    return newNode;
}

// root_t llInsertStudent(root_t root, data_t data){
//     node *newNode =
// }

root_t llInsertHead(root_t root, data_t data){
    node *newNode = createNode(data);
    newNode -> next = root;
    return (root_t)newNode;
}

root_t llInsertTail(root_t root, data_t data){
    node *newNode = createNode(data);
    if(root == NULL) return (root_t) newNode;

    node *trav = root;
    while(trav!= NULL)
        trav = trav-> next;
    //travel to last node

    trav -> next = newNode;
    return root;
}

root_t llInsertStudent(root_t p, data_t data){
// Insert student to after node p
    node *temp = createNode(data);
    p -> next = temp;
    return temp;
}

data_t *llFindStudent(root_t root, char id[]){
    node *trav = root;
    while(trav != NULL){
        data_t *curNode = &(trav-> studentData);
        if(!strcmp(curNode->id, id)){
            return curNode;
            //return pointer of curNode
        }
        trav = trav -> next;
    }
    return NULL;
}

root_t llDeleteHead(root_t root){
    //if(root == NULL) return NULL;

    node_t *p = root -> next;
    delete(root);
    return (root_t)p;
}

root_t llDeleteTail(root_t root){
    // if(root == NULL) return NULL;

    if(root -> next == NULL){
        delete(root);
        return NULL;
    }
    node *p = root;
    //find pre node of tail  
    while(p-> next != NULL)
        p = p-> next;
    delete(p-> next);
    p -> next = NULL;
    return root;
}

root_t llDeleteCurStudent(root_t root, node *needtoDel){
    if(root == NULL) return NULL;
    if((needtoDel == NULL) || (needtoDel-> next == NULL)) return root;
    node *p = root;
    //find pre node of p
    while(p -> next != needtoDel)
        p = p-> next;
    p -> next = needtoDel -> next; 
    delete(needtoDel);
    return root;
}

root_t llDeleteStudent(root_t root, char id[]){
    node *trav = root;
    int stt = 0;
    while(trav != NULL){
        data_t curNode = trav -> studentData;
        if(!strcmp(curNode.id, id))
        {
            break;
        }
        trav = trav -> next;
        stt++;
    }
    if(stt == 0) 
        return llDeleteHead(root);
    if(trav -> next == NULL){
        return llDeleteTail(trav);
    }
    return llDeleteCurStudent(root, trav);
}

root_t llChangeGrade(root_t root, char id[], int newGrade){
    node *trav = root;
    while(trav != NULL){
        data_t curNode = trav -> studentData;
        if(!strcmp(curNode.id, id))
        {
            (trav -> studentData).grade = newGrade;
            return root;
        }
        trav = trav -> next;
    }
    return root;
}

void showData(data_t *curStudent){
    //data_t curStudent = trav -> studentData;
    printf("%s %s %d\n", curStudent->id, curStudent->name, curStudent->grade);
}

void printLL(root_t root){
    printf("------------------\n");
    node *trav = root;
    while(trav != NULL){
        showData(&(trav->studentData));
        trav = trav -> next;
    }
    printf("------------------\n");
    return;
}


int main(){
    FILE *f = fopen(inputFile,"r");
    root_t root, p;
    // data_t student[5];
    // int n;
    // n = 5;
    // for(int i=0; i<n; i++){
    //     fscanf(f,"%s %s %d", student[i].id, student[i].name, &student[i].grade);
    //     if(i == 0){
    //         root = createNode(student[i]);
    //         p = root;
    //         continue;
    //     }
    //     p = llInsertStudent(p , student[i]);
    // }
    // printLL(root);
    data_t student[5] = { {"001", "sv1", 3}, {"002", "sv2", 5}, {"003", "sv3", 7},{"004", "sv4", 8},{"005", "sv5", 10}};
    for(int i=0; i<5; i++){
        if(i == 0){
            root = createNode(student[i]);
            p = root;
            continue;
        }
        p = llInsertStudent(p , student[i]);
    }
    printLL(root);
    data_t *temp = llFindStudent(root, "002");
    showData(temp);
    root = llChangeGrade(root, "002", 9);
    printLL(root);
    root = llDeleteStudent(root, "001");
    printLL(root);
    return 0;
}