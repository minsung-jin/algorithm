#include <stdio.h>

int main(void) {
    int n;

    printf("integer: ");
    scanf("%d", &n);
    if(n > 0) {
        printf("It's a positive number.\n");
    } else if(n < 0) {
        printf("It's a negative number.\n");
    } else {
        printf("It's zero.\n");
    }
    return 0;
}
