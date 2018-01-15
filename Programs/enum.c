// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {
    
    enum status { TEMP = 1, APPRENTICE, PERMANENT };
    
    enum status mystatus = APPRENTICE;      // mystatus = 2
    
    mystatus++;                             // mystatus = 3
    
    printf("%d\n", mystatus);
    
    return 0;
    
}
