#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ll.h"

#define NOT_FOUND (-1)

root_t llInsertByDecreaseOrderByName(root_t root, data_t data){
    if(root == NULL) 
        return llInsertHead(root, data);
    node_t *trav = root;
    node_t *prev = NULL;
    while(trav != NULL && strcmp(data.name, (trav->data).name) < 0){
        prev = trav;
        trav = trav -> next;
    }
    if(prev == NULL)
        return llInsertHead(root, data);
    return llRootInsertAfter(root, prev, data);
}

root_t Middle(node_t *start, node_t *last){
    if(start == NULL)
        return NULL;
    node_t *fast = start -> next;
    node_t *slow = start;

    while(fast != last){
        fast = fast -> next;
        if(fast != last){
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    //fast go 2* as slow
    return slow;
}

student_t *binarySearchByName(root_t root, char* key){
    node_t *start = root;
    node_t *last = NULL;
    while(last == NULL || last != start){
        node_t *mid = Middle(start, last);
        if(mid == NULL) return NULL;
        if(strcmp(mid->data.name, key) == 0)
            return &(mid->data);
        if(strcmp(mid->data.name, key) > 0)
            start = mid-> next;
        else
            last = mid;
    }
    return NULL;
}

int main(){
    data_t aSV[] = {{"001", "sv1", 2},
                    {"002", "sv2", 1},
                    {"003", "sv3", 6},
                    {"004", "sv4", 5},
                    {"005", "sv5", 4},
                    {"006", "sv6", 7},
                    {"007", "sv7", 10}};

    root_t lst = llInit();

    for(int i = (sizeof(aSV) / sizeof(aSV[0])) - 1; i >= 0; i--){
        lst = llInsertByDecreaseOrderByName(lst, aSV[i]);
    }

    printf("PRINT ALL\n");
    llPrint(lst);

    char *name = "sv4";
    data_t *need = binarySearchByName(lst, name);
    if(need == NULL){
        printf("NOT FOUND\n");
    }
    else 
        printf("FOUND\n%-10s%-10s%d", need->id, need->name, need->grade);    
    return 0;
}