// OG Trio
// Louie Kotler, Simone Stern & Chris Narducci

#include <stdio.h>

int main() {
    
    int a[3];
    int b[3];
    int c[6];
    
    int acounter = 0;
    int bcounter = 0;
    
    int i;
    
    printf("Enter A: ");
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    
    printf("Enter B: ");
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    
    for (i = 0; i < 6; i++)
    {
        
        if ((a[acounter] < b[bcounter] && acounter != 3) || bcounter == 3)
        {
            c[i] = a[acounter];
            acounter++;
        }
        else
        {
            c[i] = b[bcounter];
            bcounter++;
        }
        
    }
    
    printf("Array C: ");
    printf("%d %d %d %d %d %d\n", c[0], c[1], c[2], c[3], c[4], c[5]);
    
    return 0;
    
}