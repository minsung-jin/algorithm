#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;
    do {
        int pc = (pl + pr) / 2;
        if (a[pc] == key)
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);

    return -1;
}

int main(void) {
    int nx, ky;

    puts("binary search");
    printf("number of elements: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    printf("enter in ascending order.\n");
    printf("x[0]: ");
    scanf("%d", &x[0]);
    for (int i=1; i<nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i-1]);
    }

    printf("search value: ");
    scanf("%d", &ky);
    int idx = bin_search(x, nx, ky);
    if (idx == -1)
        puts("search failed");
    else
        printf("%d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}

