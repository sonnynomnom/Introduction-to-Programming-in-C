// Team LeapFrog
// Marcus Kapoor, Andrea Corro & Louie Kotler

// https://www.youtube.com/watch?v=cSLeBKT7-sM

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL));
    
    int player = 0;        // player choice
    int computer = 0;      // computer choice
    
    int score1 = 0;        // player score
    int score2 = 0;        // computer score
    
    printf("================================\n");
    printf("Rock Paper Scissors Lizard Spock\n");
    printf("================================\n\n");
    
    printf("       The Big Bang Theory      \n\n");
    
    printf("  - Rock crushes Lizard\n");
    printf("  - Lizard poisons Spock\n");
    printf("  - Spock smashes Scissors\n");
    printf("  - Scissors decapitate Lizard\n");
    printf("  - Lizard eats Paper\n");
    printf("  - Paper disproves Spock\n");
    printf("  - Spock vaporizes Rock\n\n");
    
    printf("         (Best of Five)         \n\n");
    
    printf("================================\n\n");
    
    while (score1 != 3 && score2 != 3) {
        
        computer = rand() % 5 + 1;
        
        printf("You: %d                RNGesus: %d\n\n", score1, score2);
        
        printf("    1) Rock\n");
        printf("    2) Paper\n");
        printf("    3) Scissors\n");
        printf("    4) Lizard\n");
        printf("    5) Spock\n\n");
        
        printf("Your move:");
        scanf("%d", &player);
        
        printf("\n");
        
        if (player == computer) {
            
            printf("You tied!\n\n");
            
        }
        else if (player == 1) {
            
            if (computer == 2) {
                
                printf("You chose Rock.\n");
                printf("Computer chose Paper.\n\n");
                printf("You lost this round!\n\n");
                score2++;
            }
            else if (computer == 3) {
                
                printf("You chose Rock.\n");
                printf("Computer chose Scissors.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 4) {
                
                printf("You chose Rock.\n");
                printf("Computer chose Lizard.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 5) {
                
                printf("You chose Rock.\n");
                printf("Computer chose Spock.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            
        }
        else if (player == 2) {
            
            if (computer == 1) {
                
                printf("You chose Paper.\n");
                printf("Computer chose Rock.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 3) {
                
                printf("You chose Paper.\n");
                printf("Computer chose Scissors.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 4) {
                
                printf("You chose Paper.\n");
                printf("Computer chose Lizard.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 5) {
                
                printf("You chose Paper.\n");
                printf("Computer chose Spock.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            
        }
        else if (player == 3) {
            
            if (computer == 1) {
                
                printf("You chose Scissors.\n");
                printf("Computer chose Rock.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 2) {
                
                printf("You chose Scissors.\n");
                printf("Computer chose Paper.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 4) {
                
                printf("You chose Scissors.\n");
                printf("Computer chose Lizard.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 5) {
                
                printf("You chose Scissors.\n");
                printf("Computer chose Spock.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
        }
        else if (player == 4) {
            
            if (computer == 1) {
                
                printf("You chose Lizard.\n");
                printf("Computer chose Rock.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 2) {
                
                printf("You chose Lizard.\n");
                printf("Computer chose Paper.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 3) {
                
                printf("You chose Lizard.\n");
                printf("Computer chose Scissors.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 5) {
                
                printf("You chose Lizard.\n");
                printf("Computer chose Spock.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            
        }
        else if (player == 5) {
            
            if (computer == 1) {
                
                printf("You chose Spock.\n");
                printf("Computer chose Rock.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 2) {
                
                printf("You chose Spock.\n");
                printf("Computer chose Paper.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            else if (computer == 3) {
                
                printf("You chose Spock.\n");
                printf("Computer chose Scissors.\n\n");
                printf("You won this round!\n\n");
                score1++;
                
            }
            else if (computer == 4) {
                
                printf("You chose Spock.\n");
                printf("Computer chose Lizard.\n\n");
                printf("You lost this round!\n\n");
                score2++;
                
            }
            
        }
        
        printf("================================\n\n");
        
    }
    
    printf("You: %d                RNGesus: %d\n\n", score1, score2);
    
    if (score1 == 3) {
        
        printf("        YOU WON THE GAME!       \n\n");
        printf("================================\n\n");
        
    }
    else {
        
        printf("       YOU LOST THE GAME!       \n\n");
        printf("================================\n\n");
        
    }
    
    return 0;
    
}
