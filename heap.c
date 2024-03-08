#include <stdlib.h>
#include "heap.h"

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->nodes = (HeapNode*)malloc(sizeof(HeapNode) * (capacity + 1));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left <= pq->size && pq->nodes[left].priority < pq->nodes[smallest].priority)
        smallest = left;
    if (right <= pq->size && pq->nodes[right].priority < pq->nodes[smallest].priority)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->nodes[idx], &pq->nodes[smallest]);
        heapify(pq, smallest);
    }
}

void enqueue(PriorityQueue* pq, int priority, int value) {
    if (pq->size == pq->capacity)
        return;

    int idx = ++pq->size;
    pq->nodes[idx].priority = priority;
    pq->nodes[idx].value = value;

    int parent;
    while (idx > 1) {
        parent = idx / 2;
        if (pq->nodes[parent].priority > pq->nodes[idx].priority) {
            swap(&pq->nodes[parent], &pq->nodes[idx]);
            idx = parent;
        } else {
            break;
        }
    }
}

HeapNode dequeue(PriorityQueue* pq) {
    HeapNode root = pq->nodes[1];
    pq->nodes[1] = pq->nodes[pq->size--];
    heapify(pq, 1);
    return root;
}

void freePriorityQueue(PriorityQueue* pq) {
    free(pq->nodes);
    free(pq);
}

