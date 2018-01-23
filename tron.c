//Marcus
#include <stdio.h>
#include <ncurses.h> //REMEMBER TO LINK THIS IN GCC (-lform -lncurses)
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h> //REMEMBER TO LINK THIS IN GCC (-pthread)

//Should we prevent accidental deaths when a person attempts to press a key that goes in the opposite direction they are printing?


void menu();
void customizations();  //switch statement to names. Player 1, What is your name!?!??!?!?!??!??!?!??!? fgets(hdjbjvblv) = variablename | PLayer 2 same. 
void instructions();
void bike(int position);
void terminate();

struct numbers //I'll be using this for coordinates in the main and background thread. 
{
	int x;
	int y;
};

int speed = 100; //speed the game will be played at. Edited in customizations function
int gamemode; //5 rounds, 10 rounds, infinite until quit. Edited in customizations function
int gamemodecounter = 0;
int pick; //color choice, edited in customizations function. 
int pick2;


int animationcounter = 0; //makes sure that animation doesn't happen again, wasting time, if one of the options is accessed.
char arrow = '0';

struct numbers coordinates1[3233]; 
struct numbers coordinates2[3233];
struct numbers dimensions;

int score1 = 0, score2 = 0; //player 1 score, player 2 score.
char player1name[10];
char player2name[10];

   int w,a,s,d; // Controls 1
   int i,j,k,l; // Controls 2

   int z = 0; 

int gamecounter = 0;
int main()
{
   dimensions.x = 136;
   dimensions.y = 53;

   int initialy = 1, initialx = 1;
   int initialwhy = dimensions.y - 2, initialex = dimensions.x - 3; 

   int x = initialx, y = initialy; //Coordinates 1. They are initially equal to their initial counterparts, but will change while playing. 
   int ex = initialex, why = initialwhy; //Coordinates 2 (x y are already taken in struct and naming them x2 y2 would be confusing because it indicates a relationship)
   
   int playing = 1;
	printf("\e[8;%d;%dt", dimensions.y+4, dimensions.x); //resize the terminal window. MacOS only. Makes my life easier. Don't ask me how it works, idk.


   if (gamecounter == 0)
   {
      system("afplay music.mp3 & "); //LET THERE BE MUSIC
   }
   


	initscr(); 
   sleep(1);
		

   start_color();
      init_pair(1, COLOR_RED, COLOR_BLACK); //3rd argument is the background color (highlight). -1 is the default background for the terminal.
      init_pair(2, COLOR_GREEN, COLOR_BLACK);
      init_pair(3, COLOR_YELLOW, COLOR_BLACK);
      init_pair(4, COLOR_BLUE, COLOR_BLACK);
      init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
      init_pair(6, COLOR_CYAN, COLOR_BLACK);
      init_pair(7, COLOR_WHITE, COLOR_BLACK);
      init_pair(8, COLOR_RED, COLOR_BLACK); //use this
      init_pair(9, COLOR_BLUE, COLOR_BLACK); //use this
      init_pair(10, COLOR_CYAN, COLOR_BLACK); //use this
      init_pair(11, COLOR_YELLOW, COLOR_BLACK); //use this
    

      clear();
      refresh(); 

   curs_set(0); //sets the cursor to invisible
   noecho();
   menu(); //<-- MENU FUNCTION HERRERHEREE
   cbreak();

 


	
   gamemodecounter = 1;
//everything below this shall restart 
   restart:
   gamemodecounter++;
   flushinp();
   timeout(speed);
   arrow = '0';
   refresh();
   w = 0;
   a = 0;
   s = 0;
   d = 0;
   i = 0;
   j = 0;
   k = 0;
   l = 0;

   if (score1 != 0 || score2 != 0)
   {
      initscr();
   }
   z = 0;

    x = initialx;
    y = initialy; 
    ex = initialex;
    why = initialwhy;
 
   
   cbreak();
  
    WINDOW *play;

   play = newwin(dimensions.y, dimensions.x, 0, 0);
   box(play, 0 , 0);      


   wrefresh(play);  

  WINDOW *score;

   score = newwin(5, dimensions.x, dimensions.y-1, 0);
   box(score, 0 , 0); 

   if (gamemode > 10)
   {
   mvwprintw(score,1,59, "Round %d of Infinity", gamemodecounter);
   }
   else {
   mvwprintw(score,1,61, "Round %d of %d", gamemodecounter, gamemode);
   }

   mvwprintw(score, 2,2,  "%s: %d", player1name, score1 );
   mvwprintw(score,2, dimensions.x-6-strlen(player2name), "%s: %d",player2name, score2);

   wrefresh(score);   


   attron(COLOR_PAIR(pick));
   attron(A_BOLD);
   mvprintw(y,x, "[]");
   attroff(COLOR_PAIR(pick));
   attron(COLOR_PAIR(pick2));
   mvprintw(why,ex, "[]");
   attroff(COLOR_PAIR(pick2));


   for (int i = 0; i < 1000; ++i) //Sets all the collision coordinates to some far off place from the screen so that they don't interfere when unwritten. 
   {
      coordinates1[i].x = 1000000;
      coordinates1[i].y = 1000000;
      coordinates2[i].x = 1000000;
      coordinates2[i].y = 1000000;

   }



	refresh();
   while (arrow != 'q' && playing == 1 && gamemodecounter <= gamemode)
   {

         coordinates1[z].x = x;
   		coordinates1[z].y = y; 

   		coordinates2[z].x = ex;
   		coordinates2[z].y = why; 



        if (z == 0) {

            arrow = 's';

          }

          else if (z == 1)
          {
             arrow = 'i';
          }
          else if (z > 3)
          {

             arrow = getch();
             
                 
          }


          


         switch (arrow)
         {

            case 'w':

               if (s)
               {
               w=0;
               a=0;
               s=1;
               d=0;
               }
               else
               {
               w=1;
               a=0;
               s=0;
               d=0;
               }
               break;
            case 'a':
               if (d)
               {
               w=0;
               a=0;
               s=0;
               d=1;
               }
               else{
               w=0;
               a=1;
               s=0;
               d=0;
               }
               break;
            case 's':
               if (w)
               {
               w=1;
               a=0;
               s=0;
               d=0;
               }
               else {
               w=0;
               a=0;
               s=1;
               d=0;
               }
               break;
            case 'd':
               if (a)
               {
               w=0;
               a=1;
               s=0;
               d=0;
               }
               else {
               w=0;
               a=0;
               s=0;
               d=1;
               }
               break;

            case 'i':
               if (k)
               {
               i=0;
               j=0;
               k=1;
               l=0;
               }
               else {
               i=1;
               j=0;
               k=0;
               l=0;
               }
               break;
            case 'j':
               if (l)
               {
               i=0;
               j=0;
               k=0;
               l=1;
               }
               else {
               i=0;
               j=1;
               k=0;
               l=0;
               }
               break;
            case 'k':
               if (i)
               {
               i=1;
               j=0;
               k=0;
               l=0;
               }
               else {
               i=0;
               j=0;
               k=1;
               l=0;
               }
               break;
            case 'l':
               if (j)
               {
               i=0;
               j=1;
               k=0;
               l=0;  
               }
               else{
               i=0;
               j=0;
               k=0;
               l=1;
               }
               break;

            case 'q':
               //terminate();
               arrow = 'q'; 
               break;

            default:
               break;

         }

         if (w)
         {
            y--;
              
         }
         if (a)
         {
            x--;
            x--;
         }
         if (s)
         {
            y++;
         }
         if (d)
         {
            x++;
            x++;
               
         }
         if (i)
         {
            why--;
              
         }
         if (j)
         {
            ex--;
            ex--;
         }
         if (k)
         {
            why++;
         }
         if (l)
         {
            ex++;
            ex++;
               
         }

         attron(COLOR_PAIR(pick));
         attron(A_BOLD);
         mvprintw(y,x, "[]");
         attroff(COLOR_PAIR(pick));
         attron(COLOR_PAIR(pick2));
         mvprintw(why,ex, "[]");
         attroff(COLOR_PAIR(pick2));
         attroff(A_BOLD);
         refresh();



         if (z > 0) {

   		for (int i = 0; i <= z; ++i) 
   		{
            if ( ( (x < 1 || x > dimensions.x-2 || y < 1 || y > dimensions.y-2) || (x == coordinates1[i].x && y == coordinates1[i].y) || (x == coordinates2[i].x && y == coordinates2[i].y )  )  && ( (ex < 1 || ex > dimensions.x-2 || why < 1 || why > dimensions.y-2) || (ex == coordinates1[i].x && why == coordinates1[i].y) || (ex == coordinates2[i].x && why == coordinates2[i].y ) ) )
            {
               mvprintw(y-5,x-9,"       _.-._");
               mvprintw(y-4,x-9,"      ({  ` )");
                 mvprintw(y-3,x-9,"       ` |''   *WHAM!*");
              mvprintw(y-2,x-9,"        \\_/");
               mvprintw(y-1,x-9," .(      |      ),");
               mvprintw(y,x-9,"`  -----' `-----  ' ");

               mvprintw(why-5,ex-9,"       _.-._");
               mvprintw(why-4,ex-9,"      ({  ` )");
                 mvprintw(why-3,ex-9,"       ` |''   *WHAM!*");
              mvprintw(why-2,ex-9,"        \\_/");
               mvprintw(why-1,ex-9," .(      |      ),");
               mvprintw(why,ex-9,"`  -----' `-----  ' ");

               refresh();
               system("afplay explosion.wav &");

               wattron(score, A_BLINK);
               wattron(score,A_BOLD);
               mvwprintw(score,1,59, "Both players died this round!                    "); //the extra spaces are here so that "Round X of Y" is deleted, without using clear line, breaking the box
               wattroff(score,A_BLINK);
               wattroff(score,A_BOLD);
               wrefresh(score);
               sleep(3);
               clear();
               goto restart;
               playing = 0;
              



            }
   			if ( (x < 1 || x > dimensions.x-2 || y < 1 || y > dimensions.y-2) || (x == coordinates1[i].x && y == coordinates1[i].y) || (x == coordinates2[i].x && y == coordinates2[i].y ) 		)
   			{
               mvprintw(y-5,x-9,"       _.-._");
               mvprintw(y-4,x-9,"      ({  ` )");
                 mvprintw(y-3,x-9,"       ` |''   *WHAM!*");
              mvprintw(y-2,x-9,"        \\_/");
               mvprintw(y-1,x-9," .(      |      ),");
               mvprintw(y,x-9,"`  -----' `-----  ' ");
               refresh();
               system("afplay explosion.wav &");

               
               wattron(score, A_BLINK);
               wattron(score,A_BOLD);
               mvwprintw(score,1,59, "%s won this round!              ", player2name);
               wattroff(score,A_BLINK);
               wattroff(score,A_BOLD);
               mvwprintw(score, 2,2,  "%s: %d", player1name, score1 );
               mvwprintw(score,2, dimensions.x-6-strlen(player2name), "%s: %d",player2name, score2);
               wrefresh(score);
               sleep(3);
               score2++;
               clear();
               goto restart;
   				playing = 0;	
   			} 
            else if ( (ex < 1 || ex > dimensions.x-2 || why < 1 || why > dimensions.y-2) || (ex == coordinates1[i].x && why == coordinates1[i].y) || (ex == coordinates2[i].x && why == coordinates2[i].y )    )
            {
               
               mvprintw(why-5,ex-9,"       _.-._");
               mvprintw(why-4,ex-9,"      ({  ` )");
                 mvprintw(why-3,ex-9,"       ` |''   *WHAM!*");
              mvprintw(why-2,ex-9,"        \\_/");
               mvprintw(why-1,ex-9," .(      |      ),");
               mvprintw(why,ex-9,"`  -----' `-----  ' ");
               refresh();
               system("afplay explosion.wav &");

               wattron(score,A_BLINK);
               wattron(score,A_BOLD);
               mvwprintw(score,1,59, "%s won this round!              ", player1name);
               wattroff(score,A_BLINK);
               wattroff(score,A_BOLD);
               mvwprintw(score, 2,2,  "%s: %d", player1name, score1 );
               mvwprintw(score,2, dimensions.x-6-strlen(player2name), "%s: %d",player2name, score2);
               wrefresh(score);
               
               sleep(3);
               score1++;
               clear();
               goto restart;
               playing = 0;
            }

   		}

   	  	  }

         z++;

   }

   flushinp();
   clear();
   timeout(-1);
   attron(COLOR_PAIR(10));
   mvprintw(2,25,"  ######      ###    ##     ## ########     #######  ##     ## ######## ########  ");
   mvprintw(3,25," ##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ## ");
   mvprintw(4,25," ##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ## ");
   mvprintw(5,25," ##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ########  ");
   mvprintw(6,25," ##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##   ");
   mvprintw(7,25," ##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ##  ");
   mvprintw(8,25,"  ######   ##     ## ##     ## ########     #######     ###    ######## ##     ## ");
   mvprintw(9,25,"=================================================================================");
   refresh();

   if (score1 > score2 )
   {
      mvprintw(12,55, "%s won the Game! ", player1name);
   }
   else if (score2 > score1)
   {
      mvprintw(12,55, "%s won the Game! ", player2name);
   }
   else
   {
      mvprintw(12,59, "It was a tie! ");
   } 
//------------
noecho();
attron(A_UNDERLINE);

mvprintw(16, 59, "Continue?"); 

attroff(A_UNDERLINE);

mvprintw(18, 59, "Quit");

char selecta= '0'; //controls getch
int selectb = 2; //controls progression to selected screen. 
int gb = 0;


while (gb == 0) {
   cbreak();
   selecta= getch();

   if (selecta== 's' && selectb != 2)
   {
      system("afplay menuselect.wav & ");
      selectb++; 
   }
   else if (selecta== 'w' && selectb != 1)
   {
      system("afplay menuselect.wav & ");
      selectb--;
   }
   
   switch (selectb){

      case 1:
         attron(A_UNDERLINE);
         mvprintw(16, 59, "Continue?"); 
         attroff(A_UNDERLINE);
         mvprintw(18, 59, "Quit");


         break;
      case 2:
         mvprintw(16, 59, "Continue?"); 
         attron(A_UNDERLINE);
         mvprintw(18, 59, "Quit");
         attroff(A_UNDERLINE); 

         break;

   }
         if (selecta== '\n')
         {
            system("afplay menuenter.wav &");
            gb = 1;         }



}
         switch(selectb) {

         case 1: 
               gamecounter++;
               main();
            break; 
         case 2: 
            terminate();
            break;


         }

//------------
   nocbreak();
   getch();

   terminate();
	return 0;
}
// END OF MAIN-----------------------------------------------------------------------------

void menu() {
   clear();
   refresh();
      attron(COLOR_PAIR(2));
      attron(A_BOLD);

//-------------Put Jacob's Animation Code here

   refresh();


attron(COLOR_PAIR(10)); 
mvprintw(2,3,  " _____         __________________");
mvprintw(3,3,  "|:::::|      _|::::::::::::::::::"); 
mvprintw(4,3,  "|:::::|   __|::::::::::::::::::::"); 
mvprintw(5,3,  " -----  _|::::::   ______________");      
mvprintw(6,3,  "        |::::::::::|        ");
mvprintw(7,3,  "        |::::::::::|       ");
mvprintw(8,3,  "        |::::::::::|        ");
mvprintw(9,3,  "        |::::::::::|       ");
mvprintw(10,3, "        |::::::::::|        ");
mvprintw(11,3, "        |::::::::::|        ");
mvprintw(12,3, "        |::::::::::|        ");
mvprintw(13,3, "        |::::::::::|        ");
mvprintw(14,3, "        |::::::::::|      ");
mvprintw(15,3, "        |::::::::::|      ");
mvprintw(16,3, "        |::::::::::|        ");
mvprintw(17,3, "         ----------      ");
attroff(COLOR_PAIR(10));

attron(COLOR_PAIR(10)); 
mvprintw(2,30, "____________________");
mvprintw(3,30, "::::::::::::::::::::|__");
mvprintw(4,30, ":::::::::::::::::::::::|__");
mvprintw(5,30, "________________  ::::::::|_");
mvprintw(6,35, "                |::::::|_");
mvprintw(7,35, "                 |::::::|");
mvprintw(8,35, "                  |::::::|");
mvprintw(9,35, "   _____________   |_____|"); 
mvprintw(10,38,"|:::::|   |_:::|_ ");
mvprintw(11,38,"|:::::|    |_::::|_ ");
mvprintw(12,38,"|:::::|      |_::::|_ ");
mvprintw(13,38,"|:::::|       |_:::::|_ ");
mvprintw(14,38,"|:::::|        |_::::::|_ ");
mvprintw(15,38,"|:::::|         |_:::::::|_ ");
mvprintw(16,38,"|:::::|          |:::::::::| ");
mvprintw(17,38,"-------           --------- ");
attroff(COLOR_PAIR(10)); 






attron(COLOR_PAIR(10)); 
mvprintw(2,65, "        ____________");
mvprintw(3,65, "     |::::::::::::::|");
mvprintw(4,65, "    |::::::::::::::::|");
mvprintw(5,65, "   |::::::::::::::::::|");
mvprintw(6,65, "  |:::::::_----_:::::::|");
mvprintw(7,65, " |::::::|        |::::::|");
mvprintw(8,65, "|:::::::|        |::::::::|");
mvprintw(9,65, "|:::::::|        |::::::::|"); 
mvprintw(10,65,"|:::::::|        |::::::::|");
mvprintw(11,65,"|:::::::|        |::::::::|");
mvprintw(12,65,"|:::::::::-____-::::::::::|");
mvprintw(13,65," |::::::::::::::::::::::: |");
mvprintw(14,65,"  |::::::::::::::::::::::::::::|");
mvprintw(15,65,"   |:::::::::::::::::::::::::::|");
mvprintw(16,65,"    |::::::::::::::::::::::::::|");
mvprintw(17,65,"     |_________________________|");
attroff(COLOR_PAIR(10)); 

attron(COLOR_PAIR(10)); 
mvprintw(2,92, " |:::::\\            ______");
mvprintw(3,92, " |::::::\\          |::::::|");
mvprintw(4,92, " |:::::::\\         |::::::|");
mvprintw(5,92, " |::::::::\\        |::::::|");
mvprintw(6,92, " |:::::::::\\       |::::::|");
mvprintw(7,92, " |::::::::::\\      |::::::|");
mvprintw(8,92, " |:::::::::::\\     |::::::|");
mvprintw(9,92, " |::::::::___:\\____|::::::|"); 
mvprintw(10,92," |:::::::|   \\::::::::::::|");
mvprintw(11,92," |:::::::|     \\::::::::::|");
mvprintw(12,92," |:::::::|      \\:::::::::|");
mvprintw(13,92," |:::::::|       \\::::::::|");
mvprintw(14,92,":::::::::|        \\:::::::|");
mvprintw(15,92,":::::::::|         \\::::::|");
mvprintw(16,92,":::::::::|          \\:::::|");
mvprintw(17,92,"_________|           \\::::|");
attroff(COLOR_PAIR(10)); 

if (animationcounter == 0)
{
      for (int i = 1; i < 125; i= i+2)
   {
   
      attron(COLOR_PAIR(8));
      mvprintw(1,i,"[]"); //red
      attroff(COLOR_PAIR(8));
      
      attron(COLOR_PAIR(9));
      mvprintw(18,i,"[]"); //blue
      attroff(COLOR_PAIR(9));
      
         // sleep(1);
      nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
      refresh();
   }
int d = 1;
   for(int p = 125; p<171; p=p+2)
   {  
      if (p < 161)
      {
      attron(COLOR_PAIR(9));
      mvprintw(18,p,"[]"); //blue
      attroff(COLOR_PAIR(9));
      }


      if (d <= 17)
      {
      attron(COLOR_PAIR(8));
      mvprintw(d,125,"[]"); //red
      attroff(COLOR_PAIR(8));
      }


      nanosleep((const struct timespec[]){{0, 50000000L}}, NULL);
      refresh();
      d++;
   }
   flushinp();


    attron(COLOR_PAIR(11));      
   mvprintw(14,123,"  ooo");
   mvprintw(15,123," ooooo");
   mvprintw(16,123,"ooooooo");
   mvprintw(17,123," ooooo");
   mvprintw(18,123,"  ooo" );
    attroff(COLOR_PAIR(11));
  attron(COLOR_PAIR(8));   
   mvprintw(14,122,"  (");
   mvprintw(15,122," (");
   mvprintw(16,122,"(");
   mvprintw(17,122," (");
   mvprintw(18,122,"  (" );
   attroff(COLOR_PAIR(8));

   attron(COLOR_PAIR(8));
   mvprintw(14,128,")");
   mvprintw(15,129,")");
   mvprintw(16,130,")");
   mvprintw(17,129,")");
   mvprintw(18,128,")" );
   attroff(COLOR_PAIR(8));
   refresh(); 
   flushinp();
   bike(45);
}
else if (animationcounter > 0)
{
attron(COLOR_PAIR(10));   

 mvprintw(2,1,"   _____         ________________________________                       ____________        |:::::             ______     ");
 mvprintw(3,1,"  |:::::|      _|::::::::::::::::::::::::::::::::|__                 |::::::::::::::|       |::::::           |::::::|    ");
 mvprintw(4,1,"  |:::::|   __|:::::::::::::::::::::::::::::::::::::|__             |::::::::::::::::|      |:::::::          |::::::|    ");
 mvprintw(5,1,"   -----  _|::::::   ________________________  ::::::::|_          |::::::::::::::::::|     |::::::::         |::::::|    ");
 mvprintw(6,1,"          |::::::::::|                            |::::::|_       |:::::::_----_:::::::|    |:::::::::        |::::::|    ");
 mvprintw(7,1,"          |::::::::::|                              |::::::|      |::::::|        |::::::|   |::::::::::       |::::::|    ");
 mvprintw(8,1,"          |::::::::::|                              |::::::|    |:::::::|        |::::::::| |:::::::::::      |::::::|    ");
 mvprintw(9,1,"          |::::::::::|               _____________   |_____|    |:::::::|        |::::::::| |::::::::___: ____|::::::|    ");
mvprintw(10,1,"          |::::::::::|               |:::::|   |_:::|_          |:::::::|        |::::::::| |:::::::|    ::::::::::::|    ");
mvprintw(11,1,"          |::::::::::|               |:::::|    |_::::|_        |:::::::|        |::::::::| |:::::::|      ::::::::::|    ");
mvprintw(12,1,"          |::::::::::|               |:::::|      |_::::|_      |:::::::::-____-::::::::::| |:::::::|       :::::::::|    ");
mvprintw(13,1,"          |::::::::::|               |:::::|       |_:::::|_     |::::::::::::::::::::::: | |:::::::|        ::::::::|    ");
mvprintw(14,1,"          |::::::::::|               |:::::|        |_::::::|_    |:::::::::::::::::::::::::::::::::|         :::::::|    ");
mvprintw(15,1,"          |::::::::::|               |:::::|         |_:::::::|_   |::::::::::::::::::::::::::::::::|          ::::::|    ");
mvprintw(16,1,"          |::::::::::|               |:::::|          |:::::::::    |:::::::::::::::::::::::::::::::|           :::::|    ");
mvprintw(17,1,"           ----------                -------           ---------     |______________________________|            ::::|    ");

 
}
   



   animationcounter++;
//----------------------
    box(stdscr,0,0);

      attroff(COLOR_PAIR(2));
      attroff(A_BOLD);

refresh();
attron(A_BLINK);
attron(A_BOLD);
attron(COLOR_PAIR(10));
mvprintw(27, 47, "Welcome to Tron! Press Any Key to Start");
attroff(A_BLINK);
attroff(A_BOLD);
attroff(COLOR_PAIR(10));

mvprintw(52, 35, "Player 1 Controls: [W][A][S][D]");
mvprintw(52, 75, "Player 2 Controls: [I][J][K][L]");
flushinp();
refresh();
getch();
 
refresh();

//----------------
attron(COLOR_PAIR(10));
move(27,40); //move cursor to welcome line
clrtoeol(); //clear that line
box(stdscr,0,0); //fix the box that the line cleared
refresh(); //remove later

attron(A_BOLD);
attron(A_UNDERLINE);
mvprintw(25, 40, "Play"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
attroff(A_UNDERLINE);
mvprintw(27, 40, "Instructions"); 
mvprintw(29, 40, "Quit");
//attroff(A_BOLD);

char select; //controls blinking text
int select1 = 1; //controls progression to selected screen. 
int g = 0;


while (g == 0) {
   cbreak();
   flushinp();
   select = getch();

   if (select == 's' && select1 != 3)
   {
      system("afplay menuselect.wav & ");
      select1++; 
   }
   else if (select == 'w' && select1 != 1)
   {
      system("afplay menuselect.wav & ");
      select1--;
   }
   
   switch (select1){

      case 1:
         attron(A_UNDERLINE);
         mvprintw(25, 40, "Play");
         attroff(A_UNDERLINE);

         mvprintw(27, 40, "Instructions"); 
         
         mvprintw(29, 40, "Quit");
         break;
      case 2:
         attron(A_UNDERLINE);
         mvprintw(27, 40, "Instructions"); 
         attroff(A_UNDERLINE);

         mvprintw(25, 40, "Play");
        
         mvprintw(29, 40, "Quit");
         break;
      
      
      case 3:
         attron(A_UNDERLINE);
         mvprintw(29, 40, "Quit");
         attroff(A_UNDERLINE);

         mvprintw(27, 40, "Instructions"); 
         mvprintw(25, 40, "Play");

         break;


   }
         if (select == '\n')
         {
            system("afplay menuenter.wav &");
            g = 1;         }



}

      switch(select1) {

         case 1: 
            customizations();
            break; //continue onto play
         case 2: 
            instructions();
            break;
         case 3:
            terminate();
            break;

 
   }
attroff(COLOR_PAIR(10));
//---final menu bracket
}


void terminate() {
   echo();
   endwin();
   system("killall afplay");
   abort();

}

void instructions() {
flushinp();
clear();
attron(COLOR_PAIR(10));
box(stdscr, 0,0);

mvprintw(2,5," #### ##    ##  ######  ######## ########  ##     ##  ######  ######## ####  #######  ##    ##  ######  ");
mvprintw(3,5,"  ##  ###   ## ##    ##    ##    ##     ## ##     ## ##    ##    ##     ##  ##     ## ###   ## ##    ## ");
mvprintw(4,5,"  ##  ####  ## ##          ##    ##     ## ##     ## ##          ##     ##  ##     ## ####  ## ##       ");
mvprintw(5,5,"  ##  ## ## ##  ######     ##    ########  ##     ## ##          ##     ##  ##     ## ## ## ##  ######  ");
mvprintw(6,5,"  ##  ##  ####       ##    ##    ##   ##   ##     ## ##          ##     ##  ##     ## ##  ####       ## ");
mvprintw(7,5,"  ##  ##   ### ##    ##    ##    ##    ##  ##     ## ##    ##    ##     ##  ##     ## ##   ### ##    ## ");
mvprintw(8,5," #### ##    ##  ######     ##    ##     ##  #######   ######     ##    ####  #######  ##    ##  ######  ");
mvprintw(9,5,"========================================================================================================");

                                                    
mvprintw(11,  3, "1) You and your friend are battling each other on light cycles!");
mvprintw(14, 3, "2) Player 1 uses the WASD keys and Player 2 uses the IJKL keys to move in any direction!");
mvprintw(17, 3, "3) Player 1 is in the top left corner. Player 2 is in the bottom right corner.");
mvprintw(20, 3, "4) The Aim? Make the other person crash! Who ever crashes first loses the round!");
attroff(COLOR_PAIR(10));    
   
   nocbreak();
   getch();
   menu();
}

void customizations() { 
   flushinp();
   echo();
   
   clear();
   attron(COLOR_PAIR(10)); //cyan
   box(stdscr, 0,0);
 

   mvprintw(2,5,"  ######  ##     ##  ######  ########  #######  ##     ## #### ########    ###    ######## ####  #######  ##    ##  ######  ");
   mvprintw(3,5," ##    ## ##     ## ##    ##    ##    ##     ## ###   ###  ##       ##    ## ##      ##     ##  ##     ## ###   ## ##    ## ");
   mvprintw(4,5," ##       ##     ## ##          ##    ##     ## #### ####  ##      ##    ##   ##     ##     ##  ##     ## ####  ## ##       ");
   mvprintw(5,5," ##       ##     ##  ######     ##    ##     ## ## ### ##  ##     ##    ##     ##    ##     ##  ##     ## ## ## ##  ######  ");
   mvprintw(6,5," ##       ##     ##       ##    ##    ##     ## ##     ##  ##    ##     #########    ##     ##  ##     ## ##  ####       ## ");
   mvprintw(7,5," ##    ## ##     ## ##    ##    ##    ##     ## ##     ##  ##   ##      ##     ##    ##     ##  ##     ## ##   ### ##    ## ");
   mvprintw(8,5,"  ######   #######   ######     ##     #######  ##     ## #### ######## ##     ##    ##    ####  #######  ##    ##  ######  ");
   mvprintw(9,5,"============================================================================================================================");
   refresh();   

//------beginning of names                       
   curs_set(1); //set cursor to visible. Change this to 0 at end of function.                                  
   
   mvprintw(11,  3, "Player 1, Enter Your Name: ");
   refresh();
   scanw("%s", player1name);
         // mvchgat(11, 2, -1, A_NORMAL, 10, NULL); //While I don't need this any more, it's pretty useful (coordx, coordy, -1 = end of line, attribute, color, NULL)

   mvprintw(13, 3, "Player 2, Enter your Name: ");
   refresh();
   scanw("%s", player2name);

   curs_set(0); 

//---- end of names

//--beginning of colors 15-33
   /* init_pair(1, COLOR_RED, COLOR_BLACK); //3rd argument is the background color (highlight). -1 is the default background for the terminal.
      init_pair(2, COLOR_GREEN, COLOR_BLACK);
      init_pair(3, COLOR_YELLOW, COLOR_BLACK);
      init_pair(4, COLOR_BLUE, COLOR_BLACK);
      init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
      init_pair(6, COLOR_CYAN, COLOR_BLACK);
      init_pair(7, COLOR_WHITE, COLOR_BLACK);
      init_pair(8, COLOR_RED, COLOR_BLACK); //use this
      init_pair(9, COLOR_BLUE, COLOR_BLACK); //use this
      init_pair(10, COLOR_CYAN, COLOR_BLACK); //use this
      init_pair(11, COLOR_YELLOW, COLOR_BLACK); //use this*/
   noecho();
      attron(COLOR_PAIR(10));
      attron(A_BOLD);
      mvprintw(15,4,"Player 1 Choose a color: (Use the WASD Keys) ");
      attroff(COLOR_PAIR(10));   
      attron(COLOR_PAIR(1));
      attron(A_UNDERLINE);
      mvprintw(16, 4, "Red"); 
      attroff(A_UNDERLINE);
      attroff(COLOR_PAIR(1));
      attron(COLOR_PAIR(10));
      mvprintw(17, 4, "Green");                                                    
      mvprintw(18, 4, "Yellow"); 
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      mvprintw(21, 4, "Cyan");
      mvprintw(22, 4, "White");
      attroff(COLOR_PAIR(10));
      attroff(A_BOLD);
      refresh();  
      char select = '0'; 
      int select1 = 1; 
      int g = 0;

while (g == 0) {
         cbreak();
         select = getch();

      if (select == 's' && select1 != 7)
      {
      system("afplay menuselect.wav & ");
      select1++; 
        }
         else if (select == 'w' && select1 != 1)
         {
      system("afplay menuselect.wav & ");
         select1--;
         }
         switch (select1){
      case 1:
      attron(COLOR_PAIR(10));
      attron(A_BOLD);
      attron(COLOR_PAIR(1));
      attron(A_UNDERLINE);
      mvprintw(16, 4, "Red"); 
      attroff(A_UNDERLINE); 
      attroff(COLOR_PAIR(1));
         attron(COLOR_PAIR(10));
      mvprintw(17, 4, "Green");                                
      mvprintw(18, 4, "Yellow"); //probably color only
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      mvprintw(21, 4, "Cyan");
      mvprintw(22, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10)); 
         break;
      case 2:
         attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
      attron(COLOR_PAIR(2));
      attron(A_UNDERLINE);
      mvprintw(17, 4, "Green");
      attroff(A_UNDERLINE);       
      attroff(COLOR_PAIR(2));
      attron(COLOR_PAIR(10));
      mvprintw(18, 4, "Yellow"); 
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      mvprintw(21, 4, "Cyan");
      mvprintw(22, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10));
         break;
      case 3:
        attron(COLOR_PAIR(10));
        attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
      mvprintw(17, 4, "Green");
      attron(COLOR_PAIR(3));
      attron(A_UNDERLINE);                                                    
      mvprintw(18, 4, "Yellow");
      attroff(A_UNDERLINE);
      attroff(COLOR_PAIR(3));
      attron(COLOR_PAIR(10));
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      mvprintw(21, 4, "Cyan");
      mvprintw(22, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10));
         break;
      case 4:
        attron(COLOR_PAIR(10));
        attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
        mvprintw(17, 4, "Green");
                                                   
        mvprintw(18, 4, "Yellow");
   

        attron(COLOR_PAIR(4));
        attron(A_UNDERLINE); 
        mvprintw(19, 4, "Blue");
        attroff(A_UNDERLINE);
        attroff(COLOR_PAIR(4));
        attron(COLOR_PAIR(10));
        mvprintw(20, 4, "Magenta");
        mvprintw(21, 4, "Cyan");
        mvprintw(22, 4, "White");
        attroff(A_BOLD);
        attroff(COLOR_PAIR(10));
         break;
      case 5:
        attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
      mvprintw(17, 4, "Green");                                             
      mvprintw(18, 4, "Yellow"); 
      mvprintw(19, 4, "Blue");
      attron(COLOR_PAIR(5));
      attron(A_UNDERLINE);
      mvprintw(20, 4, "Magenta");
      attroff(A_UNDERLINE);  
      attroff(COLOR_PAIR(5));
      attron(COLOR_PAIR(10));
      mvprintw(21, 4, "Cyan");
      mvprintw(22, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10));
         break;
           case 6:
        attron(COLOR_PAIR(10));
        attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
      mvprintw(17, 4, "Green");                                  
      mvprintw(18, 4, "Yellow"); 
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      attron(A_UNDERLINE);
      mvprintw(21, 4, "Cyan");
      attroff(A_UNDERLINE);  
      mvprintw(22, 4, "White");
      attroff(A_BOLD);
      attroff(COLOR_PAIR(10));
         break;
           case 7:
        attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(16, 4, "Red"); 
      mvprintw(17, 4, "Green");                                             
      mvprintw(18, 4, "Yellow"); 
      mvprintw(19, 4, "Blue");
      mvprintw(20, 4, "Magenta");
      mvprintw(21, 4, "Cyan");
      attroff(COLOR_PAIR(10));
      attron(COLOR_PAIR(7));
      attron(A_UNDERLINE);
      mvprintw(22, 4, "White");
      attroff(A_UNDERLINE);  
      attroff(COLOR_PAIR(7));
      attroff(A_BOLD);
         
         break;
      }
   if (select == '\n')
         {
            system("afplay menuenter.wav");
            g = 1;        
         }
switch(select1) {
         case 1: 
        pick = 1;
            break; 
         case 2: 
         pick = 2;
            break;
         case 3:
         pick = 3;
            break;
         case 4:
         pick = 4;
            break;
         case 5:
         pick = 5;
            break;
         case 6:
         pick = 6;
            break;
         case 7:
         pick = 7;
            break;
}
              }
      attron(A_BOLD);
          attron(COLOR_PAIR(10));
      mvprintw(24,4,"Player 2 Choose a color: (Use the IJKL Keys)");
      attroff(COLOR_PAIR(10));
      attron(COLOR_PAIR(10));
      attron(COLOR_PAIR(1)); 
      attron(A_UNDERLINE);
      mvprintw(25, 4, "Red"); 
      attroff(A_UNDERLINE);
      attron(COLOR_PAIR(1));
      attron(COLOR_PAIR(10));
      mvprintw(26, 4, "Green");                                                    
      mvprintw(27, 4, "Yellow"); 
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
      attroff(COLOR_PAIR(10));
      refresh();  
   
      char part= '0'; 
      int choose = 1; 
      int v = 0;

while (v == 0) {
         cbreak();
         part = getch();
      if (part == 'k' && choose != 7)
      {
      system("afplay menuselect.wav & ");
      choose++; 
        }
         else if (part == 'i' && choose != 1)
         {
      system("afplay menuselect.wav & ");
         choose--;
         }
         switch (choose){
      case 1: 
    attron(COLOR_PAIR(10));
    attron(A_BOLD);
   attron(COLOR_PAIR(1));
    attron(A_UNDERLINE);
   mvprintw(25, 4, "Red"); 
    attroff(A_UNDERLINE); 
    attroff(COLOR_PAIR(1));
   attron(COLOR_PAIR(10));
      mvprintw(26, 4, "Green");                                
      mvprintw(27, 4, "Yellow"); //probably color only
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
   attroff(A_BOLD);
   attroff(COLOR_PAIR(10));   
         break;
      case 2:
         attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
      attron(COLOR_PAIR(2));
      attron(A_UNDERLINE);
      mvprintw(26, 4, "Green");
      attroff(A_UNDERLINE);       
      attroff(COLOR_PAIR(2));
      attron(COLOR_PAIR(10));
      mvprintw(27, 4, "Yellow"); //probably color only
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10)); 
         break;
      case 3:
      attron(COLOR_PAIR(10));
        attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level.
      mvprintw(26, 4, "Green");
      attron(COLOR_PAIR(3));
      attron(A_UNDERLINE);                                                    
      mvprintw(27, 4, "Yellow");
      attroff(A_UNDERLINE);
      attroff(COLOR_PAIR(3));
      attron(COLOR_PAIR(10));
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10));
         break;
      case 4:
         attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
      mvprintw(26, 4, "Green");                                               
      mvprintw(27, 4, "Yellow"); //probably color only
      attron(COLOR_PAIR(4));
      attron(A_UNDERLINE);
      mvprintw(28, 4, "Blue");
      attroff(A_UNDERLINE);   
      attroff(COLOR_PAIR(4));
      attron(COLOR_PAIR(10));
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10)); 
         break;
      case 5:
         attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
      mvprintw(26, 4, "Green");                                             
      mvprintw(27, 4, "Yellow"); //probably color only
      mvprintw(28, 4, "Blue");
      attron(COLOR_PAIR(5));
      attron(A_UNDERLINE);
      mvprintw(29, 4, "Magenta");
      attroff(A_UNDERLINE);  
      attroff(COLOR_PAIR(5));
      attron(COLOR_PAIR(10));
      mvprintw(30, 4, "Cyan");
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
        attroff(COLOR_PAIR(10)); 
         break;
           case 6:
        attron(COLOR_PAIR(10));
        attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
      mvprintw(26, 4, "Green");                                  
      mvprintw(27, 4, "Yellow"); //probably color only
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      attron(A_UNDERLINE);
      mvprintw(30, 4, "Cyan");
      attroff(A_UNDERLINE);   
          
      mvprintw(31, 4, "White");
      attroff(A_BOLD);
      attroff(COLOR_PAIR(10));
         break;
           case 7:
         attron(COLOR_PAIR(10));
         attron(A_BOLD);
        mvprintw(25, 4, "Red"); //enter another screen with Player 1 and Player 2 names + difficulty/speed level. 
      mvprintw(26, 4, "Green");                                             
      mvprintw(27, 4, "Yellow"); //probably color only
      mvprintw(28, 4, "Blue");
      mvprintw(29, 4, "Magenta");
      mvprintw(30, 4, "Cyan");
      attroff(COLOR_PAIR(10)); 
      attron(COLOR_PAIR(7));
      attron(A_UNDERLINE);
      mvprintw(31, 4, "White");
      attroff(A_UNDERLINE);  
      attroff(COLOR_PAIR(7));
      attroff(A_BOLD);
               break;
      }
   if (part == '\n')
         {
            system("afplay menuenter.wav");
            v = 1;        
         }
switch(choose) 
      {
         case 1: 
        pick2 = 1;
            break; 
         case 2: 
         pick2 = 2;
         //  clear();
            break;
         case 3:
         pick2 = 3;
            break;
         case 4:
         pick2 = 4;
            break;
         case 5:
         pick2 = 5;
            break;
         case 6:
         pick2 = 6;
            break;
         case 7:
         pick2 = 7;
            break;
      }
   }


//----end of colors

   
//----beginning of speed setting
attron(COLOR_PAIR(10));
noecho();
mvprintw(35, 3, "Choose a Speed Level: ");
mvprintw(36, 10, "SLOW"); 
attron(A_UNDERLINE);
mvprintw(37, 10, "NORMAL");
attroff(A_UNDERLINE); 
mvprintw(38, 10, "FAST"); 

;

select = '0'; //controls blinking text
select1 = 2; //controls progression to selected screen. 
g = 0;


while (g == 0) {
   cbreak();
   select = getch();

   if (select == 's' && select1 != 3)
   {
      system("afplay menuselect.wav & ");
      select1++; 
   }
   else if (select == 'w' && select1 != 1)
   {
      system("afplay menuselect.wav & ");
      select1--;
   }
   
   switch (select1){

      case 1:
         attron(A_UNDERLINE);
         mvprintw(36, 10, "SLOW"); 
         attroff(A_UNDERLINE);
         mvprintw(37, 10, "NORMAL");
         mvprintw(38, 10, "FAST"); 

         break;
      case 2:
         mvprintw(36, 10, "SLOW"); 
         attron(A_UNDERLINE);
         mvprintw(37, 10, "NORMAL");
         attroff(A_UNDERLINE); 
         mvprintw(38, 10, "FAST");
         break;
      case 3:
         mvprintw(36, 10, "SLOW"); 
         mvprintw(37, 10, "NORMAL");
         attron(A_UNDERLINE); 
         mvprintw(38, 10, "FAST");
         attroff(A_UNDERLINE);
         break;


   }
         if (select == '\n')
         {
            system("afplay menuenter.wav &");
            g = 1;         }



}
         switch(select1) {

         case 1: 
            speed = 200; //the higher the number, the slower it is, because it is used in timeout(#here); when the game initializes
            break; 
         case 2: 
            speed = 100;
            break;
         case 3:
            speed = 50; 
            break;

         }
//------------end of speed setting

//------------beginning of Game Mode (5, 10, infinity until quit)
      mvprintw(40, 3, "Choose a Game Mode: ");
      mvprintw(41, 10, "5 Rounds"); 
      attron(A_UNDERLINE);
      mvprintw(42, 10, "10 Rounds");
      attroff(A_UNDERLINE); 
      mvprintw(43, 10, "Infinite Until Quit"); 

      

      select = 0; //controls blinking text
      select1 = 2; //controls progression to selected screen. 
      g = 0;


      while (g == 0) {
         cbreak();
         select = getch();

         if (select == 's' && select1 != 3)
         {
            system("afplay menuselect.wav & ");
            select1++; 
         }
         else if (select == 'w' && select1 != 1)
         {
            system("afplay menuselect.wav & ");
            select1--;
         }
         
         switch (select1){

            case 1:
               attron(A_UNDERLINE);
               mvprintw(41, 10, "5 Rounds"); 
               attroff(A_UNDERLINE);
               mvprintw(42, 10, "10 Rounds");
               mvprintw(43, 10, "Infinite Until Quit"); 

               break;
            case 2:
               mvprintw(41, 10, "5 Rounds"); 
               attron(A_UNDERLINE);
               mvprintw(42, 10, "10 Rounds");
               attroff(A_UNDERLINE); 
               mvprintw(43, 10, "Infinite Until Quit");
               break;
            case 3:
               mvprintw(41, 10, "5 Rounds"); 
               mvprintw(42, 10, "10 Rounds");
               attron(A_UNDERLINE); 
               mvprintw(43, 10, "Infinite Until Quit");
               attroff(A_UNDERLINE);
               break;

               attroff(COLOR_PAIR(10)); 
         }
               if (select == '\n')
               {
                  system("afplay menuenter.wav &");
                  g = 1;         }



      }
               switch(select1) {

               case 1: 
                  gamemode = 5; 
                  break; 
               case 2: 
                  gamemode = 10;
                  break;
               case 3:
                  gamemode = 999999999; 
                  break;

               }





   attroff(COLOR_PAIR(10));
   bike(50);
   noecho();    
      

//Names
//Colors
//Difficulty (speed)
//Game Mode
      nocbreak();

      

} 

void bike(int position) {

      for (int i = 1; i < 126; ++i)
   {
         clrtoeol();
         refresh();

   attron(COLOR_PAIR(11));
   mvprintw(position,i,"_");
   attroff(COLOR_PAIR(11)); // 11 yellow

   attron(COLOR_PAIR(10)); // 10 blue
   mvprintw(position,i+1,"_____");
   attroff(COLOR_PAIR(10));

   attron(COLOR_PAIR(11));
   mvprintw(position+1,i,"/");
   attroff(COLOR_PAIR(11));

   attron(COLOR_PAIR(10));
   mvprintw(position+1,i+1,"------\\");  
   attroff(COLOR_PAIR(10));   

   attron(COLOR_PAIR(11));
   mvprintw(position+2,i,"{");
   attroff(COLOR_PAIR(11));
      attron(COLOR_PAIR(10));
   mvprintw(position+2,i+1,"(O)} {(O)}");
   attron(COLOR_PAIR(10));

   nanosleep((const struct timespec[]){{0, 9000000L}}, NULL);
   refresh();
      
   }

}