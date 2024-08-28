#include <stdio.h>
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
    printf("number of people: ");
    scanf("%d", &number);

    int* height = calloc(number, sizeof(int));
    printf("Enter the key of %d people.\n", number);
    for (int i=0; i<number; i++) {
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }

    printf("The maximum value is %d.\n", maxof(height, number));
    free(height);

    return 0;
}

