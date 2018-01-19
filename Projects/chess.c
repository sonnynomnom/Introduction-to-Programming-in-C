#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

int start();
int ins();
void display(char* piece[8][8]);
void cmd(int turn, char* piece[8][8]);
//void check();

char * piece[8][8] = {
    {"x", "♞", "♝", "♛", "♚", "♝", "♞", "♜"},
    {"♟", "♟", "♟", "♟", "♟", "♟", "♟", "♟"},
    {" ", " ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " ", " "},
    {" ", " ", " ", " ", " ", " ", " ", " "},
    {"♙", "♙", "♙", "♙", "♙", "♙", "♙", "♙"},
    {"♖", "♘", "♗", "♔", "♕", "♗", "♘", "♖"}
};


//===============================================================================================================================================================

int main(){
    int choice = start(), win=0, turn=1;
    
    // int l = strlen("♜");
    // printf("%d\n", l);
    
    
    
    if (choice == 1)
    {
        system("clear");
        display(piece);
    }
    if (choice == 2)
    {
        system("clear");
        ins();
        display(piece);
    }
    
    cmd(turn, piece);
    system("clear");
    display(piece);
    
    
    
    return 0;
}
//===============================================================================================================================================================

void cmd(int turn, char *piece[8][8]){
    
    int x, y, x1, y1;
    char temp1[3];
    char temp2[3];
    
    if (turn % 2 != 0)
    {
        
        printf("Player 1's Turn\n");
        printf("Enter the x coordinate of your piece: ");
        scanf("%d", &x);
        printf("Enter the y coordinate of your piece: ");
        scanf("%d", &y);
        printf("Enter the x coordinate of your desired location: ");
        scanf("%d", &x1);
        printf("Enter the y coordinate of your desired location: ");
        scanf("%d", &y1);
        
        //==============================
        
        
        // strcpy(temp1, piece[y-1][x-1]);
        // printf("%s check1\n", temp1);
        //
        // strcpy(temp2, piece[y1-1][x1-1]);
        // printf("%s check2\n", temp2);
        //
        // strcpy(piece[y1-1][x1-1], "x");
        // printf("%s check3\n", piece[y1-1][x1-1]);
        //
        // printf("check4 %s\n", piece[y1-1][x1-1]); // not working
        //
        // strcpy((piece[y-1][x-1]), (piece[y1-1][x1-1]));
        //
        //
        //
        // printf("check3\n");
        // printf("%s\n", piece[y-1][x-1]);
        //
        // strcpy(piece[x1-1][y1-1], temp1);
        // printf("%s\n", piece[x1-1][y1-1]);
        
        
        
    }
    /*
     else
     {
     printf("Player 2's Turn\n");
     printf("Enter the coordinates of your piece in format <x coordinate><y coordinate>: ");
     scanf("%d", &cmd);
     
     }*/
    
}
//===============================================================================================================================================================
int start(){
    int choice;
    system("clear");
    
    printf("\n                 WELCOME TO CHESS                         \n\n");
    printf("                 To Start: Press 1 \n");
    printf("               Instructions: Press 2 \n\n");
    printf("> ");
    scanf("%d", &choice);
    
    return choice;
}


//===============================================================================================================================================================

//===============================================================================================================================================================


int ins(){
    int choice;
    
    printf("\nThis is a chess game between 2 players, since making AI is too hard.\n");
    printf("To Move a piece, enter its x coordinate, then its y coordinate.\n");
    printf("Then, enter the square of a valid spot to move there.\n");
    printf("Player 1: lower case\n");
    printf("Player 2: lower case\n");
    printf("W / w = KING\n");
    printf("Q / q = QUEEN\n");
    printf("R / r = Rook\n");
    printf("K / k = KNIGHT\n");
    printf("B / b = BISHOP\n");
    printf("P / p = PAWN\n\n");
    printf("Once you are done, enter 1 to begin playing.\n");
    scanf("%d", &choice);
    
    system("clear");
    return choice;
}
//===============================================================================================================================================================
void display(char* piece[8][8]){
    
    printf("\n\n");
    printf("    0     1     2     3     4     5     6     7\n");
    printf("  .................................................\n");
    printf("0 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 0\n", piece[0][0], piece[0][1], piece[0][2], piece[0][3], piece[0][4], piece[0][5], piece[0][6], piece[0][7]);
    printf("  .................................................\n");
    printf("1 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 1\n", piece[1][0], piece[1][1], piece[1][2], piece[1][3], piece[1][4], piece[1][5], piece[1][6], piece[1][7]);
    printf("  .................................................\n");
    printf("2 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 2\n", piece[2][0], piece[2][1], piece[2][2], piece[2][3], piece[2][4], piece[2][5], piece[2][6], piece[2][7]);
    printf("  .................................................\n");
    printf("3 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 3\n", piece[3][0], piece[3][1], piece[3][2], piece[3][3], piece[3][4], piece[3][5], piece[3][6], piece[3][7]);
    printf("  .................................................\n");
    printf("4 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 4\n", piece[4][0], piece[4][1], piece[4][2], piece[4][3], piece[4][4], piece[4][5], piece[4][6], piece[4][7]);
    printf("  .................................................\n");
    printf("5 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 5\n", piece[5][0], piece[5][1], piece[5][2], piece[5][3], piece[5][4], piece[5][5], piece[5][6], piece[5][7]);
    printf("  .................................................\n");
    printf("6 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 6\n", piece[6][0], piece[6][1], piece[6][2], piece[6][3], piece[6][4], piece[6][5], piece[6][6], piece[6][7]);
    printf("  .................................................\n");
    printf("7 |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  |  %s  | 7\n", piece[7][0], piece[7][1], piece[7][2], piece[7][3], piece[7][4], piece[7][5], piece[7][6], piece[7][7]);
    printf("  .................................................\n");
    printf("    0     1     2     3     4     5     6     7\n");
}
