/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPositive)
{
	int inputValue = 0;
	int valid = 0;

	do
	{
		scanf("%d", &inputValue);

		if (inputValue > 0)
		{
			valid = 1;
			// when intPositive has address
			if (intPositive != NULL)
			{
				*intPositive = inputValue;
			}
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (!valid);

	return inputValue;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive)
{
	double inputValue = 0.0;
	int valid = 0;

	do
	{
		scanf("%lf", &inputValue);

		if (inputValue > 0)
		{
			valid = 1;
			// when doublePositive has address
			if (doublePositive != NULL)
			{
				*doublePositive = inputValue;
			}
		}
		else
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (!valid);

	return inputValue;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int enteredProductNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n",
		    enteredProductNum);
	printf("NOTE: A 'serving' is %dg\n", NUM_OF_GRAMS);
	putchar('\n');
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum)
{
	struct CatFoodInfo catFoodInfo = { 0 };

	printf("Cat Food Product #%d\n", sequenceNum + 1);
	printf("--------------------\n");

	// Try calling the helper functions in different ways to get the return value
	printf("SKU           : ");
	getIntPositive(&catFoodInfo.sku);

	printf("PRICE         : $");
	catFoodInfo.productPrice = getDoublePositive(&catFoodInfo.productPrice);

	printf("WEIGHT (LBS)  : ");
	catFoodInfo.weightInPound = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	getIntPositive(&catFoodInfo.carPerServ);
	putchar('\n');

	return catFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* productPrice, const int carPerServ, const double* weightInPound)
{
	printf("%07d %10.2lf %10.1lf %8d\n",		    sku, *productPrice, *weightInPound, carPerServ);}

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFoodInfo[PRODUCT_MAX] = { {0} };
	int i;

	openingMessage(PRODUCT_MAX);

	for (i = 0; i < PRODUCT_MAX; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < PRODUCT_MAX; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].productPrice,
			               catFoodInfo[i].carPerServ, &catFoodInfo[i].weightInPound);
	}
} 