// Team Pizza Rolls
// Cruz Fernandez, Jordana Pearlman & Jason Chay

#include <stdio.h>

int main() {
    
    int phone = 0;
    phone = 1;
    
    int audience = 0;
    audience = 1;
    
    char answer;
    
    printf("=========================================\n");
    printf("Welcome to Who Wants To Be A Millionaire!\n");
    printf("=========================================\n");
    printf("\n");
    
    // ==================== Question 1 ====================
    
    printf("Question #1: What's Cruz's favorite food?\n\n");
    
    printf("      A: Pizza Roll    B: Hot Dog\n");
    printf("      C: Steak         D: Cactus\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'A' || answer == 'a') {
        
        printf("\nCongrats, you won $10,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you don't move on. Answer: A\n");
        return 0;
        
    }
    
    // ==================== Question 2 ====================
    
    printf("=========================================\n\n");
    
    printf("Question #2: One Bitcoin = how much USD?\n\n");
    
    printf("      A: $1000         B: $5000\n");
    printf("      C: $10000        D: $15000+\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'D' || answer == 'd') {
        
        printf("\nCongrats, you won $25,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you do not move on. Answer: D\n");
        return 0;
        
    }
    
    // ==================== Question 3 ====================
    
    printf("=========================================\n\n");
    
    printf("Question #3: The final project is due on?\n\n");
    
    printf("      A: July 14       B: July 15\n");
    printf("      C: July 21       D: Never\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'B' || answer == 'b') {
        
        printf("\nCongrats, you won $50,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you do not move on. Answer: B\n");
        return 0;
        
    }
    
    // ==================== Question 4 ====================
    
    printf("=========================================\n\n");
    
    printf("Question #4: Where have Sonny taught?\n\n");
    
    printf("      A: Columbia      B: NYU\n");
    printf("      C: Lehman        D: All the above\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'D' || answer == 'd') {
        
        printf("\nCongrats, you won $100,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you do not move on. Answer: D\n");
        return 0;
        
    }
    
    // ==================== Question 5 ====================
    
    printf("=========================================\n\n");
    
    printf("Question #5: Who was the first programmer?\n\n");
    
    printf("      A: Alan Turing   B: Edsger Dijkstra\n");
    printf("      C: Ada Lovelace  D: Grace Hopper\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'C' || answer == 'c') {
        
        printf("\nCongrats, you won $250,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you do not move on. Answer: C\n");
        return 0;
        
    }
    
    // ==================== Question 6 ====================
    
    printf("=========================================\n\n");
    
    printf("Question #6: What year was C developed?\n\n");
    
    printf("      A: 1969          B: 1979\n");
    printf("      C: 1989          D: 1999\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\n'Phone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'A' || answer == 'a') {
        
        printf("\nCongrats, you won $500,000! You move on!\n\n");
        
    }
    else {
        
        printf("\nSorry, you do not move on. Answer: A\n");
        return 0;
        
    }
    
    // ==================== Question 7 ====================
    
    printf("=========================================\n\n");
    
    printf("And for the million dollar question...\n\n");
    
    printf("Question #7: What is 1010100 in decimal?\n\n");
    
    printf("      A: 42            B: 84\n");
    printf("      C: 85            D: 168\n\n");
    
    printf("      E: Ask Audience (%d)\n", audience);
    printf("      F: Phone Friend (%d)\n\n", phone);
    
    printf("Type your final answer:");
    scanf(" %c", &answer);
    
    while (answer == 'E' || answer == 'e' || answer == 'F' || answer == 'f')
    {
        
        if (audience == 1 && (answer == 'E' || answer == 'e'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            audience = 0;
        }
        else if (audience == 0 && (answer == 'E' || answer == 'e'))
        {
            printf("\n'Ask Audience' lifeline have been used.\n\n");
        }
        else if (phone == 1 && (answer == 'F' || answer == 'f'))
        {
            printf("\nYou have 30 seconds. Staaarts....... now!\n\n");
            phone = 0;
        }
        else if (phone == 0 && (answer == 'F' || answer == 'f'))
        {
            printf("\nPhone Friend' lifeline have been used.\n\n");
        }
        
        printf("Type your final answer:");
        scanf(" %c", &answer);
        
    }
    
    if (answer == 'B' || answer == 'b') {
        
        printf("\nCongratulations! You are a *millionaire*!\n");
        
    }
    else {
        
        printf("\nSo close... tough loss! Answer: B\n");
        
    }
    
    return 0;
    
}
