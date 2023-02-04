//------------LuvU4ever------------

#include<stdio.h>
#include<string.h>

#define MAX_LENGTH (25)
#define MAX_ATM_LENGTH (15)
#define MAX_N (10005);

typedef struct BankTransaction_t{
    char from[MAX_LENGTH];
    char to[MAX_LENGTH];
    int money;
    // int hour;
    // int minute;
    // int second;
    // char atm[MAX_ATM_LENGTH];
} BankT;

BankT a[10005];

char bankaccount[1005][MAX_LENGTH];
int totalmoney[1005];
int connect[1005][1005];
int check[1005];

int NotExisted(char a[], int n){
    if(n==-1) return 1;
    for(int i=0;i<n; i++){
        if(!strcmp(bankaccount[i],a))
            return 0;
    }
    return 1;
}


void SortBankAccount(int n){
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if(strcmp(bankaccount[i],bankaccount[j]) > 0)
            {
                for(int t = 0; t < 20; t ++){
                    char temp = bankaccount[i][t];
                    bankaccount[i][t] = bankaccount[j][t];
                    bankaccount[j][t] = temp;
                }
            }
        }
    }
    return;
}

int ListSortedAccount(BankT a[], int count){
    int n = -1;
    for(int i=0; i<count; i++){
        if(NotExisted(a[i].from, n)){
            n++;
            for(int j=0; j<20; j++){
                bankaccount[n][j] = a[i].from[j];
            }
        }
        if(NotExisted(a[i].to, n)){
            n++;
            for(int j=0; j<20; j++){
                bankaccount[n][j] = a[i].to[j];
            }
        }
    }
    SortBankAccount(n);
    return n;
}

void PreCalculate(BankT a[], int count, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<count; j++){
            if(strcmp(bankaccount[i], a[j].from) == 0)
                totalmoney[i] += a[j].money;
        }
    }
    for(int i=0; i<count; i++){
        int from = 0;
        int to = 0;
        for(int j=0; i<n; j++){
            if(strcmp(bankaccount[j], a[i].from) == 0)
                from = j;
            if(strcmp(bankaccount[j], a[i].to) == 0)
                to = j;    
        }
        connect[from][to] = 1;
    }
}

int Recursion(int cur, int need, int p, int first, int n){
    if(cur == need+1){
        if(connect[p][first] == 1)
            return 1;
        return 0;
    }
    int sumcheck = 0;
    for(int i=0; i<n; i++){
        if(check[i] == 0 && connect[p][i] == 1){
            check[i] = 1;
            sumcheck += Recursion(cur+1, need, i, first, n);
            check[i] = 0;
        }
    }
    return sumcheck;
}

int CheckCycle(char key[], int need, int n){
    int first = 0;
    for(int i=0; i<n; i++){
        if(strcmp(bankaccount[i], key) == 0)
            first = i;
    }
    return Recursion(0, need, first, first, n);
}

int main(){
    int count = -1;
    int n = -1;
    int sum =0;
    int hour, min, sec;
    char atm[MAX_ATM_LENGTH];
    do{
        count++;
        scanf("%s", a[count].from);
        if(a[count].from[0] == '#'){
            count--;
            break;
        }
        scanf("%s %d %d:%d:%d %s", a[count].to, &a[count].money, &hour, &min, &sec, atm);
        sum += a[count].money;
    }
    while (1);
    //number of transactions && total money
    n = ListSortedAccount(a, count);
    PreCalculate(a, count , n);
    char order[100];
    do{
        scanf("%s", order);
        if(order[0] == '#') return 0;
        if(order[1] == 'n'){
            printf("%d\n", count+1);
            continue;
        }
        // if(order[1] == 't' && strlen(order) == 24){
        //     printf("%d\n", sum);
        //     continue;
        // }
        // if(order[1] == 'l'){
        //     for(int i=0; i<n; i++){
        //         printf("%s\n", bankaccount[i]);
        //     }
        //     continue;
        // }
        // char key[25];
        // scanf("%s", key);
        // if(order[1] == 'i'){
        //     int d;
        //     scanf("%d", &d);
        //     CheckCycle(key, d, n);   
        // }
        // for(int i=0; i<n; i++){
        //     if(!strcmp(bankaccount[i], key)){
        //         printf("%d\n", totalmoney[i]);
        //         break;
        //     }
        // }
    }
    while(1);
    return 0;
}