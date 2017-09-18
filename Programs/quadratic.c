/* Jonathan Daniel */
/* Fun Fact: I'm a huge Marvel Cinematic Universe fan. */

#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c;
    float r1, r2;

    printf("Enter a: ");
    scanf("%f", &a);

    printf("Enter b: ");
    scanf("%f", &b);

    printf("Enter c: ");
    scanf("%f", &c);

    r1 = (-b + sqrt((b*b) - 4*a*c)) / (2*a);
    r2 = (-b - sqrt((b*b) - 4*a*c)) / (2*a);

    printf("\n");
    printf("Root 1 is %.4f\n", r1);
    printf("Root 2 is %.4f\n", r2);

    return 0;

}
