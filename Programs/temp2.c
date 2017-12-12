// Marcus Kapoor
// Fun Fact: I'm half Czech, half Indian. ヾ(⌐■_■)ノ♪

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
