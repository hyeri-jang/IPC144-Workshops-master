#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    int patShirtCnt, salShirtCnt, tomShirtCnt;
    int patSubTotal, salSubTotal, tomSubTotal;
    int patTaxes, salTaxes, tomTaxes;
    int patTotal, salTotal, tomTotal;
    int taxExcludeTotal, taxIncludeTotal;
    int remainder;
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

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &tomShirtCnt);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &salShirtCnt);

    patSubTotal = (int)((priceS * patShirtCnt + 0.005) * 100);
    patTaxes = (patSubTotal * TAX) + 0.5;
    patTotal = patSubTotal + patTaxes;

    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, priceS, patShirtCnt, (double)patSubTotal / 100, (double)patTaxes / 100, (double)patTotal / 100);

    salSubTotal = (int)((priceM * salShirtCnt + 0.005) * 100);
    salTaxes = (salSubTotal * TAX) + 0.5;
    salTotal = salSubTotal + salTaxes;

    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, priceM, salShirtCnt, (double)salSubTotal / 100, (double)salTaxes / 100, (double)salTotal / 100);

    tomSubTotal = (int)((priceL * tomShirtCnt + 0.005) * 100);
    tomTaxes = (tomSubTotal * TAX) + 0.5;
    tomTotal = tomSubTotal + tomTaxes;

    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, priceL, tomShirtCnt, (double)tomSubTotal / 100, (double)tomTaxes / 100, (double)tomTotal / 100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", (double)(patSubTotal+salSubTotal+tomSubTotal) / 100, (double)(patTaxes + salTaxes + tomTaxes) / 100, (double)(patTotal + salTotal + tomTotal) / 100);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    taxExcludeTotal = patSubTotal + salSubTotal + tomSubTotal;

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)taxExcludeTotal / 100);
    
    remainder = taxExcludeTotal % 200;
    printf("Toonies  %3d %9.4lf\n", taxExcludeTotal / 200, remainder / 100.0);
    printf("Loonies  %3d %9.4lf\n", remainder / 100, remainder % 100 / 100.0);
    remainder %= 100;
    printf("Quarters %3d %9.4lf\n", remainder / 25, remainder % 25 / 100.0);
    remainder %= 25;
    printf("Dimes    %3d %9.4lf\n", remainder / 10, remainder % 10 / 100.0);
    remainder %= 10;
    printf("Nickels  %3d %9.4lf\n", remainder / 5, remainder % 5 / 100.0);
    remainder %= 5;
    printf("Pennies  %3d %9.4lf\n\n", remainder, remainder % 1/ 100.0);
    
    printf("Average cost/shirt: $%.4lf\n\n", (double)(patSubTotal + salSubTotal + tomSubTotal) / (patShirtCnt + salShirtCnt + tomShirtCnt) / 100);

    taxIncludeTotal =  patSubTotal + patTaxes + salSubTotal + salTaxes + tomSubTotal + tomTaxes;

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)taxIncludeTotal / 100);

    remainder = taxIncludeTotal % 200;
    printf("Toonies  %3d %9.4lf\n", taxIncludeTotal / 200, remainder / 100.0);
    printf("Loonies  %3d %9.4lf\n", remainder / 100, remainder % 100 / 100.0);
    remainder %= 100;
    printf("Quarters %3d %9.4lf\n", remainder / 25, remainder % 25 / 100.0);
    remainder %= 25;
    printf("Dimes    %3d %9.4lf\n", remainder / 10, remainder % 10 / 100.0);
    remainder %= 10;
    printf("Nickels  %3d %9.4lf\n", remainder / 5, remainder % 5 / 100.0);
    remainder %= 5;
    printf("Pennies  %3d %9.4lf\n\n", remainder, remainder % 1 / 100.0);
    
    printf("Average cost/shirt: $%.4lf\n\n", (double)(patTotal + salTotal + tomTotal) / (patShirtCnt + salShirtCnt + tomShirtCnt) / 100);

    return 0;
}
