//----------LuvU4ever--------

#include<stdio.h>
#define MAX_N 10005

#define secof24h 86400

typedef struct date_t{
    int year;
    int month;
    int day;
} Date;

char inputFile[] = "nextdatetime.inp";

Date date[MAX_N];

void Calculate(int year, int month, int day, int hour, int min, int sec, int time){
    int daytime = hour * 60 * 60 + min * 60 + sec;
    daytime += time;
    //if no next day
    if(daytime < secof24h){
        hour = daytime / (60*60);
        daytime -= hour * 60 * 60;
        min = daytime / 60;
        sec = daytime - min * 60;
        printf("%d-%d-%d %d:%d:%d\n", year, month, day, hour, min, sec);
        return;
    }
    int nextday = daytime / secof24h;
    int check = 0;
    int trav = 0;
    while(nextday != 0){
        if(date[trav].year == year && date[trav].month == month && date[trav].day == day)
            check =1;
        if(check == 1){
            nextday--;
        }
        trav++;
    }
    printf("%d-%d-%d %d:%d:%d\n", date[trav].year, date[trav].month, date[trav].day, hour, min, sec);
        return;
}

int main(){
    //FILE *f = fopen(inputFile, "r");
    int cur = -1;
    do{
        cur++;
        scanf("%d-%d-%d", &date[cur].year, &date[cur].month, &date[cur].day);
    } while(getchar() != '*');
    //printf("%d", 1);
    int curyear, curmonth, curday, curh, curm, curs, taketime;
    do{
        scanf("%d", &curyear);
        scanf("-%d-%d ", &curmonth, &curday);
        scanf("%d:%d:%d %d", &curh, &curm, &curs, &taketime);
        Calculate(curyear, curmonth, curday, curh, curm, curs, taketime);
        //getc(f);
    } while(getchar() != '*') ;
    return 0;
}
