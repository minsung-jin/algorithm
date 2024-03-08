#include <stdio.h>

struct Node {
    int first;
    int second;
    int value;
};

struct Node *node;

int N, M;
int dist[1001];
int parent[1001];

int main() {
    // input
    scanf("%d %d", &N, &M);
    node = (struct Node*)malloc(sizeof(struct Node) * M);
    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &node[i].first, &node[i].secode, &node[value]);
    }

    dijkstra(1);
}
