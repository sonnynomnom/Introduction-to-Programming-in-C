// Team NAX
// Xingheng Lin, Naglis Paunksnis, Alua Orazbek

// Fan Fact (Xingheng): I started to learn English when I was 10 years old.
// Fun Fact (Naglis): I was born in Lithuania.
// Fun Fact (Alua): I lived in Japan my first 1 year.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void logo() {
    
    printf("=============================================== \n");
    printf("#   #  #####  #   #  #####  #####  #####  #   # \n");
    printf("#   #  #   #  ##  #  #      # # #  #   #  ##  # \n");
    printf("#####  #####  # # #  #  ##  # # #  #####  # # # \n");
    printf("#   #  #   #  #  ##  #   #  # # #  #   #  #  ## \n");
    printf("#   #  #   #  #   #  #####  # # #  #   #  #   # \n");
    printf("=============================================== \n");
    
}

int main() {
    
    int wrong = 0;
    int right = 0;
    
    int i = 0;
    
    char ans;
    char fullans[10] = "**********";
    
    char word[10] = {'c', 'i', 'r', 'c', 'u', 'm', 'f', 'l', 'e', 'x'};
    
    logo();
    
    printf("\n");
    printf("Let's play!\n");
    
    while (wrong < 10 && strcmp(fullans, word) != 0) {
        
        printf("\nGuess a letter: ");
        scanf(" %c", &ans);
        
        printf("\n");
        printf("Word: ");
        
        for (i = 0; i < 10; i++) {
            
            if (ans == word[i]) {
                
                fullans[i] = ans;
                right++;
                
            }
            
            printf("%c ", fullans[i]);
        
        }
        
        if (right == 0) {
            
            wrong++;
        
        }
        
        switch (wrong) {
                
            case 0:
                break;
                
            case 1:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf("             \n");
                printf("             \n");
                printf("             \n");
                printf("             \n");
                printf("             \n");
                printf("             \n");
                printf("_____________\n\n");
                break;
                
            case 2:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf("             \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 3:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/         \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 4:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 5:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |   |      \n");
                printf("  |   |      \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 6:
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |  \\|     \n");
                printf("  |   |      \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 7 :
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |  \\|/    \n");
                printf("  |   |      \n");
                printf("  |          \n");
                printf("__|__________\n\n");
                break;
                
            case 8 :
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |  \\|/    \n");
                printf("  |   |      \n");
                printf("  |  /       \n");
                printf("__|__________\n\n");
                break;
                
            case 9 :
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   O      \n");
                printf("  |  \\|/    \n");
                printf("  |   |      \n");
                printf("  |  / \\    \n");
                printf("__|__________\n\n");
                break;
                
            case 10 :
                printf("\n\n# of wrong guesses: %d\n\n", wrong);
                printf(" ________    \n");
                printf("  |/  |      \n");
                printf("  |   X      \n");
                printf("  |  \\|/    \n");
                printf("  |   |      \n");
                printf("  |  / \\    \n");
                printf("__|__________\n\n");
                
                printf("\nYou lost!\n");
                break;
                
        }
        
        right = 0;
        
    }
    
    if (strcmp(fullans, word) == 0) {
        
        printf("\nYou won!\n");
    
    }
    
    return 0;

}
