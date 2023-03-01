//---------------<3LuvU4ever-------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COMPUTER (25)

void display_menu(){
    printf("\n====Program for management computers===\n");
    printf("1. Load Data Files:\n");
    printf("2. Update CPU info:\n");
    printf("3. Update RAM info\n");
    printf("4. Search\n");
    printf("5. Quit\n");
    return;
}

typedef struct ComputerIn4{
    char cpu[3];
    int ram;
} com_t;

com_t computer[MAX_COMPUTER];

const char dataFile[] = "file1.inp";

int total = -1;

void readInput(){
    FILE *f = fopen(dataFile, "r");

    fclose(f);
}

void Task1(){
    char inputFile[30] = "file1.inp";
    //fscanf(stdin, "%s", inputFile);
    FILE *fin = fopen(dataFile, "r");
    if(fin == NULL){
        printf("File khong ton tai.\n");
        return;
    }
    int n;
    fscanf(fin, "%d", &n);
    char cpu[3];
    int ram;
    for(int i=0; i<n; i++){
        fscanf(fin, "%s", cpu);
        fscanf(fin, "%d", &ram);
        printf("%s %d\n", cpu, ram);
        cpu[0] = 'I';
        strcpy(computer[++total].cpu, cpu);
        computer[total] .ram = ram;
        if(total == 20){
            printf("Danh sach da day, khong them duoc\n");
            printf("So luong may vua them: %d\n", i);
            return;
        }
    }
    printf("So luong may vua them: %d\n", n);
    for(int i=0; i<=total; i++){
        printf("%s %d\n", computer[i].cpu, computer[i].ram);
    }
    fclose(fin);
}

void Task2(){
    int start = 0;
    fscanf(stdin, "%d", start);
    while(start < total){
        char cpu[3];
        printf("CPU cho may co ID %d: ");
        fscanf(stdin, "%s", cpu);
        strcpy(computer[start].cpu, cpu);
        start++;
    }
    for(int i=0; i<=total;i++){
        printf("%s %d", computer[i].cpu, computer[i].ram);
    }
    fclose(fin);
}

void Task5(){
    printf("Exit...");
    return;
}

int main(){
    readInput();

    int choice;
    do{
        display_menu();
        fscanf(stdin, "%d", &choice);
        switch(choice){
            case 1:
                Task1();
                break;
            // case 2:
            //     Task2();
            //     break;
            // case 3:
            //     Task3();
            //     break;
            // case 4:
            //     Task4();
            //     break;
            case 5:
                Task5();
                break;
            default:
                printf("Error!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}