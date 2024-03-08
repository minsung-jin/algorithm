#include <stdio.h>
#include <string.h>

struct Part {
    char type[20];
    char name[20];
    int price;
    long quality;
};

int main() {
    int T;
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
        int n;
        long b;
        scanf("%d %ld", &n, &b);

        struct Part parts[n];
        memset(parts, 0, sizeof(parts));
        for (int i=0; i<n; i++) {
            scanf("%s %s %d %ld", parts[i].type, parts[i].name, &parts[i].price, &parts[i].quality);
        }

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (parts[i].price > parts[j].price) {
                    struct Part temp = parts[i];
                    parts[i] = parts[j];
                    parts[j] = temp;
                }
            }
        }

        struct Part computer[n];
        memset(computer, 0, sizeof(computer));
        long total = 0;
        int counter = 0;
        for (int i=0; i<n; i++) {
            int isContains = 0;
            for (int j=0; j<=counter; j++) {
                if (strcmp(parts[i].type, computer[j].type) == 0) {
                    isContains = 1;
                    break;
                } else {
                    isContains = 0;
                }
            }

            if (isContains == 0 && total <= b) {
                total += parts[i].price;
                computer[counter] = parts[i];
                counter++;
            }
        }

        while (total < b) {
            long minQuality = 1000000000;
            int index = 0;
            for (int i=0; i<counter; i++) {
                if (computer[i].quality < minQuality) {
                    minQuality = computer[i].quality;
                    index = i;
                }
            }

            for (int i=0; i<n; i++) {
                if (strcmp(parts[i].type, computer[index].type) == 0) {
                    if (parts[i].quality > computer[index].quality) {
                        total = total - computer[index].price + parts[i].price;
                        if (total <= b) {
                            computer[index] = parts[i];
                        }
                    }
                }
            }
        }

        long answer = 1000000000;
        for (int i=0; i<counter; i++) {
            if (answer > computer[i].quality) {
                answer = computer[i].quality;
            }
            printf("computer: %s, quality: %ld\n", computer[i].type, computer[i].quality);
        }

        printf("#%d: %ld\n", t, answer);
    }

    return 0;
}

