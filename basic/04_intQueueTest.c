#include <stdio.h>
#include "04_intQueue.h"

int main(void) {
    IntQueue q;
    if (Initialize(&q, 64) == -1) {
        puts("queue creation failed.");
        return 1;
    }

    while(1) {
        int m, x;
        printf("current data count: %d / %d \n", Size(&q), Capacity(&q));
        printf("(1)enque (2)deque (3)peek (4)print (5)end: ");
        scanf("%d", &m);

        if (m == 0) break;
        switch (m) {
            case 1:
                printf("data: ");
                scanf("%d", &x);
                if (Enque(&q, x) == -1) {
                    puts("\aError: enque failed.");
                }
                break;
            case 2:
                if (Deque(&q, &x) == -1) {
                    puts("\aError: deque failed.");
                } else {
                    printf("deque data is %d.\n", x);
                }
                break;
            case 3:
                if (Peek(&q, &x) == -1) {
                    puts("\aError: peek failed.");
                } else {
                    printf("peek data is %d.\n", x);
                }
                break;
            case 4:
                Print(&q);
                break;
        }
    }
    Terminate(&q);
    return 0;
}

