#include <stdio.h>

int main(void) {
    int no;
    printf("Enter a two-digit positive number.\n");
    do {
        printf("No.: ");
        scanf("%d", &no);
    } while(no<10 || no>99);
    printf("The variable No. value becomes %d.\n", no);

    return 0;
}

