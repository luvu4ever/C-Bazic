//---------------LuvU4ever---------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH (32)
#define MAX_DATE_LENGTH (15)
#define MAX_LOG_LENGTH (105)
#define MAX_N (25)

char inputFile[] = "bai2.inp";

typedef struct Log_t{
    int money;
    int amount;
    char id[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
} Log;

typedef struct node_s{
    Log key;
    struct node_s *left;
    struct node_s *right;
} node_t;

typedef node_t *tree_t;

int moneyCheck(int cost){
    if(cost < 1 || cost > 2000000)
        return 0;
    return 1;
}

int amountCheck(int number){
    if(number <= 0 || number >= 100)
        return 0;
    return 1;
}

int bestPPN(int cost, int number, float max){
    float ppn = cost / number * 1.0;
    if(ppn > max) 
        return ppn;
}

Log *createLog(int money, int amount, char *id, char *date){
    Log *temp = (Log *) malloc (sizeof(Log));
    temp -> money = money;
    temp -> amount = amount;
    strcpy(temp->id, id);
    strcpy(temp->date, date);

    temp -> left = NULL;
    temp -> right = NULL;
}

Log *insertLog(Log *node, int money, int amount, char *id, char *date){
    if(node == NULL)
        return createLog(money, amount, id, date);
    int cmp = 0;
    if(money < node->money)
        cmp = -1;
    else if(money > node->money)
        cmp = 1;
    else if(amount < node -> amount)
        cmp = -1;
    else if(amount > node -> amount)
        cmp = 1;
    else{
        cmp = strcmp(id, node->id);
        if(cmp == 0)
            cmp = strcmp(date, node->date);
    }
    if(cmp < 0)
        node->left = insertLog(node->left, money, amount, id, date);
    else if(cmp > 0)
        node -> right = insertLog(node -> right, money, amount, id, date);
    else{
        node -> money += money;
        node -> amount += amount;
    }
}

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error opening input file");
        return 0;
    }

    char date[MAX_N][MAX_DATE_LENGTH], sender[MAX_N][MAX_NAME_LENGTH], receiver[MAX_N][MAX_NAME_LENGTH];
    char id[MAX_N][MAX_NAME_LENGTH];
    int number[MAX_N], cost[MAX_N];
    int max_line;
    float max = 0;
    int valid_money = 0, valid_amount = 0;
    //price per number
    //Node tree.root = NULL;
    char log[MAX_LOG_LENGTH];
    int count = 0;
    while(fscanf(fin, "%s %s %s %s %d %d", date[count], sender[count], receiver[count], id[count], &number[count], &cost[count]) == 6){
        valid_money += moneyCheck(cost[count]);
        valid_amount += amountCheck(number[count]);
        max = bestPPN(cost[count], number[count], max);
        if(max == (cost[count] / number[count] * 1.0))
            max_line = count;
        root = insertLog(root, cost, number, id, date);
    }
    printf("%d %d %d\n", valid_money, valid_amount, max_line);

    int order;
    fscanf("%d", &order);
    for(int i=0; i<n; i++){

    }

}
