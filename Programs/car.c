// Sonny Li
// Intro to Programming in C

#include <stdio.h>
#include <string.h>

struct Car {
    
    char make[50];
    char model[50];
    float expense;
    float price;
    int quantity;
    
};

int main() {
    
    struct Car car1;
    struct Car car2;
    struct Car car3;
    struct Car car4;
    
    strcpy(car1.make, "Mercedes");
    strcpy(car1.model, "GLE SUV");
    car1.expense = 6000;
    car1.price = 69000;
    car1.quantity = 3;
    
    strcpy(car2.make, "Porsche");
    strcpy(car2.model, "Macan");
    car2.expense = 8000;
    car2.price = 68999.99;
    car2.quantity = 5;
    
    strcpy(car3.make, "Audi");
    strcpy(car3.model, "R8");
    car3.expense = 30000;
    car3.price = 120000;
    car3.quantity = 2;
    
    strcpy(car4.make, "BMW");
    strcpy(car4.model, "X5");
    car4.expense = 4000;
    car4.price = 65000;
    car4.quantity = 7;
    
    car1.price = 1.6 * car1.price;
    
    car2.expense = 0;
    
    printf("Car 1 make:      %s\n", car1.make);
    printf("Car 1 model:     %s\n", car1.model);
    printf("Car 1 expense:   $%.2f\n", car1.expense);
    printf("Car 1 price:     $%.2f\n", car1.price);
    printf("Car 1 quantity:  %d\n", car1.quantity);
    printf("\n");
    
    printf("Car 1 value = $%.2f\n", car1.price * car1.quantity);
    printf("\n");
    
    printf("Car 2 make:      %s\n", car2.make);
    printf("Car 2 model:     %s\n", car2.model);
    printf("Car 2 expense:   $%.2f\n", car2.expense);
    printf("Car 2 price:     $%.2f\n", car2.price);
    printf("Car 2 quantity:  %d\n", car2.quantity);
    printf("\n");
    
    printf("Car 2 value = $%.2f\n", car2.price * car2.quantity);
    printf("\n");
    
    printf("Car 3 make:      %s\n", car3.make);
    printf("Car 3 model:     %s\n", car3.model);
    printf("Car 3 expense:   $%.2f\n", car3.expense);
    printf("Car 3 price:     $%.2f\n", car3.price);
    printf("Car 3 quantity:  %d\n", car3.quantity);
    printf("\n");
    
    printf("Car 3 value = $%.2f\n", car3.price * car3.quantity);
    printf("\n");
    
    printf("Car 4 make:      %s\n", car4.make);
    printf("Car 4 model:     %s\n", car4.model);
    printf("Car 4 expense:   $%.2f\n", car4.expense);
    printf("Car 4 price:     $%.2f\n", car4.price);
    printf("Car 4 quantity:  %d\n", car4.quantity);
    printf("\n");
    
    printf("Car 4 value = $%.2f\n", car4.price * car4.quantity);
    printf("\n");
    
    return 0;
    
}
