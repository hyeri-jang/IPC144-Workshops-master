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


// ----------------------------------------------------------------------------
// defines/macros
#define PRODUCTS_MAX 3
#define NUM_OF_GRAMS 64
#define LBS_FOR_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int sku;
	double productPrice;
	int calPerServ;
	double weightInLbs;
};

struct ReportData
{
	int sku;
	double productPrice;
	int calPerServ;
	double weightInLbs;
	double weightInKg;
	int weightInG;
	double totalServ;
	double costPerServ;
	double costOfCalPerServ;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intValue);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doubleValue);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productsNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSeqNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* price, const int calPerServ, const double* weightInLbs);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* lbsValue, double* equivalentKg);

// 9. convert lbs: g
int convertLbsG(const double* lbsValue, int* equivalentG);

// 10. convert lbs: kg / g
void convertLbs(const double* lbsValue, double* equivalentKg, int* equivalentG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeInG, const int totalG, double* totalServ);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServ, double* costPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCal, double* costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo productData);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int cheapestOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProductData);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);