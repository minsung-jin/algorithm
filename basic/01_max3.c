#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Find the maximum value of three integers.\n");
    printf("a: "); scanf("%d", &a);
    printf("b: "); scanf("%d", &b);
    printf("c: "); scanf("%d", &c);

    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;

    printf("The maximum value is %d.\n", max);

    return 0;
}
    
/*
 * sequntial
 * selection
 * operator, operand
 * expression, assignment expression
 * evaluation
 * flowchart
 * variable
 * parameter
 * argument
 */

