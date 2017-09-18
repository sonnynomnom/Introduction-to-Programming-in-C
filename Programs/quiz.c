/* Team Egg && Bananas */
/* Alexan Varelas && Jimmy Liu */

#include <stdio.h>

int main() {

    int correct = 0;

    int answer1;
    int answer2;
    int answer3;

    printf("The quiz is starting whooooooooooooooo!\n\n");

    // =========== Question 1 ============

    printf("Q1) What is the largest living mammal?\n");
    printf("    1) Elephant\n");
    printf("    2) Whale\n");
    printf("    3) Chicken\n");

    scanf("%d", &answer1);

    if (answer1 == 2)
    {
        printf("Good job, you're relatively educated.\n\n");
        correct++;
    }
    else
    {
	      printf("You're dumb sorry.\n\n");
    }

    // =========== Question 2 ============

    printf("Q2) What is the only mammal that can fly?\n");
    printf("    1) A Flying Squirrel\n");
    printf("    2) A Sparrow\n");
    printf("    3) A Bat\n");

    scanf("%d", &answer2);

    if (answer2 == 1)
    {
        printf("FLYING SQUIRRELS DON'T ACTUALLY FLY.\n\n");
    }
    else if (answer2 == 2)
    {
        printf("A sparrow is a bird and a bird is not a mammal.\n\n");
    }
    else if (answer2 == 3)
    {
        printf("Yas.\n\n");
        correct++;
    }
    else
    {
        printf("Nah.\n\n");
    }

    // =========== Question 3 ============

    printf("Q3) If you are waiting for your food, aren't you the waiter...?\n");
    printf("    1) What.\n");
    printf("    2) Holy moly I never thought of that.\n");
    printf("    3) :') \n");

    scanf("%d", &answer3);

    printf("Good answer.\n\n");
    correct++;

    printf("You got %d out of 3 correct.\n", correct);
    printf("Thanks for playing!\n");

    return 0;

}
