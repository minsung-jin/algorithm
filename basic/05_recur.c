#include <stdio.h>

void recur(int n) {
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

void recur2(int n) {
    if (n > 0) {
        recur2(n - 2);
        printf("%d\n", n);
        recur2(n - 1);
    }
}

int main(void) {
    int x;
    printf("enter an integer: ");
    scanf("%d", x);
    recur(x);

    return 0;
}

