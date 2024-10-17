#include <stdio.h>

// #include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_user_details()
{
    // This asks user for name and age//
    char firstName[20];
    const char *firstNamePrompt = "Enter your first name: ";
    get_input_with_prompt(firstNamePrompt, firstName);

    const char *lastNamePrompt = "Enter your last name: ";
    char lastName[20];
    get_input_with_prompt(firstNamePrompt, lastName);

    const char *agePrompt = "Enter your age. Age: ";
    char age[2];
    get_input_with_prompt(agePrompt, age);
    int userAge = atoi(age);

    printf("Hello %s, %s, Welcome to the Car Sales office!\n\n", firstName, lastName);
}

void get_input_with_prompt(const char *prompt, char *input)
{
    // 1. Print the prompt
    printf("%s", prompt);

    // 2. Read the input and write it to the input buffer
    scanf("%s", input);
}

// A struct to hold the discount information
typedef struct
{
    int applied;
    float value;
} Discount;

Discount apply_discount(char club_member, float *totalPrice, int carsNeeded, float discountPercentage, float multibuy_discount)
{
    float discountValue;
    int discountApplied = 0;
    // check if member discount needs to be applied
    if (club_member == 'Y' || club_member == 'y')
    {
        discountApplied = 1;
        *totalPrice *= (1 - discountPercentage);
        discountValue = discountPercentage;
    }
    // otherwise, check multibuy discount
    else if (carsNeeded >= multibuy_discount)
    {
        discountApplied = 1;
        *totalPrice *= (1 - multibuy_discount);
        discountValue = multibuy_discount;
    }

    return (Discount){discountApplied, discountValue};
}

int main()
{
    
    /* Constants */
#define CAR_PRICE 20500.0f
#define DISCOUNT_MULTIBUY_PERCENTAGE 0.20f
#define DISCOUNT_MULTIBUY_AMOUNT 3
#define DISCOUNT_MEMBER_PERCENTAGE 0.25f

    /* Variables */
    unsigned short carsAvailable = 10;
    // defining each variable independently allows us to add comments
    unsigned short arsNeeded = 0;
    // It also helps us when refactoring our code, we only get to touch a single line
    unsigned short giveDiscount = 0;

    // A function to get user details
    get_user_details();

    // Potential candiate for a menu function??
    printf("Menu:\n");
    printf("a. Buy Cars\n");
    printf("b. View Sales Stats\n");
    printf("x. Exit\n\n");
    
    

    /* Stock info */
    if (carsAvailable > 0)
    {
        printf("We have %hd cars available. Each car costs %.2f.\n\n",
               carsAvailable, CAR_PRICE);
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

    // check if member discount needs to be applied
    //        first because % is greater
    if (isMemberOfCarClub == 'Y')
    {
        giveDiscount = 1;
        totalPrice *= (1 - DISCOUNT_MEMBER_PERCENTAGE);
        discountValue = DISCOUNT_MEMBER_PERCENTAGE;
    }
        // otherwise, check multibuy discount
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
            // convert from 0.2 format to 20% format
            discountValue *= 100;
            // hide decimals, not needed
            printf("\nDiscount of %.0f%% applied!\n", discountValue);
            break;
        case 0:
            printf("\nDiscount not applied.\n");
            break;
    }

    /* Present final outcome */
    printf("\nThank you for your custom.\n");
    printf("\nYou have bought %hd cars. Total price to pay is %.2f.",
           carsNeeded, totalPrice);

    printf("\n\nThere are %hd cars remaining.", carsAvailable);

    printf("\n\nThank you. Have a good day!");

    return 0;
}
