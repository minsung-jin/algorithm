#include <stdio.h>

int sum(int x1, int x2) {
    return x1 + x2;
}

int mul(int x1, int x2) {
    return x1 * x2;
}

void kuku(int (*cal)(int, int)) {
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            printf("%3d", (*cal)(i, j));
        }
        putchar('\n');
    }
}

int main(void) {
    puts("Addition Table");
    kuku(sum);
    puts("\n Multiplication Table");
    kuku(mul);

    return 0;
}

