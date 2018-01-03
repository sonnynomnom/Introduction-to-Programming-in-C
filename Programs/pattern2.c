// Christopher Narducci
// Fun Fact: My favorite food is pizza.

#include <stdio.h>

int main() {
    
    int num;
    int i, j, k;
    
    printf("Please enter a number (1-9): ");
    scanf("%d", &num);
    
    for (i = 0; i <= num; i++)
    {
        
        for (k = 0; k < 2 *(num - i); k++)
        {
            printf(" ");
        }
        
        for (j = 0; j < i; j++)
        {
            printf("%d ", i - j);
        }
        
        printf("\n");
        
    }
    
    return 0;
    
}
