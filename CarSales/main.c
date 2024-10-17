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
               carsAvailable, car_price);
    }
    else
    {
        printf("Sorry, there are no more cars available.");
        return 0;
    }

    /* Prompt cars needed */
    char quantity[2];
    const char *quantityPrompt = "How many cars would you like to buy? Amount: ";
    get_input_with_prompt(quantityPrompt, quantity);
    carsNeeded = atoi(quantity);

    /* Check available stock */
    if (carsAvailable < carsNeeded)
    {
        printf("Sorry, there are fewer cars available than you require.");
        return 0;
    }

    /* Calculate full price & update stock */
    float totalPrice = carsNeeded * car_price;
    carsAvailable -= carsNeeded;

    /* Start discount checks */
    char isMemberOfCarClub;
    const char *carClubMemberPrompt = "\nAre you a member of the Car Club? Answer (Y/N) = ";
    get_input_with_prompt(carClubMemberPrompt, isMemberOfCarClub);

    // Applies a discount for car club members or multibuy discount
    // takes in the total price, the number of cars needed, and the discount percentage
    // returns a discount struct with the discount applied and the value of the discount
    // we also mutate totalPrice slightly different to show how we can pass mutable values to a function
    Discount discount = apply_discount(isMemberOfCarClub, &totalPrice, carsNeeded, DISCOUNT_MEMBER_PERCENTAGE, DISCOUNT_MULTIBUY_PERCENTAGE);

    /* Present discount outcome */
    if (discount.applied)
    {
        printf("\nDiscount of %.0f%% applied!\n", discount.value * 100);
    }
    else
    {
        printf("\nDiscount not applied.\n");
    }
    /* Present final outcome */
    printf("\nThank you for your custom.\n");
    printf("\nYou have bought %hd cars. Total price to pay is %.2f.",
           carsNeeded, totalPrice);

    printf("\n\nThere are %hd cars remaining.", carsAvailable);

    printf("\n\nThank you. Have a good day!");

    return 0;
}