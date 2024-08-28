#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int height;
    int weight;
} Person;

int npcmp(const Person *x, const Person *y) {
    return strcmp(x->name, y->name);
}

int main(void) {
    Person x[] = {
        { "kim", 179, 79 },
        { "park", 172, 63 },
        { "lee", 176, 52 },
        { "chei", 165, 51 },
        { "ham", 181, 73 },
        { "hong", 172, 84 },
    };
    int nx = sizeof(x) / sizeof(x[0]);
    int retry;
    puts("search by name.");
    do {
        Person temp;
        printf("name: ");
        scanf("%s", temp.name);
        Person *p = bsearch(&temp, x, nx, sizeof(Person), (int(*)(const void *, const void *)) npcmp);
        if (p == NULL) {
            puts("search failed.");
        } else {
            puts("search success.");
            printf("x[%d]: %s %dcm %dkg\n", (int)(p-x), p->name, p->height, p->weight);
        }
        printf("search again? (1)yes/(0)no: ");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}

