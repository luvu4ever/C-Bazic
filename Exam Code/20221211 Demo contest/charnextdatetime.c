//---------LuvU4ever----------
#include<stdio.h>
#include<string.h>
#define MAX_N 10005

#define secof24h 86400

typedef struct date_t{
    int year;
    int month;
    int day;
} Date;

char inputFile[] = "nextdatetime.inp";

Date date[MAX_N];

void PrintFormart(int year, int month, int day, int hour, int minute, int second){
    int year1 = year / 1000;
    int year2 = (year - year1*1000)/100;
    int year3 = (year - year1*1000-year2*100)/10;
    int year4 = (year - year1*1000-year2*100 - year3*10);
    int month1 = month /10;
    int month2 = (month - month1*10);
    int day1 = day/10;
    int day2 = day - day1*10;
    int hour1 = hour /10;
    int hour2 = hour - hour1*10;
    int minute1 = minute / 10;
    int minute2 = minute - minute1*10;
    int second1 = second / 10;
    int second2 = second - second1*10;
    printf("%d%d%d%d-%d%d-%d%d %d%d:%d%d:%d%d\n", year1,year2,year3,year4,month1,month2,day1,day2,hour1,hour2,minute1,minute2,second1,second2);
}

void Calculate(int year, int month, int day, int hour, int min, int sec, int time){
    int daytime = hour * 60 * 60 + min * 60 + sec;
    daytime += time;
    int nextday = daytime / secof24h;
    int check = 0;
    int trav = 0;
    daytime = daytime % secof24h;
    hour = daytime / (60*60);
    daytime -= hour * 60 * 60;
    min = daytime / 60;
    sec = daytime - min * 60;
    if(nextday == 0){
        PrintFormart(year, month, day, hour, min, sec);
        return;
    }
    while(nextday != 0){
        if(date[trav].year == year && date[trav].month == month && date[trav].day == day)
            check =1;
        trav++;
        if(check == 1){
            daytime -= 86400;
            nextday--;
        }
    }
    PrintFormart(date[trav].year, date[trav].month, date[trav].day, hour, min, sec);
    return;
}

int main(){
    int cur = -1;
    do{
        cur++;
        scanf("%d-%d-%d", &date[cur].year, &date[cur].month, &date[cur].day);
    } while(getchar() != '*');

    int curyear, curmonth, curday, curh, curm, curs, taketime;
    char c;
    getchar();
    do{
        curyear = 0;
        for(int i=0; i<4; i++){
            c = getchar();
            if(c == '*') return 0;
            curyear = curyear * 10 + (c - '0');
        }
        scanf("-%d-%d ", &curmonth, &curday);
        scanf("%d:%d:%d %d", &curh, &curm, &curs, &taketime);
        Calculate(curyear, curmonth, curday, curh, curm, curs, taketime);
        getchar();
    }   while(1);
    return 0;
}