#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_S 1005
#define MAX_SIZE 7

//string to float

char inputFile[] = "input.txt";

double sizeCovert(char *size){
    char copy[MAX_SIZE];
    for(int i=0; i<strlen(size)-1; i++){
        copy[i] = size[i];
    }
    double real = atof(copy);
    if(size[strlen(size)-1] == 'M')
        real *= 1024;
    else if(size[strlen(size)-1] == 'G')
        real *= 1024 * 1024;
    return real;
}

void ReadInput(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("cant open file\n");
        return;
    }
    char ch;
    while((ch = fgetc(fin)) != '$'){
        int day = (ch - '0');
        int month, year, block;
        char sender[MAX_S], receiver[MAX_S];
        char size[MAX_SIZE];

        ch = fgetc(fin);
        day = day * 10 + (ch - '0');

        fscanf(fin, "-%d-%d", &month, &year);   fgetc(fin);
        fscanf(fin, "%s", sender);  fgetc(fin);
        fscanf(fin, "%s", size);    fgetc(fin); 
        fscanf(fin, "%s", receiver);    fgetc(fin);
        fscanf(fin, "%d", &block);  fgetc(fin);
        printf("%lf\n",sizeCovert(size));
    }
}

int main(){
    ReadInput();
    return 0;
}