// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {

    float ph;

    printf("Enter pH level (0-14): ");
    scanf("%f", &ph);

    if (ph > 7)
    {
        printf("Basic\n");
    }
    else if (ph < 7)
    {
        printf("Acidic\n");
    }
    else
    {
        printf("~Neutral~\n");
    }

    return 0;

}
