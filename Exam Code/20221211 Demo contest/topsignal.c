//-----------LuvU4ever

#include<stdio.h>
#define MAX_N 1000005


int main(){
    int n;
    scanf("%d",&n);
    int pre = 0, cur = 0, next = 0;
    int count = 0;
    scanf("%d",&pre);
    scanf("%d",&cur);
    for(int i=2; i<n; i++){
        scanf("%d",&next);
        if((cur > pre) && (cur > next))
            count ++;
        pre = cur;
        cur = next;
    }
    printf("%d", count);
}