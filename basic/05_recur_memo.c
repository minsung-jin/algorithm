#include <stdio.h>

static char memo[128][1024];

void recur(int n) {
    if (memo[n+1][0] != '\0') {
        printf("%s", memo[n + 1]);
    } else {
        if (n > 0) {
            recur(n - 1);
            printf("%d\n", n);
            recur(n - 2);
            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);
        } else {
            strcpy(memo[n + 1], "");
        }
    }
}

int main(void) {
    int x;
    printf("enter an integer: ");
    scanf("%d", &x);
    recur(x);

    return 0;
}

