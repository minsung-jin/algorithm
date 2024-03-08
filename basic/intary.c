#include <stdio.h>

#define N 5

int main(void) {
    int a[N];
    for (int i=0; i<N; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    puts("The value of each element");
    for (int i=0; i<N; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

