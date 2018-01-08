// Sonny Li
// Intro to Programming in C

# include <stdio.h>
# include <string.h>

int main() {
    
    printf("Enter a string: ");
    
    char a[50];
    fgets(a, 50, stdin);
    
    int i;
    
    int vowel = 0;
    int digit = 0;
    
    for (i = 0; i < 50; i++) {
        
        if (a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i] == 'u')
        {
            vowel++;
        }
        
        else if (a[i]=='0' || a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5'|| a[i]=='6' || a[i]=='7'|| a[i]=='8' || a[i]=='9')
        {
            digit++;
        }
        
    }
    
    printf("Number of vowels: %d\n", vowel);
    printf("Number of digits: %d\n", digit);
    
    return 0;
    
}
