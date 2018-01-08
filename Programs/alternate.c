// Jacob Lindahl
// Fun Fact: My favorite subject is physics.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    int i;
    char text[50];
    
    printf("Enter a string: ");
    fgets(text, 50, stdin);
    
    for (i = 0; i < strlen(text); i++)
    {
        
        if (i % 2 == 0)
        {
            text[i] = toupper(text[i]);
        }
        else
        {
            text[i] = tolower(text[i]);
        }
        
    }
    
    printf("Output: ");
    printf("%s\n", text);
    
    return 0;
    
}
