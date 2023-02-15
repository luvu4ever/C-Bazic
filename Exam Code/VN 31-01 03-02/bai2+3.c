//------------LuvU4ever-----------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_MESSAGES (105)
#define MAX_HASH_DATE (505)
#define MAX_DATE_LENGTH (15)
#define MAX_MESS_LENGTH (105)
#define MAX_NAME_LENGTH (32)
#define MAX_SIZE_LENGTH (10)
#define MAX_YSR_LENGTH (70)
// DD-MM-YYYY   sender size receiver blocked
// 01234567891011

//Note: 2000 year of hash is too much to handle, so i just do for about 30 year.
//so year gonna run from 1 -> 30 is fine, or 2000 -> 2030, cause i use year % 2000
//hope this work fine
//This only affects the task 3. if the task 3 isn't concerned of year, it gonna be better
//Just use hash instead of hashlongday then.

char inputFile[] = "bai2.inp";
char outputFile[] = "bai2.out";

typedef struct Message_t{
    double size;
    char ysr[MAX_YSR_LENGTH];
    // ysr stand for year_sender_receiver
    int blocked;
    int sent;
    struct Message_t *left, *right;
} Mess;

typedef struct node{
    char date[MAX_DATE_LENGTH];
    Mess *root;
} Node;

void display_menu(){
    printf("\n--------Menu---------\n");
    printf("1. A\n");
    printf("2. B\n");
    printf("3. C\n");
    printf("4. D\n");
    printf("5. Exit\n");
    return;
}

int hash(int day, int month){
    return month*31 + day;
    //12 * 31 + 31 = 402 is fine 
}

int hashlongday(int day, int month, int year){
    year %= 2000;
    return year * 31 * 31 + month * 31 + day;
}

int CheckValidDay(int day, int month){
    int dateofmonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month < 0 || month > 12)
        return 0;
    if(day<0 || day > dateofmonth[month])
        return 0;
    return 1;
}

void YSRconvert(char *year, char *sender, char *receiver, char result[]){
        //year_sender_receiver
        int temp = 0;
        int i = 0;
        for(i=0; i < strlen(year); i++)
            result[temp++] = year[i];
        result[temp++] = '_';

        for(i=0; i < strlen(sender); i++)
            //+1 because of _
            result[temp++] = sender[i];
        result[temp++] = '_';

        for(i=0; i< strlen(receiver); i++)
            result[temp++] = receiver[i];
        result[temp] = '\0';
        return;
}

Mess *createMessage(char ysr[], double size, int blocked){
    Mess *temp = (Mess *) malloc (sizeof(Mess));
    strcpy(temp->ysr, ysr);
    temp ->size = size;
    printf("%d", blocked);
    temp ->blocked = blocked;
    temp ->sent = 1;
    temp->left = NULL;
    temp -> right = NULL;
    return temp;
}
//build a bst tree and add node, main included

Mess *insertMessage(Mess *node, char ysr[], double size, int blocked){
    if(node == NULL)
        return createMessage(ysr, size, blocked);
    int cmp = strcmp(ysr, node -> ysr);
    if(cmp < 0)
        node->left = insertMessage(node->left, ysr, size, blocked);
    else if(cmp > 0)
        node -> right = insertMessage(node->right, ysr, size, blocked);
    else{
        node -> blocked += blocked;
        node -> size += size;
        node -> sent++;
    }

    return node;
}

Mess *searchMessage(Mess *node, char *ysr){
    while(node != NULL){
        int cmp = strcmp(ysr, node -> ysr);
        if(cmp < 0)
            node = node -> left;
        else if(cmp > 0)
            node = node -> right;
        else 
            return node;
    }
    return NULL;
}

void PrintSize(double size){
    printf("Total size of mess sent: ");
    if(size > 0.5 * 1024 * 1024)
        printf("%.3lfGB", size/1024/1024);
    else if(size > 0.5*1024)
        printf("%.3lfMB", size/1024);
    else
        printf("%.3lfKB", size);
    printf("\n");
}

void Task5(FILE *fin, FILE *fout, Node all[]){
    char day[3], month[3], year[5];
    char sender[MAX_NAME_LENGTH], receiver[MAX_NAME_LENGTH];
    printf("Nhap ngay thang nam: ");
    scanf("%s %s %s", day, month, year);
    printf("Nhap ten nguoi gui: ");
    scanf("%s", sender);
    printf("Nhap ten nguoi nhan: ");
    scanf("%s", receiver);
    
    int index = hash(atoi(day), atoi(month));
    char ysr[MAX_YSR_LENGTH];
    YSRconvert(year, sender, receiver, ysr);
    Mess *messP = searchMessage(all[index].root, ysr);
    if(messP == NULL){
        printf("Error 404: Unfound\n");
        return;
    }
    printf("Number of mess sent: %d\n", messP -> sent);
    PrintSize(messP -> size);
    //printf("Total size of mess sent: %lf\n", messP -> size);
    printf("Number of mess blocked: %d\n", messP -> blocked);
    
    return;
}

void ReadInput(FILE *fin, Node *all, int *ans1, double *ans2, char *ans3){
    char mess[MAX_MESS_LENGTH];
    char day[3], month[3], year[5];
    char sender[MAX_NAME_LENGTH], receiver[MAX_NAME_LENGTH], size[MAX_SIZE_LENGTH];
    int blocked;
    int inaday[300005], notayear[505];
    int max_mess_year = 0;
    int max_mess = 0;
    fgets(mess, MAX_MESS_LENGTH, fin);

    while(mess[0] != '$'){
        int i;
        for(i=0; i<2; i++){
            day[i] = mess[i];
        }
        day[2] = '\0';
        for(i=3; i<5; i++){
            month[i-3] = mess[i];
        }
        month[2] = '\0';
        for(i=6; i<10; i++){
            year[i-6] = mess[i];
        }
        year[4] = '\0';
        if(!CheckValidDay(atoi(day), atoi(month))) continue;
        // if day is not valid, skip all


        (*ans1) ++;
        for(i=11; mess[i] != ' '; i++){
            sender[i-11] = mess[i];
        }
        sender[i++-11] = '\0';

        int temp = i;
        for(; mess[i] != ' '; i++){
            size[i-temp] = mess[i];
        }
        size[i-temp] = '\0';
        double formatsize = atof(size);
        if(mess[i-1] == 'M') 
            formatsize *=1024;
        else if(mess[i-1] == 'G') formatsize *= 1024*1024;
        if((*ans2) < formatsize) 
            (*ans2) = formatsize;

        temp = ++i;
        for(; mess[i] != ' '; i++){
            receiver[i-temp] = mess[i];
        }
        receiver[i++-temp] = '\0';

        blocked = mess[i] - '0';

        int index = hash(atoi(day), atoi(month));
        char ysr[MAX_YSR_LENGTH];
        //printf("%s %s %s\n", sender, size, receiver);
        
        YSRconvert(year, sender, receiver, ysr);
        
        all[index].root = insertMessage(all[index].root, ysr, formatsize, blocked);      

        index = hashlongday(atoi(day), atoi(month), atoi(year));
        inaday[index]++;
        if(inaday[index] > max_mess_year){
            max_mess_year = inaday[index];
            int j=0;
            for(int i=0; i<2; i++){
                ans3[j++] = day[i];
            }
            ans3[j++] = '-';
            for(int i=0; i<2; i++){
                ans3[j++] = month[i];
            }
            ans3[j++] = '-';
            for(int i=0; i<4; i++){
                ans3[j++] = year[i];
            }
            ans3[j++] = '\0';
        }
        //printf("%s\n", ysr);
        fgets(mess, MAX_MESS_LENGTH, fin);
    }
}

int main(){
    FILE *fin = fopen(inputFile, "r");
    if(fin == NULL){
        printf("Error opening input file\n");
        return 0;
    }
    
    FILE *fout = fopen(outputFile, "w");
    if(fout == NULL){
        printf("Error opening output file\n");
        return 0;
    }

    Node all[MAX_HASH_DATE];
    for(int i=0; i<400; i++){
        all[i].root = NULL;
    }
    int validday = 0;
    double max_size = 0;
    char most_mess[10];
        (fin, all, &validday, &max_size, most_mess);
    int choice;
    do{
        display_menu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Have %d line have valid day.", validday);
                break;
            case 2:
                printf("Message with largest size: %6lfGB", max_size);
                break;
            case 3:
                printf("Day with most message: %s", most_mess);
                break;
            case 4:
                Task5(fin, fout, all);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while(choice != 5);
    return 0;
    
}

