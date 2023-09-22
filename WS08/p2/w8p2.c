/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* inputIntValue)
{
	int inputValue = 0;
	int valid = 0;

	do
	{
		scanf("%d", &inputValue);
		if (inputValue > 0)
		{
			valid = 1;
			if (inputIntValue != NULL)
			{
				*inputIntValue = inputValue;
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
double getDoublePositive(double* inputDoubleValue)
{
	double inputValue = 0.0;
	int valid = 0;

	do
	{
		scanf("%lf", &inputValue);
		if (inputValue > 0)
		{
			valid = 1;
			if (inputDoubleValue != NULL)
			{
				*inputDoubleValue = inputValue;
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
void openingMessage(const int productsNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", productsNum);
	printf("NOTE: A 'serving' is %dg\n", NUM_OF_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSeqNum)
{
	struct CatFoodInfo catFoodInfo = { 0 };

	putchar('\n');
	printf("Cat Food Product #%d\n", productSeqNum + 1);
	printf("--------------------\n");

	// Try calling the helper functions in different ways to get the return value
	printf("SKU           : ");
	getIntPositive(&catFoodInfo.sku);

	printf("PRICE         : $");
	catFoodInfo.productPrice = getDoublePositive(&catFoodInfo.productPrice);

	printf("WEIGHT (LBS)  : ");
	catFoodInfo.weightInLbs = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	getIntPositive(&catFoodInfo.calPerServ);

	return catFoodInfo;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calPerServ, const double* weightInLbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n",
		    sku, *price, *weightInLbs, calPerServ);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbsValue, double* equivalentKg)
{
	if (equivalentKg != NULL)
	{
		*equivalentKg = *lbsValue / LBS_FOR_KG;
	}

	return *lbsValue / LBS_FOR_KG;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbsValue, int* equivalentG)
{
	if (equivalentG != NULL)
	{
		*equivalentG = (int)(convertLbsKg(lbsValue, NULL) * 1000);
	}

	return (int)(convertLbsKg(lbsValue, NULL) * 1000);
}


// 10. convert lbs: kg and g
void convertLbs(const double* lbsValue, double* equivalentKg, int* equivalentG)
{
	convertLbsKg(lbsValue, equivalentKg);
	convertLbsG(lbsValue, equivalentG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeInG, const int totalG, double* totalServ)
{
	if (totalServ != NULL)
	{
		*totalServ = (double)totalG / servSizeInG;
	}

	return (double)totalG / servSizeInG;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServ, double* costPerServ)
{
	if (costPerServ != NULL)
	{
		*costPerServ = *price / *totalServ;
	}

	return *price / *totalServ;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal)
{
	if (costPerCal != NULL)
	{
		*costPerCal = *price / *totalCal;
	}

	return *price / *totalCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productData)
{
	struct ReportData reportData = { 0 };
	double calPerServ;

	reportData.sku = productData.sku;
	reportData.productPrice = productData.productPrice;
	reportData.calPerServ = productData.calPerServ;
	reportData.weightInLbs = productData.weightInLbs;

	convertLbs(&productData.weightInLbs, &reportData.weightInKg, &reportData.weightInG);

	calculateServings(NUM_OF_GRAMS, reportData.weightInG, &reportData.totalServ);

	calculateCostPerServing(&reportData.productPrice, &reportData.totalServ, &reportData.costPerServ);

	calPerServ = (double)reportData.calPerServ; 

	calculateCostPerCal(&reportData.costPerServ, &calPerServ, &reportData.costOfCalPerServ);

	return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUM_OF_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestOption)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		    reportData.sku, reportData.productPrice, reportData.weightInLbs,
		    reportData.weightInKg, reportData.weightInG, reportData.calPerServ, 
		    reportData.totalServ, reportData.costPerServ, reportData.costOfCalPerServ);

	if (cheapestOption)
	{
		printf(" ***");
	}
	putchar('\n');
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProductData)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf", cheapestProductData.sku, cheapestProductData.productPrice);
		
	printf("\n\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{

	struct CatFoodInfo catFoodInfo[PRODUCTS_MAX] = { {0} }; 
	struct ReportData reportData[PRODUCTS_MAX] = { {0} };
	int i, cheapestProductIndex; 
	double currentCheapest = 999.9;
	
	openingMessage(PRODUCTS_MAX);

	for (i = 0; i < PRODUCTS_MAX; i++)
	{
		catFoodInfo[i] = getCatFoodInfo(i);

		reportData[i] = calculateReportData(catFoodInfo[i]);

		if (reportData[i].costPerServ < currentCheapest)
		{
			currentCheapest = reportData[i].costPerServ;
			cheapestProductIndex = i;
		}
	}
	putchar('\n');

	displayCatFoodHeader();

	for (i = 0; i < PRODUCTS_MAX; i++)
	{
		displayCatFoodData(catFoodInfo[i].sku, &catFoodInfo[i].productPrice,
			               catFoodInfo[i].calPerServ, &catFoodInfo[i].weightInLbs);
	}
	putchar('\n');

	displayReportHeader();

	for (i = 0; i < PRODUCTS_MAX; i++)
	{
		displayReportData(reportData[i], (i == cheapestProductIndex));
	}
	putchar('\n');

	displayFinalAnalysis(catFoodInfo[cheapestProductIndex]);

}