// Nicole Fraidenreich
// Fun Fact: I do handstands in lots of places I visit.

#include <stdio.h>
#include <string.h>

struct Books {
    
    char title[50];
    char author[50];
    int id;
    
};

struct Customers {
    
    char firstname[20];
    char lastname[20];
    int customerid;
    char bday[20];
    char checkoutrecords[50];
    
};

int main() {
    
    struct Books Book1;
    struct Books Book2;
    struct Customers Customer1;
    
    strcpy(Customer1.firstname, "Carla");
    strcpy(Customer1.lastname, "Escalante");
    Customer1.customerid = 1;
    strcpy(Customer1.bday, "November 14th, 2000");
    strcpy(Customer1.checkoutrecords, "Borrowed one book.");
    
    strcpy(Book1.title, "In The Time of The Butterflies");
    strcpy(Book1.author, "Julia Alvarez");
    Book1.id = 200;
    
    strcpy(Book2.title, "Harry Potter and the Prisoner of Azkaban");
    strcpy(Book2.author, "J.K. Rowling");
    Book2.id = 201;
    
    // output ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    printf("Book 1 Title:          %s\n", Book1.title);
    printf("Book 1 Author:         %s\n", Book1.author);
    printf("Book 1 ID:             %d\n\n", Book1.id);
    
    printf("Book 2 Title:          %s\n", Book2.title);
    printf("Book 2 Author:         %s\n", Book2.author);
    printf("Book 2 ID:             %d\n\n", Book2.id);
    
    printf("Customer 1 Name:       %s %s\n", Customer1.firstname, Customer1.lastname);
    printf("Customer 1 ID:         %d\n", Customer1.customerid);
    printf("Customer 1 Birthday:   %s\n", Customer1.bday);
    printf("Customer 1 Records:    %s\n", Customer1.checkoutrecords);
    
    return 0;
    
}
