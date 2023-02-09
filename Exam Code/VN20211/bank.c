//---------------LuvU4ever-----------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME_LENGTH (5)


double max(double a, double b){
    return (a>b) ? a:b;
}
double min(double a, double b){
    return (a<b) ? a:b;
}

typedef struct Stock_t{
    char name[MAX_NAME_LENGTH];
    double sum, max_close, min_close;
    int increase;
    int day;
} Stock;

typedef struct node_s{
    Stock data;
    struct node_s *left;
    struct node_s *right;
} node_t, Node;

typedef node_t *tree_t;

Node *root = NULL;

Node *createStock(char *name, double sum, double close){
    Node *temp = (Node*) malloc (sizeof(Node));
    strcpy(temp->data.name, name);
    temp->data.sum = sum;
    temp->data.max_close = close;
    temp->data.min_close = close;
    temp->data. day = temp -> data.increase = (sum > 0) ? 1: 0;

    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
    
}

Node *insertStock(Node *node, char *name, double sum, double close){
    if(node == NULL)
        return createStock(name, sum, close);
    int cmp = strcmp(name, node->data.name);
    if(cmp <0)
        node->left = insertStock(node->left, name, sum, close);
    else if(cmp > 0)
        node->right = insertStock(node->right, name, sum, close);
    else{
        node -> data. sum += sum;
        node -> data. max_close = max(node->data.max_close, close);
        node -> data. min_close = min(node->data.min_close, close);
        if(node->data.increase == 1 && sum > 0) 
            node->data.increase = 2;
        else if(node->data.increase != 2)
            node->data.increase = 0;
        // == 2 means increase already
        node -> data.day += (sum > 0) ? 1:0;
    }
    return node;
}

Node *searchStock(Node *node, char *name){
    while(node != NULL){
        int cmp = strcmp(name, node->data.name);
        if(cmp < 0)
            node = node -> left;
        else if(cmp > 0)
            node = node -> right;
        else 
            return node;
    }
    return NULL;
}

int findMax(Node *node){
    if(node == NULL)
        return 0;
    return max(node->data.day, max(findMax(node->left), findMax(node->right)));
}

void PrintAll(Node *node, int task, int max){
    if(node == NULL)
        return;
    PrintAll(node -> left, task, max);
    if(task == 1)
        printf("%-20s %-10.3lf\n", node->data.name, node->data.sum *1.0 / 10);
    if(task == 3 && node->data.increase == 2)
        printf("%-20s\n", node->data.name);
    if(task == 4 && node->data.day == max){
        printf("%-20s\n", node->data.name);
    }
    PrintAll(node -> right, task, max);
    return;
}

void display_menu(){
    printf("\n----------Menu-----------\n");
    printf("1. Read file\n");
    printf("2. Find\n");
    printf("3. Increase\n");
    printf("4. Most\n");
    printf("5. Exit\n");
    return;
}

void Task1(FILE *fin){
    char name[MAX_NAME_LENGTH];
    double open, close;
    int n;
    fscanf(fin, "%d", &n);
    for(int i=0; i < n*10; i++){
        fscanf(fin, "%s %lf %lf", name, &open, &close);
        root = insertStock(root, name, close - open, close);
    }
    printf("\n----------------------------\n");
    printf("Danh sach cac ma co phieu la:\n");
    PrintAll(root, 1, 0);
    printf("----------------------------\n");
}

void Task2(FILE *fin){
    char name[MAX_NAME_LENGTH];
    printf("Yeu cau nguoi dung nhap vao ten co phieu: ");
    fscanf(stdin, "%s", name);
    Node *findP = searchStock(root, name);
    if(findP == NULL){
        printf("Not found\n");
        return;
    }
    printf("\n----------------------------\n");
    printf("%-20s %-10s %-14s\n", "Ma co phieu", "Gia max", "Gia min");
    printf("%-20s %-10.3lf %-10.3lf\n", name, findP->data.max_close, findP->data.min_close);
    printf("----------------------------\n");
}

void Task3(){
    printf("\n----------------------------\n");
    printf("Danh sach cac ma co phieu tang la:\n");
    PrintAll(root, 3, 0);
    //PrintAll(root);
    printf("----------------------------\n");
}

void Task4(){
    printf("\n----------------------------\n");
    int max = findMax(root);
    printf("So ngay tang lon nhat la: %d\n", max);
    printf("Ma co so ngay tang lon nhat la:\n");
    PrintAll(root, 4, max);
    //PrintAll(root);
    printf("----------------------------\n");
}

void Task5(){
    printf("\n----------------------------\n");
    printf("Thong tin tac gia\n");
    printf("Ho ten: Mai Viet Dung\n");
    printf("MSSV: 20210228\n");
    printf("---------------<3-------------\n");
    printf("----------------------------\n");
}

char inputFile[] = "data.txt";

int main(){

    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error: Cant opening input file.");
        return 0;
    }

    int choice;
    do{
        display_menu();
        fscanf(stdin, "%d", &choice);
        switch (choice){
            case 1:
                Task1(fin);
                break;
            case 2:
                Task2(fin);
                break;
            case 3:
                Task3(fin);
                break;
            case 4:
                Task4(fin);
                break;
            case 5:
                Task5(fin);
                break;
            default:
                break;
        }
    } while (choice != 5);
    return 0;
}