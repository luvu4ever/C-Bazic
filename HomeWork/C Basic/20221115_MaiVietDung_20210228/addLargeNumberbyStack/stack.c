//LuvU4ever

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void initialize(Stack *pS){
    pS -> Top = 0;
}

int Empty_Stack(Stack S){
    return S.Top == 0;
};
int Full_Stack(Stack S){
    return S.Top == MAX_LENGTH;
};
void Push(ElementType X, Stack *pS){
    if(Full_Stack(*pS))
        printf("Stack overflow\n");
    else
        (*pS).Elements[(*pS).Top++] = X;
};
ElementType Pop(Stack *pS){
    if(Empty_Stack(*pS))
        printf("Stack underflow\n");
    else
        return (*pS).Elements[--(*pS).Top];
};