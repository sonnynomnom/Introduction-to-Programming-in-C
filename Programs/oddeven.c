// Team $20 Gift Card
// Jack Lu, Brandon Lim, Nicole Fraidenraich & Cruz Fernandez

#include <stdio.h>

int main() {
    
    int a[6];
    
    int i, etotal, oproduct = 1;
    
    printf("Input Array: ");
    scanf("%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
    
    for (i = 0; i < 6; i++)
    {
        
        if (a[i] % 2 == 0)
        {
            etotal = etotal + a[i];
        }
        else
        {
            oproduct = oproduct * a[i];
        }
        
    }
    
    printf("\nSum of the even numebrs is %d.\n", etotal);
    printf("Product of the odd numbers is %d.\n", oproduct);
    
    return 0;
    
}
