//----------LuvU4ever--------

#include<stdio.h>

int a[15], check[15];
int count = 0;
//I0, C1, T2, H3, U4, S5, K6

void Check(int a[], int n){
    int ICT = a[0] * 100 + a[1] * 10 + a[2];
    int K62 = a[6] * 100 + 62;
    int HUST = a[3]*1000 + a[4] * 100 + a[5] * 10 + a[2];
    //printf("%d", a[6]);
    if(ICT - K62 + HUST == n){
        //printf("%d", n);
        count++;
    }
    return;
}

void Recursion(int cur, int n){
    if(cur == 7){
        Check(a, n);
        return;
    }
    for(int i=1; i<=9; i++){
        if(check[i] == 0){
            check[i] = 1;
            a[cur] = i;
            Recursion(cur+1, n);
            check[i] = 0;
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    Recursion(0, n);
    printf("%d", count);
}