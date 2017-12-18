#include <stdio.h>

int main() {
    
    int num, total = 0;
    
    printf("Number: ");
    scanf("%d", &num);
    
    printf("\n");
    
    for (int x = 1; x <= num; x++)
    {
        
        printf("%d ", x);
        
        total = total + x;
        
    }
    
    printf("\n");
    printf("The sum is %d.\n", total);
    
    return 0;
    
}
