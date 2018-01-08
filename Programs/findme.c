// Jack Lu
// Fun Fact: I go to Stuyvesant *_*

#include <stdio.h>
#include <string.h>

int main() {
    
    char string[50];
    
    int i, num;
    
    printf("Enter a string: ");
    fgets(string, 50, stdin);
    
    for (i = 0; i < 50; i++)
    {
        
        if (string[i] == 'm')
        {
            
            if (string[i+1] == 'e')
            {
                num++;
            }
            
        }
        
    }
    
    printf("'me' appears %d times.\n", num);
    
    return 0;
    
}
