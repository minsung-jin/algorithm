#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b) {
    if (*a < *b) return -1;
    else if (*a > *b) return 1;
    else return 0;
} // ascending

int int_cmpa(const int *a, const int *b) {
    return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int int_compp(const void *a, const void *b) {
    if (*(int *)a < *(int *)b) return -1;
    else if (*(int *)a > *(int *)b) return 1;
    else return 0;
}

int int_cmpr(const int *a, const int *b) {
    if (*a < *b) return 1;
    else if (*a > *b) return -1;
    else return 0;
} // descending

int main(void) {
    int nx, ky;
    puts("Using the binary search function");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    printf("Enter in ascending order.\n");
    printf("x[0]: ");
    scanf("%d", &x[0]);

    for (int i=1; i<nx; i++) {
        do {  // if it less than the previous value, re-enter it
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i-1]);
    }

    printf("search value: ");
    scanf("%d", &ky);
    int *p = bsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *)) int_cmp);

    if (p == NULL)
        puts("search failed.");
    else
        printf("%d is in x[%d].\n", ky, (int)(p-x));

    free(x);
    return 0;
}

