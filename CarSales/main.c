#include <stdio.h>
#include <stdlib.h> // for atoi function

// Function to get input with a prompt
void get_input_with_prompt(const char *prompt, char *input) {
    // Print the prompt
    printf("%s", prompt);

    // Read the input and write it to the input buffer
    scanf("%s", input);
}

int main() {
    /* Constants */
    #define CAR_PRICE 20500.0f
    #define DISCOUNT_MULTIBUY_PERCENTAGE 0.20f
    #define DISCOUNT_MULTIBUY_AMOUNT 3
    #define DISCOUNT_MEMBER_PERCENTAGE 0.25f

    /* Variables */
    unsigned short carsAvailable = 10, carsNeeded = 0, giveDiscount = 0;
    float totalPrice = 0.0f, discountValue = 0.0f;
    char isMemberOfCarClub;
    
    // Variables to store user input for name and age
    char firstName[20];
    char lastName[20];
    char age[4]; // Allow up to 3 digits for age
    int userAge;
    char userChoice;
    

    // Get the user's first name
    const char *firstNamePrompt = "Enter your first name: ";
    get_input_with_prompt(firstNamePrompt, firstName);

    // Get the user's last name
    const char *lastNamePrompt = "Enter your last name: ";
    get_input_with_prompt(lastNamePrompt, lastName);

    // Get the user's age
    const char *agePrompt = "Enter your age: ";
    get_input_with_prompt(agePrompt, age);
    userAge = atoi(age); // Convert the age input from string to integer

    // Greet the user
    printf("\nHello %s %s, age %d! Welcome to the Car Sales office!\n\n", firstName, lastName, userAge);

    // Display the menu options
    printf("Menu:\n");
    printf("a. Buy Cars\n");
    printf("b. View Sales Stats\n");
    printf("x. Exit\n\n");
    
    printf("Please select a option: ");
    scanf(" %c", &userChoice);
    getchar();
    
    

    // Stock info
    if (carsAvailable > 0) {
        printf("We have %hd cars available. Each car costs %.2f.\n\n", carsAvailable, CAR_PRICE);
    } else {
        printf("Sorry, there are no more cars available.");
        return 0;
    }

    // Prompt the user for how many cars they want to buy
    printf("How many cars would you like to buy? Amount: ");
    scanf("%hd", &carsNeeded);

    // Check if there are enough cars in stock
    if (carsAvailable < carsNeeded) {
        printf("Sorry, there are fewer cars available than you require.");
        return 0;
    }

    // Calculate the total price and update the stock
    totalPrice = carsNeeded * CAR_PRICE;
    carsAvailable -= carsNeeded;

    // Ask if the user is a member of the Car Club
    printf("\nAre you a member of the Car Club? Answer (Y/N): ");
    scanf("\n%c", &isMemberOfCarClub);

    // Apply discounts if necessary
    if (isMemberOfCarClub == 'Y') {
        giveDiscount = 1;
        totalPrice *= (1 - DISCOUNT_MEMBER_PERCENTAGE);
        discountValue = DISCOUNT_MEMBER_PERCENTAGE * 100; // Convert to percentage
    } else if (carsNeeded >= DISCOUNT_MULTIBUY_AMOUNT) {
        giveDiscount = 1;
        totalPrice *= (1 - DISCOUNT_MULTIBUY_PERCENTAGE);
        discountValue = DISCOUNT_MULTIBUY_PERCENTAGE * 100; // Convert to percentage
    }

    // Present the discount outcome
    switch (giveDiscount) {
        case 1:
            printf("\nDiscount of %.0f%% applied!\n", discountValue);
            break;
        case 0:
            printf("\nNo discount applied.\n");
            break;
    }

    // Present the final outcome
    printf("\nThank you for your purchase.\n");
    printf("You have bought %hd cars. Total price to pay is %.2f.\n", carsNeeded, totalPrice);
    printf("There are %hd cars remaining.\n\n", carsAvailable);

    printf("Thank you. Have a great day!\n");

    return 0;
}
