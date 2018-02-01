// Week 2 Project: Matching Game
// Team OG Trio
// Louie Kotler, Simone Stern & Chris Narducci (Columbia University)

// Instructor: Sonny Li

// gcc -lform -lncurses -Wall matching.c -o matching
// ./matching

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>

void reload();
int terminate();

// =========================================================================================================

int main () {
    
    // ~~~~~~ Initialization: Part I ~~~~~~
    
    srand(time(NULL));
    
    initscr();              // creates a 'window' that can be edited. printw(), scanw(), refresh(), etc. are editing this 'window'
    
    mvprintw(0, 0, "Matching Game! To play, press [Enter]\n");
    
    noecho();               // the terminal doesn't echo (type) what you enter. kind of like when you input a password
    
    char enter;
    
    enter = getch();        // get character
    
    while (enter != '\n')   // if the key typed is not [enter], do nothing
    {
        refresh();          // refreshes the window. needed for ncurses function. prints won't appear unless the screen is refreshed
        enter = getch();
    }
    
    move(0, 0);             // move cursor to top left of window (starting point). coordinates are (y, x) instead of (x, y)
    clrtoeol();             // clear the line (Matching Game! blah blah blah)
    
    refresh();
    
    // ~~~~~~ Initialization: Part 2 ~~~~~~
    
    // mvprintw(0, 0,"=============================\n");
    // mvprintw(1, 0,"        Matching Game        \n");
    // mvprintw(2, 0,"=============================\n\n");
    //
    // refresh();
    
    // ---------------------------------------------------------------------------------------------------------
    
    // covered displayed
    
    char array1[4][4] = {{'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}, {'*', '*','*','*'}};
    
    int x = 0;
    
    // make arr2[16] a randomized answer
    
    char arr[16] = {'!', '@', '#', '$','#', '$', '%', '^','@', '^', '!', '&','=', '%', '=', '&'};
    
    char arr2[16] = {'0', '0', '0', '0','0', '0', '0', '0','0', '0', '0', '0', '0', '0', '0', '0'};
    
    while (x < 16) {
        
        int r = rand() % 16;
        
        if (arr[r] != '0') {
            
            arr2[x] = arr[r];
            arr[r] = '0';
            x++;
        
        }
        
    }
    
    // plug arr2[ 16] -> array2[4][4]
    
    char array2[4][4] = {{'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}};
    
    int count = 0;
    
    for (int y = 0; y < 4; y++) {
        
        for (int z = 0; z < 4; z++) {
            
            array2[y][z] = arr2[count];
            count++;
        
        }
    
    }
    
    // ---------------------------------------------------------------------------------------------------------
    
    int running = 1;
    int counterfull = 0;
    
    while (running) {
        
        int ent1 = 0, ent2 = 0, ent3 = 0, ent4 = 0;
        
        initscr();
        
        // reload();
        
        mvprintw(0, 0, "=============================\n");
        mvprintw(1, 0, "        Matching Game        \n");
        mvprintw(2, 0, "=============================\n\n");
        refresh();
        
        mvprintw(5, 0, "      \\   1   2   3   4     \n\n");
        refresh();
        
        mvprintw(8,  0, "      1   %c   %c   %c   %c", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
        mvprintw(11, 0, "      2   %c   %c   %c   %c", array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
        mvprintw(14, 0, "      3   %c   %c   %c   %c", array1[2][0], array1[2][1], array1[2][2], array1[2][3]);
        mvprintw(17, 0, "      4   %c   %c   %c   %c", array1[3][0], array1[3][1], array1[3][2], array1[3][3]);
        refresh();
        
        // sleep(3);
        
        mvprintw(20, 0,"Enter Coordinate 1 (x y): ");
        
        echo();
        refresh();
        
        scanw("%d %d", &ent1, &ent2);
        
        while (ent1 < 1 || ent1 > 4 || ent2 < 1 || ent2 > 4) {
            
            mvprintw(20, 0,"Enter Coordinate 1 (x y): ");
            
            echo();
            refresh();
            
            scanw("%d %d", &ent1, &ent2);
            
        }
        
            
        refresh();
        echo();
        
        refresh();
        
        mvprintw(21, 0,"Enter Coordinate 2 (x y): ");
        
        echo();
        refresh();
        
        scanw("%d %d", &ent3, &ent4);
        
        while (ent3 < 1 || ent3 > 4 || ent4 < 1 || ent4 > 4) {
            
            mvprintw(21, 0, "Enter Coordinate 2 (x y): ");
            
            echo();
            refresh();
            
            scanw("%d %d", &ent3, &ent4);
            
        }
        
        
        refresh();
        
        noecho();
        refresh();
        
        ent1 -= 1;
        ent2 -= 1;
        ent3 -= 1;
        ent4 -= 1;
        
        memcpy(&array1[ent1][ent2], &array2[ent1][ent2], 1);
        memcpy(&array1[ent3][ent4], &array2[ent3][ent4], 1);
        
        // sleep(3);
        
        mvprintw(5,  0, "      \\   1   2   3   4     \n\n");
        
        mvprintw(8,  0, "      1   %c   %c   %c   %c", array1[0][0], array1[0][1], array1[0][2], array1[0][3]);
        mvprintw(11, 0, "      2   %c   %c   %c   %c", array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
        mvprintw(14, 0, "      3   %c   %c   %c   %c", array1[2][0], array1[2][1], array1[2][2], array1[2][3]);
        mvprintw(17, 0, "      4   %c   %c   %c   %c", array1[3][0], array1[3][1], array1[3][2], array1[3][3]);
        
        echo();
        refresh();
        
        // WIN
        
        if (array1[ent1][ent2] == array1[ent3][ent4]) {
            
            if (ent1 != ent3 || ent2 != ent4) {
                
                running = 0;
                
                mvprintw(0, 0, "=============================\n");
                mvprintw(1, 0, "        Matching Game        \n");
                mvprintw(2, 0, "=============================\n\n");
                refresh();
                
                mvprintw(5, 0, "      \\   1   2   3   4     \n\n");
                refresh();
                
                mvprintw(8,  0, "      1   %c   %c   %c   %c", array2[0][0], array2[0][1], array2[0][2], array2[0][3]);
                mvprintw(11, 0, "      2   %c   %c   %c   %c", array2[1][0], array2[1][1], array2[1][2], array2[1][3]);
                mvprintw(14, 0, "      3   %c   %c   %c   %c", array2[2][0], array2[2][1], array2[2][2], array2[2][3]);
                mvprintw(17, 0, "      4   %c   %c   %c   %c", array2[3][0], array2[3][1], array2[3][2], array2[3][3]);
                refresh();
                
                mvprintw(21, 0, "You got it! Nice!\n");
                
                // terminate();
                // endwin();
                
                system("clear");
                
            }
            
        }
        
        // here is refresh
        
        array1[ent1][ent2]= '*';
        array1[ent3][ent4]= '*';
    
        counterfull++;
        
        mvprintw(23, 0, "Guesses Left: %d", 5-counterfull);
        
        if (counterfull >= 5) {
            
            running = 0;
            
            mvprintw(0, 0, "=============================\n");
            mvprintw(1, 0, "        Matching Game        \n");
            mvprintw(2, 0, "=============================\n\n");
            refresh();
            
            mvprintw(5, 0, "      \\   1   2   3   4     \n\n");
            refresh();
            
            mvprintw(8,  0, "      1   %c   %c   %c   %c", array2[0][0], array2[0][1], array2[0][2], array2[0][3]);
            mvprintw(11, 0, "      2   %c   %c   %c   %c", array2[1][0], array2[1][1], array2[1][2], array2[1][3]);
            mvprintw(14, 0, "      3   %c   %c   %c   %c", array2[2][0], array2[2][1], array2[2][2], array2[2][3]);
            mvprintw(17, 0, "      4   %c   %c   %c   %c", array2[3][0], array2[3][1], array2[3][2], array2[3][3]);
            refresh();
            
            mvprintw(19, 0, "\nYou ran out of guesses, bruh ur stupid.\n");
            
            system("clear");
            
        }
        
        refresh();
        
        reload();
        
    }

    terminate();
    
    return 0;

}

// ====================================================================================================

void reload() {
    
    char enter;
    
    noecho();
    
    enter = getch();
    
    while (enter != '\n') {
        
        refresh();
        enter = getch();
    
    }
    
    move(0, 0);
    
    for (int i = 0; i < 100; i++) {
        
        for (int j = 0; j < 100; j++) {
            
            printw(" ");
        
        }
        
        printw("\n");
    
    }
    
    move(0, 0);

    clrtoeol();
    refresh();

}

// ====================================================================================================

int terminate () {
    
    char leave;
    
    mvprintw(22, 0, "To quit, press [q]\n");
    
    leave = getch();
    leave = tolower(leave);
    
    refresh();
    
    while (leave != 'q') {
        
        leave = getch();
        leave = tolower(leave);
        endwin();
    
    }
    
    endwin();
    
    return 0;
    
}
