#include <stdio.h>

int factorial(int n) {
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int main(void) {
    int x;
    printf("enter an integer: ");
    scanf("%d", &x);
    printf("the sequential multiplication of %d is %d.\n", x, factorial(x));

    return 0;
}

