// Sonny Li
// Intro to Programming in C

#include <stdio.h>

int main()
{
    
    int answer = 8;
    int guess;
    
    printf("I have guessed a number between 1-10. Please guess it: ");
    scanf("%d", &guess);
    
    while (guess != answer)
    {
        
        printf("Wrong guess, please try again: ");
        scanf("%d", &guess);
        
    }
    
    printf("You got it!\n");
    
    return 0;
    
}
