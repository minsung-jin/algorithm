#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int na;
    printf("number of elements: ");
    scanf("%d", &na);

    int* a= calloc(na, sizeof(int));

    if (a == NULL) {
        puts("Failed to acquire memory.");
    } else {
        printf("Enter %d integers.\n", na);
        for (int i=0; i<na; i++) {
            printf("a[%d]: ", i);
            scanf("%d", &a[i]);
        }

        printf("The values of each elements are as follows.\n");
        for (int i=0; i<na; i++) {
            printf("a[%d] = %d\n", i, a[i]);
        }
        free(a);
    }

    return 0;
}

