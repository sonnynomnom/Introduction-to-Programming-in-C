// Blackout
// Ariel Gross, Jonathan Daniel & Steve You

#include <stdio.h>
#include <unistd.h>

/* STORY: You are in the middle of a blackout, and you have walked into the Empire State Building. You see 3 doors, on the left, middle and right. Which one do you go through? (Repeat 10 times). You then enter a room and a man says that he is going to kill you. He gives you four choices... */

void introduction();
void doors();
void endingScenarios();
void printBigLetters();

int main() {
    
    introduction();
    
    doors();
    
    endingScenarios();
    
}

void introduction() {
    
    char start;
    
    printf("===============================================================================\n");
    usleep(200000);
    printf("BBBBBBB   LLL        AAAAAA    CCCCCC   KK   KK   OOOOOO   UU    UU  TTTTTTTTTT\n");
    usleep(200000);
    printf("BB    BB  LLL       AA    AA  CC    CC  KK  KK   OO    OO  UU    UU      TT    \n");
    usleep(200000);
    printf("BB    BB  LLL       AA    AA  CC        KK KK    OO    OO  UU    UU      TT    \n");
    usleep(200000);
    printf("BBBBBBB   LLL       AAAAAAAA  CC        KKKK     OO    OO  UU    UU      TT    \n");
    usleep(200000);
    printf("BB    BB  LLL       AA    AA  CC        KK KK    OO    OO  UU    UU      TT    \n");
    usleep(200000);
    printf("BB    BB  LLL       AA    AA  CC    CC  KK  KK   OO    OO  UU    UU      TT    \n");
    usleep(200000);
    printf("BBBBBBB   LLLLLLLL  AA    AA   CCCCCC   KK   KK   OOOOOO    UUUUUU       TT    \n");
    usleep(200000);
    printf("===============================================================================\n");
    usleep(200000);
    
    printf("\n");
    printf("Type x to begin: ");
    scanf("%s", &start);
    
    printf("\nIt is the middle of the night.\n");
    usleep(900000);
    printf("You are walking home.\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    printf("Bzzzzzzzzzzzzzzz (buzzing sound)\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    printf("Sketched out, you quickly went inside the nearby building.\n");
    usleep(900000);
    printf("the * lights * are bright inside.\n");
    usleep(900000);
    printf("You feel safe now.\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
    printf("...\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
    printf("Suddenly, the lights go out!\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
    printf("You quickly get your phone out and use it for light.\n");
    usleep(900000);
    printf("The doors to go back outside are locked.\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
}

void doors() {
    
    int door;
    
    printf("          _________            _________            _________          \n");
    usleep(250000);
    printf("         | _______ |          | _______ |          | _______ |         \n");
    usleep(250000);
    printf("         || _ A _ ||          || _ B _ ||          || _ C _ ||         \n");
    usleep(250000);
    printf("         ||| | | |||          ||| | | |||          ||| | | |||         \n");
    usleep(250000);
    printf("         |||_| |_|||          |||_| |_|||          |||_| |_|||         \n");
    usleep(250000);
    printf("         || _   _o||          || _   _o||          || _   _o||         \n");
    usleep(250000);
    printf("         ||| | | |||          ||| | | |||          ||| | | |||         \n");
    usleep(250000);
    printf("         |||_| |_|||          |||_| |_|||          |||_| |_|||         \n");
    usleep(250000);
    printf("         ||_______||          ||_______||          ||_______||         \n");
    usleep(250000);
    printf("________/___________\\________/___________\\________/___________\\________\n");
    usleep(250000);
    printf("        |___________|        |___________|        |___________|        \n");
    usleep(250000);
    printf("       /_____________\\      /_____________\\      /_____________\\       \n");
    usleep(250000);
    printf("       |_____________|      |_____________|      |_____________|       \n\n");
    usleep(900000);
    
    printf("You see three doors in front of you, which door would you pick?\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
    printf("   Enter 1) for door A\n");
    usleep(500000);
    printf("   Enter 2) for door B\n");
    usleep(500000);
    printf("   Enter 3) for door C\n");
    usleep(500000);
    
    printf("\n> ");
    scanf("%d", &door);
    
    for (int time = 0; time < 2; time++) {
        
        printf("\nYou walked in another room that has three doors! Pick again!\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("   Enter 1) for door A\n");
        usleep(500000);
        printf("   Enter 2) for door B\n");
        usleep(500000);
        printf("   Enter 3) for door C\n");
        usleep(500000);
        
        printf("\n> ");
        scanf("%d", &door);
        
    }
        
    if (door == 1 || door == 2 || door == 3) {

        printf("\n");
        usleep(900000);
        printf("...\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
    }
    
    return;
    
}

void endingScenarios() {
    
    int choice = 0;
    
    printf("You walk into a dark room.\n");
    usleep(1000000);
    printf("\n");
    usleep(1000000);
    
    printf("Immediately, you feel a gun pointed at your forehead.\n");
    usleep(1000000);
    printf("The man holding the gun begin to speak.\n");
    usleep(1000000);
    printf("\n");
    usleep(900000);
    
    printf("   \"You can jump out the window.\"\n");
    usleep(900000);
    printf("   \"Or sit in an extremely powerful electric chair.\"\n");
    usleep(900000);
    printf("   \"Or be shot by this gun.\"\n");
    usleep(900000);
    printf("\n");
    usleep(900000);
    
    printf("However, the door is wide open, so maybe you could still make a run for it.\n");
    usleep(1000000);
    printf("\n");
    usleep(1000000);
    
    printBigLetters();
    
    printf("\n");
    usleep(900000);
    
    printf("   Enter 1) Jump out the window\n");
    usleep(900000);
    printf("   Enter 2) Sit in an extremely powerful electric chair\n");
    usleep(900000);
    printf("   Enter 3) Be shot by his gun\n");
    usleep(900000);
    printf("   Enter 4) Run away towards the door\n");
    usleep(900000);
    
    printf("\n> ");
    scanf("%d", &choice);
    
    while (choice < 1 || choice > 4) {
        
        printf("Invalid Input. Please try again.\n");
        scanf("%d", &choice);
    
    }
    
    if (choice == 1) {
        
        printf("\nYou make a run to the window and jump out.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("As you fall, you begin to think about your life...\n");
        usleep(900000);
        printf("your loved ones...\n");
        usleep(900000);
        printf("AND THE FACT THAT YOU LEFT THE FRONT DOOR UNLOCKED!\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("This is the last thought you have as you become one with the cement.\n");
        usleep(900000);
        
    }
    else if (choice == 2) {
        
        printf("\nHe straps you into the electric chair...\n");
        usleep(900000);
        printf("and he flips the switch.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("Nothing happens.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("He keeps flipping the switch.\n");
        usleep(900000);
        printf("Increasingly frustrated, he slams his gun on a table.\n");
        usleep(900000);
        printf("The bullet fires, bounces off the wall, and kills him.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("You walk away free.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        
        printf("Oh yeah, there is no electricity during a blackout.\n");
        usleep(900000);
        
    }
    else if (choice == 3) {
        
        printf("\nHe shoots you with his gun, and you die from the point-blank shot.\n");
        usleep(900000);
    
    }
    else if (choice == 4) {
        
        printf("\nYou kick the man in his crotch and run.\n");
        usleep(900000);
        printf("He is in so much pain that he can't chase after you and get a clean shot.\n");
        usleep(900000);
        printf("You run out to the street and think you're free...\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        printf("until you get hit by a taxi driver.\n");
        usleep(900000);
        printf("\n");
        usleep(900000);
        printf("You die from your injuries.\n");
        usleep(900000);
    
    }
    
    printf("\n");
    usleep(900000);
    printf("=================================== THE END ===================================\n\n");
    usleep(900000);
    
    return;
    
}

void printBigLetters() {
    
    printf("`8.`888b                 ,8' 8 8888        8          .8.    8888888 8888888888 \n");
    usleep(150000);
    printf(" `8.`888b               ,8'  8 8888        8         .888.         8 8888 \n");
    usleep(150000);
    printf("  `8.`888b             ,8'   8 8888        8        :88888.        8 8888 \n");
    usleep(150000);
    printf("   `8.`888b     .b    ,8'    8 8888        8       . `88888.       8 8888 \n");
    usleep(150000);
    printf("    `8.`888b    88b  ,8'     8 8888        8      .8. `88888.      8 8888\n");
    usleep(150000);
    printf("     `8.`888b .`888b,8'      8 8888        8     .8`8. `88888.     8 8888\n");
    usleep(150000);
    printf("      `8.`888b8.`8888'       8 8888888888888    .8' `8. `88888.    8 8888\n");
    usleep(150000);
    printf("       `8.`888`8.`88'        8 8888        8   .8'   `8. `88888.   8 8888\n");
    usleep(150000);
    printf("        `8.`8' `8,`'         8 8888        8  .888888888. `88888.  8 8888\n");
    usleep(150000);
    printf("         `8.`   `8'          8 8888        8 .8'       `8. `88888. 8 8888\n\n");
    usleep(500000);
    
    printf("`8.`888b                 ,8'  8 8888 8 8888         8 8888\n");
    usleep(150000);
    printf(" `8.`888b               ,8'   8 8888 8 8888         8 8888 \n");
    usleep(150000);
    printf("  `8.`888b             ,8'    8 8888 8 8888         8 8888\n");
    usleep(150000);
    printf("   `8.`888b     .b    ,8'     8 8888 8 8888         8 8888 \n");
    usleep(150000);
    printf("    `8.`888b    88b  ,8'      8 8888 8 8888         8 8888\n");
    usleep(150000);
    printf("     `8.`888b .`888b,8'       8 8888 8 8888         8 8888   \n");
    usleep(150000);
    printf("      `8.`888b8.`8888'        8 8888 8 8888         8 8888  \n");
    usleep(150000);
    printf("       `8.`888`8.`88'         8 8888 8 8888         8 8888     \n");
    usleep(150000);
    printf("        `8.`8' `8,`'          8 8888 8 8888         8 8888 \n");
    usleep(150000);
    printf("         `8.`   `8'           8 8888 8 888888888888 8 888888888888 \n\n");
    usleep(500000);
    
    printf("`8.`8888.      ,8' ,o888888o.     8 8888      88\n");
    usleep(150000);
    printf(" `8.`8888.    ,8. 8888     `88.   8 8888      88\n");
    usleep(150000);
    printf("  `8.`8888.  ,8,8 8888       `8b  8 8888      88\n");
    usleep(150000);
    printf("   `8.`8888.,8'88 8888        `8b 8 8888      88\n");
    usleep(150000);
    printf("    `8.`88888' 88 8888         88 8 8888      88\n");
    usleep(150000);
    printf("     `8. 8888  88 8888         88 8 8888      88\n");
    usleep(150000);
    printf("      `8 8888  88 8888        ,8P 8 8888      88\n");
    usleep(150000);
    printf("       8 8888  `8 8888       ,8P  ` 8888     ,8P\n");
    usleep(150000);
    printf("       8 8888   ` 8888     ,88'     8888   ,d8P\n");
    usleep(150000);
    printf("       8 8888      `8888888P'        `Y88888P'   \n\n");
    usleep(500000);
    
    printf("8 888888888o.          ,o888888o.\n");
    usleep(150000);
    printf("8 8888    `^888.    . 8888     `88.\n");
    usleep(150000);
    printf("8 8888        `88. ,8 8888       `8b  \n");
    usleep(150000);
    printf("8 8888         `88 88 8888        `8b\n");
    usleep(150000);
    printf("8 8888          88 88 8888         88\n");
    usleep(150000);
    printf("8 8888          88 88 8888         88 \n");
    usleep(150000);
    printf("8 8888         ,88 88 8888        ,8P \n");
    usleep(150000);
    printf("8 8888        ,88' `8 8888       ,8P  \n");
    usleep(150000);
    printf("8 8888    ,o88P'    ` 8888     ,88' \n");
    usleep(150000);
    printf("8 888888888P'          `8888888P'\n");
    usleep(500000);
    
}
