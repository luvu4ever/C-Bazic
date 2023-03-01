//---------------<3LuvU4ever-------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bst.h"

#define MAX_ROAD (3)
#define MIN_ROAD_LENGTH (10)
#define MAX_ROAD_LENGTH (500)
#define MIN_ROAD_WIDTH (3)
#define MAX_ROAD_WIDTH (20)

#define MAX_J_NAME (255)
#define MAX_BUFFER_NAME (255)

typedef struct Lane{
    char j1[MAX_J_NAME];
    char j2[MAX_J_NAME];
    char name[MAX_J_NAME];
    int L, W, d;
} Lane;

int checkJ(char *j){
    if(j[0] != 'J')
        return 0;
    if(j[1] > '9' || j[1] < '0' || j[2] >'9' || j[2] < '0' || j[3] > '9' || j[3] < '0')
        return 0;
    return 1;
}

int checkLW(int l, int w){
    if(l < MIN_ROAD_LENGTH || l > MAX_ROAD_LENGTH || w < MIN_ROAD_WIDTH || w > MAX_ROAD_LENGTH)
        return 0;
    return 1;
}

void display_menu(){
    printf("\n----------Menu-----------\n");
    printf("1. \n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    return;
}

char dataFilename[] = "input.txt";

Lane* getContent(char *fileName, int *N){
    Lane *tmp;
    FILE *f;
    char buffer[MAX_BUFFER_NAME];
    f = fopen(fileName, "r");
    int line = 0;
    int size = 0;
    int max = 0;
    int totalJ = 0, totalLW = 0;
    int maxline = 0;
    while(fgets(buffer, MAX_BUFFER_NAME, f)){
        if(line == 0){
            sscanf(buffer, "%d", N);
            tmp = (Lane*) malloc((*N)*sizeof(Lane));
            line++;
            continue;
        }
        Lane lane;
        sscanf(buffer, "%s %s %s %d %d %d", lane.j1, lane.j2, lane.name, &lane.L, &lane.W, &lane.d);
        totalJ += (checkJ(lane.j1) * checkJ(lane.j2));
        if(checkLW(lane.L, lane.W)){
            if(max < lane.L * lane.W){
                max = lane.L * lane.W;
                maxline = line;
            }
            totalLW++;
        }
        tmp[line++-1] = lane;
    }
    printf("%d %d %d", totalJ, totalLW, maxline);
    fclose(f);
    return tmp;
}

Lane* Task1(){
    int n;
    return getContent(dataFilename, &n); 
}

tree_t root = NULL;

data_t makedata(char *j1, char *j2, char *name){
    data_t temp;
    temp.sum = 0;
    for(int i=1; i<=3; i++){
        temp.sum *= 10;
        temp.sum += j1[i] - '0' + j2[i] - '0';
    }
    strcpy(temp.key, name);
    return temp;
}

tree_t BuildTree(Lane *temp, int n){
    for(int i=0; i<n; i++){
        root = insertNode(makedata(temp[i].j1, temp[i].j2, temp[i].name), root);
    }
}

void Task2(Lane *temp){
    int n;
    fscanf(stdin, "%d", &n);
    BuildTree(temp, n);
}

int main(){
    //readInput();
    int n;
    int choice;
    do{
        display_menu();
        fscanf(stdin, "%d", &choice);
        switch(choice){
            case 1:
                Lane *temp = Task1();
                break;
            case 2:
                Task2(temp);
                break;
            // case 3:
            //     Task3();
            //     break;
            // case 4:
            //     Task4();
            //     break;
            // case 5:
            //     Task5();
            //     break;
            default:
                break;
        }
    } while (choice != 5);
    return 0;
}