//--------------LuvU4ever--------------//
#include<stdio.h>

char inputFile[] = "input.txt";

char s[10005];

int main(){
    FILE *F = fopen(inputFile, "r");
    if(F == NULL){
        printf("Error: Cannot open %s for reading\n", inputFile);
        return 1;
    }
    int cur = 1;
    while(fgets(s, sizeof(s), F) != NULL){
        printf("%d. %s", cur++, s); 
    }
    fclose(F);
    return 0;
}