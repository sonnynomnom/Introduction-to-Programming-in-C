// Andrea Corro
// Fun Fact: I've been swimming competitively for almost 5 years.

#include <stdio.h>
#include <math.h>

void triangle() {
    
    int base, height;
    float area;
    
    printf("\nEnter the base: ");
    scanf("%d", &base);
    
    printf("Enter the height: ");
    scanf("%d", &height);
    
    area = (base*height)/2;
    
    printf("\nThe area is %.2f\n\n", area);
    
}

void rectangle() {
    
    int length, width;
    float area;
    
    printf("\nEnter the length: ");
    scanf("%d", &length);
    
    printf("Enter the width: ");
    scanf("%d", &width);
    
    area = length*width;
    
    printf("\nThe area is %.2f\n\n", area);
    
}

void square() {
    
    int side;
    float area;
    
    printf("\nEnter the length of a side: ");
    scanf("%d", &side);
    
    area = side*side;
    
    printf("\nThe area is %.2f\n\n", area);
    
}

void circle() {
    
    int radius;
    float area;
    
    printf("\nEnter the radius: ");
    scanf("%d", &radius);
    
    area = M_PI*(radius*radius);
    
    printf("\nThe area is %.2f\n\n", area);
    
}

int main() {
    
    int shape = 0;
    
    while (shape != 5) {
        
        printf("==============================\n\n");
        
        printf("1) Triangle\n");
        printf("2) Rectangle\n");
        printf("3) Square\n");
        printf("4) Circle\n");
        printf("5) Quit\n\n");
        
        printf("Which shape? ");
        scanf("%d", &shape);
        
        if (shape == 1) {
            
            triangle();
            
        }
        else if (shape == 2) {
            
            rectangle();
            
        }
        else if (shape == 3) {
            
            square();
            
        }
        else if (shape == 4) {
            
            circle();
            
        }
        
    }
    
    printf("\nGoodbye!\n");
    
    return 0;
    
}
