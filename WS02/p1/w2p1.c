/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Hyeri Jang
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
    const double TAX = 0.13;
    const char patSize = 'S';
    int patShirtCnt;
    int subTotal, taxes, total;
    double priceS, priceM, priceL;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceS);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &priceM);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceL);

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceS);
    printf("MEDIUM : $%.2lf\n", priceM);
    printf("LARGE  : $%.2lf\n\n", priceL);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &patShirtCnt);

    subTotal = (int)((priceS * patShirtCnt + 0.005) * 100);
    taxes = (subTotal * TAX) + 0.5;
    total = subTotal + taxes;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", patShirtCnt);
    printf("Sub-total: $%8.4lf\n", (double)subTotal / 100);
    printf("Taxes    : $%8.4lf\n", (double)taxes / 100);
    printf("Total    : $%8.4lf\n", (double)total / 100);

    return 0;
}