#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key) {
    int i=0;
    a[n] = key;
    while(1) {
        if (a[i] == key)
            break;
        i++;
    }

    return i == n ? -1 : i;
}

int main(void) {
    int nx, ky;
    puts("linear search(sentinal)");
    printf("number of elements: ");
    scanf("%d", &nx);
    int *x = calloc(nx+1, sizeof(int));
    for (int i=0; i<nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    printf("search value: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);
    if (idx == -1)
        puts("search failed.");
    else
        printf("%d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}

