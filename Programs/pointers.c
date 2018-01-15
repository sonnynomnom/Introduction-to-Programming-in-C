// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {
    
    int x = 4;
    
    printf("%d\n", x);
    printf("%p\n\n", &x);
    
    int *ptr;
    ptr = &x;
    
    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    printf("%p\n\n", &ptr);
    
    return 0;
    
}
