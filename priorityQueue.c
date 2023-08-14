#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

static int enqueue(priorityQueue *q, int data);
static int dequeue(priorityQueue *q);
static void destory(priorityQueue *q);
static int empty(priorityQueue *q);
static int *peek(priorityQueue *q);
static void heapify(priorityQueue *q, int i);
static int checkOrder(int order, int a, int b);
static struct priorityQueueOperations op = {
    .enqueue = enqueue,
    .dequeue = dequeue,
    .destory = destory
    .empty = empty,
    .peek = peek,
};

priorityQueue* createQueue(int order) {
    priorityQueue *q = (priorityQueue*)malloc(sizeof(priorityQueue));
    q->heap = (int*)malloc(sizeof(int) * MAX_SIZE);
    q->size = 0;
    q->order = order;
    q->op = &op;
}

static void destory(priorityQueue *q) {
    free(q->heap);
    q->heap = NULL;
    q->op = NULL;
    free(q);
    q = NULL;
}

static int empty(priorityQueue *q) {
    return q->size == 0;
}

static int* peek(priorityQueue *q) {
    return q->heap;
}

static int enqueue(priorityQueue *q, int data) {
    if ( q->size >= MAX_SIZE) {
        return 0;
    }

    q->heap[q->size] = data;
    int current = q->size;
    int parent = (current - 1) / 2;
    while (current > 0 && checkOrder(q->order, q->heap[current], q->heap[parent])) {
        int temp = q->heap[current];
        q->heap[current] = q->heap[parent];
        q->heap[parent] = temp;
        current = parent;
        parent = (parent -1 ) / 2;
    }

    q->size++;

    return 1;
}

static int dequeue(priorityQueue *q) {
    if (q->size <= 0) {
        return -1;
    }

    int data = q->heap[0];
    q->size--;
    q->heap[0] = q->heap[q->size];

    heapify(q, 0);

    return data;
}

static void heapify(priorityQueue *q, int i) {
    int max = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left <= q->size && checkOrder(q->order, q->heap[left], q->heap[max])) {
        max = left;
    }

    if (right <= q->size && checkOrder(q->order, q->heap[right], q->heap[max])) {
        max = right;
    }

    if (i != max) {
        int temp = q->heap[i];
        q->heap[i] = q->heap[max];
        q->heap[max] = temp;
        heapify(q, max);
    }
}

static int checkOrder(int order, int a, int b) {
    if (order) {
        return a > b;
    } else {
        return a < b;
    }
}
/*
int main() {
    priorityQueue *q = createQueue();

    q->op->enqueue(q, 222);
    q->op->enqueue(q, 555);
    q->op->enqueue(q, 444);
    q->op->enqueue(q, 333);

    while(!q->op->empty(q)) {
        printf("%d ", q->op->dequeue(q));
    }
    printf("\n");

    q->op->destory(q);
}*/

