/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MIN_PATH_LENGHT 10
#define MAX_PATH_LENGHT 70
#define MIN_PLAYER_LIVES 1
#define MAX_PLAYER_LIVES 10
#define MULTIPLY 5

struct PlayerInfo
{
    int playerLives;
    char playerSymbol;
    int treasureCount;
    int pastPositions[MAX_PATH_LENGHT];
};

struct GameInfo
{
    int maxMoves;
    int pathLength;
    int bombs[MAX_PATH_LENGHT];
    int treasures[MAX_PATH_LENGHT];
};

int main(void)
{
    int i, j, valid;

    struct PlayerInfo PlayerA = { 0 };
    struct GameInfo GameA = { 0 };


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &PlayerA.playerSymbol);
    
    valid = 1;
    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &PlayerA.playerLives);
        
        if (PlayerA.playerLives <= MIN_PLAYER_LIVES || 
            PlayerA.playerLives > MAX_PLAYER_LIVES)
        {
            valid = 0;
            printf("     Must be between %d and %d!\n",
                    MIN_PLAYER_LIVES, MAX_PLAYER_LIVES);
        }
        else
        {
            valid = 1;
        }
    } while (!valid);

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    valid = 1;
    do
    {
        printf("Set the path length (a multiple of %d between %d-%d): ",
                MULTIPLY, MIN_PATH_LENGHT, MAX_PATH_LENGHT);
        scanf("%d", &GameA.pathLength);

        if (GameA.pathLength < MIN_PATH_LENGHT ||
            GameA.pathLength > MAX_PATH_LENGHT ||
            GameA.pathLength % MULTIPLY != 0)
        {
            valid = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n",
                    MULTIPLY, MIN_PATH_LENGHT, MAX_PATH_LENGHT);
        }
        else
        {
            valid = 1;
        }
    } while (!valid);

    valid = 1;
    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &GameA.maxMoves);

        if (GameA.maxMoves < PlayerA.playerLives ||
            GameA.maxMoves > (int)(GameA.pathLength * 0.75))
        {
            valid = 0;
            printf("    Value must be between %d and %d\n",
                    PlayerA.playerLives, (int)(GameA.pathLength * 0.75));
        }
        else
        {
            valid = 1;
        }
    } while (!valid);
    putchar('\n');

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLY);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GameA.pathLength);
    for (i = 0; i < GameA.pathLength; i+=MULTIPLY)
    {
        printf("   Positions [%2d-%2d]: ", i+1, i+MULTIPLY);
        for (j = i; j <  i + MULTIPLY; j++)
        {
            scanf("%d", &GameA.bombs[j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLY);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GameA.pathLength);
    for (i = 0; i < GameA.pathLength; i += MULTIPLY)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLY);
        for (j = i; j < i + MULTIPLY; j++)
        {
            scanf("%d", &GameA.treasures[j]);
        }
    }
    printf("TREASURE placement set\n\n");
    
    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", PlayerA.playerSymbol);
    printf("   Lives      : %d\n", PlayerA.playerLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", GameA.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < GameA.pathLength; i++)
    {
        printf("%d", GameA.bombs[i]);

    }
    putchar('\n');
    printf("   Treasure   : ");
    for (i = 0; i < GameA.pathLength; i++)
    {
        printf("%d", GameA.treasures[i]);

    }
    putchar('\n');

    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}
