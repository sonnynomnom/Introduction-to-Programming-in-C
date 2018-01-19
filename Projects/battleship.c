// Final Project: Battleship
// Team OG Trio
// Louie Kotler, Simone Stern & Chris Narducci (Columbia University)

// Instructor: Sonny Li

// gcc -lform -lncurses -Wall battleship.c -o battleship
// ./battleship

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

// =========================================================================================================

int computerguess ();
int computerguess2 ();

int h = 0, b = 0, hit = 0, dir = 0;

char enter1, enter2;

char array1[10][10][10]= {
    
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"}

};

char array2[10][10][10];

char computerarray1[10][10][10] = {
    
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},
    {"~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~", "~^~"},

};

char computerarray2[10][10][10];

char computerboard1[10][10][10] = {
    
    {"(0)", "<=>", "<=>", "<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
    {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
    {"<=>", "(0)", "(0)", "(0)", "<=>", "(0)", "<=>", "(0)", "(0)", "(0)"},
    {"<=>", "(0)" ,"(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "<=>"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"}

};

char computerboard2[10][10][10] = {
    
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "<=>", "<=>", "<=>", "<=>", "<=>", "(0)", "<=>", "(0)"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)"},
    {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"<=>", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)"},
    {"<=>", "(0)" ,"(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)"},
    {"<=>", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"}

};

char computerboard3[10][10][10] = {
    
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)"},
    {"(0)", "(0)", "<=>", "<=>", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)"},
    {"(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "<=>" ,"(0)", "(0)", "(0)", "(0)", "<=>", "<=>", "<=>", "(0)"},
    {"(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"}

};

char computerboard4[10][10][10] = {
    
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"<=>", "<=>" ,"<=>", "<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
    {"(0)", "<=>" ,"<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"},
    {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"},
    {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>"}

};

// =========================================================================================================

int main () {
    
    srand(time(NULL));
    
    char board1[10][10][10] = {
        
        {"(0)", "<=>", "<=>", "<=>", "<=>", "<=>", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "<=>", "<=>"}
    
    };
    
    char board2[10][10][10] = {
        
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"<=>", "(0)", "(0)", "(0)", "(0)", "<=>", "<=>", "<=>"},
        {"(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"}
    
    };
    
    char board3[10][10][10] = {
        
        {"<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "<=>", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "<=>", "<=>", "<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"}
    
    };
    
    char board4[10][10][10] = {
        
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "<=>", "<=>", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)" ,"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "<=>", "<=>", "<=>", "(0)", "(0)", "(0)"},
        {"(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)", "(0)"},
        {"<=>", "<=>" ,"<=>", "<=>", "<=>", "(0)", "(0)", "(0)", "(0)", "(0)"}
    
    };
    
    
    // ========================================================================
    // New window
    
    initscr();
    
    //=========================================================================
    // Welcome Page
    
    noecho();
    
    start_color();
    
    init_pair(1, COLOR_RED, COLOR_BLACK);      // foreground color, background color (i feel like marcus)
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    
    system("afplay battleship.mp3 &");
    
    mvprintw(2, 85, "Welcome to: \n\n");
    
    attron(COLOR_PAIR(1));
    mvprintw(15, 64, " ____   __  ____  ____  __    ____  ____  _  _  __  ____ \n");
    mvprintw(16, 64, "(  _ \\ / _\\(_  _)(_  _)(  )  (  __)/ ___)/ )( \\(  )(  _ \\ \n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(17, 64, " ) _ (/    \\ )(    )(  / (_/\\ ) _) \\___ \\) __ ( )(  ) __/ \n");
    mvprintw(18, 64, "(____/\\_/\\_/(__)  (__) \\____/(____)(____/\\_)(_/(__)(__) \n\n\n");
    attroff(COLOR_PAIR(2));
    
    attron(COLOR_PAIR(1));
    mvprintw(21, 84, "   ..-^~~~^-..\n");
    mvprintw(22, 84, " .~           ~.\n");
    mvprintw(23, 84, "(;:           :;)\n");
    mvprintw(24, 84, " (:           :)\n ");
    mvprintw(25, 84, "   ':._   _.:' \n");
    mvprintw(26, 84, "       | |  \n");
    mvprintw(27, 84, "     (=====) \n");
    mvprintw(28, 84, "       | |  \n");
    mvprintw(29, 84, "       | |  \n");
    mvprintw(30, 84, "       | |  \n");
    mvprintw(31, 84, "    ((/   \\)) \n ");
    attroff(COLOR_PAIR(1));
    
    mvprintw(35, 83, "Press [enter] to play\n\n" );
    
    while (enter1 != '\n') {
        
        refresh();
        enter1 = getch();
    
    }
    
    clear();
    
    move(0,0);
    
    attron(COLOR_PAIR(1));
    mvprintw(10, 53, ",--.                 ,--.                         ,--.  ,--.\n");
    mvprintw(11, 53, "|  |,--,--,  ,---., -'  '-.,--.--.,--.,--. ,---.,-'  '-.`--' ,---. ,--,--,  ,---.\n");
    mvprintw(12, 53, "|  ||      | (  .-''-.  .-'|  .--'|  ||  || .--''-.  .-',--.| .-. ||      |(.-'\n");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(13, 53, "|  ||  ||  | .-' `)  |  |  |  |   '  ''  ' .-' `) |  |  |  |' '-' '|  ||  |.-' `)\n");
    mvprintw(14, 53, "`--'`--''--' `---'   `--'  `--'    `----'  `---'  `--'  `--' `---' `--''--'`----'\n");
    attroff(COLOR_PAIR(2));
    
    mvprintw(20, 55, "Welcome to Battleship! Choose a board on the next screen to start gameplay.\n");
    mvprintw(21, 55, "You will then be prompted to enter a guess. You must enter it in the format \n");
    mvprintw(22, 55, "of an Uppercase Letter a space and a Number. Ex: D 6 . On the left is the \n");
    mvprintw(23, 55, "computers board of which you will be guessing and on the right is your board.\n");
    mvprintw(24, 55, "The object of the game is to hit all of the computer's ships and sink them.\n");
    
    mvprintw(30, 90, "Key:\n\n");
    mvprintw(31, 75, "A boat or fleet looks like: ");
    attron(COLOR_PAIR(1));
    printw("<=>\n");
    attroff(COLOR_PAIR(1));
    mvprintw(32, 76, "A missed launch looks like: ");
    attron(COLOR_PAIR(3));
    printw("(0)\n");
    attroff(COLOR_PAIR(3));
    mvprintw(33, 74, "An untargeted location looks like: ");
    attron(COLOR_PAIR(3));
    printw("~^~\n");
    attroff(COLOR_PAIR(3));
    
    mvprintw(45, 82, "Press [enter] to play\n\n" );
    
    while (enter2 != '\n') {
        
        refresh();
        enter2 = getch();
    
    }
    
    clear();

    move(0,0);
    
    // =========================================================================
    // Choose Board
    
    int input = 0;
    int j;
    int k;
    
    clear();
    refresh();
    mvprintw(4, 83, "CHOOSE YOUR BOARD");
    
    // Print Board 1
    
    mvprintw(7, 39, "1");
    attron(COLOR_PAIR(1));
    mvprintw(9, 9, "       A    B    C    D    E    F    G    H    I    J", board1[0][0], board1[0][1], board1[0][2], board1[0][3]);
    attroff(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(3));
    mvprintw(11, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[0][0], board1[0][1], board1[0][2], board1[0][3], board1[0][4], board1[0][5], board1[0][6], board1[0][7], board1[0][8], board1[0][9]);
    mvprintw(13, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[1][0], board1[1][1], board1[1][2], board1[1][3], board1[1][4], board1[1][5], board1[1][6], board1[1][7], board1[1][8], board1[1][9]);
    mvprintw(15, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[2][0], board1[2][1], board1[2][2], board1[2][3],board1[2][4], board1[2][5], board1[2][6], board1[2][7], board1[2][8], board1[2][9]);
    mvprintw(17, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[3][0], board1[3][1], board1[3][2], board1[3][3],board1[3][4], board1[3][5],board1[3][6], board1[3][7],board1[3][8],board1[3][9]);
    mvprintw(19, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[4][0], board1[4][1], board1[4][2], board1[4][3],board1[4][4], board1[4][5],board1[4][6], board1[4][7],board1[4][8],board1[4][9]);
    mvprintw(21, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[5][0], board1[5][1], board1[5][2], board1[5][3],board1[5][4], board1[5][5],board1[5][6], board1[5][7],board1[5][8],board1[5][9]);
    mvprintw(23, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[6][0], board1[6][1], board1[6][2], board1[6][3],board1[6][4], board1[6][5],board1[6][6], board1[6][7],board1[6][8],board1[6][9]);
    mvprintw(25, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[7][0], board1[7][1], board1[7][2], board1[7][3],board1[7][4], board1[7][5],board1[7][6], board1[7][7],board1[7][8],board1[7][9]);
    mvprintw(27, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[8][0], board1[8][1], board1[8][2], board1[8][3],board1[8][4], board1[8][5],board1[8][6], board1[8][7],board1[8][8],board1[8][9]);
    mvprintw(29, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board1[9][0], board1[9][1], board1[9][2], board1[9][3],board1[9][4], board1[9][5],board1[9][6], board1[9][7],board1[9][8],board1[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(11, 10, " 1");
    mvprintw(13, 10, " 2");
    mvprintw(15, 10, " 3");
    mvprintw(17, 10, " 4");
    mvprintw(19, 10, " 5");
    mvprintw(21, 10, " 6");
    mvprintw(23, 10, " 7");
    mvprintw(25, 10, " 8");
    mvprintw(27, 10, " 9");
    mvprintw(29, 10, " 10");
    attroff(COLOR_PAIR(1));
    
    // Print Board 3
    
    mvprintw(6, 154, "3");
    attron(COLOR_PAIR(1));
    mvprintw(8, 124,"       A    B    C    D    E    F    G    H    I    J", board3[0][0], board3[0][1], board3[0][2], board3[0][3]);
    attroff(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(3));
    mvprintw(11, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[0][0], board3[0][1], board3[0][2], board3[0][3], board3[0][4], board3[0][5], board3[0][6], board3[0][7], board3[0][8], board3[0][9]);
    mvprintw(13, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[1][0], board3[1][1], board3[1][2], board3[1][3], board3[1][4], board3[1][5], board3[1][6], board3[1][7], board3[1][8], board3[1][9]);
    mvprintw(15, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[2][0], board3[2][1], board3[2][2], board3[2][3],board3[2][4], board3[2][5], board3[2][6], board3[2][7], board3[2][8], board3[2][9]);
    mvprintw(17, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[3][0], board3[3][1], board3[3][2], board3[3][3],board3[3][4], board3[3][5],board3[3][6], board3[3][7],board3[3][8],board3[3][9]);
    mvprintw(19, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[4][0], board3[4][1], board3[4][2], board3[4][3],board3[4][4], board3[4][5],board3[4][6], board3[4][7],board3[4][8],board3[4][9]);
    mvprintw(21, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[5][0], board3[5][1], board3[5][2], board3[5][3],board3[5][4], board3[5][5],board3[5][6], board3[5][7],board3[5][8],board3[5][9]);
    mvprintw(23, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[6][0], board3[6][1], board3[6][2], board3[6][3],board3[6][4], board3[6][5],board3[6][6], board3[6][7],board3[6][8],board3[6][9]);
    mvprintw(25, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[7][0], board3[7][1], board3[7][2], board3[7][3],board3[7][4], board3[7][5],board3[7][6], board3[7][7],board3[7][8],board3[7][9]);
    mvprintw(27, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[8][0], board3[8][1], board3[8][2], board3[8][3],board3[8][4], board3[8][5],board3[8][6], board3[8][7],board3[8][8],board3[8][9]);
    mvprintw(29, 125,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board3[9][0], board3[9][1], board3[9][2], board3[9][3],board3[9][4], board3[9][5],board3[9][6], board3[9][7],board3[9][8],board3[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(11, 125, " 1");
    mvprintw(13, 125, " 2");
    mvprintw(15, 125, " 3");
    mvprintw(17, 125, " 4");
    mvprintw(19, 125, " 5");
    mvprintw(21, 125, " 6");
    mvprintw(23, 125, " 7");
    mvprintw(25, 125, " 8");
    mvprintw(27, 125, " 9");
    mvprintw(29, 125, " 10");
    attroff(COLOR_PAIR(1));
    
    // Print Board 2
    
    mvprintw(35, 39, "2");
    attron(COLOR_PAIR(1));
    mvprintw(37, 9, "       A    B    C    D    E    F    G    H    I    J", board2[0][0], board2[0][1], board2[0][2], board2[0][3]);
    attroff(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(3));
    mvprintw(39, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[0][0], board2[0][1], board2[0][2], board2[0][3], board2[0][4], board2[0][5], board2[0][6], board2[0][7], board2[0][8], board2[0][9]);
    mvprintw(41, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[1][0], board2[1][1], board2[1][2], board2[1][3], board2[1][4], board2[1][5], board2[1][6], board2[1][7], board2[1][8], board2[1][9]);
    mvprintw(43, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[2][0], board2[2][1], board2[2][2], board2[2][3],board2[2][4], board2[2][5], board2[2][6], board2[2][7], board2[2][8], board2[2][9]);
    mvprintw(45, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[3][0], board2[3][1], board2[3][2], board2[3][3],board2[3][4], board2[3][5],board2[3][6], board2[3][7],board2[3][8],board2[3][9]);
    mvprintw(47, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[4][0], board2[4][1], board2[4][2], board2[4][3],board2[4][4], board2[4][5],board2[4][6], board2[4][7],board2[4][8],board2[4][9]);
    mvprintw(49, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[5][0], board2[5][1], board2[5][2], board2[5][3],board2[5][4], board2[5][5],board2[5][6], board2[5][7],board2[5][8],board2[5][9]);
    mvprintw(51, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[6][0], board2[6][1], board2[6][2], board2[6][3],board2[6][4], board2[6][5],board2[6][6], board2[6][7],board2[6][8],board2[6][9]);
    mvprintw(53, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[7][0], board2[7][1], board2[7][2], board2[7][3],board2[7][4], board2[7][5],board2[7][6], board2[7][7],board2[7][8],board2[7][9]);
    mvprintw(55, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[8][0], board2[8][1], board2[8][2], board2[8][3],board2[8][4], board2[8][5],board2[8][6], board2[8][7],board2[8][8],board2[8][9]);
    mvprintw(57, 10, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board2[9][0], board2[9][1], board2[9][2], board2[9][3],board2[9][4], board2[9][5],board2[9][6], board2[9][7],board2[9][8],board2[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(39, 10, " 1");
    mvprintw(41, 10, " 2");
    mvprintw(43, 10, " 3");
    mvprintw(45, 10, " 4");
    mvprintw(47, 10, " 5");
    mvprintw(49, 10, " 6");
    mvprintw(51, 10, " 7");
    mvprintw(53, 10, " 8");
    mvprintw(55, 10, " 9");
    mvprintw(57, 10, " 10");
    attroff(COLOR_PAIR(1));
    
    // Print Board 4
    
    mvprintw(35, 154, "4");
    attron(COLOR_PAIR(1));
    mvprintw(37, 124, "       A    B    C    D    E    F    G    H    I    J", board4[0][0], board4[0][1], board4[0][2], board4[0][3]);
    attroff(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(3));
    mvprintw(39, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[0][0], board4[0][1], board4[0][2], board4[0][3], board4[0][4], board4[0][5], board4[0][6], board4[0][7], board4[0][8], board4[0][9]);
    mvprintw(41, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[1][0], board4[1][1], board4[1][2], board4[1][3], board4[1][4], board4[1][5], board4[1][6], board4[1][7], board4[1][8], board4[1][9]);
    mvprintw(43, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[2][0], board4[2][1], board4[2][2], board4[2][3],board4[2][4], board4[2][5], board4[2][6], board4[2][7], board4[2][8], board4[2][9]);
    mvprintw(45, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[3][0], board4[3][1], board4[3][2], board4[3][3],board4[3][4], board4[3][5],board4[3][6], board4[3][7],board4[3][8],board4[3][9]);
    mvprintw(47, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[4][0], board4[4][1], board4[4][2], board4[4][3],board4[4][4], board4[4][5],board4[4][6], board4[4][7],board4[4][8],board4[4][9]);
    mvprintw(49, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[5][0], board4[5][1], board4[5][2], board4[5][3],board4[5][4], board4[5][5],board4[5][6], board4[5][7],board4[5][8],board4[5][9]);
    mvprintw(51, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[6][0], board4[6][1], board4[6][2], board4[6][3],board4[6][4], board4[6][5],board4[6][6], board4[6][7],board4[6][8],board4[6][9]);
    mvprintw(53, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[7][0], board4[7][1], board4[7][2], board4[7][3],board4[7][4], board4[7][5],board4[7][6], board4[7][7],board4[7][8],board4[7][9]);
    mvprintw(55, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[8][0], board4[8][1], board4[8][2], board4[8][3],board4[8][4], board4[8][5],board4[8][6], board4[8][7],board4[8][8],board4[8][9]);
    mvprintw(57, 125, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", board4[9][0], board4[9][1], board4[9][2], board4[9][3],board4[9][4], board4[9][5],board4[9][6], board4[9][7],board4[9][8],board4[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(39, 125, " 1");
    mvprintw(41, 125, " 2");
    mvprintw(43, 125, " 3");
    mvprintw(45, 125, " 4");
    mvprintw(47, 125, " 5");
    mvprintw(49, 125, " 6");
    mvprintw(51, 125, " 7");
    mvprintw(53, 125, " 8");
    mvprintw(55, 125, " 9");
    mvprintw(57, 125, " 10");
    attroff(COLOR_PAIR(1));
    
    echo();
    mvprintw(33, 80, "Enter Board Choice: ");
    input = getch();
    getch();
    noecho();
    
    int easyhard;
    
    echo();
    mvprintw(36, 72, "Enter Difficulty (1 = Easy  2 = Hard): ");
    scanw("%d", &easyhard);
    noecho();
    
    // =========================================================================
    // Set Chosen User Board as "array2"
    
    if (input == '1') {
        
        for (j = 0; j < 10; j++) {
            
            for (k = 0; k < 10; k++) {
                
                strcpy(array2[j][k], board1[j][k]);
                
            }
            
        }
        
    }
    else if (input == '2') {
        
        for(j = 0; j < 10; j++) {
            
            for(k = 0; k < 10; k++) {
                
                strcpy(array2[j][k], board2[j][k]);
                
            }
            
        }
        
    }
    else if (input == '3') {
        
        for (j = 0; j < 10; j++) {
            
            for (k = 0; k < 10; k++) {
                
                strcpy(array2[j][k], board3[j][k]);
                
            }
            
        }
        
    }
    else if (input == '4') {
        
        for(j = 0; j < 10; j++) {
            
            for (k = 0; k < 10; k++) {
                
                strcpy(array2[j][k], board4[j][k]);
                
            }
            
        }
        
    }
    
    // =========================================================================
    // Set Chosen Computer Board as "array2"
    
    int computerchoice=rand() % 4;
    
    if (computerchoice == 0) {
        
        for (j = 0; j < 10; j++) {
            
            for (k = 0; k < 10; k++) {
                
                strcpy(computerarray2[j][k], computerboard1[j][k]);
                
            }
            
        }
        
    }
    else if (computerchoice == 1) {
        
        for(j = 0; j < 10; j++) {
            
            for (k = 0; k < 10; k++) {
                
                strcpy(computerarray2[j][k], computerboard2[j][k]);
                
            }
            
        }
        
    }
    else if (computerchoice == 2) {
        
        for(j = 0; j < 10; j++) {
            
            for(k = 0; k < 10; k++) {
                
                strcpy(computerarray2[j][k], computerboard3[j][k]);
                
            }
            
        }
        
    }
    else if (computerchoice == 3) {
        
        for(j = 0; j < 10; j++) {
            
            for(k = 0; k < 10; k++) {
                
                strcpy(computerarray2[j][k], computerboard4[j][k]);
                
            }
            
        }
        
    }
    
    // =========================================================================
    // Print Blank Board
    // While Loop Starts
    
    clear();
    refresh();
    
    int running = 1;
    int usercounter = 0;
    int compcounter = 0;
    int userbcheck = 0, userccheck = 0, userdcheck = 0, userpcheck = 0;
    int combcheck = 0, comccheck = 0, comdcheck = 0, compcheck = 0;
    
    while (running) {
        
        int ent1, ent2 = 0;
        
        attron(COLOR_PAIR(4));
        mvprintw(0 , 17, "     Computer Map");
        attroff(COLOR_PAIR(4));
        
        attron(COLOR_PAIR(1));
        mvprintw(1 , 0, "       A    B    C    D    E    F    G    H    I    J", computerarray1[0][0], computerarray1[0][1], computerarray1[0][2], computerarray1[0][3]);
        attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(3));
        mvprintw(3, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[0][0], computerarray1[0][1], computerarray1[0][2], computerarray1[0][3], computerarray1[0][4], computerarray1[0][5], computerarray1[0][6], computerarray1[0][7], computerarray1[0][8], computerarray1[0][9]);
        mvprintw(5, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[1][0], computerarray1[1][1], computerarray1[1][2], computerarray1[1][3], computerarray1[1][4], computerarray1[1][5], computerarray1[1][6], computerarray1[1][7], computerarray1[1][8], computerarray1[1][9]);
        mvprintw(7, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[2][0], computerarray1[2][1], computerarray1[2][2], computerarray1[2][3],computerarray1[2][4], computerarray1[2][5], computerarray1[2][6], computerarray1[2][7], computerarray1[2][8], computerarray1[2][9]);
        mvprintw(9, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[3][0], computerarray1[3][1], computerarray1[3][2], computerarray1[3][3],computerarray1[3][4], computerarray1[3][5],computerarray1[3][6], computerarray1[3][7],computerarray1[3][8],computerarray1[3][9]);
        mvprintw(11, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[4][0], computerarray1[4][1], computerarray1[4][2], computerarray1[4][3],computerarray1[4][4], computerarray1[4][5],computerarray1[4][6], computerarray1[4][7],computerarray1[4][8],computerarray1[4][9]);
        mvprintw(13, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[5][0], computerarray1[5][1], computerarray1[5][2], computerarray1[5][3],computerarray1[5][4], computerarray1[5][5],computerarray1[5][6], computerarray1[5][7],computerarray1[5][8],computerarray1[5][9]);
        mvprintw(15, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[6][0], computerarray1[6][1], computerarray1[6][2], computerarray1[6][3],computerarray1[6][4], computerarray1[6][5],computerarray1[6][6], computerarray1[6][7],computerarray1[6][8],computerarray1[6][9]);
        mvprintw(17, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[7][0], computerarray1[7][1], computerarray1[7][2], computerarray1[7][3],computerarray1[7][4], computerarray1[7][5],computerarray1[7][6], computerarray1[7][7],computerarray1[7][8],computerarray1[7][9]);
        mvprintw(19, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[8][0], computerarray1[8][1], computerarray1[8][2], computerarray1[8][3],computerarray1[8][4], computerarray1[8][5],computerarray1[8][6], computerarray1[8][7],computerarray1[8][8],computerarray1[8][9]);
        mvprintw(21, 1, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[9][0], computerarray1[9][1], computerarray1[9][2], computerarray1[9][3],computerarray1[9][4], computerarray1[9][5],computerarray1[9][6], computerarray1[9][7],computerarray1[9][8],computerarray1[9][9]);
        attroff(COLOR_PAIR(3));
        
        attron(COLOR_PAIR(1));
        mvprintw(3, 1, " 1");
        mvprintw(5, 1, " 2");
        mvprintw(7, 1, " 3");
        mvprintw(9, 1, " 4");
        mvprintw(11,1, " 5");
        mvprintw(13,1, " 6");
        mvprintw(15,1, " 7");
        mvprintw(17,1, " 8");
        mvprintw(19,1, " 9");
        mvprintw(21,1, " 10");
        attroff(COLOR_PAIR(1));
        
        // computers view
        
        attron(COLOR_PAIR(4));
        mvprintw(0, 100, "     User Map");
        attroff(COLOR_PAIR(4));
        
        attron(COLOR_PAIR(1));
        mvprintw(1, 80, "      A    B    C    D    E    F    G    H    I    J", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
        attroff(COLOR_PAIR(1));
        
        attron(COLOR_PAIR(3));
        mvprintw(3, 80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[0][0], array1[0][1], array1[0][2], array1[0][3], array1[0][4], array1[0][5], array1[0][6], array1[0][7], array1[0][8], array1[0][9]);
        mvprintw(5, 80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[1][0], array1[1][1], array1[1][2], array1[1][3], array1[1][4], array1[1][5], array1[1][6], array1[1][7], array1[1][8], array1[1][9]);
        mvprintw(7, 80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[2][0], array1[2][1], array1[2][2], array1[2][3],array1[2][4], array1[2][5], array1[2][6], array1[2][7], array1[2][8], array1[2][9]);
        mvprintw(9, 80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[3][0], array1[3][1], array1[3][2], array1[3][3],array1[3][4], array1[3][5],array1[3][6], array1[3][7],array1[3][8],array1[3][9]);
        mvprintw(11,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[4][0], array1[4][1], array1[4][2], array1[4][3],array1[4][4], array1[4][5],array1[4][6], array1[4][7],array1[4][8],array1[4][9]);
        mvprintw(13,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[5][0], array1[5][1], array1[5][2], array1[5][3],array1[5][4], array1[5][5],array1[5][6], array1[5][7],array1[5][8],array1[5][9]);
        mvprintw(15,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[6][0], array1[6][1], array1[6][2], array1[6][3], array1[6][4], array1[6][5], array1[6][6], array1[6][7],array1[6][8],array1[6][9]);
        mvprintw(17,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[7][0], array1[7][1], array1[7][2], array1[7][3],array1[7][4], array1[7][5],array1[7][6], array1[7][7],array1[7][8],array1[7][9]);
        mvprintw(19,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[8][0], array1[8][1], array1[8][2], array1[8][3],array1[8][4], array1[8][5],array1[8][6], array1[8][7],array1[8][8],array1[8][9]);
        mvprintw(21,80, "     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[9][0], array1[9][1], array1[9][2], array1[9][3],array1[9][4], array1[9][5],array1[9][6], array1[9][7],array1[9][8], array1[9][9]);
        attroff(COLOR_PAIR(3));
        
        attron(COLOR_PAIR(1));
        mvprintw(3, 80, " 1");
        mvprintw(5, 80, " 2");
        mvprintw(7, 80, " 3");
        mvprintw(9, 80, " 4");
        mvprintw(11,80, " 5");
        mvprintw(13,80, " 6");
        mvprintw(15,80, " 7");
        mvprintw(17,80, " 8");
        mvprintw(19,80, " 9");
        mvprintw(21,80, " 10");
        attroff(COLOR_PAIR(1));
        
        // =========================================================================
        // Enter Coordinate
        
        char ent1c;
        echo();
        attron(A_BOLD);
        mvprintw(25, 0, "Enter Coordinate 1 (Letter Number): ");
        attroff(A_BOLD);
        scanw("%c%d", &ent1c,&ent2);
        noecho();
        
        if (ent1c == 'A') {
            
            ent1 = 1;
        
        }
        
        if (ent1c == 'B') {
            
            ent1 = 2;
        
        }
        
        if (ent1c == 'C') {
            
            ent1 = 3;
        
        }
        
        if (ent1c == 'D') {
            
            ent1 = 4;
        
        }
        
        if (ent1c == 'E') {
            
            ent1 = 5;
        
        }
        
        if (ent1c == 'F') {
            
            ent1 = 6;
        
        }
        
        if (ent1c == 'G') {
            
            ent1 = 7;
        
        }
        
        if (ent1c == 'H') {
            
            ent1 = 8;
        
        }
        
        if (ent1c == 'I') {
            
            ent1 = 9;
        
        }
        
        if (ent1c == 'J') {
            
            ent1 = 10;
        
        }
        
        ent1 -= 1;
        ent2 -= 1;
        
        refresh();
        
        strcpy(computerarray1[ent2][ent1], computerarray2[ent2][ent1]);
        
        clear();
        
        // =========================================================================
        // Hit or Miss users view
        
        if (strcmp(computerarray1[ent2][ent1], "<=>") == 0) {
            
            mvprintw(27, 0, "Torpedo Status:");
            attron(COLOR_PAIR(1));
            mvprintw(27,17, "You Hit!");
            system("afplay explosion.mp3 &");
            attroff(COLOR_PAIR(1));
            
        }
        else{
            mvprintw(27, 0, "Torpedo Status:");
            attron(COLOR_PAIR(3));
            mvprintw(27,17, "You Missed!");
            system("afplay waterdrop.mp3 &");
            attroff(COLOR_PAIR(3));
        }
        
        
        //=====================================================================
        //checking if the you sunk the computers boats
        
        //board 1
        if(computerchoice==0){
            if(userbcheck != 1 && strcmp(computerarray1[1][6],"<=>") == 0 && strcmp(computerarray1[2][6],"<=>") == 0 && strcmp(computerarray1[3][6],"<=>") == 0 && strcmp(computerarray1[4][6],"<=>") == 0 && strcmp(computerarray1[5][6],"<=>") == 0)
            {
                mvprintw(29,0,"You Sunk My Battleship!");
                usercounter++;
                userbcheck = 1;
            }
            
            if(userccheck != 1 && strcmp(computerarray1[0][1],"<=>") == 0 && strcmp(computerarray1[0][2],"<=>") == 0 && strcmp(computerarray1[0][3],"<=>") == 0 && strcmp(computerarray1[0][4],"<=>") == 0)
            {
                mvprintw(31,0,"You Sunk My Carrier!");
                usercounter++;
                userccheck = 1;
            }
            
            if(userdcheck != 1 && strcmp(computerarray1[4][0],"<=>") == 0 && strcmp(computerarray1[5][0],"<=>") == 0 && strcmp(computerarray1[6][0],"<=>") == 0)
            {
                mvprintw(33,0,"You Sunk My Destroyer!");
                usercounter++;
                userdcheck = 1;
            }
            if(userpcheck != 1 && strcmp(computerarray1[5][4],"<=>") == 0 && strcmp(computerarray1[6][4],"<=>") == 0)
            {
                mvprintw(35,0,"You Sunk My Patroller!");
                usercounter++;
                userpcheck = 1;
            }
            
            if(usercounter==4){
                running=0;
            }
            
        }
        
        
        //board 2
        if(computerchoice==1){
            if(userbcheck != 1 && strcmp(computerarray1[2][2],"<=>") == 0 && strcmp(computerarray1[2][3],"<=>") == 0 && strcmp(computerarray1[2][4],"<=>") == 0 && strcmp(computerarray1[2][5],"<=>") == 0 && strcmp(computerarray1[2][6],"<=>") == 0)
            {
                mvprintw(29,0,"You Sunk My Battleship!");
                usercounter++;
                userbcheck = 1;
            }
            
            if(userccheck != 1 && strcmp(computerarray1[4][0],"<=>") == 0 && strcmp(computerarray1[5][0],"<=>") == 0 && strcmp(computerarray1[6][0],"<=>") == 0 && strcmp(computerarray1[7][0],"<=>") == 0)
            {
                mvprintw(31,0,"You Sunk My Carrier!");
                usercounter++;
                userccheck = 1;
            }
            
            if(userdcheck != 1 && strcmp(computerarray1[5][5],"<=>") == 0 && strcmp(computerarray1[6][5],"<=>") == 0 && strcmp(computerarray1[7][5],"<=>") == 0)
            {
                mvprintw(33,0,"You Sunk My Destroyer!");
                usercounter++;
                userdcheck = 1;
            }
            
            if(userpcheck != 1 && strcmp(computerarray1[2][8],"<=>") == 0 && strcmp(computerarray1[3][8],"<=>") == 0)
            {
                mvprintw(35,0,"You Sunk My Patroller!");
                usercounter++;
                userpcheck = 1;
            }
            
            if(usercounter==4){
                running=0;
                
            }
            
        }
        
        //board 3
        if(computerchoice==2){
            if(userbcheck != 1 && strcmp(computerarray1[4][1],"<=>") == 0 && strcmp(computerarray1[5][1],"<=>") == 0 && strcmp(computerarray1[6][1],"<=>") == 0 && strcmp(computerarray1[7][1],"<=>") == 0 && strcmp(computerarray1[8][1],"<=>") == 0)
            {
                mvprintw(29,0,"You Sunk My Battleship!");
                usercounter++;
                userbcheck = 1;
            }
            
            if(userccheck != 1 && strcmp(computerarray1[0][7],"<=>") == 0 && strcmp(computerarray1[1][7],"<=>") == 0 && strcmp(computerarray1[2][7],"<=>") == 0 && strcmp(computerarray1[3][7],"<=>") == 0)
            {
                mvprintw(31,0,"You Sunk My Carrier!");
                usercounter++;
                userccheck = 1;
            }
            
            if(userdcheck != 1 && strcmp(computerarray1[6][6],"<=>") == 0 && strcmp(computerarray1[6][7],"<=>") == 0 && strcmp(computerarray1[6][8],"<=>") == 0)
            {
                mvprintw(33,0,"You Sunk My Destroyer!");
                usercounter++;
                userdcheck = 1;
            }
            
            if(userpcheck != 1 && strcmp(computerarray1[1][2],"<=>") == 0 && strcmp(computerarray1[1][3],"<=>") == 0)
            {
                mvprintw(35,0,"You Sunk My Patroller!");
                usercounter++;
                userpcheck = 1;
            }
            
            if(usercounter==4){
                running=0;
                
            }
            
        }
        
        //board 4
        if(computerchoice==3){
            if(userbcheck != 1 && strcmp(computerarray1[3][0],"<=>") == 0 && strcmp(computerarray1[3][1],"<=>") == 0 && strcmp(computerarray1[3][2],"<=>") == 0 && strcmp(computerarray1[3][3],"<=>") == 0 && strcmp(computerarray1[3][4],"<=>") == 0)
            {
                mvprintw(29,0,"You Sunk My Battleship!");
                usercounter++;
                userbcheck = 1;
            }
            
            if(userccheck != 1 && strcmp(computerarray1[6][9],"<=>") == 0 && strcmp(computerarray1[7][9],"<=>") == 0 && strcmp(computerarray1[8][9],"<=>") == 0 && strcmp(computerarray1[9][9],"<=>") == 0)
            {
                mvprintw(31,0,"You Sunk My Carrier!");
                usercounter++;
                userccheck = 1;
            }
            
            if(userdcheck != 1 && strcmp(computerarray1[6][1],"<=>") == 0 && strcmp(computerarray1[6][2],"<=>") == 0 && strcmp(computerarray1[6][3],"<=>") == 0)
            {
                mvprintw(33,0,"You Sunk My Destroyer!");
                usercounter++;
                userdcheck = 1;
            }
            
            if(userpcheck != 1 && strcmp(computerarray1[0][9],"<=>") == 0 && strcmp(computerarray1[1][9],"<=>") == 0)
            {
                mvprintw(35,0,"You Sunk My Patroller!");
                usercounter++;
                userpcheck = 1;
            }
            
            if(usercounter==4){
                running=0;
                
            }
        }
        
        
        //=====================================================================
        //Reprint Array With New Coordinate
        
        attron(COLOR_PAIR(3));
        mvprintw(3,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[0][0], computerarray1[0][1], computerarray1[0][2], computerarray1[0][3], computerarray1[0][4], computerarray1[0][5], computerarray1[0][6], computerarray1[0][7], computerarray1[0][8], computerarray1[0][9]);
        mvprintw(5,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[1][0], computerarray1[1][1], computerarray1[1][2], computerarray1[1][3], computerarray1[1][4], computerarray1[1][5], computerarray1[1][6], computerarray1[1][7], computerarray1[1][8], computerarray1[1][9]);
        mvprintw(7,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[2][0], computerarray1[2][1], computerarray1[2][2], computerarray1[2][3], computerarray1[2][4], computerarray1[2][5], computerarray1[2][6], computerarray1[2][7], computerarray1[2][8], computerarray1[2][9]);
        mvprintw(9,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[3][0], computerarray1[3][1], computerarray1[3][2], computerarray1[3][3], computerarray1[3][4], computerarray1[3][5],computerarray1[3][6], computerarray1[3][7],computerarray1[3][8],computerarray1[3][9]);
        mvprintw(11,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[4][0], computerarray1[4][1], computerarray1[4][2], computerarray1[4][3],computerarray1[4][4], computerarray1[4][5],computerarray1[4][6], computerarray1[4][7],computerarray1[4][8],computerarray1[4][9]);
        mvprintw(13,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[5][0], computerarray1[5][1], computerarray1[5][2], computerarray1[5][3],computerarray1[5][4], computerarray1[5][5],computerarray1[5][6], computerarray1[5][7],computerarray1[5][8],computerarray1[5][9]);
        mvprintw(15,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[6][0], computerarray1[6][1], computerarray1[6][2], computerarray1[6][3],computerarray1[6][4], computerarray1[6][5],computerarray1[6][6], computerarray1[6][7],computerarray1[6][8],computerarray1[6][9]);
        mvprintw(17,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[7][0], computerarray1[7][1], computerarray1[7][2], computerarray1[7][3],computerarray1[7][4], computerarray1[7][5],computerarray1[7][6], computerarray1[7][7],computerarray1[7][8],computerarray1[7][9]);
        mvprintw(19,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[8][0], computerarray1[8][1], computerarray1[8][2], computerarray1[8][3],computerarray1[8][4], computerarray1[8][5],computerarray1[8][6], computerarray1[8][7],computerarray1[8][8],computerarray1[8][9]);
        mvprintw(21,1,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", computerarray1[9][0], computerarray1[9][1], computerarray1[9][2], computerarray1[9][3],computerarray1[9][4], computerarray1[9][5],computerarray1[9][6], computerarray1[9][7],computerarray1[9][8],computerarray1[9][9]);
        
        refresh();
        
        
        //=====================================================================
        if(easyhard == 1)
        {
            computerguess();
        }
        
        if(easyhard == 2)
        {
            computerguess2();
        }
        
        //=====================================================================
        //checking if computer sunk your boats
        
        //board 1
        if(input=='1'){
            if(combcheck != 1 && strcmp(array1[0][1],"<=>") == 0 && strcmp(array1[0][2],"<=>") == 0 && strcmp(array1[0][3],"<=>") == 0 && strcmp(array1[0][4],"<=>") == 0 && strcmp(array1[0][5],"<=>") == 0)
            {
                mvprintw(29, 80,"The Computer Sunk Your Battleship!");
                compcounter++;
                combcheck = 1;
            }
            
            if(comccheck != 1 && strcmp(array1[2][6],"<=>") == 0 && strcmp(array1[3][6],"<=>") == 0 && strcmp(array1[4][6],"<=>") == 0 && strcmp(array1[5][6],"<=>") == 0)
            {
                mvprintw(31,80,"The Computer Sunk Your Carrier!");
                compcounter++;
                comccheck = 1;
            }
            
            if(comdcheck != 1 && strcmp(array1[9][7],"<=>") == 0 && strcmp(array1[9][8],"<=>") == 0 && strcmp(array1[9][9],"<=>") == 0)
            {
                mvprintw(33,80,"The Computer Sunk Your Destroyer!");
                compcounter++;
                comdcheck = 1;
            }
            if(compcheck != 1 && strcmp(array1[5][4],"<=>") == 0 && strcmp(array1[6][4],"<=>") == 0)
            {
                mvprintw(35,80,"The Computer Sunk Your Patroller!");
                compcounter++;
                compcheck = 1;
            }
            
            if(compcounter==4){
                running=0;
            }
            
        }
        
        //board 2
        if(input=='2'){
            if(combcheck != 1 && strcmp(array1[0][0],"<=>") == 0 && strcmp(array1[1][0],"<=>") == 0 && strcmp(array1[2][0],"<=>") == 0 && strcmp(array1[3][0],"<=>") == 0 && strcmp(array1[4][0],"<=>") == 0)
            {
                mvprintw(29,80,"The Computer Sunk Your Battleship!");
                compcounter++;
                combcheck = 1;
            }
            
            if(comccheck != 1 && strcmp(array1[6][2],"<=>") == 0 && strcmp(array1[7][2],"<=>") == 0 && strcmp(array1[8][2],"<=>") == 0 && strcmp(array1[9][2],"<=>") == 0)
            {
                mvprintw(31,80,"The Computer Sunk Your Carrier!");
                compcounter++;
                comccheck = 1;
            }
            
            if(comdcheck != 1 && strcmp(array1[6][7],"<=>") == 0 && strcmp(array1[6][8],"<=>") == 0 && strcmp(array1[6][9],"<=>") == 0)
            {
                mvprintw(33,80,"The Computer Sunk Your Destroyer!");
                compcounter++;
                comdcheck = 1;
            }
            
            if(compcheck != 1 && strcmp(array1[0][6],"<=>") == 0 && strcmp(array1[1][6],"<=>") == 0)
            {
                mvprintw(35,80,"The Computer Sunk Your Patroller!");
                compcounter++;
                compcheck = 1;
            }
            
            if(compcounter==4){
                running=0;
                
            }
            
        }
        
        //board 3
        if(input=='3'){
            if(combcheck != 1 && strcmp(array1[8][0],"<=>") == 0 && strcmp(array1[8][1],"<=>") == 0 && strcmp(array1[8][2],"<=>") == 0 && strcmp(array1[8][3],"<=>") == 0 && strcmp(array1[8][4],"<=>") == 0)
            {
                mvprintw(29,80,"The Computer Sunk Your Battleship!");
                compcounter++;
                combcheck = 1;
            }
            
            if(comccheck != 1 && strcmp(array1[0][8],"<=>") == 0 && strcmp(array1[1][8],"<=>") == 0 && strcmp(array1[2][8],"<=>") == 0 && strcmp(array1[3][8],"<=>") == 0)
            {
                mvprintw(31,80,"The Computer Sunk Your Carrier!");
                compcounter++;
                comccheck = 1;
            }
            
            if(comdcheck != 1 && strcmp(array1[3][4],"<=>") == 0 && strcmp(array1[4][4],"<=>") == 0 && strcmp(array1[5][4],"<=>") == 0)
            {
                mvprintw(33,80,"The Computer Sunk Your Destroyer!");
                compcounter++;
                comdcheck = 1;
            }
            
            if(compcheck != 1 && strcmp(array1[0][0],"<=>") == 0 && strcmp(array1[0][1],"<=>") == 0)
            {
                mvprintw(35,80,"The Computer Sunk Your Patroller!");
                compcounter++;
                compcheck = 1;
            }
            
            if(compcounter==4){
                running=0;
                
            }
            
        }
        
        //board 4
        if(input=='4'){
            if(combcheck != 1 && strcmp(array1[9][0],"<=>") == 0 && strcmp(array1[9][1],"<=>") == 0 && strcmp(array1[9][2],"<=>") == 0 && strcmp(array1[9][3],"<=>") == 0 && strcmp(array1[9][4],"<=>") == 0)
            {
                mvprintw(29,80,"The Computer Sunk Your Battleship!");
                compcounter++;
                combcheck = 1;
            }
            
            if(comccheck != 1 && strcmp(array1[2][0],"<=>") == 0 && strcmp(array1[3][0],"<=>") == 0 && strcmp(array1[4][0],"<=>") == 0 && strcmp(array1[5][0],"<=>") == 0)
            {
                mvprintw(31,80,"The Computer Sunk Your Carrier!");
                compcounter++;
                comccheck = 1;
            }
            
            if(comdcheck != 1 && strcmp(array1[7][4],"<=>") == 0 && strcmp(array1[7][5],"<=>") == 0 && strcmp(array1[7][6],"<=>") == 0)
            {
                mvprintw(33,80,"The Computer Sunk Your Destroyer!");
                compcounter++;
                comdcheck = 1;
            }
            
            if(compcheck != 1 && strcmp(array1[0][6],"<=>") == 0 && strcmp(array1[0][7],"<=>") == 0)
            {
                mvprintw(35,80,"The Computer Sunk Your Patroller!");
                compcounter++;
                compcheck = 1;
            }
            
            if(compcounter==4){
                running=0;
                
            }
        }
        
        //=====================================================================
        refresh();
        
    }
    
    refresh();
    if(usercounter==4){
        
        
        attron(COLOR_PAIR(4));
        mvprintw(50, 60,"__  __               _       __              ");
        mvprintw(51, 60,"\\ \\/ /___  __  __   | |     / /___  ____     ");
        mvprintw(52, 60,"  \\  / __ \\/ / / /   | | /| / / __ \\/ __ \\    ");
        mvprintw(53, 60,"  / / /_/ / /_/ /    | |/ |/ / /_/ / / / /    ");
        mvprintw(54, 60,"/_/\\____/\\__,_/     |__/|__/\\____/_/ /_/     ");
        
        attroff(COLOR_PAIR(4));
        
    }
    else{
        
        attron(COLOR_PAIR(4));
        mvprintw(50,60," \\ \\/ /___  __  __   / /   ____  _____/ /_  ");
        mvprintw(51,60,"  \\  / __ \\/ / / /  / /   / __ \\/ ___/ __/ ");
        mvprintw(52,60,"  / / /_/ / /_/ /  / /___/ /_/ (__  ) /_      ");
        mvprintw(53,60," /_/\\____/\\__,_/  /_____/\\____/____/\\__/  ");
        attroff(COLOR_PAIR(4));
        
        
        
    }
    getch();
    endwin();
    return 0;
    
}

//=====================================================================================================

int computerguess(){
    int x=0, r;
    
    
    srand(time(NULL));
    while(x<5){
        r = rand()%100;
        if(strcmp(array2[(r - (r%10))/10][r%10], "~^~\0") != 0){
            x = x + 6;
        }
    }
    x = x - 6;
    
    
    
    strcpy(array1[(r - (r%10))/10][r%10], array2[(r - (r%10))/10][r%10]);
    strcpy(array2[(r - (r%10))/10][r%10], "~^~\0");
    
    
    
    refresh();
    //replace with big array
    attron(COLOR_PAIR(1));
    mvprintw(1 ,80,"      A    B    C    D    E    F    G    H    I    J", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
    attroff(COLOR_PAIR(1));
    
    
    attron(COLOR_PAIR(3));
    mvprintw(3,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[0][0], array1[0][1], array1[0][2], array1[0][3], array1[0][4], array1[0][5], array1[0][6], array1[0][7], array1[0][8], array1[0][9]);
    mvprintw(5,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[1][0], array1[1][1], array1[1][2], array1[1][3], array1[1][4], array1[1][5], array1[1][6], array1[1][7], array1[1][8], array1[1][9]);
    mvprintw(7,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[2][0], array1[2][1], array1[2][2], array1[2][3],array1[2][4], array1[2][5], array1[2][6], array1[2][7], array1[2][8], array1[2][9]);
    mvprintw(9,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[3][0], array1[3][1], array1[3][2], array1[3][3],array1[3][4], array1[3][5],array1[3][6], array1[3][7], array1[3][8],array1[3][9]);
    mvprintw(11,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[4][0], array1[4][1], array1[4][2], array1[4][3],array1[4][4], array1[4][5],array1[4][6], array1[4][7],array1[4][8],array1[4][9]);
    mvprintw(13,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[5][0], array1[5][1], array1[5][2], array1[5][3],array1[5][4], array1[5][5],array1[5][6], array1[5][7],array1[5][8],array1[5][9]);
    mvprintw(15,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[6][0], array1[6][1], array1[6][2], array1[6][3], array1[6][4], array1[6][5], array1[6][6], array1[6][7],array1[6][8],array1[6][9]);
    mvprintw(17,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[7][0], array1[7][1], array1[7][2], array1[7][3],array1[7][4], array1[7][5],array1[7][6], array1[7][7],array1[7][8],array1[7][9]);
    mvprintw(19,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[8][0], array1[8][1], array1[8][2], array1[8][3],array1[8][4], array1[8][5],array1[8][6], array1[8][7],array1[8][8],array1[8][9]);
    mvprintw(21,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[9][0], array1[9][1], array1[9][2], array1[9][3],array1[9][4], array1[9][5],array1[9][6], array1[9][7],array1[9][8], array1[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(3,80," 1");
    mvprintw(5,80," 2");
    mvprintw(7,80," 3");
    mvprintw(9,80," 4");
    mvprintw(11,80," 5");
    mvprintw(13,80," 6");
    mvprintw(15,80," 7");
    mvprintw(17,80," 8");
    mvprintw(19,80," 9");
    mvprintw(21,80," 10");
    attroff(COLOR_PAIR(1));
    
    
    //=====================================================================================================
    //
    
    if(strcmp(array1[(r - (r%10))/10][r%10],"<=>")==0){
        attron(COLOR_PAIR(5));
        mvprintw(27, 80, "Torpedo Status:");
        attron(COLOR_PAIR(5));
        attron(COLOR_PAIR(3));
        attron(COLOR_PAIR(1));
        mvprintw(27,97, "The Computer Hit!");
        attroff(COLOR_PAIR(1));
        
    }
    else{
        
        attron(COLOR_PAIR(5));
        mvprintw(27, 80, "Torpedo Status:");
        attron(COLOR_PAIR(5));
        attron(COLOR_PAIR(3));
        mvprintw(27,97, "The Computer Missed!");
        attroff(COLOR_PAIR(3));
    }
    
    return 0;
}


//=====================================================================================================
//=====================================================================================================

//Not Random computer guessing
int computerguess2(){
    int x, r;
    
    //hit = 0;
    x = 0;
    
    srand(time(NULL));
    
    while(x<5){
        r = rand()%100;
        if(strcmp(array2[(r - (r%10))/10][r%10], "~^~\0") != 0){
            x = x + 6;
        }
    }
    x = x - 6;
    
    if(hit == 0){
        strcpy(array1[(r - (r%10))/10][r%10], array2[(r - (r%10))/10][r%10]);
        strcpy(array2[(r - (r%10))/10][r%10], "~^~\0");
        if(strcmp(array1[(r - (r%10))/10][r%10], "<=>\0") == 0){
            hit = 1;
            h = r;
            b = r;
            attron(COLOR_PAIR(5));
            mvprintw(27, 80, "Torpedo Status:");
            attron(COLOR_PAIR(5));
            attron(COLOR_PAIR(3));
            attron(COLOR_PAIR(1));
            mvprintw(27,97, "The Computer Hit!");
            attroff(COLOR_PAIR(1));
        }
        else{
            attron(COLOR_PAIR(5));
            mvprintw(27, 80, "Torpedo Status:");
            attron(COLOR_PAIR(5));
            attron(COLOR_PAIR(3));
            attron(COLOR_PAIR(3));
            mvprintw(27,97, "The Computer Missed!");
            attroff(COLOR_PAIR(3));
        }
    }
    else if(hit == 1){
        if((((h - (h%10))/10 + 1 <10) || ((strcmp( array2[(h - (h%10))/10 - 1][h%10], "~^~\0")== 0 || h - (h%10)/10 - 1 <0) && (strcmp( array2[(h - (h%10))/10][h%10+1], "~^~\0") == 0 || h%10 + 1 >=10) && ((strcmp( array2[(h - (h%10))/10][h%10 - 1], "~^~\0") == 0) || h%10 - 1 <0))) && strcmp( array2[(h - (h%10))/10 + 1][h%10], "~^~\0") != 0){
            strcpy( array1[(h - (h%10))/10 + 1][h%10],  array2[(h - (h%10))/10 + 1][h%10]);
            strcpy( array2[(h - (h%10))/10 + 1][h%10], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10 + 1][h%10], "<=>\0") == 0){
                hit++;
                h = h + 10;
                dir = 1;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if((((h - (h%10))/10 - 1 >= 0) || ((strcmp( array2[(h - (h%10))/10][h%10 + 1], "~^~\0")== 0 || h%10 + 1 >=10) && (strcmp( array2[(h - (h%10))/10][h%10 - 1], "~^~\0")== 0 || h%10 - 1 <0))) && strcmp( array2[(h - (h%10))/10 - 1][h%10], "~^~\0") != 0){
            strcpy( array1[(h - (h%10) - 1)/10][h%10],  array2[(h - (h%10))/10 - 1][h%10]);
            strcpy( array2[(h - (h%10))/10 - 1][h%10], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10 - 1][h%10], "<=>\0") == 0){
                hit++;
                h = h - 10;
                dir = 2;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(((h%10 + 1 < 10) || (strcmp( array2[(h - (h%10))/10][h%10 + 1], "~^~\0")== 0 || h%10 - 1 <0)) && strcmp( array2[(h - (h%10))/10][h%10 + 1], "~^~\0") != 0){
            strcpy( array1[(h - (h%10))/10][h%10 + 1],  array2[(h - (h%10))/10][h%10 + 1]);
            strcpy( array2[(h - (h%10))/10][h%10 + 1], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10][h%10 + 1], "<=>\0") == 0){
                hit++;
                h = h + 1;
                dir = 3;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if((h%10 - 1 >= 0) && strcmp( array2[(h - (h%10))/10][h%10 - 1], "~^~\0") != 0){
            strcpy( array1[(h - (h%10))/10][h%10 - 1],  array2[(h - (h%10))/10][h%10 - 1]);
            strcpy( array2[(h - (h%10))/10][h%10 - 1], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10][h%10 - 1], "<=>\0") == 0){
                hit++;
                h = h - 1;
                dir = 4;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
    }
    else if(hit > 1){
        if(dir == 1 && strcmp( array2[(h - (h%10))/10 + 1][h%10], "~^~\0") != 0 && (h - (h%10))/10 + 1 <10){
            strcpy( array1[(h - (h%10))/10 + 1][h%10],  array2[(h - (h%10))/10 + 1][h%10]);
            strcpy( array2[(h - (h%10))/10 + 1][h%10], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10 + 1][h%10], "<=>\0") == 0){
                hit++;
                h = h + 10;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 1 && strcmp( array2[(b - (b%10))/10 - 1][b%10], "~^~\0") != 0 && (b - (b%10))/10 - 1 >=0){
            strcpy( array1[(b - (b%10))/10 - 1][b%10],  array2[(b - (b%10))/10 - 1][b%10]);
            strcpy( array2[(b - (b%10))/10 - 1][b%10], "~^~\0");
            if(strcmp( array1[(b - (b%10))/10 - 1][b%10], "<=>\0") == 0){
                hit++;
                b = b - 10;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 2 && strcmp( array2[(h - (h%10))/10 - 1][h%10], "~^~\0") != 0 && (h - (h%10))/10 - 1 >=0){
            strcpy( array1[(h - (h%10))/10 - 1][h%10],  array2[(h - (h%10))/10 - 1][h%10]);
            strcpy( array2[(h - (h%10))/10 - 1][h%10], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10 - 1][h%10], "<=>\0") == 0){
                hit++;
                h = h - 10;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 2 && strcmp( array2[(b - (b%10))/10 + 1][b%10], "~^~\0") != 0 && (b - (b%10))/10 + 1 <10){
            strcpy( array1[(b - (b%10))/10 + 1][b%10],  array2[(b - (b%10))/10 + 1][b%10]);
            strcpy( array2[(b - (b%10))/10 + 1][b%10], "~^~\0");
            if(strcmp( array1[(b - (b%10))/10 + 1][b%10], "<=>\0") == 0){
                hit++;
                b = b + 10;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 3 && strcmp( array2[(h - (h%10))/10][h%10 + 1], "~^~\0") != 0 && h%10 + 1 <10){
            strcpy( array1[(h - (h%10))/10][h%10 + 1],  array2[(h - (h%10))/10][h%10 + 1]);
            strcpy( array2[(h - (h%10))/10][h%10 + 1], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10][h%10 + 1], "<=>\0") == 0){
                hit++;
                h = h + 1;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 3 && strcmp( array2[(b - (b%10))/10][b%10 - 1], "~^~\0") != 0 && b%10 - 1 >=0){
            strcpy( array1[(b - (b%10))/10][b%10 - 1],  array2[(b - (b%10))/10][b%10 - 1]);
            strcpy( array2[(b - (b%10))/10][b%10 - 1], "~^~\0");
            if(strcmp( array1[(b - (b%10))/10][b%10 - 1], "<=>\0") == 0){
                hit++;
                b = b - 1;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 4 && strcmp( array2[(h - (h%10))/10][h%10 - 1], "~^~\0") != 0 && h%10 - 1 >=0){
            strcpy( array1[(h - (h%10))/10][h%10 - 1],  array2[(h - (h%10))/10][h%10 - 1]);
            strcpy( array2[(h - (h%10))/10][h%10 - 1], "~^~\0");
            if(strcmp( array1[(h - (h%10))/10][h%10 - 1], "<=>\0") == 0){
                hit++;
                h = h - 1;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else if(dir == 4 && strcmp( array2[(b - (b%10))/10][b%10 + 1], "~^~\0") != 0 && b%10 + 1 <10){
            strcpy( array1[(b - (b%10))/10][b%10 + 1],  array2[(b - (b%10))/10][b%10 + 1]);
            strcpy( array2[(b - (b%10))/10][b%10 + 1], "~^~\0");
            if(strcmp( array1[(b - (b%10))/10][b%10 + 1], "<=>\0") == 0){
                hit++;
                b = b + 1;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
        else{
            hit = 0;
            strcpy( array1[(r - (r%10))/10][r%10],  array2[(r - (r%10))/10][r%10]);
            strcpy( array2[(r - (r%10))/10][r%10], "~^~\0");
            if(strcmp( array1[(r - (r%10))/10][r%10], "<=>\0") == 0){
                hit = 1;
                h = r;
                b = r;
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(1));
                mvprintw(27,97, "The Computer Hit!");
                attroff(COLOR_PAIR(1));
            }
            else{
                attron(COLOR_PAIR(5));
                mvprintw(27, 80, "Torpedo Status:");
                attron(COLOR_PAIR(5));
                attron(COLOR_PAIR(3));
                mvprintw(27,97, "The Computer Missed!");
                attroff(COLOR_PAIR(3));
            }
        }
    }
    refresh();
    attron(COLOR_PAIR(1));
    mvprintw(1 ,80,"      A    B    C    D    E    F    G    H    I    J", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
    attroff(COLOR_PAIR(1));
    
    
    attron(COLOR_PAIR(3));
    mvprintw(3,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[0][0], array1[0][1], array1[0][2], array1[0][3], array1[0][4], array1[0][5], array1[0][6], array1[0][7], array1[0][8], array1[0][9]);
    mvprintw(5,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[1][0], array1[1][1], array1[1][2], array1[1][3], array1[1][4], array1[1][5], array1[1][6], array1[1][7], array1[1][8], array1[1][9]);
    mvprintw(7,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[2][0], array1[2][1], array1[2][2], array1[2][3],array1[2][4], array1[2][5], array1[2][6], array1[2][7], array1[2][8], array1[2][9]);
    mvprintw(9,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[3][0], array1[3][1], array1[3][2], array1[3][3],array1[3][4], array1[3][5],array1[3][6], array1[3][7],array1[3][8],array1[3][9]);
    mvprintw(11,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[4][0], array1[4][1], array1[4][2], array1[4][3],array1[4][4], array1[4][5],array1[4][6], array1[4][7],array1[4][8],array1[4][9]);
    mvprintw(13,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[5][0], array1[5][1], array1[5][2], array1[5][3],array1[5][4], array1[5][5],array1[5][6], array1[5][7],array1[5][8],array1[5][9]);
    mvprintw(15,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[6][0], array1[6][1], array1[6][2], array1[6][3], array1[6][4], array1[6][5], array1[6][6], array1[6][7],array1[6][8],array1[6][9]);
    mvprintw(17,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[7][0], array1[7][1], array1[7][2], array1[7][3],array1[7][4], array1[7][5],array1[7][6], array1[7][7],array1[7][8],array1[7][9]);
    mvprintw(19,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[8][0], array1[8][1], array1[8][2], array1[8][3],array1[8][4], array1[8][5],array1[8][6], array1[8][7],array1[8][8],array1[8][9]);
    mvprintw(21,80,"     %s  %s  %s  %s  %s  %s  %s  %s  %s  %s", array1[9][0], array1[9][1], array1[9][2], array1[9][3],array1[9][4], array1[9][5],array1[9][6], array1[9][7],array1[9][8], array1[9][9]);
    attroff(COLOR_PAIR(3));
    
    attron(COLOR_PAIR(1));
    mvprintw(3,80," 1");
    mvprintw(5,80," 2");
    mvprintw(7,80," 3");
    mvprintw(9,80," 4");
    mvprintw(11,80," 5");
    mvprintw(13,80," 6");
    mvprintw(15,80," 7");
    mvprintw(17,80," 8");
    mvprintw(19,80," 9");
    mvprintw(21,80," 10");
    attroff(COLOR_PAIR(1));
    
    return 0;
    
}
