// OG Trio
// Louie Kotler, Simone Stern, Chris Narducci

#include <stdio.h>
#include <math.h>

int main() {
    
    int num, x, nonprime = 0;
    
    int total = 0, totalsq = 0, counter = 0;
    
    for (num = 2; num <= 50; num++)
    {
        
        for (x = 2; x < num; x++)
        {
            
            if (num % x == 0)
            {
                nonprime = 1;
            }
            
        }
        
        if (nonprime == 0)
        {
            
            printf("%d for %d\n", num*num, num);
            
            total = total + num;
            totalsq = totalsq + num * num;
            
            counter++;
            
        }
        
        nonprime = 0;
        
    }
    
    printf("\nAvg for total: %d\n", total/counter);
    printf("Avg for squared total: %d\n", totalsq/counter);
    
    return 0;
    
}
