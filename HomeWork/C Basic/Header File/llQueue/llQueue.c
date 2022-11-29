#include "llQueue.h"

#include <stdio.h>
#include <stdlib.h>
void initialize(Queue *pQ) { MakeNullQueue(pQ); }
void MakeNullQueue(Queue *pQ) {
  Position Header;
  Header = (Node_t *)malloc(sizeof(Node_t));  // Allocation	Header
  Header->Next = NULL;
  pQ->Front = Header;
  pQ->Rear = Header;
}
int EmptyQueue(Queue Q) { return (Q.Front == Q.Rear); }

void EnQueue(ElementType X, Queue *pQ) {
  pQ->Rear->Next = (Node_t *)malloc(sizeof(Node_t));
  pQ->Rear = pQ->Rear->Next;
  pQ->Rear->Element = X;
  pQ->Rear->Next = NULL;
}
ElementType DeQueue(Queue *pQ) {
  if (!EmptyQueue(*pQ)) {
    ElementType retVal;    
    Position T;
    T = pQ->Front;
    pQ->Front = pQ->Front->Next;
    free(T);
    return pQ->Front->Element;;
  } else {
    printf("Error: Queue is empty.");
    exit(-1);
  }
}
