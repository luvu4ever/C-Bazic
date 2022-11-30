//LuvU4ever
#include<stdio.h>
#define forr(i,a,b) for(int i = (a); i<=(b); i++)
#define MAX_N 105

int BinarySearch(int a[], int n, int target){
    int low = 1;
    int high = n;
    int count = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        printf("%d\n", mid);
        count++;
        if(a[mid] == target)
            return mid;
        else{
            if(a[mid] < target) low = mid+1;
            else
                high = mid -1;
        }
    }
    printf("%d\n", count);
    return -1;
}

int BinarySearchBackTrack(int a[], int low, int high, int target){
    if(low >high) return -1;
    int mid = low + (high - low) /2;
    if(a[mid] == target)
        return mid;
    if(a[mid] < target)
        return (a, low, mid-1, target);
    return (a, mid+1, high, target);
}

int main(){
    int x, a[MAX_N];
    int n = 100;
    forr(i,1,n){
        a[i] = i;
    }
    scanf("%d", &x);
    // if(BinarySearch(a, n, x) == -1)
    //     printf("Not found");
    // else
    //printf("%d\n", BinarySearch(a, n, x));
    printf("%d\n", BinarySearchBackTrack(a, 1, n, x));
    return 0;
}