//
//  main.c
//  helloAge
//
//  Created by Manuel Duffis on 01/10/2024.
//

#include <stdio.h>

int main() {
    int age;
    char firstName[20];
    char lastName[20];

    printf("\nEnter your first name: ");
    scanf("%19s", firstName);  // Prevent buffer overflow

    printf("\nEnter your last name: ");
    scanf("%19s", lastName);  // Prevent buffer overflow

    printf("\nEnter your age: ");

    // Validate age input
    while (scanf("%d", &age) != 1) {
        // Clear the input buffer
        while (getchar() != '\n');
        printf("\nInvalid input. Please enter a valid age: ");
    }

    printf("\nHello %s %s you're %d years old!", firstName, lastName, age);
    

    return 0;
}

