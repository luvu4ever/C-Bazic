//------------LuvU4ever---------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data_s{
    char location[45];
    int hour;
} data_t;

typedef struct node_s{
    data_t data;
    struct node_s *next;
} node_t, *root_t;

root_t llInit(){
    return NULL;
}

node_t *createNewNode(data_t data){
    node_t *newNode = (node_t*) malloc (sizeof(node_t));
    if(newNode == NULL)
        return NULL;

    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

root_t llInsertHead(root_t root, data_t data){
    node_t *newNode = createNewNode(data);
    newNode -> next = root;
    return newNode;
}

root_t llInsertAfter(node_t *cur, data_t data){
    node_t *newNode = createNewNode(data);
    if(cur == NULL)
        return newNode;
    newNode -> next = cur -> next;
    cur -> next = newNode;
    return newNode;
}

int timeCal(int hour, int minute){
    return hour * 60 + minute;
}

void display_menu(){
    printf("\nCHUONG TRINH TRUY VET COVID19\n");
    printf("1. Nap file log lich su di chuyen\n");
    printf("2. In ra lich su di chuyen\n");
    printf("3. Tim kiem lich su theo dia diem\n");
    printf("4. Tim kiem lich su theo thoi gian\n");
    printf("5. Kiem tra truy vet moi nhat\n");
    printf("6. Thoat\n");
}

char inputFile[] = "log.txt";

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error: Opening input file.\n");
        return 0;
    }

    root_t root = llInit();
    node_t *cur = root;
    char s[50];
    int hour, min;

    while((fscanf(fin, "%s %d %d", s, hour, min)) == 3){
        data_t temp;
        strcpy(temp.location, s);
        temp.hour = timeCal(hour, min);
        cur = llInsertAfter(cur, temp);
    }
    int choice;
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while(choice != 6);
}
