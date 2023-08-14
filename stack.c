/*
 * Stack은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조 (LIFO - Last in First Out)로
 * 데이터를 저장하는 형식을 말한다.
 */

#include <stdio.h>
#define MAX_N 100

int top;
int stack[MAX_N];

void stackInit() {
	top = 0;
}

int stackIsEmpty() {
	return (top == 0);
}

int stackIsFull() {
	return (top == MAX_N);
}

int stackPush(int value) {
	if (stackIsFull()) {
		printf("stack overflow!");
		return 0;
	}

	stack[top] = value;
	top++;

	return 1;
}

int stackPop(int *value) {
	if (stackIsEmpty()) {
		printf("stack is empty!");
		return 0;
	}

	top--;
	*value = stack[top];

	return 1;
}

int main(int argc, char* argv[]) {
	int T, N;
	scanf("%d", &T);
	for (int testCase=1; testCase<=T; testCase++) {
		scanf("%d", &N);
		stackInit();
		for (int i=0; i<N; i++) {
			int value;
			scanf("%d", &value);
			stackPush(value);
		}

		printf("#%d ", testCase);
		while(stackIsEmpty() == 0) {
			int value;
			if (stackPop(&value) == 1) {
				printf("%d ", value);
			}
		}

		printf("\n");
	}

	return 0;
}

