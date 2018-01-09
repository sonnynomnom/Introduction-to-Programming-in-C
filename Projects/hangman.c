// Hangman
// Marcus Kapoor

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

char word[12];          // the answer word chosen from the word bank above ^
int length;             // the length of the answer word

char letter;            // the letter user guesses

int dying = 0;          // how dead your are (once counter reaches max number, you lose)

int playing = 1;
int win = 0;            // goes up to letter count. if statement will end the game by setting playing = 0

char lettersused[26];   // every letter used, regardless of success or failure (needed to stop duplicates that mess up the win counter)

// =========================================================================================================================================

int main () {
    
    // Initialization: Part 1
    
    srand(time(NULL));
    
    initscr();              // creates a window/image that can be edited. printw, scanw, refresh, etc. are editing this 'window'
    
    printw("Welcome to Hangman! To play, press [Enter]\n" );
    
    noecho();               // the terminal doesn't echo (type) what you enter. Kind of like when you input a password.
    enter = getch();        // get character typed. Like scanf()
    
    while (enter != '\n')   // if key typed is not entered, do nothing.
    {
        refresh();          // refreshes the screen/window. needed for ncurses function. prints won't appear unless the screen is refreshed.
        enter = getch();
    }
    
    move(0, 0);              // move cursor to top left of window (starting point). coordinates are (y,x) instead of (x,y)
    clrtoeol();             // clear the line (The welcome to Hangman! blah blah blah)
    refresh();
    
    // Initialization: Part 2
    
    mvprintw(1, 27, "===========================");     // mvprintw prints a line at specific corrdinates
    mvprintw(2, 27, "       !! HANGMAN !!       ");
    mvprintw(3, 27, "===========================");
    
    dyingimages();                                      // function that displays the hangman images (separated to reduce clutter)
    
    mvprintw(14, 0, "================================================================================");
    
    mvprintw(16, 0, "Attempted Letters: ");              // the area where your failed letters appear
    refresh();
    
    randdict = rand() % 10;                             // random #
    strcpy(word, words[randdict]);                      // copy random word from dictionary to word. limit to first run through
    
    // mvprintw(35, 0, "%s\n\n", word);                   // prints the chosen word (testing purposes only)
    
    refresh();
    
    length = strlen(word);                              // find length of word.
    char reveal[length];                                // create an array of the size of the length of the word
    
    int i;
    
    for (i = 0; i < length; i++)                        // set the # of blanks for the word
    {
        reveal[i] = '_';
    }
    
    reveal[length] = '\0';                              // terminating character (if not for this, the blanks later on would be inaccurate)
    
    mvprintw(18,0,"I'm thinking of a word: ");          // prints the '_' string that was set up just before
    
    for (int i = 0; i < length; ++i)
    {
        printw("%c ", reveal[i]);                       // notetome: if necessary, use a similar for loop to put spaces between the reveal (_ _ _ _ _) above to make it more legible.
    }
    
    
    // Game
    
    while (playing == 1) {
        
        move(19,0);
        clrtoeol();
        
        mvprintw(19,0,"Guess a letter: ");
        echo();                                         // reenables echo (disabled in the first initialization)
        refresh();
        
        scanw("%1c", &letter);                          // the letter you choose
        letter = tolower(letter);                       // decapitalize the letter if necessary so that when comparisons are made I don't have to do more work ('a' != 'A')
        refresh();
        noecho();
        
        int yes = 0;                                    // do letters match? 0 = false 1 = true
        
        for (i = 0; i < length; i++)                    // The for loop checks every character within the random word and compares it to the letter typed
        {
            
            if (letter == word[i] && lettersused[i] != letter)
            {
                // if one or more of the letters match, reveal the letter, set yes = 1, and win++
                
                reveal[i] = letter;
                lettersused[i] = letter;                // this is to prevent the person from entering the same character again. Otherwise, it messes with the win counter and win is invoked even if you still have characters missing.
                move(18,24);
                
                for (int i = 0; i < length; ++i)
                {
                    printw("%c ", reveal[i]);           // prints the new reveal array with the added character and spaces in between.
                }
                
                yes = 1;
                win++;
                refresh();
            
            }
            
        }
        
        char aletters[6];
        
        if (yes != 1){                                  // if letters do not match, then print attempted letter
            aletters[dying] = letter;                   // if dying is 0, the letter will be put in the first index of the attempt array. dying determines index.
            aletters[dying+1] = '\0';                  // terminates the string so that the weird null characters don't show up.
            mvprintw(15, 0, "Attempted Letters: ");
            
            for (int i = 0; i < 7; ++i)
            {
                printw("%c ", aletters[i]);             // notetome: if necessary, use a similar for loop to put spaces between the reveal (_ _ _ _ _) above to make it more legible.
            }
            
            dying++;                                    // dying counter goes up
            
            dyingimages();                              // the image displayed is based on the dying counter. 0 = hanger only; 1 = head; 2 = head and neck, etc.
        
        }
        
        refresh();
        
        if (dying == 7 || win == length) {              // if the dying counter is equal to 7, you lose. if the win counter is equal to the words length, you win (This exits the overarching while loop.)
            playing = 0;
        }
    }                                                   // this is the end of the while loop. It will keep repeating until the win or lose if statements inside are satisfied.
    
    
    if (win == length) { //determines if you won or lost when you exit the while loop.
        
        mvprintw(21, 0, "You win!\n");
        
        terminate();
    
    }
    else if (dying == 7) {
        
        mvprintw(21, 0, "You let the poor man die! Shame on you.\nThe word you were looking for was '%s'.\n", word);
        
        terminate();
        
    }
    
    else {
        
        mvprintw(21, 0, "Gah. You broke the game. Say sorry\n");
        
        terminate();
    
    }
    
    return 0;

}


// =========================================================================================================================================

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

int dyingimages () {
    
    if (dying == 0) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]        ");
        mvprintw(8 ,32, "    [][]        ");
        mvprintw(9 ,32, "    [][]        ");
        mvprintw(10,32, "    [][]        ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 1) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]        ");
        mvprintw(10,32, "    [][]        ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
        // if it was just your head hanging, wouldn't you be deader than if your full body was hanging? #logic
        
    }
    else if (dying == 2) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]     |  ");
        mvprintw(10,32, "    [][]        ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 3) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]    \\| ");
        mvprintw(10,32, "    [][]        ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 4) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]    \\|/");
        mvprintw(10,32, "    [][]        ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 5) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]    \\|/");
        mvprintw(10,32, "    [][]     |  ");
        mvprintw(11,32, "    [][]        ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 6) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]    \\|/");
        mvprintw(10,32, "    [][]     |  ");
        mvprintw(11,32, "    [][]    /   ");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else if (dying == 7) {
        
        mvprintw(5 ,32, "  [][][][][][][]");
        mvprintw(6 ,32, "  [][][][][][][]");
        mvprintw(7 ,32, "    [][]     |  ");
        mvprintw(8 ,32, "    [][]     0  ");
        mvprintw(9 ,32, "    [][]    \\|/");
        mvprintw(10,32, "    [][]     |  ");
        mvprintw(11,32, "    [][]    / \\");
        mvprintw(12,32, "    [][]        ");
        mvprintw(13,32, "[][][][][][][][]");
    
    }
    else {
        
        mvprintw(13, 32, "You broke the game. Bugs suck :(");
    
    }
    
    return 0;

}
