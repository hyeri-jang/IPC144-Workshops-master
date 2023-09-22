/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : HYERI JANG
Student ID#: 115328221
Email      : hjang34@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int applesNeeded, orangesNeeded, pearsNeeded, tomatoesNeeded, cabbagesNeeded;
    int applesCnt, orangesCnt, pearsCnt, tomatoesCnt, cabbagesCnt;
    int continueShopping; // flag

        do
        {
            printf("Grocery Shopping\n");
            printf("================\n");

            do
            {
                printf("How many APPLES do you need? : ");
                scanf("%d", &applesNeeded);
                if (applesNeeded < 0)
                {
                    printf("ERROR: Value must be 0 or more.\n");
                }
            } while (applesNeeded < 0);
            printf("\n");

           do
            {
                printf("How many ORANGES do you need? : ");
                scanf("%d", &orangesNeeded);
                if (orangesNeeded < 0)
                {
                    printf("ERROR: Value must be 0 or more.\n");
                }
            } while (orangesNeeded < 0);
            printf("\n");

            do
            {
                printf("How many PEARS do you need? : ");
                scanf("%d", &pearsNeeded);
                if (pearsNeeded < 0)
                {
                    printf("ERROR: Value must be 0 or more.\n");
                }
            } while (pearsNeeded < 0);
            printf("\n");

            do
            {
                printf("How many TOMATOES do you need? : ");
                scanf("%d", &tomatoesNeeded);
                if (tomatoesNeeded < 0)
                {
                    printf("ERROR: Value must be 0 or more.\n");
                }
            } while (tomatoesNeeded < 0);
            printf("\n");

            do
            {
                printf("How many CABBAGES do you need? : ");
                scanf("%d", &cabbagesNeeded);
                if (cabbagesNeeded < 0)
                {
                    printf("ERROR: Value must be 0 or more.\n");
                }
            } while (cabbagesNeeded < 0);
            printf("\n");

            printf("--------------------------\n");
            printf("Time to pick the products!\n");
            printf("--------------------------\n\n");

            if (applesNeeded > 0)
            {
                do
                {
                    printf("Pick some APPLES... how many did you pick? : ");
                    scanf("%d", &applesCnt);

                    if (applesCnt <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else
                    {
                        if (applesCnt > applesNeeded)
                        {
                            printf("You picked too many... only %d more APPLE(S) are needed.\n", applesNeeded);
                        }
                        else
                        {
                            applesNeeded -= applesCnt;
                            if (applesNeeded != 0)
                            {
                                printf("Looks like we still need some APPLES...\n");
                            }
                            else
                            {
                                printf("Great, that's the apples done!\n\n");
                            }
                        }
                    }
                } while (applesNeeded != 0);
            }

            if (orangesNeeded > 0)
            {
                do
                {
                    printf("Pick some ORANGES... how many did you pick? : ");
                    scanf("%d", &orangesCnt);

                    if (orangesCnt <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else
                    {
                        if (orangesCnt > orangesNeeded)
                        {
                            printf("You picked too many... only %d more ORANGE(S) are needed.\n", orangesNeeded);
                        }
                        else 
                        {
                            orangesNeeded -= orangesCnt;
                            if (orangesNeeded != 0)
                            {
                                printf("Looks like we still need some ORANGES...\n");
                            }
                            else
                            {
                                printf("Great, that's the oranges done!\n\n");
                            }
                        }
                    }
                } while (orangesNeeded != 0);
            }

            if (pearsNeeded > 0)
            {
                do
                {
                    printf("Pick some PEARS... how many did you pick? : ");
                    scanf("%d", &pearsCnt);

                    if (pearsCnt <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else
                    {
                        if (pearsCnt > pearsNeeded)
                        {
                            printf("You picked too many... only %d more PEAR(S) are needed.\n", pearsNeeded);
                        }
                        else
                        {
                            pearsNeeded -= pearsCnt;
                            if (pearsNeeded != 0)
                            {
                                printf("Looks like we still need some PEARS...\n");
                            }
                            else
                            {
                                printf("Great, that's the pears done!\n\n");
                            }
                        }
                    }
                } while (pearsNeeded != 0);
            }

            if (tomatoesNeeded > 0)
            {
                do
                {
                    printf("Pick some TOMATOES... how many did you pick? : ");
                    scanf("%d", &tomatoesCnt);

                    if (tomatoesCnt <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else
                    {
                        if (tomatoesCnt > tomatoesNeeded)
                        {
                            printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoesNeeded);
                        }
                        else
                        {
                            tomatoesNeeded -= tomatoesCnt;
                            if (tomatoesNeeded != 0)
                            {
                                printf("Looks like we still need some TOMATOES...\n");
                            }
                            else
                            {
                                printf("Great, that's the tomatoes done!\n\n");
                            }
                    }
                    }
                } while (tomatoesNeeded != 0);
            }

            while (cabbagesNeeded > 0)
            {
                do
                {
                    printf("Pick some CABBAGES... how many did you pick? : ");
                    scanf("%d", &cabbagesCnt);

                    if (cabbagesCnt <= 0)
                    {
                        printf("ERROR: You must pick at least 1!\n");
                    }
                    else
                    {
                        if (cabbagesCnt > cabbagesNeeded)
                        {
                            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbagesNeeded);
                        }
                        else
                        {
                            cabbagesNeeded -= cabbagesCnt;
                            if (cabbagesNeeded != 0)
                            {
                                printf("Looks like we still need some CABBAGES...\n");
                            }
                            else
                            {
                                printf("Great, that's the cabbages done!\n\n");
                            }
                        }
                    }
                } while (cabbagesNeeded != 0);
            }

            printf("All the items are picked!\n\n");

            printf("Do another shopping? (0=NO): ");
            scanf("%d", &continueShopping);
            printf("\n");

        } while (continueShopping);

        printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
                                                                                                                       