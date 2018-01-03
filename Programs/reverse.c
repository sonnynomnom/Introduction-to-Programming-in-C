// Team C
// Zach Hine, Jason Chay & Andrea Corro

#include <stdio.h>

int main() {
    
    int num;
    
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);
    
    int one = num % 10;
    
    int ten = ((num - one) / 10) % 10;
    
    int hundred = (num - (ten * 10 + one)) / 100;
    
    // putting the three together
    
    int answer = (one * 100 + ten * 10 + hundred);
    
    printf("The reversed number is %d.\n", answer);
    
    return 0;
    
}
