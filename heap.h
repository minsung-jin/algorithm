typedef struct {
    int priority;
    int value;
} HeapNode;

typedef struct {
    HeapNode* nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue* createPriorityQueue(int capacity);
void enqueue(PriorityQueue* pq, int priority, int value);
HeapNode dequeue(PriorityQueue* pq);
void freePriorityQueue(PriorityQueue* pq);
    
