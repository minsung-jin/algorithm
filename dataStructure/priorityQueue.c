/*
 * Prioriry Queue는 높은 우선순위를 가진 원소는 낮은 우선순위를 가진 원소보다 먼저 처리되는 자료구조이다.
 */

#include <stdio.h>
#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

void heapInit() {
	heapSize = 0;
}

int heapPush(int value) {
	if (heapSize + 1 > MAX_SIZE) {
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = value;
	int current = heapSize;
	while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
		int temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(int* value) {
	if (heapSize <= 0) {
		return -1;
	}

	*value = heap[0];
	heapSize = heapSize - 1;
	heap[0] = heap[HeapSize];
	int current = 0;
	while (current * 2 + 1 < heapSize) {
		int child;
		if (current * 2 + 2 == heapSize) {
			child = current * 2 + 1;
		} else {
			if (heap[current * 2 + 1] < heap[current * 2 + 2]) {
				child = current * 2 + 1;
			} else {
				child = current * 2 + 2;
			}
		}

		if (heap[current] < heap[child]) {
			break;
		}

		int temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;
		current = child;
	}

	return 1;
}

int main (int argc, char* argv[]) {
	int T, N;
	scanf("%d", &T);
	for (int TC=1; TC<=T; TC++) {
		scanf("%d", &N);
		heapInit();
		for (int i=0; i<N; i++) {
			int value;
			scanf("%d", &value);
			heapPush(value);
		}

		printf("#%d ", TC);
		for (int i=0; i<N; i++) {
			int value;
			heapPop(&value);
			printf("%d ", value);
		}

		printf("\n");
	}

	return 0;
}

