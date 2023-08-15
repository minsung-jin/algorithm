/* 
 * Queue는 컴퓨터의 기본적인 자료 구조의 한가지로, 먼저 집어넣은 데이터가 먼저 나오는
 * FIFO(First in First out)구조로 저당하는 형식을 말한다.
 */

#include <stdio.h>
#define MAX_N 100

int front, rear;
int queue[MAX_N];

void queueInit() {
	front = 0;
	rear = 0;
}

int queueIsEmpty() {
	return (front == rear);
}

int queueIsFull() {
	if ((rear + 1) % MAX_N == front) {
		return 1;
	} else {
		return 0;
	}
}

int queueEnqueue(int value) {
	if (queueIsFull()) {
		printf("queue is full!");
		return 0;
	}

	queue[rear] = value;
	rear++;
	if (rear == MAX_N) {
		rear = 0;
	}

	return 1;
}

int queueDequeue(int *value) {
	if (queueIsEmpty()) {
		printf("queue is empty!");
		return 0;
	}

	*value = queue[front];
	front++;
	if (front == MAX_N) {
		front = 0;
	}

	return 1;
}

int main(int argc, char* argv[]) {
	int T, N;
	scanf("%d", &T);

	for (int TC=1; TC<=T; TC++) {
		scanf("%d", &N);
		queueInit();
		for (int i=0; i<N; i++) {
			int value;
			scanf("%d", &value);
			queueEnqueue(value);
		}

		printf("#%d ", TC);
		while(queueIsEmpty() == 0) {
			int value;
			if(queueDequeue(&value) == 1) {
				printf("%d", value);
			}
		}
		printf("\n");
	}

	return 0;
}

