#include <stdio.h>

int main(void) {
    int n;
    puts("Returns the total from 1 to n.");
    do {
        printf("n: ");
        scanf("%d", &n);
    } while(n <= 0);
    int sum = 0;
    for (int i=1; i<=n; i++)
        sum += i;
    printf("The sum from 1 to %d is %d.\n", n, sum);

    return 0;
}

