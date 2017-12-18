// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main() {
    
    int pin = 1234;
    int entry;
    
    printf("===============================\n");
    printf("WELCOME TO THE BANK OF COLUMBIA\n");
    printf("===============================\n\n");
    
    printf("Enter your PIN: ");
    scanf("%d", &entry);
    
    while (entry != pin) {
        
        printf("Incorrect PIN. Please try again: ");
        scanf("%d", &entry);
        
    }
    
    printf("\nPIN accepted! You now have access to your account.\n");
    
    return 0;
    
}
