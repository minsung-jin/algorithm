#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int maxof(const int a[], int n) {
    int max = a[0];
    for (int i=1; i<n; i++) {
        if (a[i] > max) max = a[i];
    }

    return max;
}

int main(void) {
    int number;
    printf("number: ");
    scanf("%d", &number);

    int *height = calloc(number, sizeof(int));
    srand(time(NULL));
    for (int i=0; i<number; i++) {
        height[i] = 100 + rand() % 99;
        printf("height[%d] = %d\n", i, height[i]);
    }
    printf("The maximum value is %d.\n", maxof(height, number));
    free(height);

    return 0;
}

