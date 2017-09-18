// Sonny Li
// Intro to Programming in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int r = rand();

    if (r % 2 == 0)
    {
        printf("Heads\n");
    }
    else
    {
        printf("Tails\n");
    }

    return 0;

}
