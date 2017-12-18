// Team Solid
// Brandon Lim, Christopher Narducci & Jacob Lindahl

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    srand(time(NULL));
    int num = rand() % 99 + 1;

    int guess;

    int i = 1;

    printf("I'm thinking of a number between 1-100. You have 7 guesses.\n\n");

    printf("First Guess: ");
    scanf("%d", &guess);

    i++;

    while(guess != num && i <= 7)
    {

        if (guess > num)
        {
            printf("Sorry, too high.\n\n");
        }
 	      else
        {
            printf("Sorry, too low.\n\n");
        }

        printf("Guess #%d: ", i);
        scanf("%d", &guess);

        i++;
    }

    if (guess == num)
    {
        printf("\nCongrats! What are the odds?!\n");
    }
    else
    {
        printf("\nSorry, you didn't guess it in 7 tries.\n");
        printf("The number was %d.\n", num);
    }

    return 0;

}
