/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

    char loopType;
    int loopCount, count;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do
    {
        printf("\nD = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &loopCount);

        if (loopType == 'D' || loopType == 'W' || loopType == 'F')
        {
            if (loopCount > 2 && loopCount < 21)
            {
                if (loopType == 'D')
                {
                    count = 0;
                    printf("DO-WHILE: ");
                    do
                    {
                        putchar(loopType);
                        count++;
                    } while (count < loopCount);
                    printf("\n");
                }
                else if (loopType == 'W')
                {
                    count = 0;
                    printf("WHILE   : ");
                    while (count < loopCount)
                    {
                        putchar(loopType);
                        count++;
                    }
                    printf("\n");
                }
                else if (loopType == 'F')
                {
                    printf("FOR     : ");
                    for (count = 0; count < loopCount; count++)
                    {
                        putchar(loopType);
                    }
                    printf("\n");
                }
            }
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (!(loopType == 'Q' && loopType == 'D' && loopType == 'W' && loopType == 'F'))
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
        else if (loopType == 'Q' && loopCount != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
    } while (!(loopType == 'Q' && loopCount == 0));

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}