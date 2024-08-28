#include <stdio.h>

#define swap(type, x, y) do{type t=x; x=y; y=t;} while(0)

int card_conv(unsigned x, int n, char d[]) {
    char dc[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    if (x == 0) {
        d[digits++] = dc[0];
    } else {
        while (x) {
            d[digits++] = dc[x % n];
            x /= n;
        }
    }

    for (int i=0; i<digits/2; i++) {
        swap(char, d[i], d[digits-i-1]);
    }

    return digits;
}

int main(void) {
    puts("Convet a decimal number to radix.");

    int retry;
    do {
        unsigned no;
        int cd;
        char cno[512];

        printf("enter a non-negative integer: ");
        scanf("%u", &no);
        do {
            printf("convert to?(2-36): ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36);

        int dno = card_conv(no, cd, cno);

        printf("%d number is ", cd);
        for (int i=0; i< dno; i++) {
            printf("%c", cno[i]);
        }
        printf(".\n");
        
        printf("one more time? (1-yes/0-no): ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}

