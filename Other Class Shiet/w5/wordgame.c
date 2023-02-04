#include<stdio.h>
#include<string.h>

char inputfile[] = "wordgame.inp";
char outputfile[] = "wordgame.out";

int m = 7;
int n = 10;
int k = 9;
char a[100][100];
char dic[1005][1005];

void TRY(int x, int y){
    //check hang` ngang
    for(int cur = 0; cur < k; cur ++){
        if(x + strlen(dic[cur]) - 1 > m) continue;
        int check = 1;
        for(int i=0; i < strlen(dic[cur]); i++){
            if(a[i+x][y] != dic[cur][i])
                check = 0;
        }
        if(check == 1){
            //fprintf(OUTPUT, "%s ", dic[cur]);
            printf("%s ", dic[cur]);
            printf(" Cot. %d, tu` %d den %d", y, x, x+ strlen(dic[cur]));
            // for(int i=0; i < strlen(dic[cur]); i++){
            //     //fprintf(OUTPUT, "%d %d", i+x, y);
            //     printf("%d %d  ", i+x, y);
            // }
            //fprintf(OUTPUT, "\n");
            printf("\n");
        }
    }
    //check hang` doc.
    for(int cur = 0; cur < k; cur ++){
        if(y + strlen(dic[cur]) - 1 > n) continue;
        int check = 1;
        for(int i=0; i < strlen(dic[cur]); i++){
            if(a[x][y+i] != dic[cur][i])
                check = 0;
        }
        if(check == 1){
            //fprintf(OUTPUT, "%s ", dic[cur]);
            printf("%s ", dic[cur]);
            printf(" Hang` %d, tu` %d den %d", x, y, y+ strlen(dic[cur]));
            // for(int i=0; i < strlen(dic[cur]); i++){
            //     //fprintf(OUTPUT, "%d %d", x, y+i);
            //     printf("%d %d  ", x, y+i);
            // }
            //fprintf(OUTPUT, "\n");
            printf("\n");
        }
    }
    //check hang` cheo'
    for(int cur = 0; cur < k; cur ++){
        if(y + strlen(dic[cur]) - 1 > n) continue;
        if(x + strlen(dic[cur]) - 1 > m) continue;
        int check = 1;
        for(int i=0; i < strlen(dic[cur]); i++){
            if(a[x+i][y+i] != dic[cur][i])
                check = 0;
        }
        if(check == 1){
            //fprintf(OUTPUT, "%s ", dic[cur]);
            printf("%s ", dic[cur]);
            printf(" Cheo tu` %d %d den %d %d", x, y, x+ strlen(dic[cur]), y + strlen(dic[cur]));
            // for(int i=0; i < strlen(dic[cur]); i++){
            //     //fprintf(OUTPUT, "%d %d", x+i, y+i);
            //     printf("%d %d  ", x+i, y+i);
            // }
            //fprintf(OUTPUT, "\n");
            printf("\n");
        }
    }
}

void BackTrack(){
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            TRY(i, j);
        }
    }
}

int main(){
    FILE *INPUT = fopen(inputfile, "r");
    FILE *OUTPUT = fopen(outputfile, "w");
    //fscanf(INPUT, "%d %d", &m, &n);
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            a[i][j] = fgetc(INPUT);
        }
        fgetc(INPUT);
        // clear '\n'
    }
    //fscanf(INPUT, "%d", &k);
    for(int i = 0; i < k; i++){
        fscanf(INPUT, "%s", dic[i]);
    }
    BackTrack();
    // for(int i=0; i < m; i++){
    //     for(int j=0; j < n; j++){
    //         fprintf(OUTPUT, "%c", a[i][j]);
    //     }
    //     fprintf(OUTPUT, "\n");
    // }
    
}