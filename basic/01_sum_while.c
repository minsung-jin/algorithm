#include <stdio.h>

int main(void) {
    int n;
    puts("Returns the sum form 1 to n.");
    printf("n: ");
    scanf("%d", &n);
    int sum = 0, i = 1;
    while(i <= n) {
        sum += i;
        i++;
    }
    printf("The sum form 1 to %d is %d.\n", n, sum);

    return 0;
}

