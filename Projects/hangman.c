// Week 2 Extra Credit: Hangman
// Marcus Kapoor (Columbia University)

// Instructor: Sonny Li

// gcc -lform -lncurses -Wall hangman.c -o hangman
// ./hangman

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <ctype.h>

int terminate();
int dyingimages();

int randdict;

char enter, leave;

const char *words[10] = {
    
    "computer",
    "communism",
    "mathematics",
    "macintosh",
    "lamborghini",
    "apricot",
    "dentist",
    "earthquake",
    "hexagon",
    "electricity"

};

char word[12];              // the answer word chosen from the word bank above ^
int length;                 // the length of the answer word

char letter;                // the letter user guesses

int dying = 0;              // how dead your are (once it reaches max number, you lose)

int playing = 1;
int win = 0;                // goes up to letter count (if statement will end the game by setting playing = 0)

char lettersused[26];       // every letter used, regardless of success/failure (to prevent duplicates that mess up the win counter)

// =================================================================================================================================

int main () {
    
    // ~~~~~~ Initialization: Part I ~~~~~~
    
    srand(time(NULL));
    
    initscr();              // creates a 'window' that can be edited. printw(), scanw(), refresh(), etc. are editing this 'window'
    
    printw("Welcome to Hangman! To play, press [Enter]\n");
    
    noecho();               // the terminal doesn't echo (type) what you enter. kind of like when you input a password
    
    enter = getch();        // get character
    
    while (enter != '\n')   // if the key typed is not [enter], do nothing
    {
        refresh();          // refreshes the window. needed for ncurses function. prints won't appear unless the screen is refreshed
        enter = getch();
    }
    
    move(0, 0);             // move cursor to top left of window (starting point). coordinates are (y, x) instead of (x, y)
    clrtoeol();             // clear the line (The welcome to Hangman! blah blah blah)
    
    refresh();
    
    // ~~~~~~ Initialization: Part 2 ~~~~~~
    
    mvprintw(1, 27, "===========================");     // mvprintw prints a line at specific coordinates
    mvprintw(2, 27, "       !! HANGMAN !!       ");
    mvprintw(3, 27, "===========================");
    
    dyingimages();                                      // function that displays the hangman images (separated to reduce clutter)
    
    mvprintw(14, 0, "================================================================================");
    
    mvprintw(16, 0, "Attempted Letters: ");             // the area where your failed letters appear
    refresh();
    
    randdict = rand() % 10;                             // random #
    strcpy(word, words[randdict]);                      // copy random word from dictionary to word. limit to first run through
    
    // mvprintw(35, 0, "%s\n\n", word);                 // prints the chosen word (testing purposes only)
    
    refresh();
    
    length = strlen(word);                              // find length of word
    
    char reveal[length];                                // create an array of the size of the length of the word
    
    for (int i = 0; i < length; i++) {                  // set the # of blanks for the word

        reveal[i] = '_';
        
    }
    
    reveal[length] = '\0';                              // terminating character (if not for this, the blanks would be inaccurate)
    
    mvprintw(18, 0, "I'm thinking of a word: ");        // prints the '_' string that was set up just before
    
    // note to me: if necessary, use a similar for loop to put spaces between the reveal (_ _ _ _ _) above to make it more legible
    
    for (int i = 0; i < length; ++i) {
        
        printw("%c ", reveal[i]);
    
    }
    
    // ~~~~~~ Game Starts ~~~~~~
    
    while (playing == 1) {
        
        move(19,0);
        clrtoeol();
        
        mvprintw(19, 0, "Guess a letter: ");
        echo();                                         // reenables echo (disabled in the first initialization)
        refresh();
        
        scanw("%1c", &letter);                          // the letter you choose
        letter = tolower(letter);                       // decapitalize the letter ('a' != 'A')
        
        refresh();
        noecho();
        
        int yes = 0;                                    // do letters match? 0 = false 1 = true
        
        for (int i = 0; i < length; i++) {              // compares letter guessed to every character within the random word
            
            if (letter == word[i] && lettersused[i] != letter) {
                
                // if one or more of the letters match, reveal the letter, set yes = 1, and win++
                
                reveal[i] = letter;
                lettersused[i] = letter;                // this is to prevent the person from entering the same character again
                                                        // otherwise, it messes with the win counter
                move(18, 24);
                
                for (int i = 0; i < length; ++i) {
                    
                    printw("%c ", reveal[i]);           // prints the new reveal array with the added character and spaces
                
                }
                
                yes = 1;
                win++;
                
                refresh();
            
            }
            
        }
        
        char aletters[6];
        
        if (yes != 1){                                  // if letters do not match, then print attempted letter
            
            aletters[dying] = letter;                   // if dying is 0, the letter will be put in the 1st index of the attempt array
                                                        // dying determines index
            
            aletters[dying+1] = '\0';                   // terminates the string so that the weird null characters don't show up
            
            mvprintw(16, 0, "Attempted Letters: ");
            
            // note to me: if necessary, use a similar for loop to put spaces between the reveal to make it more legible
            
            for (int i = 0; i < 7; ++i) {
                
                printw("%c ", aletters[i]);
            
            }
            
            dying++;                                    // dying counter goes up
            
            dyingimages();                              // the image displayed is based on the dying counter
                                                        // 0 = hanger only; 1 = head; 2 = head and neck, etc.
        
        }
        
        refresh();
        
        // if the dying counter is equal to 7, you lose
        // if the win counter is equal to the word's length, you win (this exits the overarching while loop)
        
        if (dying == 7 || win == length) {
            
            playing = 0;
            
        }
        
    }
    
    // end of the while (it will keep repeating 'til the win/lose if statements inside are satisfied)
    
    if (win == length) {
        
        mvprintw(21, 0, "You win!\n");
        terminate();
    
    }
    else if (dying == 7) {
        
        mvprintw(21, 0, "You let the poor man die! Shame on you.");
        mvprintw(22, 0, "The word you were looking for was: %s.", word);
        terminate();
        
    }
    else {
        
        mvprintw(21, 0, "Gah. You broke the game. Say sorry!\n");
        terminate();
    
    }
    
    return 0;

}

// =================================================================================================================================

int terminate () {

    mvprintw(24, 0, "Press [Q] to Quit\n");
    
    leave = getch();
    leave = tolower(leave);
    
    refresh();
    
    while (leave != 'q') {
        
        leave = getch();
        leave = tolower(leave);
    
    }
    
    endwin();
    
    return 0;
    
}

// =================================================================================================================================

int dyingimages () {
    
    if (dying == 0) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]          ");
        mvprintw(8 ,31, "    [][]          ");
        mvprintw(9 ,31, "    [][]          ");
        mvprintw(10,31, "    [][]          ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 1) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]          ");
        mvprintw(10,31, "    [][]          ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
        // if it was just your head hanging, wouldn't you be deader than if your full body was hanging? #logic
        
    }
    else if (dying == 2) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]     |    ");
        mvprintw(10,31, "    [][]          ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 3) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]    \\|   ");
        mvprintw(10,31, "    [][]          ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 4) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]    \\|/  ");
        mvprintw(10,31, "    [][]          ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 5) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]    \\|/  ");
        mvprintw(10,31, "    [][]     |    ");
        mvprintw(11,31, "    [][]          ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 6) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]    \\|/  ");
        mvprintw(10,31, "    [][]     |    ");
        mvprintw(11,31, "    [][]    /     ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else if (dying == 7) {
        
        mvprintw(5 ,31, "  [][][][][][][]  ");
        mvprintw(6 ,31, "  [][][][][][][]  ");
        mvprintw(7 ,31, "    [][]     |    ");
        mvprintw(8 ,31, "    [][]     0    ");
        mvprintw(9 ,31, "    [][]    \\|/  ");
        mvprintw(10,31, "    [][]     |    ");
        mvprintw(11,31, "    [][]    / \\  ");
        mvprintw(12,31, "    [][]          ");
        mvprintw(13,31, "[][][][][][][][][]");
    
    }
    else {
        
        mvprintw(13, 31, "You broke the game. Bugs suck :(");
    
    }
    
    return 0;

}
