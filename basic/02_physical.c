#include <stdio.h>
#define VMAX 21

typedef struct {
    char name[20];
    int height;
    double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[], int n) {
    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += dat[i].height;
    }
    return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[]) {
    for (int i=0; i<VMAX; i++) {
        dist[i] = 0;
    }
    for (int i=0; i<n; i++) {
        if(dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0) {
            dist[(int)(dat[i].vision * 10)]++;
        }
    }
}

int main(void) {
    PhysCheck x[] = {
        {"person1", 162, 0.3},
        {"person2", 173, 0.7},
        {"person3", 175, 2.0},
        {"person4", 171, 1.5},
        {"person5", 168, 0.4},
        {"person6", 174, 1.2},
        {"person7", 169, 0.8}
    };

    int nx = sizeof(x) / sizeof(x[0]);
    int vdist[VMAX];
    puts("*** Physical Check Table ***");
    puts("   name     height    vision");
    puts("----------------------------");
    for (int i=0; i<nx; i++) {
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);
    }
    printf("\n average height: %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);
    printf("\n vision table\n");
    for (int i=0; i<VMAX; i++) {
        printf("%3.1f ~: %2d person\n", i/10.0, vdist[i]);
    }

    return 0;
}

