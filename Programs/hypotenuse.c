// Louie Kotler
// Fun Fact: I play the didgeridoo. It's an Australian aboriginal instrument.

#include <stdio.h>
#include <math.h>

void findh() {
    
    int a, b;
    float c;
    
    printf("Enter side a: ");
    scanf("%d", &a);
    
    printf("Enter side b: ");
    scanf("%d", &b);
    
    c = sqrt(a*a + b*b);
    
    printf("The hypotenuse is %f\n\n", c);
    
}

int main() {
    
    findh();
    findh();
    findh();
    
    return 0;
    
}
