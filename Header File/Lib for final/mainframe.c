//---------------<3LuvU4ever-------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display_menu(){
    printf("\n----------Menu-----------\n");
    printf("1. \n");
    printf("2. \n");
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    return;
}

const char dataFilename[] = ".txt";

void readInput(){
    FILE *f = fopen(dataFilename, "r");

    fclose(f);
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
            case 2:
                Task2();
                break;
            case 3:
                Task3();
                break;
            case 4:
                Task4();
                break;
            case 5:
                Task5();
                break;
            default:
                break;
        }
    } while (choice != 5);
    return 0;
}