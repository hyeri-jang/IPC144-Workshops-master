/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

#define MAX_ITEM_CNT 10
#define MIN_ITEM_CNT 1
#define MIN_ITEM_COST 100.00

int main(void)
{
	/* variables */
	const double incomeMinimum = 500, incomeMaximun = 400000;
	double userIncome, itemCostTotal;
	int itemCnt;
	int i, valid;
	/* arrays */
	double itemCost[MAX_ITEM_CNT] = { 0 };
	int priority[MAX_ITEM_CNT] = { 0 };
	char financed[MAX_ITEM_CNT] = { 0 };

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	// income validation
	do {
		valid = 1;

		printf("\n");
		printf("Enter your monthly NET income: $");
		scanf("%lf", &userIncome);

		if (userIncome < incomeMinimum)
		{
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n",
				   incomeMinimum);
		}
		if (userIncome > incomeMaximun)
		{
			valid = 0;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n",
				    incomeMaximun);
		}
	} while (!valid);

	// wish list item count validation
	do {
		valid = 1;

		printf("\n");
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &itemCnt);

		if (itemCnt < MIN_ITEM_CNT || itemCnt > MAX_ITEM_CNT)
		{
			valid = 0;
			printf("ERROR: List is restricted to between %d and %d items.\n",
				    MIN_ITEM_CNT, MAX_ITEM_CNT);
		}
	} while (!valid);

	// prompt datas for parallel arrays
	for (i = 0; i < itemCnt; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);

		// item cost validation
		do {
			valid = 1;
			printf("   Item cost: $");
			scanf("%lf", &itemCost[i]);

			if (itemCost[i] < MIN_ITEM_COST)
			{
				valid = 0;
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_ITEM_COST);
			}
		} while (!valid);

		// priority validation
		do {
			valid = 1;
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < 1 || priority[i] > 3)
			{
				valid = 0;
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (!valid);

		// financing options validation
		do {
			valid = 1;
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financed[i]);

			if (!(financed[i] == 'y' || financed[i] == 'n'))
			{
				valid = 0;
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (!valid);
	}

	// summarize
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < itemCnt; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], itemCost[i]);
	}
	printf("---- -------- -------- -----------\n");
	itemCostTotal = 0;
	for (i = 0; i < itemCnt; i++)
	{
		itemCostTotal += itemCost[i];
	}
	printf("                      $%11.2lf\n\n", itemCostTotal);

	printf("Best of luck in all your future endeavours!\n");

    return 0;
}