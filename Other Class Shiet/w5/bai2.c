#include<stdio.h>

char inputFile[] = "bai2.inp";
char outputFile[] = "bai2.out";

int tplt = 0;
int moveX[5] = {-1, 1, 0, 0};
int moveY[5] = {0, 0, -1, 1};
int a[10005][10005];
int dd[10005][10005];
int area = 0;

void TRY(int x, int y, int n, int m){
    dd[x][y] = 1;
    area = area + 1;
    //printf("%d %d\n", x, y); 
    for(int i=0; i<4; i++){
        int xcur = x + moveX[i];
        int ycur = y + moveY[i];
        if(xcur <0 || ycur <0 || xcur >=n || ycur >=m) continue;
        if(dd[xcur][ycur]==0 && a[xcur][ycur]==1)
            TRY(xcur, ycur, n, m);
    }
}

int DFS(int n, int m){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dd[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dd[i][j]==0 && a[i][j]==1){
                //printf("tplt %d %d\n", i, j);
                tplt ++;
                area = 0;
                TRY(i, j, n, m);
                //printf("%d", area);
                if(area > ans) ans = area;
            }
        }
    }
    return ans;
}

int main(){
    FILE *INPUT = fopen(inputFile, "r");
    FILE *OUTPUT = fopen(outputFile, "w");
    int n, m;
    fscanf(INPUT, "%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            fscanf(INPUT, "%d", &a[i][j]);
            //fgets(a[i], sizeof a[i], INPUT);
        }
    }
    printf("%d ", DFS(n, m));
    printf("%d", tplt);
    return 0;
}