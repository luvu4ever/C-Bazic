#include<stdio.h>
#include<stdlib.h>

char outputFilename[] = "output.txt";

int main(){
    int n;
    double sum = 0;
    double *ptr;
    FILE *f = fopen(outputFilename, "w");
    scanf("%d", &n);
    ptr = (double*)malloc(n * sizeof(double));
    if(ptr == NULL){
        printf("Memory not allocated");
        return 0;
    }
    for(int i=0; i<n; i++){
        scanf("%lf", &ptr[i]);
        sum += ptr[i];
    }
    for(int i=n-1; i>=0; i--){
        fprintf(f, "%.3lf ", ptr[i]);
    }
    fprintf(f,"%.3lf", sum);
    return 0;
}