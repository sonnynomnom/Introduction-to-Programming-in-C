/*Space Invaders game.*/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

char board[30][30];
char board2[30];
int end = 0;
int delay = 30000;
int x;
int bullets = 3;
int alien = 0;
int level;
int y, t;
int score;
/*int scores[5];
 FILE *highscore;
 */

void setup();
void display();
void movement();
void enemy();
void down();
void down2();
void player();
void gamecheck();
void attack();
void diffcheck();

int main() {
    
    setup();
    
    do {
        movement();
        display();
        enemy();
        down();
        display();
        attack();
        display();
        attack();
        down2();
        player();
        gamecheck();
        
    } while(end == 0);
    
    endwin();
    curs_set(TRUE);
    system("clear");
    
    if(end == 1) {
        printf("\033[036m\n\n\nYou failed to stop the virus.\n\n\nThe damage done has become irreversible and your terminal is doomed. RIP.\n\n\n\n\033[0m");
        
        sleep(2);
        
        printf("\033[036mSCORE: %d\n\n\033[0m", score);
        
        /*  highscore = fopen("highscore.txt", "w");
         fprintf(highscore, "%d", score);
         fclose(highscore);
         */
        
    }
    else if(end == 2) {
        printf("\n\n\nYou beat the virus!\n\n\nYou learn that being cheap is good.\n\n\n\n\033[0m");
        
        sleep(2);
        
        score += 300;
        printf("\033[036mSCORE: %d\n\n\033[0m", score - 300);
        printf("\033[036mBONUS: %d\n\n\033[0m", 300);
        printf("\033[036mTOTAL: %d\n\n\033[0m", score);
        /*  highscore = fopen("highscore.txt", "w");
         fprintf(highscore, "%d", score);
         fclose(highscore);
         */
    }
    
    system("killall play");
    return 0;
}


// =============================================================================


void setup() {
    
    system("clear");
    
    char startgame;
    char instruct;
    char difficulty;
    
    printf("\033[035m		   ssssss  pppppp     aaa     ccccc eeeee		   \033[0m\n");
    printf("\033[035m		  s        p     p   a   a   c      e    		   \033[0m\n");
    printf("\033[035m		  s        p     p  a     a  c      e    		   \033[0m\n");
    printf("\033[035m		   ssssss  pppppp  aaaaaaaaa c      eee  		   \033[0m\n");
    printf("\033[035m		         s p       a       a c      e    		   \033[0m\n");
    printf("\033[035m		         s p       a       a c      e    		   \033[0m\n");
    printf("\033[035m		   ssssss  p       a       a  ccccc eeeee		   \033[0m\n");
    
    printf("\n");
    
    printf("\033[036miiiiiiiii  n      n  v     v     aaa    ddddd    eeeeee rrrrr     ssssss \033[0m\n");
    printf("\033[036m    i      nn     n  v     v    a   a   d    d   e      r    r   s       \033[0m\n");
    printf("\033[036m    i      n n    n  v     v   a     a  d     d  e      r     r  s       \033[0m\n");
    printf("\033[036m    i      n  n   n  v     v  aaaaaaaaa d      d e      r    r   s       \033[0m\n");
    printf("\033[036m    i      n   n  n  v     v  a       a d      d eeee   rrrrr     ssssss \033[0m\n");
    printf("\033[036m    i      n    n n   v   v   a       a d      d e      r  r            s\033[0m\n");
    printf("\033[036m    i      n     nn    v v    a       a d     d  e      r   r           s\033[0m\n");
    printf("\033[036miiiiiiiii  n      n     v     a       a dddddd   eeeeee r    r    ssssss \033[0m\n");
    
    /*  highscore = fopen("highscore.txt", "r");
     while (!feof(highscore)) {
     scanf("%d\n %d\n %d\n %d\n %d", scores[0], scores[1], scores[2], scores[3], scores[4]);
     printf("%d\n %d\n %d\n %d\n %d", scores[0], scores[1], scores[2], scores[3], scores[4]);
     }
     fclose(highscore);
     */
    
    printf("\n");
    printf("\033[032mPress 's' to see instruction: \033[0m");
    scanf("%c", &instruct);
    
    if (instruct == 's') {
        
        system("(play -q gamemusic.mp3 ) &");
        
        system("clear");
        
        printf("\033[031mIIIII N     N  SSSSS TTTTT RRRRR  U    U  CCCC TTTTT IIIII  OOO   N      N  SSSSS \033[0m\n");
        printf("\033[031m  I   NN    N S        T   R    R U    U C       T     I   O   O  NN     N S      \033[0m\n");
        printf("\033[031m  I   N N   N S        T   R    R U    U C       T     I  O     O N N    N S      \033[0m\n");
        printf("\033[031m  I   N  N  N  SSSSS   T   RRRRR  U    U C       T     I  O     O N  N   N  SSSS  \033[0m\n");
        printf("\033[031m  I   N   N N       S  T   R  R   U    U C       T     I  O     O N    N N      S \033[0m\n");
        printf("\033[031m  I   N    NN       S  T   R   R  U    U C       T     I   O   O  N     NN      S \033[0m\n");
        printf("\033[031mIIIII N     N  SSSSS   T   R    R  UUUU   CCCC   T   IIIII  OOO   N      N SSSSS  \033[0m\n");
        printf("\n");
        printf("\033[037m	1)Use A and D to move left and right\033[0m\n");
        printf("\033[037m	2)This is your spaceship 'A'\033[0m\n");
        printf("\033[037m	3)The enemies are represented by 'O's\033[0m\n");
        printf("\033[037m        4)On hard mode, enemies have shields. 'O' indicates an active shield and 'M' means that the enemy is exposed \033[0m\n");
        printf("\033[037m	5)The enemies shoot down 'U's at you. Avoid them or be terminated\033[0m\n");
        printf("\033[037m	6)You CANNOT destroy their shots\033[0m\n");
        printf("\033[037m	7)Your shots are '^' which you can use by pressing the [SPACE] key\033[0m\n");
        printf("\033[037m	8)After 3 shots, you must reload by pressing 'r'\033[0m\n");
        
        printf("\n");
        printf("\033[032mPress 's' to continue: \033[0m");
        scanf(" %c", &difficulty);
        
        
        if(difficulty == 's'){
            
            system("clear");
            
            diffcheck();
            
            printf("\033[032m\nPress 's' to play: \033[0m");
            scanf(" %c", &startgame);
            
            if(startgame == 's'){
                
                system("clear");
                
                printf("\nERROR: CORRUPT DATA.\n");
                sleep(2);
                printf("\nWARNING: MALWARE DETECTED.\n");
                sleep(2);
                printf("\033[036m\nOh no! a virus has infected your terminal!\n\033[0m");
                sleep(4);
                printf("\033[036m\nOnly you can stop the virus from spreading because you're smart and didn't install anti-virus because you're cheap af.\n\033[0m");
                sleep(5);
                printf("\033[036m\nClear the wave of invaders before they swarm your computer\n\033[0m");
                sleep(4);
                
                
                system("clear");
                
                initscr();
                noecho();
                curs_set(FALSE);
                
                int i, j;
                
                for(i = 0; i < 30; i++) {
                    for(j =0; j < 30; j++) {
                        board[i][j] = ' ';
                    }
                }
                
                for(i = 0; i < t; i++) {
                    for(j = 0; j < y; j=j+2) {
                        board[i][j + (30-y)/2] = 'O';
                        alien++;
                    }
                }
            }
            
            else {
                
                printf("\033[032m\nGame aborted. Invalid input.\n\n\033[0m");
                
                abort();
                
            }
        }
        
        else {
            
            printf("\033[032m\nGame aborted. Invalid input\n\n\033[0m");
            
            abort();
            
        }
        
    }
    else {
        
        printf("\033[032m\nGame aborted. Invalid input\n\n\033[0m");
        
        abort();
        
    }
    
    x = 14;
    board2[14] = 'A';
}

// =============================================================================

void movement() {
    
    int i, j;
    for(i = 0; i < 30; i++) {
        for(j = 30; j > 0; j--) {
            if((board[i][j] == 'O' || board[i][j] == 'M') && board[i][j+1] == ' '){
                board[i][j+1] = board[i][j];
                board[i][j] = ' ';
            }
        }
    }
}

// =============================================================================

void display() {
    
    clear();
    int i, j;
    
    for(i = 0; i < 32; i++){
        mvprintw(31, i, "_");
        mvprintw(i, 0, "|");
        mvprintw(i, 31, "|");
        mvprintw(0, i, "_");
    }
    
    for(i = 0; i < 29; i++) {
        for(j = 0; j < 30; j++) {
            mvprintw(i+1,j+1, "%c", board[i][j]);
        }
        mvprintw(29+1, i+1, "%c", board2[i]);
    }
    refresh();
    usleep(delay);
    
}

void enemy() {
    
    int i, j, r;
    
    srand(time(NULL));
    
    for(j = 0; j < 30; j++)
    {
        
        for(i = 0; i < 30; i++)
        {
            
            r = rand() % 20 + 1;
            
            if((board[i][j] == 'O' || board[i][j] == 'M') && board[i+1][j] == ' ')
            {
                
                if(r > 19)
                {
                    board[i+1][j] = 'U';
                }
                
            }
            
            
        }
        
    }
}


void down() {
    
    int i, j;
    
    
    for(j = 0; j < 30; j++)
    {
        
        for(i = 30; i < 0; i--)
        {
            
            
            if(board[i][j] == 'U' && board[i+1][j]==' ' && (board[i-1][j] == 'O' || board[i-1][j] == 'M'))
            {
                
                board[i+1][j] = 'U';
                board[i][j] = ' ';
                
            }
            
            
        }
    }
}

void down2() {
    
    int i, j;
    
    
    for(j = 0; j < 30; j++)
    {
        
        for(i = 30; i > 0; i--)
        {
            
            
            if(board[i][j] == 'U' && board[i+1][j] == ' ')
            {
                
                board[i+1][j] = 'U';
                board[i][j] = ' ';
                
            }
            else if(board[29][j] == 'U' && board2[j] != board2[x]) {
                board[29][j] = ' ';
            }
            else if(board[i][j] == 'U' && board[i+1][j] == '^') {
                board[i][j] = ' ';
                board[i+1][j] = 'U';
            }
        }
    }
}

//=============================================================================

void player() {
    
    cbreak();
    timeout(1);
    char input = getch();
    
    switch(input) {
            
        case 'a':
            break;
            
        case 'd':
            break;
            
        case ' ':
            break;
            
        case 'r':
            break;
    }
    
    
    if(board2[x] == 'A') {
        
        if(input == 'a') {
            if(x != 0){
                x--;
                board2[x] = 'A';
                board2[x+1] = ' ';
            }
        }
        if(input == 'd') {
            if(x != 28){
                x++;
                board2[x] = 'A';
                board2[x-1] = ' ';
            }
        }
        if(input == ' ' && bullets > 0 && board[28][x] != 'U') {
            board[28][x] = '^';
            bullets--;
            system("(play -q pew.mp3) &");
        }
        if(input == 'r' && bullets == 0) {
            bullets = 3;
        }
    }
}

void attack() {
    
    int i, j;
    
    for(i = 0; i < 30; i++) {
        for(j = 0; j < 30; j++) {
            if(board[i][j] == '^' && board[i-1][j] == ' ') {
                board[i][j] = ' ';
                board[i-1][j] = '^';
            }
            else if(level == 3) {
                if(board[i][j] == '^' && board[i-1][j] == 'O') {
                    board[i][j] = ' ';
                    board[i-1][j] = 'M';
                    score += 10;
                }
                else if(board[i][j] == '^' && board[i-1][j] == 'M') {
                    board[i][j] = ' ';
                    board[i-1][j] = ' ';
                    alien--;
                    score += 50;
                }
            }
            else if(board[i][j] == '^' && board[i-1][j] == 'O') {
                board[i][j] = ' ';
                board[i-1][j] = ' ';
                alien--;
                score += 50;
            }
            if(board[0][j] == '^')
                board[0][j] = ' ';
        }
    }
}

//=============================================================================

void gamecheck() {
    
    
    if(board[29][x] == 'U') {
        end = 1;
    }
    
    if(alien == 0)
        end = 2;
    
    if(board[29][29] == 'O' || board[29][29] == 'M') {
        end = 1;
    }
    
}

void diffcheck() {
    
    printf("\033[033mDDDD   IIIII FFFFF FFFFF IIIII  CCCC U     U L    TTTTT  Y     Y \033[0m\n");
    printf("\033[033mD   D    I   F     F       I   C     U     U L      T     Y   Y  \033[0m\n");
    printf("\033[033mD    D   I   F     F       I   C     U     U L      T      Y Y   \033[0m\n");
    printf("\033[033mD    D   I   FFF   FFF     I   C     U     U L      T       Y    \033[0m\n");
    printf("\033[033mD    D   I   F     F       I   C     U     U L      T       Y    \033[0m\n");
    printf("\033[033mD    D   I   F     F       I   C     U     U L      T       Y    \033[0m\n");
    printf("\033[033mD   D    I   F     F       I   C      U   U  L      T       Y    \033[0m\n");
    printf("\033[033mDDDD   IIIII F     F     IIIII  CCCC   UUU   LLLL   T       Y    \033[0m\n");
    
    printf("\033[032m\n\nChoose a play mode: 1 (Easy), 2 (Medium), 3 (Hard): \033[0m");
    scanf("%d", &level);
    
    srand(time(NULL));
    if(level == 1) {
        y = rand() % 3 + 10;
        t = rand() % 2 + 1;
        delay = 30000;
    }
    else if(level == 2) {
        y = rand() % 4 + 13;
        t = rand() % 2 + 3;
        delay = 25000;
    }
    else if(level == 3) {
        y = rand() % 4 + 17;
        t = rand() % 2 + 5;
        delay = 20000;
    }
    
    else {
        printf("\033[032m\nInvalid input, try again\033[0m\n");
        diffcheck();
    }
}