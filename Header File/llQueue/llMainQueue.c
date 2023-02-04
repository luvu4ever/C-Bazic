// mainLLQueue
#include "llQueue.h"
#include <stdio.h>
int main() {
   Queue q;
   initialize(&q);
   for (int i = 1; i < 10; i++) 
      EnQueue(i, &q);
   for (; !EmptyQueue(q); ) {
      int t = DeQueue(&q);
      printf("%d ", t);
   }

   return 0;
}