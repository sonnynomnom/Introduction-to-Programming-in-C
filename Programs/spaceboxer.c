/* Team Knicks */
/* David Fang, Charlie Chen & Rui Yan */

#include <stdio.h>

int main() {

    float weight;
    int planet;

    printf("Please enter your current earth weight: ");
    scanf("%f", &weight);

    printf("\nI have information for the following planets: \n");
    printf( "   1. Venus   2. Mars   3. Jupiter \n" );
    printf( "   4. Saturn  5. Uranus 6. Neptune \n\n" );

    printf("Which planet are you visiting? ");
    scanf("%d", &planet);

    if (planet == 1)
    {
        weight = weight * 0.78;
    }
    else if (planet == 2)
    {
        weight = weight * 0.39;
    }
    else if (planet == 3)
    {
        weight = weight * 2.65;
    }
    else if (planet == 4)
    {
        weight = weight * 1.17;
    }
    else if (planet == 5)
    {
        weight = weight * 1.05;
    }
    else if (planet == 6)
    {
        weight = weight * 1.23;
    }

    printf("\nYour weight would be %.2f on that planet.\n", weight);

    return 0;

}
