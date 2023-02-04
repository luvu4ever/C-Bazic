#include<stdio.h>
#include<stdlib.h>

char inputFile[] = "bai1.inp";
char outputFile[] = "bai1.out";

struct Worker{
    int id;
    int status;
    int time;
    
};

struct Worker a[10005];
int count[100006], dem;

int amInTime = 8*24*60 + 30*60;
int amOutTime = 12*24*60;
int pmInTime = 13*24*60 + 30*60;
int pmOutTime = 17*24*60;

int main(){
    char s[10005];
    FILE *INPUT = fopen(inputFile, "r");
    FILE *OUT = fopen(outputFile, "w");
    int cur = 0;
    //while((fscanf(INPUT, "%s", s))){
    while(1){
        fscanf(INPUT, "%s", s);
        if(s[0] =='#') break;
        cur++;
        a[cur].id = atoi(s);
        if(!time[a[cur].id]) dem++;
        time[a[cur].id]++;
        fgetc(INPUT);
        fscanf(INPUT, "%s", s);
        //printf("%d %s\n", a[cur].id, s);
        a[cur].status = 1;
        if(s[0] == 'I') a[cur].status = 0;
        int h, m, g;
        fscanf(INPUT, "%d:%d:%d", &h, &m, &g);
        a[cur].time = h*24*60 + m*60 + g;
    }
    for(int i=0; i<cur; i++){
        
    }
    printf("Ngay hien tai co %d nguoi tai van phong", dem);
}