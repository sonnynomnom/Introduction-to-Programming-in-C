// Team Yatsuo
// Jack Lu, Simone Stern, Zachery Hine & Spencer Rowley

// Instructor: Sonny Li

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NRM "\x1B[0m"
#define RED "\x1B[31m"
#define GRN "\x1B[32m"

int main() {
    
    srand(time(NULL));
    
    char ans[] = "";
    
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    printf("You're lost in a dark forest with nobody around to help you.\n");
    printf("Answer the following questions to help you escape!\n");
    
    printf("\nYou walk a while and come to a break in forest:\n\n");
    
    printf("                           ___I_      ^  ^  ^   ^   ^  ^          \n");
    printf("                          /\\-_--\\    /|\\/|\\/|\\ /|\\ /|\\/|\\ \n");
    printf("                         /  \\_-__\\   /|\\/|\\/|\\ /|\\ /|\\/|\\ \n");
    printf("  ~~~~~~~~~~~~~~~~~~~~~  |[]| [] |   /|\\/|\\/|\\ /|\\ /|\\/|\\   \n");
    printf("  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ---------------------------------         \n\n");
    
    printf(" - On the left, there's a narrow river with strong currents.\n");
    printf(" - In the middle, there's a log cabin with no lights inside.\n");
    printf(" - On the right, there're lots of big trees packed together.\n\n");
    
    printf("Do you want to go %sleft%s, %smiddle%s, or %sright%s?\n\n", GRN, NRM, GRN, NRM, GRN, NRM);
    
    printf("Enter your choice: ");
    scanf("%s", ans);
    
    // invalid answer
    
    while (strcmp(ans, "left") != 0 && (strcmp(ans, "middle") == !0) && strcmp(ans, "right") != 0) {
        
        printf("\nYour answer is invalid, please choose a valid answer: ");
        scanf("%s", ans);
        
    }
    
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    // left
    
    if (strcmp(ans, "left") == 0) {
        
        printf("You chose to turn left.\n\n");
        
        printf("You’re a strong swimmer and managed to swim across.\n\n");
        
        printf("However, a hungry bear appeared out of nowhere! ARHHHHHHHHH!\n");
        printf("You have a large axe handy which you can use to fight.\n\n");
        
        printf("Do you want to %sfight %sthe bear or %srun %saway?\n\n", GRN, NRM, GRN, NRM);
        
        printf("Enter your choice: ");
        scanf("%s", ans);
        
        while (strcmp(ans, "run") != 0 && strcmp(ans, "fight") != 0) {
            
            printf("\nYour answer is invalid, please choose a valid answer:");
            scanf("%s", ans);
            
        }
        
        printf("       _     \n");
        printf("   /\\ ) \\  \n");
        printf(" <=()=>  )   \n");
        printf("   || )_/    \n");
        printf("   ||        \n");
        printf("   ||        \n");
        
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        
        // fight the bear
        
        char response[] = "";
        
        if (strcmp(ans, "fight") == 0)
        {
            
            int fight = 1;
            
            int hp = 5;
            int bearhp = 5;
            
            int bearaction = 0;
            
            while (fight == 1) {
                
                bearaction = rand() % 2;
                
                printf("Your options: %sdodge%s or %sstab%s?", GRN, NRM, GRN, NRM);
                printf("\n> ");
                scanf("%s", response);
                
                if (strcmp(response, "stab") != 0 && strcmp(response, "dodge") != 0) {
                    
                    printf("\n%sInvalid option.%s\n", RED, NRM);
                    
                }
                
                if (bearaction == 1 && strcmp(response, "stab") == 0) {
                    
                    printf("\nThe bear attacked you while you let your Guard Down.\n");
                    hp--;
                    
                }
                else if (bearaction == 1 && strcmp(response, "dodge") == 0) {
                    
                    printf("\nYou dodged the bear attack! Nice!\n");
                    
                }
                else if (bearaction == 0 && strcmp(response, "stab") == 0) {
                    
                    printf("\nNice you got the bear!\n");
                    bearhp--;
                    
                }
                else if (bearaction == 0 && strcmp(response, "dodge") == 0) {
                    
                    printf("\nYou dodged an attack that never came. Bear just stares -.-\n");
                    
                }
                
                printf("\nYou have %d HP left: ", hp);
                
                for (int i = 0; i < hp; i++) {
                
                    printf("%s|%s", RED, NRM);
                    
                }
                
                printf("\nBear has %d HP left: ", bearhp);
                
                for (int i = 0; i < bearhp; i++) {
                    
                    printf("%s|%s", RED, NRM);
                    
                }
                
                printf("\n\n");
                
                if (hp < 1) {
                    
                    fight = 0;
                    printf("Oops! You died. GG.\n\n");
                    exit(0);
                    
                }
                
                if (bearhp < 1) {
                    
                    fight = 0;
                    printf("Whew! You killed the bear.\n");
                    
                }
                
            }
            
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            
            printf("It's getting late out, and the night is cold.\n");
            printf("Would you like to %scontinue%s moving or %sstop%s to sleep?", GRN, NRM, GRN, NRM);
            printf("\n\n");
            
            printf("Enter your choice: ");
            scanf("%s", ans);
            
            while (strcmp(ans, "continue") != 0 && strcmp(ans, "stop") != 0) {
                
                printf("\nYour answer is invalid, please choose a valid answer: ");
                scanf("%s", ans);
            
            }
            
            if (strcmp(ans, "continue") == 0) {
                
                printf("\nYou found a hiking group and they got you to safety! Grats!\n");
                printf("~The End~\n\n");
            
            }
            else {
                
                printf("\nYou froze to death in the night because humans freeze.\n");
                printf("~The End~\n\n");
            
            }
            
        }
        
        // run from the bear
        
        else {
            
            printf("You got eaten by the bear because you run slow.\n\n");
            
            printf("~The End~\n\n");

        }
        
    }
    
    // middle
    
    else if (strcmp(ans, "middle") == 0) {
        
        printf("You chose to go middle.\n\n");
    
        printf("The big bad wolf has been waiting...\n\n");
        
        printf("~The End~\n\n");
        
    }
    
    // right
    
    else {
        
        printf("You chose to turn right.\n\n");
        
        printf("You climbed one of the tall trees and spotted a bear below.\n");
        printf("You have an axe handy which you can use to fight the bear.\n\n");
        
        printf("Do you want to %sstay%s up on the tree or climb down and %sfight%s?", GRN, NRM, GRN, NRM);
        
        printf("\n\n");
        printf("Enter your choice: ");
        scanf("%s", ans);
        
        while (strcmp(ans, "stay") != 0 && strcmp(ans, "fight") != 0) {
            
            printf("\nYour answer is invalid, please choose a valid answer: ");
            scanf("%s", ans);
        
        }
        
        if (strcmp(ans, "fight") == 0) {
            
            printf("\nYou tried jumping from the tree to ambush the bear, BUT...\n");
            printf("you slipped and fell, dying from shock *_*\n\n");
            
            printf("On the bright side though, you made the bear happy!\n\n");
            
            printf("~The End~\n\n");
        
        }
        
        else if (strcmp(ans, "stay") == 0) {
            
            printf("\nYou decided to stay in the tree.\n\n");
            
            printf("A few hours later, a rescue helicoptor came and rescued you,\n");
            printf("like a rescue helicoptor should.\n\n");
            
            printf("~The End~\n\n");
    
        }
    
    }
    
    return 0;

}
