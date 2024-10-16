#include <stdio.h>

void move(int no, int x, int y) {
    if (no > 1) {
        move(no - 1, x, 6 - x - y);
    }
    printf("move [%d] disk a from the %d column to the %d column.\n", no, x, y);
    if (no > 1) {
        move(no - 1, 6 - x - y, y);
    }
}

int main(void) {
    int n;
    printf("tower of hanoi\nnumber of discs: ");
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}

