#include <stdio.h>
#include "priorityQueue.h"
#define DEBUG

int main() {
    priorityQueue *q = createQueue(0);

    q->op->enqueue(q, 222);
    q->op->enqueue(q, 555);
    q->op->enqueue(q, 444);
    q->op->enqueue(q, 333);
#ifdef DEBUG
    int * arr = q->op->peek(q);
    for (int i=0; i<q->size; i++) {
        printf("i:%d, %d ", i, arr[i]);
    }
    printf("\n");
#endif
    while(!q->op->empty(q)) {
        printf("%d ", q->op->dequeue(q));
    }
    printf("\n");
    
}

// gcc priorityQueueMain.c priorityQueueMain.c -o priorityQueue
// ./priorityQueue

