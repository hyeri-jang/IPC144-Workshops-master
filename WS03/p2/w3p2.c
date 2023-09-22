/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  : HYERI JANG
Student ID#: 115328221
Email      : hjang34@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee1Type, coffee2Type, coffee3Type;
    char coffee1Cream, coffee2Cream, coffee3Cream;
    char customerCoffeeType, customerCoffeeCream;
    int coffee1Weight, coffee2Weight, coffee3Weight;
    int customerCoffeeServing;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1Type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee1Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1Cream);

    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2Type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee2Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2Cream);

    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3Type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee3Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3Cream);

    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        coffee1Type == 'l' || coffee1Type == 'L',
        coffee1Type == 'm' || coffee1Type == 'M',
        coffee1Type == 'r' || coffee1Type == 'R',
        coffee1Weight, coffee1Weight / GRAMS_IN_LBS,
        coffee1Cream == 'y' || coffee1Cream == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
        coffee2Type == 'l' || coffee2Type == 'L',
        coffee2Type == 'm' || coffee2Type == 'M',
        coffee2Type == 'r' || coffee2Type == 'R',
        coffee2Weight, coffee2Weight / GRAMS_IN_LBS, 
        coffee2Cream == 'y' || coffee2Cream == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
        coffee3Type == 'l' || coffee3Type == 'L', 
        coffee3Type == 'm' || coffee3Type == 'M', 
        coffee3Type == 'r' || coffee3Type == 'R',
        coffee3Weight, coffee3Weight / GRAMS_IN_LBS, 
        coffee3Cream == 'y' || coffee3Cream == 'Y');
    
    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerCoffeeType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCoffeeCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerCoffeeServing);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
            (customerCoffeeType == coffee1Type) ||
            ((customerCoffeeType - coffee1Type) == ('a' - 'A')) ||
            ((coffee1Type - customerCoffeeType) == ('a' - 'A')),
            (customerCoffeeServing < 5 && 250 == coffee1Weight) ||
            (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee1Weight) ||
            (customerCoffeeServing > 10 && 1000 == coffee1Weight),
            (customerCoffeeCream == coffee1Cream) ||
            ((customerCoffeeCream - coffee1Cream) == ('a' - 'A')) ||
            ((customerCoffeeCream - coffee1Cream) == ('a' - 'A')));
    printf(" 2|       %d         |      %d      |   %d   |\n",
            (customerCoffeeType == coffee2Type) ||
            ((customerCoffeeType - coffee2Type) == ('a' - 'A')) ||
            ((coffee2Type - customerCoffeeType) == ('a' - 'A')),
            (customerCoffeeServing < 5 && 250 == coffee2Weight) ||
            (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee2Weight) ||
            (customerCoffeeServing > 10 && 1000 == coffee2Weight),
            (customerCoffeeCream == coffee2Cream) ||
            ((customerCoffeeCream - coffee2Cream) == ('a' - 'A')) ||
            ((customerCoffeeCream - coffee2Cream) == ('a' - 'A')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n",
            (customerCoffeeType == coffee3Type) ||
            ((customerCoffeeType - coffee3Type) == ('a' - 'A')) ||
            ((coffee3Type - customerCoffeeType) == ('a' - 'A')),
            (customerCoffeeServing < 5 && 250 == coffee3Weight) ||
            (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee3Weight) ||
            (customerCoffeeServing > 10 && 1000 == coffee3Weight),
            (customerCoffeeCream == coffee3Cream) ||
            ((customerCoffeeCream - coffee3Cream) == ('a' - 'A')) ||
            ((customerCoffeeCream - coffee3Cream) == ('a' - 'A')));

    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &customerCoffeeType);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &customerCoffeeCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &customerCoffeeServing);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");

    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (customerCoffeeType == coffee1Type) ||
        ((customerCoffeeType - coffee1Type) == ('a' - 'A')) ||
        ((coffee1Type - customerCoffeeType) == ('a' - 'A')),
        (customerCoffeeServing < 5 && 250 == coffee1Weight) ||
        (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee1Weight) ||
        (customerCoffeeServing > 10 && 1000 == coffee1Weight),
        (customerCoffeeCream == coffee1Cream) ||
        ((customerCoffeeCream - coffee1Cream) == ('a' - 'A')) ||
        ((coffee1Cream - customerCoffeeCream) == ('a' - 'A')));
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (customerCoffeeType == coffee2Type) ||
        ((customerCoffeeType - coffee2Type) == ('a' - 'A')) ||
        ((coffee2Type - customerCoffeeType) == ('a' - 'A')),
        (customerCoffeeServing < 5 && 250 == coffee2Weight) ||
        (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee2Weight) ||
        (customerCoffeeServing > 10 && 1000 == coffee2Weight),
        (customerCoffeeCream == coffee2Cream) ||
        ((customerCoffeeCream - coffee2Cream) == ('a' - 'A')) ||
        ((coffee2Cream - customerCoffeeCream) == ('a' - 'A')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n",
        (customerCoffeeType == coffee3Type) ||
        ((customerCoffeeType - coffee3Type) == ('a' - 'A')) ||
        ((coffee3Type - customerCoffeeType) == ('a' - 'A')),
        (customerCoffeeServing < 5 && 250 == coffee3Weight) ||
        (customerCoffeeServing > 5 && customerCoffeeServing < 10 && 500 == coffee3Weight) ||
        (customerCoffeeServing > 10 && 1000 == coffee3Weight),
        (customerCoffeeCream == coffee3Cream) ||
        ((customerCoffeeCream - coffee3Cream) == ('a' - 'A')) ||
        ((coffee3Cream - customerCoffeeCream) == ('a' - 'A')));

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}