#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0)
       return x;
    else
       return gcd(y, x % y);
}

int main(void) {
    int x, y;
    puts("find the greatest common divisor of two integers.");
    printf("enter an integer: ");
    scanf("%d", &x);
    printf("enter an integer: ");
    scanf("%d", &y);
    printf("the greatest common divisor is %d\n", gcd(x, y));

    return 0;
}

