// Team C
// Andrea Corro, Zachary Hine & Jason Chay

// Instructor: Sonny Li

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char gameboard[6][7] = {
    
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}

};

int countTurn = 0;

char turn = 'X';

void makeMove(char x[6][7]) {
    
    int col = 0;                            // column entered
    
    int i = 5;
    
    int valid = 1;                          // 1: valid move 2: invalid move
    
    printf("\n");
    printf("Enter a column number: ");
    scanf("%d", &col);
    
    col -= 1;
    
    // checks if the space is empty
    
    while (gameboard[i][col] != ' ' && col < 7 && col >= 0) {
        
        // if not, look at the row above
        
        i--;
        
        if (i < 0) {
            
            valid = 0;
            
            break;
        
        }
        
    }
    
    if (valid == 1 && col < 7 && col >= 0) {
        
        gameboard[i][col] = turn;           // makes the move
        countTurn++;
        
    } else {
        
        printf("\n");
        printf("Invalid move!\n");
        printf("Try again.\n");
        
        makeMove(gameboard);
        
    }
    
    if (turn == 'X') {
        
        turn = '0';
    
    } else if (turn == '0') {
        
        turn = 'X';
    
    }
    
}

// ============================================================================================================

int checkWinner(char x[6][7]) {
    
    int winner = 0;
    
    for (int i = 0; i < 6; i++) {
        
        for (int j = 0; j < 7; j++) {
            
            // checks left/right
            
            if (((x[i][j] == x[i][j+1]) && (x[i][j+1] == x[i][j+2]) && (x[i][j+2] == x[i][j+3]))
                && (x[i][j] == 'X' || x[i][j] == '0')) {
                
                winner = 1;
                // printf("left/right\n");
                goto end;
            
            }
            
            // checks up/down
            
            if (((x[i][j] == x[i-1][j]) && (x[i-1][j] == x[i-2][j]) && (x[i-2][j] == x[i-3][j]))
                     && (x[i][j] == 'X' || x[i][j] == '0')) {
                
                // fixed the bug where x[i][j] == x[i+1][j] && ... wouldn't work (Sonny)
                
                winner = 1;
                // printf("up/down\n");
                goto end;
                
            }
            
            // checks diagonal -slope
            
            if (((x[i][j] == x[i-1][j-1]) && (x[i-1][j-1] == x[i-2][j-2]) && (x[i-2][j-2] == x[i-3][j-3]))
                     && (x[i][j] == 'X'|| x[i][j] == '0')) {
                
                winner = 1;
                // printf("diagonal -slope\n");
                goto end;
            
            }
            
            // checks diagonal +slope
            
            if (x[i][j] == x[i+1][j-1] && x[i+1][j-1] == x[i+2][j-2] && x[i+2][j-2] == x[i+3][j-3]
                     && (x[i][j] == 'X' || x[i][j] == '0') && (j-1) >= 0 && (j-2) >= 0 && (j-3) >= 0 
                     && (i+1) < 6 && (i+2) < 6 && (i+3) < 6) {
                
                winner = 1;
                // printf("diagonal +slope\n");
                goto end;
                
            }
            
        }
        
    }
    
    if (countTurn == 42) {
        
        // 42 max turns
        
        winner = 2;
    
    }
    
end:
    
    return winner;
    
}

// ============================================================================================================

int main() {

    // print the gameboard
    
    while (!checkWinner(gameboard)) {
        
        system("clear");
        
        printf("\n");
        
        for (int i = 0; i < 6; i++) {
            
            for (int j = 0; j < 7; j++) {
                
                printf("| %c ", gameboard[i][j]);
            
            }
            
            printf("|\n-----------------------------\n");
        
        }
        
        printf("  1   2   3   4   5   6   7\n");
        
        makeMove(gameboard);
        
        printf("%d\n", checkWinner(gameboard));
        
    }
    
    if (checkWinner(gameboard)) {
        
        system("clear");
    
        // prints the gameboard one last time if a winner is present
        
        if (checkWinner(gameboard) == 1) {
            
            printf("~~~~~~~~~~ WINNER! ~~~~~~~~~~\n\n");
        
        }
        
        for (int i = 0; i < 6; i++) {

            for (int j = 0; j < 7; j++) {

                printf("| %c ", gameboard[i][j]);

            }

            printf("|\n-----------------------------\n");

        }

        printf("  1   2   3   4   5   6   7\n");

    }
    
    if (turn == 'X') {
        
        // re-change turns
        
        turn = '0';
    
    } else if (turn == '0') {
        
        turn = 'X';
    
    }
    
    printf("\n");
    
    if (checkWinner(gameboard) == 1) {
        
        printf("Connect four! The winner is %c!\n\n", turn);
    
    } else if (checkWinner(gameboard) == 2) {
        
        printf("It's a draw!\n\n");
    
    }
    
    //  else {
    //
    //      printf("%d\n", checkWinner(gameboard));
    //
    //  }
    
    return 0;
    
}
