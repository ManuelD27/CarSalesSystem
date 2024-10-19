#include <stdio.h>

// Function to get input with a prompt
void get_input_with_prompt(const char *prompt, char *input)
{
    printf("%s", prompt);  // Print the prompt
    scanf("%s", input);    // Store the user's input in the input variable
}

int main()
{
    /* Constants */
    #define CAR_PRICE 20500.0f
    #define DISCOUNT_MULTIBUY_PERCENTAGE 0.20f
    #define DISCOUNT_MULTIBUY_AMOUNT 3
    #define DISCOUNT_MEMBER_PERCENTAGE 0.25f

    /* Variables */
    unsigned short carsAvailable = 10, carsNeeded = 0, giveDiscount = 0;
    float totalPrice = 0.0f, discountValue;
    char isMemberOfCarClub;
    char firstName[20];  // Array to store the first name
    char lastName[20];   // Array to store the last name
    int userAge;

    // Use the get_input_with_prompt function to gather input
    get_input_with_prompt("Enter your first name: ", firstName);
    get_input_with_prompt("Enter your last name: ", lastName);

    printf("Enter your age. Age: ");
    scanf("%d", &userAge);
    
    printf("\nMenu:\n");
    printf("a. Buy Cars\n");
    printf("b. View Sales Stats\n");
    printf("x. Exit\n\n");

    /* Greeting */
    printf("Hello %s %s, Welcome to the Car Sales office!\n\n", firstName, lastName);

    /* Stock info */
    if (carsAvailable > 0)
    {
        printf("We have %hd cars available. Each car costs %.2f.\n\n", carsAvailable, CAR_PRICE);
    }
    else
    {
        printf("Sorry, there are no more cars available.");
        return 0;
    }

    /* Prompt cars needed */
    printf("How many cars would you like to buy? Amount: ");
    scanf("%hd", &carsNeeded);

    /* Check available stock */
    if (carsAvailable < carsNeeded)
    {
        printf("Sorry, there are fewer cars available than you require.");
        return 0;
    }

    /* Calculate full price & update stock */
    totalPrice = carsNeeded * CAR_PRICE;
    carsAvailable -= carsNeeded;

    /* Start discount checks */
    printf("\nAre you a member of the Car Club? Answer (Y/N) = ");
    scanf("\n%c", &isMemberOfCarClub);

    // Check if member discount needs to be applied
    if (isMemberOfCarClub == 'Y')
    {
        giveDiscount = 1;
        totalPrice *= (1 - DISCOUNT_MEMBER_PERCENTAGE);
        discountValue = DISCOUNT_MEMBER_PERCENTAGE;
    }
    // Otherwise, check multibuy discount
    else if (carsNeeded >= DISCOUNT_MULTIBUY_AMOUNT)
    {
        giveDiscount = 1;
        totalPrice *= (1 - DISCOUNT_MULTIBUY_PERCENTAGE);
        discountValue = DISCOUNT_MULTIBUY_PERCENTAGE;
    }

    /* Present discount outcome */
    switch (giveDiscount)
    {
        case 1:
            discountValue *= 100; // Convert from 0.2 format to 20% format
            printf("\nDiscount of %.0f%% applied!\n", discountValue);
            break;
        case 0:
            printf("\nDiscount not applied.\n");
            break;
    }

    /* Present final outcome */
    printf("\nThank you for your custom.\n");
    printf("\nYou have bought %hd cars. Total price to pay is %.2f.", carsNeeded, totalPrice);
    printf("\n\nThere are %hd cars remaining.", carsAvailable);

    printf("\n\nThank you. Have a good day!\n");

    return 0;
}
