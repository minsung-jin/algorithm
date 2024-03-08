#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Point {
    int x, y;
    int sum;
};

int N, M;
int maze[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    struct Point queue[MAX_SIZE * MAX_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = (struct Point){0, 0, 0};
    visited[0][0] = true;

    while (front < rear) {
        struct Point current = queue[front++];
        int x = current.x;
        int y = current.y;
        int sum = current.sum;

        if (x == M - 1 && y == N - 1) {
            printf("%d\n", sum);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx]) {
                visited[ny][nx] = true;

                if (maze[ny][nx] == 0) {
                    queue[rear++] = (struct Point){nx, ny, sum};
                } else {
                    queue[rear++] = (struct Point){nx, ny, sum + 1};
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    bfs();

    return 0;
}

