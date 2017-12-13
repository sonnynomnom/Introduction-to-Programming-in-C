/* Team Yasuo */
/* Jack Lu, Zackery Hine, Simone Stern & Spencer Rowley */

#include <stdio.h>

int main() {

    int month, day, year;

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter day: ");
    scanf("%d", &day);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1000 || year > 2017)
    {
        printf("Invalid entry.\n");
    }
    else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        printf("%d/%d/%d falls on a leap year.\n", month, day, year);
    }
    else
    {
        printf("%d/%d/%d does not fall on a leap year.\n", month, day, year);
    }

    return 0;

}
