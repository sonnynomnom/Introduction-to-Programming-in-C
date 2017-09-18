/* Luoyou Zhao */
/* Fun Fact: My primary, middle, and high school share the same name. */

#include <stdio.h>

int main() {

    float p;
    float q;
    float c;

    float dollars;

    printf("Enter number of Mexican Pesos: ");
    scanf("%f", &p);

    printf("Enter number of Guatemalan Quetzals: ");
    scanf("%f", &q);

    printf("Enter number of Salvadoran Colóns: ");
    scanf("%f", &c);

    dollars = 0.544 * p + 0.1305 * q + 0.1144 * c;

    printf("Total USD = $%.2f\n", dollars);

    return 0;

}
