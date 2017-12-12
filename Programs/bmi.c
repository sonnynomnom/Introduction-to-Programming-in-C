// Jason Chay
// Fun Fact: I am a Roger Federer fan.

#include <stdio.h>

int main() {

    float height, weight;

    printf("Type in your height (m): ");
    scanf("%f", &height);

    printf("Type in your weight (kg): ");
    scanf("%f", &weight);

    printf("Your BMI is %0.1f\n", weight/(height*height));

    return 0;

}
