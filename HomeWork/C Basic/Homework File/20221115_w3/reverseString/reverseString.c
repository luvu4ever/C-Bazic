// Author: Mai Viet Dung - 20210228
// Finish: 22/11/2022
// Used to reverse string by stack
//---------------------<3-------------------------

#include<stdio.h>
#include"stack.h"

int main(){
    Stack s;
    initialize(&s);
    char c = '\0';
    while(c != '\n'){
        scanf("%c", &c);
        Push(c, &s);
    }
    while(!Empty_Stack(s)){
        ElementType cur = Pop(&s);
        if(cur != '\n') printf("%c", cur);
    }
    return 0;
}

