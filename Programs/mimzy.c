// Zach Hine
// Fun Fact: My favorite food is barbeque chicken.

#include <stdio.h>

int main() {
    
    int n;
    int temp;
    
    int mimzy[6] = {1, 2, 3, 4, 5, 6};
    
    for (n = 0; n <= 5; n = n + 2)
    {
        
        temp = mimzy[n];
        
        mimzy[n] = mimzy[n+1];
        
        mimzy[n+1] = temp;
        
        printf("%d %d ", mimzy[n], mimzy[n+1]);
        
    }
    
    printf("\n");
    
    return 0;
    
}
