// Author: Mai Viet Dung - 20210228
// Finish: 24/11/2022
// This program is used to add 2 really large number
//---------------------<3-------------------------

#include<stdio.h>
#include"stack.h"

int main(){
    Stack number1;
    initialize(&number1);
    Stack number2;
    initialize(&number2);
    Stack res;
    initialize(&res);
    char c;
    scanf("%c", &c);
    while(c != '\n' && c != ' '){
        Push((int) c-'0', &number1);
        scanf("%c", &c);
    }
    scanf("%c", &c);
    while(c!= '\n' && c != ' '){
        Push((int) c-'0', &number2);
        scanf("%c", &c);
    }
    int rem = 0;
    int sum = 0;
    while(!Empty_Stack(number1) && !Empty_Stack(number2)){
        sum = rem + Pop(&number1) + Pop(&number2);
        Push(sum%10, &res);
        rem = sum / 10;
    }
    while(!Empty_Stack(number1)){
        sum = rem + Pop(&number1);
        Push(sum%10, &res);
        rem = sum / 10;
    }
    while(!Empty_Stack(number2)){
        sum = rem + Pop(&number2);
        Push(sum%10, &res);
        rem = sum / 10;
    }
    
    //Use this, so the next time if i need to calculate the product, it just better
    while(rem > 0){
        Push(rem, &res);
        rem /=10;
    }
    //Print them all
    while(!Empty_Stack(res)){
        printf("%d", Pop(&res));
    }
    return 0;
}