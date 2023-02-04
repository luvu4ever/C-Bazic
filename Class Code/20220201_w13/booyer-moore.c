//searching for a string booyer moore
//make 2000 character random string
//----------LuvU4ever-------------

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define LENGTH 2000

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 

void lastOccur(char *str, int size, int last[260]){
    for(int i=0; i<256; i++)
        last[i] = -1;
    for(int i=0; i<size; i++)
        last[(int) str[i]] = i;
    for(int i=0; i<size; i++){
        printf("%d", last[(int)str[i]]);
    }
}

void Search(char *str, char *key){
    int m = strlen(key);
    int n = strlen(str);

    int last[260];
    lastOccur(key, n, last);

    int s = 0;
    while(s <= (n-m)){
        int j = m - 1;
        while(j >= 0 && key[j] == str[s+j])
            j--;
        if(j<0){
            printf("pattern occur at shift =%d\n", s);
            s+= ((s+m)< n) ? m-last[str[s+m]] : 1;
        }
        else
            s+= max(1, j - last[str[s+j]]);
    }
}

int main(){
    //make random string
    char str[LENGTH+5] = "20210228";
    srand(time(NULL));

    // for(int i=0; i< LENGTH; i++)
    //     str[i] = rand() % 26 + 'a';
    
    str[LENGTH] = '\0';
    printf("%s\n", str);
    char key[256];
    scanf("%s", key);
    Search(str, key);
}