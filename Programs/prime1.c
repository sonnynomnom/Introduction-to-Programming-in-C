// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {
    
    int num;
    
    int nonprime = 0;
    
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    for (int i = 2; i <= num/2; i++)
    {
        
        // condition for nonprime number
        
        if (num % i == 0)
        {
            nonprime = 1;
            break;
        }
        
    }
    
    if (nonprime == 0)
    {
        printf("%d is a prime number.\n", num);
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }
    
    return 0;
    
}
