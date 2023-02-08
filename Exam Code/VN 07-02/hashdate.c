//----------------------LuvU4ever-------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_DATES 100000

unsigned int hash_date_string(char *date){
    unsigned int hash = 0;
    while(*date){
        hash = hash * 31 + *date ++;
    }
    return hash % MAX_DATES;
}

int main(){
    char datestring[15];
    scanf("%s", datestring);
    printf("%d", hash_date_string(datestring));
    return 0;
}