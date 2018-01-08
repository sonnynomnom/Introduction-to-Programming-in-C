// Team $20 Gift Card
// Brandon Lim, Jack Lu, Cruz Fernandez & Nicole Fraidenraich

#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];              // 3x3 2D array

int end = 0;                    // counter for game's over
int moves = 0;                  // counter for number of turns to determine a draw

char input;                     // user input (X or O)

void startGame();
void display();
void p1();
void p2();
char check();
void intro();

int main() {
    
    char enter = ' ';           // enter key to play
    char rematch = ' ';         // rematch input (y/n)
    char result = ' ';
    
    startGame();
    
    system("clear");            // typing "clear" in the console (so that it is not cluttered)
    
    printf("===========\n");
    printf("Tic-Tac-Toe\n");
    printf("===========\n\n");
    
    printf("Player 1) X\n");
    printf("Player 2) O\n\n");
    
    printf("Press [Enter] to begin!\n");
    scanf("%c", &enter);
    
    system("clear");
    
    // loop until the game ends (when someone wins or it's a tie)
    
    while (end == 0) {
        
        display();              // refreshes the display
        p1();                   // player 1
        moves++;
        
        if (moves == 9)
            break;
        
        result = check();
        
        if (result != ' ')
            break;
        
        display();              // refreshes the display
        p2();                   // player 2
        moves++;
        
        if (moves == 9)
            break;
        
        result = check();
        
        if (result != ' ')
            break;
        
    }
    
    // ===============================================================================
    
    char ans = check();

    display();
    
    if (ans == 'X') {
        
        printf("Player 1: X won!\n\n");
        
    }
    else if (ans == 'O') {
        
        printf("Player 2: O won!\n\n");
        
    }
    else {
        
        printf("It's a Tie Game!\n\n");
        
        printf("Want a rematch (y/n)? ");
        scanf("%c", &rematch);
        scanf("%c", &rematch);
        
        if (rematch == 'y' || rematch == 'Y') {
            
            main();
            
        }
        else {
            
            printf("\n");
        }
        
    }
    
    printf("Thanks for playing!\n\n");
    
    return 0;
    
}

// initializes the 2D array

void startGame() {
    
    int i, j;
    
    for (i = 0; i < 3; i++) {
        
        for (j = 0; j < 3; j++) {
            
            matrix[i][j] = ' ';
            
        }
        
    }
    
}

// prints out the display

void display() {
    
    int i;
    
    system("clear");
    
    printf("===========\n");
    printf("Tic-Tac-Toe\n");
    printf("===========\n\n");
    
    for (i = 0; i < 3; i++) {
        
        printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);
        
        if (i != 2) {
            
            printf("\n---|---|---\n");
            
        }
        
    }
    
    printf("\n\n");
    
}

// player one

void p1() {
    
    int x, y;
    
    printf("P1) Enter coordinates: ");
    scanf("%d %d", &x, &y);
    
    // decrement by 1 (if they input 3, it will be index 2)
    
    x--;
    y--;
    
    // check for nonempty
    
    if (matrix[x][y] != ' ') {
        
        printf("\nInvalid entry, try again.\n\n");
        p1();
        
    }
    else {
        
        matrix[x][y] = 'X';
        
    }
    
}

// player two

void p2() {
    
    int x, y;
    
    printf("P2) Enter coordinates: ");
    scanf("%d %d", &x, &y);
    
    x--;
    y--;
    
    if (matrix[x][y] != ' ') {
        
        printf("\nInvalid entry, try again.\n\n");
        p2();
        
    }
    else {
        
        matrix[x][y] = 'O';
        
    }
    
}

// check for a win (return the letter if there is a win)

char check() {
    
    int i;
    
    for (i = 0; i < 3; i++) {
    
        // check rows
        
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
            return matrix[i][0];
        
        // check columns
        
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
            return matrix[0][i];
    
    }

    // check diagonal 1
    
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
        
    // check diagonal 2
    
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];
    
    // if everything else doesn't work, then it returns nothing, meaning the game goes on
    
    return ' ';
    
}

/*
 
  printf("Coordinates:\n\n");
 
  printf("      1 1|1 2|1 3\n");
  printf("      ---|---|---\n");
  printf("      2 1|2 2|2 3\n");
  printf("      ---|---|---\n");
  printf("      3 1|3 2|3 3\n\n");

*/
