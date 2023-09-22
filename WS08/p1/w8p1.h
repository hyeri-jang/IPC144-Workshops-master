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

// ----------------------------------------------------------------------------
// macros
#define PRODUCT_MAX 3
#define NUM_OF_GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    int sku;
    double productPrice;
    int carPerServ;
    double weightInPound;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPositive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int enteredProductNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* productPrice, const int carPerSer, const double* weightInPound);

// 7. Logic entry point
void start(void);