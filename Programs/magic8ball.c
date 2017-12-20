// Sonny Li
// Intro to Programming in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    int choice = rand() % 14 + 1;

    printf("Do you have a question for me? Ask away!\n\n");

    if (choice == 1)
    {
        printf("MAGIC 8-BALL SAYS: #YAS\n");
    }
    else if (choice == 2)
    {
        printf("MAGIC 8-BALL SAYS: Yes, yes, and YES!\n");
    }
    else if (choice == 3)
    {
        printf("MAGIC 8-BALL SAYS: The stars align. It's a definite yes.\n");
    }
    else if (choice == 4)
    {
        printf("MAGIC 8-BALL SAYS: Okie doke from me~\n");
    }
    else if (choice == 5)
    {
        printf("MAGIC 8-BALL SAYS: Yeah, I think so.\n");
    }
    else if (choice == 6)
    {
        printf("MAGIC 8-BALL SAYS: Never in your life.\n");
    }
    else if (choice == 7)
    {
        printf("MAGIC 8-BALL SAYS: You need to get outta there ASAP!\n");
    }
    else if (choice == 8)
    {
        printf("MAGIC 8-BALL SAYS: I don't have a good feeling about this.\n");
    }
    else if (choice == 9)
    {
        printf("MAGIC 8-BALL SAYS: N A H\n");
    }
    else if (choice == 10)
    {
        printf("MAGIC 8-BALL SAYS: Reply hazy, check back later.\n");
    }
    else if (choice == 11)
    {
        printf("MAGIC 8-BALL SAYS: One day it shall all become clear.\n");
    }
    else if (choice == 12)
    {
        printf("MAGIC 8-BALL SAYS: You are not gonna like the answer.\n");
    }
    else if (choice == 13)
    {
        printf("MAGIC 8-BALL SAYS: Idk *_*\n");
    }
    else if (choice == 14)
    {
        printf("MAGIC 8-BALL SAYS: Maaaybe, try again!\n");
    }
    else
    {
        printf("8-BALL ERROR!\n");
    }

    return 0;

}
