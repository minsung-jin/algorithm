#define MAX_SIZE 100

typedef struct {
    int *heap;
    int size;
    int order;
    struct priorityQueueOperations *op;
} priorityQueue;

struct priorityQueueOperations {
    int (*enqueue)(priorityQueue *q, int data);
    int (*dequeue)(priorityQueue *q);
    int* (*peek)(priorityQueue *q);
    int (*empty)(priorityQueue *q);
    void (*destory)(priorityQueue *q);
};

extern priorityQueue* createQueue();
