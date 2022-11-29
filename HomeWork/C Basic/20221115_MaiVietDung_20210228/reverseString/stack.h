#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>

#define MAX_LENGTH 100 
typedef char ElementType;
typedef struct stack_s{ 
   ElementType Elements[MAX_LENGTH]; 
   //Store the elements 
   //int Front, Rear; 
   int Top;
} Stack;

void initialize(Stack *pS);
int Empty_Stack(Stack S);
int Full_Stack(Stack S);
void Push(ElementType X, Stack *pS);
ElementType Pop(Stack *pS);

#endif