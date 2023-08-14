#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 987654321

struct Edge {
    int to;
    int weight;
    struct Edge* next;
};

struct Vertex {
    int index;
    int weight;
};

struct Graph {
    int V;
    struct Edge** edges;
};

struct Vertex priorityQueue[10001];
int queueSize = 0;

void swap(struct Vertex* a, struct Vertex* b) {
    struct Vertex temp = *a;
    *a = *b;
    *b = temp;
}

void push(struct Vertex vertex) {
    priorityQueue[++queueSize] = vertex;
    int child = queueSize;
    int parent = child / 2;

    while (child > 1 && priorityQueue[parent].weight > priorityQueue[child].weight) {
        swap(&priorityQueue[parent], &priorityQueue[child]);
        child = parent;
        parent = child / 2;
    }
}

struct Vertex pop() {
    struct Vertex result = priorityQueue[1];
    priorityQueue[1] = priorityQueue[queueSize--];

    int parent = 1;
    int child = parent * 2;

    if (child + 1 <= queueSize) {
        child = (priorityQueue[child].weight < priorityQueue[child + 1].weight) ? child : child + 1;
    }

    while (child <= queueSize && priorityQueue[parent].weight > priorityQueue[child].weight) {
        swap(&priorityQueue[parent], &priorityQueue[child]);
        parent = child;
        child = parent * 2;

        if (child + 1 <= queueSize) {
            child = (priorityQueue[child].weight < priorityQueue[child + 1].weight) ? child : child + 1;
        }
    }

    return result;
}

void addEdge(struct Graph* graph, int from, int to, int weight) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->to = to;
    newEdge->weight = weight;
    newEdge->next = graph->edges[from];
    graph->edges[from] = newEdge;
}

void dijkstra(struct Graph* graph, int start, int k, int** kthDist) {
    for (int i = 1; i <= graph->V; i++) {
        for (int j = 1; j <= k; j++) {
            kthDist[i][j] = INF;
        }
    }

    kthDist[start][1] = 0;
    push((struct Vertex){start, 0});

    while (queueSize > 0) {
        struct Vertex cur = pop();
        int u = cur.index;

        struct Edge* edge = graph->edges[u];
        while (edge != NULL) {
            int v = edge->to;
            int weight = edge->weight;

            for (int j = 1; j <= k; j++) {
                if (kthDist[v][j] > kthDist[u][j - 1] + weight) {
                    kthDist[v][j] = kthDist[u][j - 1] + weight;
                    push((struct Vertex){v, kthDist[v][j]});
                }
            }

            edge = edge->next;
        }
    }
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    struct Graph graph;
    graph.V = n;
    graph.edges = (struct Edge**)malloc((n + 1) * sizeof(struct Edge*));
    for (int i = 1; i <= n; i++) {
        graph.edges[i] = NULL;
    }

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        addEdge(&graph, from, to, weight);
    }

    int** kthDist = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        kthDist[i] = (int*)malloc((k + 1) * sizeof(int));
    }

    dijkstra(&graph, 1, k, kthDist);

    for (int i = 1; i <= n; i++) {
        printf("%d\n", (kthDist[i][k] == INF) ? -1 : kthDist[i][k]);
    }

    for (int i = 1; i <= n; i++) {
        struct Edge* edge = graph.edges[i];
        while (edge != NULL) {
            struct Edge* nextEdge = edge->next;
            free(edge);
            edge = nextEdge;
        }
    }
    free(graph.edges);

    for (int i = 1; i <= n; i++) {
        free(kthDist[i]);
    }
    free(kthDist);

    return 0;
}

