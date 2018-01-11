// Week 2 Project: Times Table
// Alexan Varelas, David Fang & Jonathan Daniel

// Instructor: Sonny Li

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

char names[1000][4];

void displayHeader() {
    
    system("clear");
    
    printf(" ______    __     __    __     ______     ______        ______    ______     ______     __         ______                                       \n");
    printf("/\\__  _\\  /\\ \\   /\\ \"-./  \\   /\\  ___\\   /\\  ___\\      /\\__  _\\  /\\  __ \\   /\\  == \\   /\\ \\       /\\  ___\\                 \n");
    printf("\\/_/\\ \\/  \\ \\ \\  \\ \\ \\-./\\ \\  \\ \\  __\\   \\ \\___  \\     \\/_/\\ \\/  \\ \\  __ \\  \\ \\  __<   \\ \\ \\____  \\ \\  __\\       \n");
    printf("   \\ \\_\\   \\ \\_\\  \\ \\_\\ \\ \\_\\  \\ \\_____\\  \\/\\_____\\       \\ \\_\\   \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_____\\ \n");
    printf("    \\/_/    \\/_/   \\/_/  \\/_/   \\/_____/   \\/_____/        \\/_/    \\/_/\\/_/   \\/_____/   \\/_____/   \\/_____/                        \n");

}

void introduction() {
    
    srand(time(NULL));
    
    displayHeader();
    
    printf("\n");
    printf("Press <Enter> to continue: ");
    getchar();
    
}

void assignQuestions(int digit1[], int digit2[], int answer[], int numOfQuestions) {
    
    int i;
    
    for (i = 0; i < numOfQuestions; i++) {
        
        digit1[i] = rand() % 13;
        digit2[i] = rand() % 13;
        
        answer[i] = digit1[i] * digit2[i];
        
    }
    
};

void displayHighScore(int numOfQuestions) {
    
    displayHeader();
    
    printf(" __  __     __     ______     __  __       ______     ______     ______     ______     ______                                     \n");
    printf("/\\ \\_\\ \\   /\\ \\   /\\  ___\\   /\\ \\_\\ \\     /\\  ___\\   /\\  ___\\   /\\  __ \\   /\\  == \\   /\\  ___\\              \n");
    printf("\\ \\  __ \\  \\ \\ \\  \\ \\ \\__ \\  \\ \\  __ \\    \\ \\___  \\  \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\  __<   \\ \\  __\\       \n");
    printf(" \\ \\_\\ \\_\\  \\ \\_\\  \\ \\_____\\  \\ \\_\\ \\_\\    \\/\\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_____\\ \n");
    printf("  \\/_/\\/_/   \\/_/   \\/_____/   \\/_/\\/_/     \\/_____/   \\/_____/   \\/_____/   \\/_/ /_/   \\/_____/                       \n\n");
    
    printf("Please type in your initials and press <Enter>: ");
    scanf("%c%c", &names[numOfQuestions][0], &names[numOfQuestions][1]);

}

void displayFastestTime() {
    
    printf(" ______    ______     ______     ______    ______     ______     ______                          \n");
    printf("/\\  ___\\  /\\  __ \\   /\\  ___\\   /\\__  _\\  /\\  ___\\   /\\  ___\\   /\\__  _\\           \n");
    printf("\\ \\  __\\  \\ \\  __ \\  \\ \\___  \\  \\/_/\\ \\/  \\ \\  __\\   \\ \\___  \\  \\/_/\\ \\/    \n");
    printf(" \\ \\_\\     \\ \\_\\ \\_\\  \\/\\_____\\    \\ \\_\\   \\ \\_____\\  \\/\\_____\\    \\ \\_\\  \n");
    printf("  \\/_/      \\/_/\\/_/   \\/_____/     \\/_/    \\/_____/   \\/_____/     \\/_/                 \n");

}

void runQuestions(int digit1s[], int digit2s[], int answers[], int numOfQuestions, float times[], float scores[]) {
    
    double Total_time;
    
    time_t start, end;
    
    int i, answer = 0, numCorrect = 0, numWrong = 0;

    float score = 0.0;
    
    time(&start);
    
    for (i = 0; i < numOfQuestions; i++) {
        
        // printf("Question %d)\n\n", i+1);
        
        printf("%d x %d = ", digit1s[i], digit2s[i]);
        scanf("%d", &answer);
        
        printf("\n");
        
        if (answer == answers[i]) {
            
            numCorrect += 1;
        
        } else {
            
            numWrong += 1;
            
        }
        
    }
    
    time(&end);
    
    Total_time = difftime(end, start);
    
    score = (numCorrect * 100) / numOfQuestions;
    
    printf("You got %d right and %d wrong. A score of %.0f.\n\n", numCorrect, numWrong, score);
    printf("This took you %.0f seconds.\n\n", Total_time);
    
    printf("Press <Enter> to continue: ");
    getchar();
    getchar();
    
    if ((numCorrect*100)/(numOfQuestions) > scores[numOfQuestions]) {
        
        // printf("NEW HIGH SCORE!\n");
        
        displayHighScore(numOfQuestions);
        
        scores[numOfQuestions] = (numCorrect * 100) / numOfQuestions;
        
    }
    
    if (Total_time < times[numOfQuestions]) {
        
        // printf("NEW FASTEST TIME!\n");
        
        displayFastestTime();
        
        times[numOfQuestions] = Total_time;
    
    }
    
    printf("\nHigh score for %d questions: %.0f.\n\n", numOfQuestions, scores[numOfQuestions]);
    printf("Fastest completion: %0.0f seconds.\n\n", times[numOfQuestions]);
    
}

// ======================================================================================================================================

int main() {
    
    introduction();
    
    float times[1000];
    float scores[1000];
    
    for (int i = 0; i < 100; i++) {
        
        times[i] = 200000;
        scores[i] = 0;
    
    }
    
    do {
        
        char response;
        
        int numOfQuestions = 0;
        
        printf("\n");
        printf("How many questions: ");
        scanf("%d", &numOfQuestions);
        
        int digit1s[numOfQuestions], digit2s[numOfQuestions], answers[numOfQuestions];
        
        assignQuestions(digit1s, digit2s, answers, numOfQuestions);
        
        if (scores[numOfQuestions] != 0) {
            
            printf("\nThe high score of %0.0f is currently owned by %c%c.\n", scores[numOfQuestions], names[numOfQuestions][0], names[numOfQuestions][1]);
        
        }
        
        printf("\n");
        printf("Press <Enter> to begin: ");
        getchar();
        getchar();
        
        printf("\n");
        usleep(500000);
        
        printf("~~~ 3 ~~~\n");
        usleep(1000000);
        
        printf("~~~ 2 ~~~\n");
        usleep(1000000);
        
        printf("~~~ 1 ~~~\n\n");
        usleep(1000000);
        
        printf("~ START ~\n\n");
        usleep(1000000);
        
        runQuestions(digit1s, digit2s, answers, numOfQuestions, times, scores);
        
        printf("Would you like to play again? (Y/N) ");
        scanf("%s", &response);
        
        printf("%c\n", toupper(response));
        
        if (toupper(response) == 'N') {
            
            break;
        
        }
        
        displayHeader();
        
    } while(1);
    
    system("clear");
    
}
