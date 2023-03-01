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

root_t root = NULL;

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


void Task2(FILE *fin){
    node_t *cur = root;
    char s[50];
    int hour, min;

    while((fscanf(fin, "%s %d %d", s, &hour, &min)) == 3){
        data_t temp;
        strcpy(temp.location, s);
        temp.hour = timeCal(hour, min);
        cur = llInsertAfter(cur, temp);
        if(root == NULL) root = cur;
    }
}

void Task3(){
    node_t *cur = root;
    printf("%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    while(cur != NULL){
        int hour = cur->data.hour / 60;
        int min = (cur->data.hour - hour * 60);
        printf("%-50s%-10d%-10d\n", cur->data.location, hour, min);
        cur = cur ->next;
    }
}

void Task4(){
    node_t *cur = root;
    int check = 0;
    char location[50];
    fscanf(stdin, "%s", location);
    while(cur != NULL){
        if(strcmp(cur->data.location, location)){
            cur = cur->next;
            continue;
        }
        check = 1;
        int hour = cur->data.hour / 60;
        int min = (cur->data.hour - hour * 60);
        printf("%-10d%-10d\n", hour, min);
        cur = cur ->next;
    }
    if(!check)
        printf("Ban chua toi dia diem nay\n");
}

void Task5(){
    node_t *cur = root;
    int curhour, curmin;
    fscanf(stdin, "%d %d", &curhour, &curmin);
    int time = timeCal(curhour, curmin);
    if(time < cur->data.hour){
        printf("Khong tim thay lich su di chuyen\n");
        return;
    }
    while(cur->next != NULL){
        if(time >= cur ->data.hour && time < cur -> next ->data.hour){
            printf("%s\n", cur->data.location);
            return;
        }
        cur = cur -> next;
    }
    printf("%s\n", cur->next->data.location);
    return;
}

char inputFile[] = "log.txt";

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error: Opening input file.\n");
        return 0;
    }

    int choice;
    do{
        display_menu();
        fscanf(stdin, "%d", &choice);
        switch(choice){
            case 1:
                Task2(fin);
                break;
            case 2:
                Task3();
                break;
            case 3:
                Task4();             
                break;
            case 4:
                Task5();
                break;
            // case 5:
            //     Task6();
            //     break;
            case 6:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while(choice != 6);
}
