/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int year, month;
    int valid; // flag
    int i, count;
    double ratingInput, morningRating, eveningRating;

    printf("General Well-being Log\n");
    printf("======================\n");

    do
    {
        valid = 1;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            valid = 0;
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC)
        {
            valid = 0;
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
    } while (!valid);

    printf("\n*** Log date set! ***\n");

    morningRating = 0.0;
    eveningRating = 0.0;
    count = 0;
    for (i = 0; i < LOG_DAYS; i++)
    {
        printf("\n%d-", year);
        switch (month)
        {
        case 1:
            printf("JAN");
            break;
        case 2:
            printf("FEB");
            break;
        case 3:
            printf("MAR");
            break;
        case 4:
            printf("APR");
            break;
        case 5:
            printf("MAY");
            break;
        case 6:
            printf("JUN");
            break;
        case 7:
            printf("JUL");
            break;
        case 8:
            printf("AUG");
            break;
        case 9:
            printf("SEP");
            break;
        case 10:
            printf("OCT");
            break;
        case 11:
            printf("NOV");
            break;
        case 12:
            printf("DEC");
            break;
        }
        printf("-0%d\n", count + 1);

        do {
            valid = 1;

            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &ratingInput);

            if (ratingInput < 0.0 || ratingInput > 5.0)
            {
                valid = 0;
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (!valid);
        
        morningRating += ratingInput;

        do {
            valid = 1;

            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &ratingInput);

            if (ratingInput < 0.0 || ratingInput > 5.0)
            {
                valid = 0;
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }

        } while (!valid);

        eveningRating += ratingInput;
        count++;
    }

    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morningRating);
    printf("Evening total rating:  %.3lf\n", eveningRating);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningRating + eveningRating);

    printf("Average morning rating:  %.1lf\n", morningRating / count);
    printf("Average evening rating:  %.1lf\n", eveningRating / count);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n",
           ((morningRating / count) + (eveningRating / count)) / 2);

    return 0;
}