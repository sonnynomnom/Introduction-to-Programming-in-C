// Marcus Kapoor
// Fun Fact: I'm half Czech, half Indian. ヾ(⌐■_■)ノ♪

// By default %f will display values up to 6 digits after the decimal point. 
// Writing %0.1f or %0.2f will reduce the precision to 1 or 2 digits respectively.

#include <stdio.h>

int main() {

    float tempf;
    float tempc;

    printf("Enter temp in Fahrenheit: ");
    scanf("%f", &tempf);

    tempc = (tempf-32) * 5/9;

    printf("The current temp is %0.1f degrees Celsius.\n", tempc);

    return 0;

}
