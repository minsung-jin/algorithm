#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t=x; x=y; y=t;} while(0)

void ary_reverse(int a[], int n) {
    for (int i=0; i<n/2; i++) {
        swap(int, a[i], a[n-i-1]);
    }
}

int main(void) {
    int n;
    printf("number: ");
    scanf("%d", &n);

    int *x = calloc(n, sizeof(int));
    for (int i=0; i<n; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x, n);
    printf("sorted the elements of the arry in reverse order.\n");
    for (int i=0; i<n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(0);

    return 0;
}

