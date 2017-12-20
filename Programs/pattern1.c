// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {
    
    int num, a, b;
    
    printf("Please enter a number: ");
    scanf("%d", &num);
    
    printf("\n");
    
    for (a = 1; a <= num; a++)
    {
        
        for (b = 1; b <= a; b++)
        {
            
            printf("%d ", b);
            
        }
        
        printf("\n");
        
    }
    
    return 0;
    
}
