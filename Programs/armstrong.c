// Team $20 Gift Card
// Jack Lu, Brandon Lim & Nicole Fraidenraich

#include <stdio.h>
#include <math.h>

int main() {
    
    int num;
    
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);
    
    int h = (num - (num % 100)) / 100;
    int t = ((num % 100) - (num % 10)) / 10;
    int o = num % 10;
    
    int calc = h*h*h + t*t*t + o*o*o;
    
    if (calc == num)
    {
        printf("%d is an Armstrong number since %d^3 + %d^3 + %d^3 = %d.\n", num, h, t, o, calc);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", num);
    }
    
    return 0;
    
}
