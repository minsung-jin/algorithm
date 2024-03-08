#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 1001

int graph[MAX_NODES][MAX_NODES]; // 그래프 인접행렬
int dist[MAX_NODES];             // 시작 노드로부터의 최단거리
int prev[MAX_NODES];             // 최단경로에서 현재노드의 이전노드
int visited[MAX_NODES];          // 방문 여부

int minDistance(int n) {
    int minDist = INT_MAX;
    int minIndex = -1;
  
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }
  
    return minIndex;
}

void dijkstra(int n, int start) {
    // 모든 노드의 최단 거리를 무한대로 초기화
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
  
    // 시작 노드의 최단 거리는 0으로 설정
    dist[start] = 0;
  
    for (int i = 1; i <= n; i++) {
        // 방문하지 않은 노드 중 최단 거리를 가진 노드 선택
        int u = minDistance(n);
        visited[u] = 1;
      
        // 선택한 노드와 연결된 노드들의 최단 거리 갱신
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX &&
                dist[v] > dist[u] + graph[u][v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
  
    // 그래프 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
  
    // 간선 정보 입력받아 그래프에 반영
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a][b] = c;
        graph[b][a] = c;
    }
  
    dijkstra(n, 1);
  
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (prev[i] != -1) {
            count++;
        }
    }
    printf("%d\n", count);
  
    for (int i = 2; i <= n; i++) {
        if (prev[i] != -1) {
            printf("%d %d\n", prev[i], i);
        }
    }
  
    return 0;
}

