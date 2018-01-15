// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int factorial(int n);

int main() {
    
    int n;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("The factorial of %d is %d.\n", n, factorial(n));
    
    return 0;
    
}

int factorial(int n) {
    
    if (n > 0) {
        
        return n * factorial(n-1);
    
    }
    else {
        
        return 1;
    
    }
    
}
