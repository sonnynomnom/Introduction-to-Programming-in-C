// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {

    float tempf;
    float tempc;

    // What is the current temperature in New York?
    
    tempf = 68;

    tempc = (tempf-32) * 5/9;

    printf("The current temp is %f degrees Celsius.\n", tempc);

    return 0;

}
