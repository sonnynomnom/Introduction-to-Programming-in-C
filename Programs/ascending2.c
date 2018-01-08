// Marcus Kapoor
// Intro to Programming in C

#include <stdio.h>

int main () {
    
    int A[3];
    int B[3];
    
    printf("Array A:\n");
    
    for (int x = 0; x < 3; x++)
    {
        
        printf("What is number %d? ", x+1);
        scanf("%d", &A[x]);
        
    }
    
    printf("\n");
    
    printf("Array B:\n");
    
    for (int y = 0; y < 3; y++)
    {
        
        printf("What is number %d? ", y+1);
        scanf("%d", &B[y]);
        
    }
    
    printf("\n");
    
    // =============================================
    
    int C[6] = {A[0], A[1], A[2], B[0], B[1], B[2]};
    
    for (int i = 0; i < 30; i++)
    {
        
        for (int j = 1; j < 6; j++)
        {
            
            if (C[j] < C[j-1])
            {
                int temp = C[j];
                C[j] = C[j-1];
                C[j-1] = temp;
            }
            
        }
        
    }
    
    printf("Array C: ");
    
    for (int n = 0; n < 6; n++)
    {
        
        printf("%d ", C[n]);
        
    }
    
    printf("\n");
    
    return 0;
    
}