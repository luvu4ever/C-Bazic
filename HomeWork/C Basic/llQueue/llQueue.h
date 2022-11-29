#ifndef __LLQUEUE_H__
#define __LLQUEUE_H__

typedef int ElementType; 
typedef struct Node{ 
	ElementType Element;
	struct Node* Next; //pointer to next element
 } Node_t;
 typedef Node_t* Position; 
 typedef struct{ 
	Position Front, Rear;
	} Queue;
        void MakeNullQueue(Queue* pQ);
        void initialize(Queue* pQ);
        int EmptyQueue(Queue Q);
        void EnQueue(ElementType X, Queue* pQ);
        ElementType DeQueue(Queue* pQ);

#endif