//------------LuvU4ever--------------

#include<stdio.h>
#include<string.h>

#define MAX_LENGTH (25)
#define MAX_ATM_LENGTH (15)
#define MAX_N (10005)
#define longest (20)

typedef struct BankTransaction_t{
    char from[MAX_LENGTH], to[MAX_LENGTH];
    int money;
} BankT;

BankT trans[100005];
int n=-1, m=-1;
int sum = 0;
char bankacc[MAX_N][MAX_LENGTH];
int totalmoney[MAX_N];
int connect[MAX_N][MAX_N];
int check[MAX_N];
// sum: total amount money transactions
// n stands for number of bank accounts
// m stands for number of bank transactions

void INPUT(){
    int hour, min, sec, atm[MAX_ATM_LENGTH];
    do{
        m++;
        scanf("%s", &trans[m]. from);
        if(trans[m].from[0] == '#'){
            m--;
            break;
        }
        scanf("%s %d %d:%d:%d %s", trans[m].to, &trans[m].money, &hour, &min, &sec, atm);
        sum += trans[m].money;
    }
    while(1);
}

int BinarySearch(char key[]){
    int low = 0;
    int high = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(!strcmp(key, bankacc[mid]))
            return mid;
        else
            if(strcmp(key, bankacc[mid]) > 0)
                low = mid + 1;
            else
                high = mid - 1;
    }
    return -1;
}

void MakeAccount(){
    for(int i=0; i<m; i++){
        if(BinarySearch(trans[i].from) == -1){
            n++;
            for(int j=0; j<longest; j++){
                bankacc[n][j] = trans[i].from[j];
            }
        }
        if(BinarySearch(trans[i].to) == -1){
            n++;
            for(int j=0; j<longest; j++){
                bankacc[n][j] = trans[i].to[j];
            }
        }
    }
}

int Partition(int start, int end){
    int pivot = start;

    int count = 0;

    for(int i=start + 1; i < end; i++){
        if(strcmp(bankacc[i], bankacc[pivot]) <= 0)
            count++;
    }

    int pivotIndex = start + count;
    for(int t = 0; t < longest; t++){
        char temp = bankacc[start][t];
        bankacc[start][t] = bankacc[pivotIndex][t];
        bankacc[pivotIndex][t] = temp;
    }

    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(strcmp(bankacc[i], bankacc[pivot]) <= 0) i++;
        while(strcmp(bankacc[j], bankacc[pivot]) > 0) j--;

        if(i<pivotIndex && j> pivotIndex){
            for(int t = 0; t < longest; t++){
                char temp = bankacc[i][t];
                bankacc[i][t] = bankacc[j][t];
                bankacc[j][t] = temp;
            }
            i++;
            j--;
        }
    }
    return pivotIndex;
}

void QuickSortAccount(int start, int end){
    if(start >= end)
        return;
    int p = Partition(start, end);
    QuickSortAccount(start, p-1);
    QuickSortAccount(p+1, end);
}

void SortAccount(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(strcmp(bankacc[i], bankacc[j]) > 0){
                //swap bank acc i and j
                for(int t = 0; t < longest; t++){
                    char temp = bankacc[i][t];
                    bankacc[i][t] = bankacc[j][t];
                    bankacc[j][t] = temp;
                }
            }
        }
    }
    return;
}

void PreCalculate(){
    for(int i=0; i<m; i++){
        int from = BinarySearch(trans[i].from);
        int to = BinarySearch(trans[i].to);
        totalmoney[from] += trans[i].money;
        connect[from][to] = 1;
    }
}

int Recursion(int cur, int need, int pre, int first){
    if(cur == need){
        if(connect[pre][first] == 1)
            return 1;
        return 0;
    }
    int sumcheck = 0;
    for(int i=0; i<n; i++){
        if(!check[i] && connect[pre][i]){
            check[i] = 1;
            sumcheck += Recursion(cur+1, need, i, first);
            check[i] = 0;
        }
    }
    return sumcheck;
}

int CheckCycle(char key[], int need){
    int first = BinarySearch(key);
    return Recursion(1, need, first, first)? 1:0; 
}


void Querry(){
    char order[100];
    do{
        scanf("%s", order);
        if(order[0] == '#')
            return;
        if(strlen(order) == 20){
            //?number_transactions
            printf("%d\n", m+1);
            continue;
        }
        if(strlen(order) == 21){
            //?list_sorted_accounts
            for(int i=0; i<n; i++){
                printf("%s\n", bankacc[i]);
            }
            continue;
        }
        if(strlen(order) == 24){
            //?total_money_transaction
            printf("%d\n", sum);
            continue;
        }
        char key[100];
        scanf("%s", key);
        if(strlen(order) == 29){
            //?total_money_transaction_from
            printf("%d\n", totalmoney[BinarySearch(key)]);
            continue;
        }
        // last querry
        int d;
        scanf("%d", &d);
        printf("%d\n", CheckCycle(key, d));
    }
    while(1);
    return;
}

int main(){
    INPUT();
    MakeAccount();
    QuickSortAccount(0, n-1);
    PreCalculate();
    Querry();
}
