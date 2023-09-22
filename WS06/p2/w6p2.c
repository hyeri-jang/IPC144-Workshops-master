/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
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
#define MIN_VALUE 1
#define MAX_VALUE 3

int main(void)
{
	/* variables */
	const double incomeMinimum = 500, incomeMaximun = 400000, minItemCost = 100;
	double monthlyIncome, itemCostTotal;
	int itemCnt, selection;
	int forecastYears, forecastMonths;
	int i, valid, filterContinue, ShowNote;
	/* array */
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
		scanf("%lf", &monthlyIncome);

		if (monthlyIncome < incomeMinimum)
		{
			valid = 0;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n",
				incomeMinimum);
		}
		if (monthlyIncome > incomeMaximun)
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

			if (itemCost[i] < minItemCost)
			{
				valid = 0;
				printf("      ERROR: Cost must be at least $%.2lf\n", minItemCost);
			}
		} while (!valid);

		// priority validation
		do {
			valid = 1;

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority[i]);

			if (priority[i] < MIN_VALUE || priority[i] > MAX_VALUE)
			{
				valid = 0;
				printf("      ERROR: Value must be between %d and %d\n",
					MIN_VALUE, MAX_VALUE);
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
	itemCostTotal = 0;
	for (i = 0; i < itemCnt; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financed[i], itemCost[i]);
		itemCostTotal += itemCost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n", itemCostTotal);

	// forecase menu validation
	do {
		valid = 1;

		printf("\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);

		// menu = 0
		if (selection == 0)
		{
			valid = 1;
		}
		// menu = 1
		else if (selection == 1)
		{
			valid = 0;

			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			itemCostTotal = 0;
			ShowNote = 0;
			for (i = 0; i < itemCnt; i++)
			{
				itemCostTotal += itemCost[i];
				if (financed[i] == 'y')
				{
					ShowNote = 1;
				}
			}
			printf("Amount:   $%.2lf\n", itemCostTotal);
			forecastYears = itemCostTotal / (monthlyIncome * 12);
			forecastMonths = ((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome;
			if (((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome > 0)
			{
				printf("Forecast: %d years, %d months", forecastYears, forecastMonths + 1);
			}
			else
			{
				printf("Forecast: %d years, %d months", forecastYears, forecastMonths);
			}

			if (ShowNote == 1)
			{
				printf("\nNOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.");
			}
			printf("\n====================================================\n");
		}
		// menu = 2
		else if (selection == 2)
		{
			valid = 0;

			// filter validation
			do
			{
				filterContinue = 1;

				printf("\n");
				printf("What priority do you want to filter by? [1-3]: ");
				scanf("%d", &selection);

				// filter = 1
				if (selection == 1)
				{
					printf("\n====================================================\n");
					printf("Filter:   by priority (%d)\n", selection);
					itemCostTotal = 0;
					ShowNote = 0;
					for (i = 0; i < itemCnt; i++)
					{
						if (priority[i] == 1)
						{
							itemCostTotal += itemCost[i];
							if (financed[i] == 'y')
							{
								ShowNote = 1;
							}
						}

					}
					printf("Amount:   $%.2lf\n", itemCostTotal);
					forecastYears = itemCostTotal / (monthlyIncome * 12);
					forecastMonths = ((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome;

					if (((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome > 0)
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths + 1);
					}
					else
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths);
					}

					if (ShowNote == 1)
					{
						printf("\nNOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.");
					}
					printf("\n====================================================\n");
				}
				// filter = 2
				else if (selection == 2)
				{
					printf("\n====================================================\n");
					printf("Filter:   by priority (%d)\n", selection);
					itemCostTotal = 0;
					ShowNote = 0;
					for (i = 0; i < itemCnt; i++)
					{
						if (priority[i] == 2)
						{
							itemCostTotal += itemCost[i];
							if (financed[i] == 'y')
							{
								ShowNote = 1;
							}
						}

					}
					printf("Amount:   $%.2lf\n", itemCostTotal);
					forecastYears = itemCostTotal / (monthlyIncome * 12);
					forecastMonths = ((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome;
					if (((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome > 0)
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths + 1);
					}
					else
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths);
					}

					if (ShowNote == 1)
					{
						printf("\nNOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.");
					}
					printf("\n====================================================\n");
				}
				// filter = 3
				else if (selection == 3)
				{
					printf("\n====================================================\n");
					printf("Filter:   by priority (%d)\n", selection);
					itemCostTotal = 0;
					ShowNote = 0;
					for (i = 0; i < itemCnt; i++)
					{
						if (priority[i] == 3)
						{
							itemCostTotal += itemCost[i];
							if (financed[i] == 'y')
							{
								ShowNote = 1;
							}
						}
					}
					printf("Amount:   $%.2lf\n", itemCostTotal);
					forecastYears = itemCostTotal / (monthlyIncome * 12);
					forecastMonths = ((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome;
					if (((int)itemCostTotal % (int)(monthlyIncome * 12)) / monthlyIncome > 0)
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths + 1);
					}
					else
					{
						printf("Forecast: %d years, %d months", forecastYears, forecastMonths);
					}

					if (ShowNote == 1)
					{
						printf("\nNOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.");
					}
					printf("\n====================================================\n");
				}
				// error message
				else
				{
					filterContinue = 1;
					printf("ERROR: Invalid filter selection.");
				}
			} while (!filterContinue);
		}
		// error message
		else
		{
			valid = 0;
			printf("\nERROR: Invalid menu selection.\n");
		}
	} while (!valid);

	printf("\nBest of luck in all your future endeavours!\n");

	return 0;
}