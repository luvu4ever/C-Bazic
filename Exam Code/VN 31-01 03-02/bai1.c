//--------------LuvU4ever---------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUM_SIZE 10
#define MAX_N 1005

char inputFile[] = "bai1.inp";
char outputFile[] = "bai1.out";

int road[MAX_N][MAX_N];

int ReadInput(FILE *fin, int n){
    fscanf(fin, "%d", &n);
    fgetc(fin);
    char s[NUM_SIZE], t[NUM_SIZE];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            road[i][j] = 1;
        }
        road[i][i] = 0;
    }
    fscanf(fin, "%s", s);
    while(s[0] != '$'){
        fgetc(fin);
        fscanf(fin, "%s", t);
        fgetc(fin);
        int start = atoi(s);
        int end = atoi(t);
        road[start][end] = 0;
        road[end][start] = 0;
        fscanf(fin, "%s", s);
    }
    return n;
}

void display_menu(){
    printf("\n--------Menu---------\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. Exit\n");
    return;
}

void FunctionA(FILE *fin, FILE *fout, int n){
    int from, count = 0;
    scanf("%d", &from);
    for(int i=0; i<n; i++){
        count += road[from][i];
    }
    if(count == n-1){
        printf("-1");
        return ;
    }
    printf("Tu %d den duoc: ", from);
    for(int i=0; i<n; i++){
        if(road[from][i])
            printf("%d ", i);
    }
    return;
}

void PrintRoad(int cur, int visited, int par[]){
    int list[MAX_N];
    for(int i = visited-1; i>=0; i--){
        list[i] = cur;
        cur = par[cur];
    }

    printf("Con duong: ");
    for(int i = 0; i<visited; i++)
        printf("%d ", list[i]);
    printf("\n");
    return;
}

int Recursion(int n, int cur, int visited, int par[]){
    int check = 0;
    if(visited == n){
        PrintRoad(cur, n, par);
        return 1;
    }

    for(int i=0; i<n; i++){
        if(road[cur][i] && par[i] == -2){
            par[i] = cur;
            check += Recursion(n, i, visited + 1, par);
            par[i] = -2;
        }
    }
    return check!=0 ? 1:0;
}

void FunctionB(FILE *fin, FILE *fout, int n){
    int from;
    scanf("%d", &from);
    int par[MAX_N];
    for(int i=0; i<n; i++){
        par[i] = -2;
    }
    par[from] = -1;
    if(Recursion(n, from, 1, par)) return;

    printf("-1");
    return;
    //currently at from, visited 1 home, need n home

}

void AdvancedRecursion(int n, int cur, int visited, int par[], int *ans){

    if(visited == n) return;
    for(int i=0; i<n; i++){
        if(road[i][cur] && par[i] == -2){
            par[i] = cur;
            PrintRoad(i, visited + 1, par);
            (*ans) ++;
            AdvancedRecursion(n, i, visited +1, par, ans);
            par[i] = -2;
            // +1 for i, -1 because it needed
        }
    }
}

void FunctionC(FILE *fin, FILE *fout, int n){
    int ans = 0;
    int par[MAX_N];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            par[j] = -2;
        par[i] = -1;
        AdvancedRecursion(n, i, 1, par, &ans);
    }
    printf("Total amount of road %d", ans);
    return;

}

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error opening input file\n");
        return 0;
    }
    FILE *fout = fopen(outputFile, "w");
    if(fout == NULL){
        printf("Error opening output file\n");
        return 0;
    }
    int n = ReadInput(fin, n);

    int choice;
    do{
        display_menu();
        scanf("%d", &choice);
        switch (choice){
        case 1:
            FunctionA(fin, fout, n);
            break;
        case 2:
            FunctionB(fin, fout, n);
            break;
        case 3:
            FunctionC(fin, fout, n);
            break;
        case 4:
            printf("Exiting....");
            break;
        default:
            printf("Invalid choice");
            break;
        }
    } while(choice != 4);
    
    fclose(fin);
    fclose(fout);
    return 0;
}