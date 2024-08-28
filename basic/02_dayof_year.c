#include <stdio.h>

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayof_year(int y, int m, int d) {
    int days = d;
    for (int i=1; i<m; i++)
        days += mdays[isleap(y)][i-1];
    return days;
}

int main(void) {
    int retry;
    do {
        int year, month, day;
        printf("year: "); scanf("%d", &year);
        printf("month: "); scanf("%d", &month);
        printf("day: "); scanf("%d", &day);
        printf("It's day %d of year %d.\n", dayof_year(year, month, day), year);
        printf("Retry?(1-yes, 0-no): "); scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}

