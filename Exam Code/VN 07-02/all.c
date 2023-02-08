//-------------LuvU4ever-----------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ID_LENGTH (105)
#define MAX_DATE_LENGTH (15)
#define MAX_LOG_LENGTH (32)
#define MAX_NAME_LENGTH (32)
#define DOUBLE_MAX_NAME_LENGTH (65)
#define MAX_N (25)
#define MAX_DATES (100000)

typedef struct Log_t{
    int money;
    int amount;
    char id[MAX_ID_LENGTH];
    char date[MAX_DATE_LENGTH];
    char sell_buy[MAX_NAME_LENGTH];
} Log;

typedef struct node_s{
    Log data;
    struct node_s *left;
    struct node_s *right;
} node_t, Node;


int moneyCheck(int money){
    if(money < 1 || money > 200000)
        return 0;
    return 1;
}

int amountCheck(int amount){
    if(amount < 1 || amount >= 100)
        return 0;
    return 1;
}

double PPN(int cost, int number){
    return (double)(cost/number * 1.0) ;
}

void SBconvert(char *seller, char *buyer, char result[]){
    int temp = 0;
    for(int i=0; i< strlen(seller); i++)
        result[temp++] = seller[i];
    result[temp++] = '_';
    for(int i=0; i< strlen(buyer); i++)
        result[temp++] = buyer[i];
    result[temp] = '\0';
    return;
}

int numNode = 0;

Node *createLog(int money, int amount, char *id, char *date, char *sell_buy){
    Node *temp = (Node*) malloc (sizeof(Node));
    numNode ++;
    temp ->data. money = money;
    temp ->data. amount = amount;
    strcpy(temp->data.id, id);
    strcpy(temp->data.date, date);
    strcpy(temp->data.sell_buy, sell_buy);
    temp -> left = NULL;
    temp ->right = NULL;
    return temp;
}


Node *insertLog(Node *root, int money, int amount, char *id, char *date, char *sell_buy){
    if(root == NULL)
        return createLog(money, amount, id, date, sell_buy);
    int cmp = 0;
    cmp = strcmp(date, root->data.date);
    if(cmp == 0)
        cmp = strcmp(sell_buy, root->data. sell_buy);
    if(cmp == 0)
        cmp = strcmp(id, root->data.id);

    if(cmp < 0)
        root ->left = insertLog(root->left, money, amount, id, date, sell_buy);
    else if(cmp > 0)
        root->right = insertLog(root->right, money, amount, id, date, sell_buy);
    else{
        root->data.money += money;
        root ->data.amount += amount;
    }
    return root;
}

int height(Node *node){
    if(node == NULL)
        return 0;
    int ldepth = height (node -> left);
    int rdepth = height (node -> right);

    if(ldepth > rdepth)
        return ldepth + 1;
    return rdepth + 1;
}

Node *searchLog(Node *node, char *date, char *sell_buy){
    while(node != NULL){
        int cmp = strcmp(date, node->data.date);
        if(cmp == 0)
            cmp = strcmp(sell_buy, node->data.sell_buy);
        if(cmp < 0)
            node = node ->left;
        else if(cmp > 0)
            node = node -> right;
        else{
            return node;
        }
    }
    return NULL;
}

Node *buildTree(int N, Log store[]){
    Node *root = NULL;
    for(int i=0; i<N; i++){ 
        root = insertLog(root, store[i].money, store[i].amount, store[i].id, store[i].date, store[i].sell_buy);
    }
    printf("Number of Node in tree: %d\n", numNode);
    return root;
}

void sumBST(Node *root, char *date, char *sell_buy, int *amount, int *money){
    if(root == NULL || strcmp(root->data.sell_buy, sell_buy) || strcmp(root->data.date, date)){
        *amount = 0;
        *money = 0;
        return ;
    }
    int pre_amount = 0, pre_money= 0;
    sumBST(root->left, date, sell_buy, &pre_amount, &pre_money);
    sumBST(root->right, date, sell_buy, &pre_amount, &pre_money);
    *amount += pre_amount + root->data.amount;
    *money += pre_money + root->data.money;
}

unsigned int hash_date_string(char *date){
    unsigned int hash = 0;
    while(*date){
        hash = hash * 31 + *date ++;
    }
    return hash % MAX_DATES;
}

void Task1(int valid_money, int valid_amount, int max_line){
    printf("Number of valid money line: %d\n", valid_money);
    printf("Number of valid amount line: %d\n", valid_amount);
    printf("Line with max PPN: %d\n", max_line);
}

Node* Task2(FILE *fin, Log store[]){
    int order;
    int count[MAX_DATES + 5];
    fscanf(fin, "%d", &order);
    Node *root = buildTree(order, store);
    printf("Height of bst tree: %d\n", height(root));
    int max = 0;
    char ans[MAX_DATE_LENGTH];
    for(int i=0; i< order; i++){
        int index = hash_date_string(store[i].date);
        count[index]++;
        if(count[index] > max){
            max = count[index];
            strcpy(ans, store[i].date);
        }
    }
    printf("Day with the most transaction: %s\n", ans);
    return root;
}

void Task3(FILE *fin, Log store[], Node *root){
    char date[MAX_DATE_LENGTH], seller[MAX_NAME_LENGTH], buyer[MAX_NAME_LENGTH];
    //printf("Input dd mm yyyy: \n");
    fscanf(fin, "%s", date);
    //printf("Nhap ten nguoi ban: \n");
    fscanf(fin, "%s", seller);
    //printf("Nhap ten nguoi mua: \n");
    fscanf(fin, "%s", buyer);
    char sell_buy[DOUBLE_MAX_NAME_LENGTH];
    SBconvert(seller, buyer, sell_buy);
    
    Node *findP = searchLog(root, date, sell_buy);
    if(findP == NULL){
        printf("Not found\n");
        return;
    }

    int total_amount = 0, total_money = 0;
    sumBST(findP, date, sell_buy, &total_amount, &total_money);
    printf("Number of product selled: %d\n", total_amount);
    printf("Number of money transaction: %d\n", total_money);
    return;
} 

char inputFile[] = "bai2.inp";

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error opening input file\n");
        return 0;
    }

    char date[MAX_DATE_LENGTH], buyer[MAX_NAME_LENGTH], seller[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int number, cost;
    int max_line;
    double max = 0;
    int valid_money = 0, valid_amount = 0;
    Log store[MAX_N];
    int count = -1;

    int line = -1;
    fscanf(fin, "%s", date);
    while(date[0] != '$'){
        line++;
        fscanf(fin, "%s %s %s %d %d", seller, buyer, id, &number, &cost);
        valid_money += moneyCheck(cost);
        valid_amount += amountCheck(number);
        if(PPN(cost, number) > max){
            max = PPN(cost, number);
            max_line = line;
        }
        if(moneyCheck(cost) && amountCheck(number)){
            count++;

            store[count].money = cost;
            store[count].amount = number;
            strcpy(store[count].id, id);
            strcpy(store[count].date, date);
            char sell_buy[DOUBLE_MAX_NAME_LENGTH];
            SBconvert(seller, buyer, sell_buy);
            strcpy(store[count].sell_buy, sell_buy);
        }
        fscanf(fin, "%s", date);
    }
    Task1(valid_money, valid_amount, max_line);
    //Task 2
    Node *root = Task2(fin, store);
    Task3(fin, store, root);
    return 0;
}