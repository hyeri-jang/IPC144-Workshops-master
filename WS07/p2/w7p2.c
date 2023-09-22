/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
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

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MIN_PLAYER_LIVES 1
#define MAX_PLAYER_LIVES 10
#define MULTIPLY 5
#define START_PATH 1

struct PlayerInfo
{
    int playerLives;
    char playerSymbol;
    int treasureCount;
    int positionHistory[MAX_PATH_LENGTH];
};

struct GameInfo
{
    int playersMoves;
    int pathLength;
    int bombs[MAX_PATH_LENGTH];
    int treasures[MAX_PATH_LENGTH];
};

int main(void)
{

    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };

    const char bomb = '!', treasure = '$', bombAndTreasure = '&', undiscovered = '.';
    int i, j;
    int valid, keepGoing;
    int userPosition = 0;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerSymbol);

    do
    {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.playerLives);

        if (player.playerLives < MIN_PLAYER_LIVES ||
            player.playerLives > MAX_PLAYER_LIVES)
        {
            valid = 0;
            printf("     Must be between %d and %d!\n",
                MIN_PLAYER_LIVES, MAX_PLAYER_LIVES);
        }
    } while (!valid);

    /* === reset position history === */
    for (i = 0; i < MAX_PATH_LENGTH; i++)
    {
        player.positionHistory[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");

    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        valid = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ",
            MULTIPLY, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);

        if (game.pathLength < MIN_PATH_LENGTH ||
            game.pathLength > MAX_PATH_LENGTH ||
            (game.pathLength % MULTIPLY) != 0)
        {
            valid = 0;
            printf("     Must be a multiple of %d and between %d-%d!!!\n",
                MULTIPLY, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (!valid);

    do
    {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.playersMoves);

        if (game.playersMoves < player.playerLives ||
            game.playersMoves > (int)(game.pathLength * 0.75))
        {
            valid = 0;
            printf("    Value must be between %d and %d\n",
                player.playerLives, (int)(game.pathLength * 0.75));
        }
    } while (!valid);
    putchar('\n');

    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLY);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += MULTIPLY)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLY);
        for (j = i; j < i + MULTIPLY; j++)
        {
            scanf("%d", &game.bombs[j]);
        }
    }
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLY);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += MULTIPLY)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLY);
        for (j = i; j < i + MULTIPLY; j++)
        {
            scanf("%d", &game.treasures[j]);
        }
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerSymbol);
    printf("   Lives      : %d\n", player.playerLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);

    }
    putchar('\n');
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasures[i]);

    }
    putchar('\n');

    printf("\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    /* === Part 2 === */
    do
    {
        keepGoing = 0;

        // show current user position
        if (userPosition)
        {
            printf("\n  ");
            for (i = 0; i < game.pathLength; i++)
            {
                if (i == (userPosition - 1))
                {
                    printf("%c", player.playerSymbol);
                }
                else if(i < userPosition)
                {
                    printf(" ");
                }
            }
        }

        // show the location of discovered bombs and tresures
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            // undiscovered
            if (player.positionHistory[i] == 0)
            {
                printf("-");
            }
            else
            {
                // bomb and treasure
                if (game.bombs[i] && game.treasures[i])
                {
                    printf("%c", bombAndTreasure);
                }
                // bomb
                else if (game.bombs[i])
                {
                    printf("%c", bomb);
                }
                // treasure
                else if (game.treasures[i])
                {
                    printf("%c", treasure);
                }
                // undiscovered
                else
                {
                    printf("%c", undiscovered);
                }
            }
        }

        // ruller
        // shows number every 10
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            if ((i + 1) % 10 != 0 || i == 0)
            {
                printf("|");
            }
            else
            {
                printf("%d", ((i + 1) / 10));
            }
        }
       
        // display numbers 1-10
        printf("\n  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%d", ((i + 1) % 10));
        }

        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
                player.playerLives, player.treasureCount, game.playersMoves);
        printf("+---------------------------------------------------+\n");

        if (player.playerLives > 0 && game.playersMoves > 0)
        {
            keepGoing = 1;

            do
            {
                valid = 1;
                printf("Next Move [%d-%d]: ", START_PATH, game.pathLength);
                scanf("%d", &userPosition);

                if (userPosition < START_PATH || userPosition > game.pathLength)
                {
                    valid = 0;
                    printf("  Out of Range!!!\n");
                }
            } while (!valid);
            putchar('\n');

            // if true(= 1), already visited!
            if (player.positionHistory[userPosition - 1])
            {
                printf("===============> Dope! You've been here before!\n");
            }
            else
            {
                // set place to 1 (1 = visited)
                player.positionHistory[userPosition - 1] = 1;
                // decrement player l
                game.playersMoves--;

                if (game.treasures[userPosition - 1] && game.bombs[userPosition - 1])
                {
                    printf("===============> [%c] %c%c%c BOOOOOM %c%c%c [%c]\n",
                        bombAndTreasure, bomb, bomb, bomb, bomb, bomb, bomb, bombAndTreasure);
                    printf("===============> [%c] %c%c%c Life Insurance Payout%c%c%c [%c]\n",
                        bombAndTreasure, treasure, treasure, treasure, bomb, bomb, bomb, bombAndTreasure);
                    // increment treasure count
                    player.treasureCount++;
                    // decrement player lives
                    player.playerLives--;
                }
                else if (game.treasures[userPosition - 1])
                {
                    printf("===============> [%c] %c%c%c Found Treasure! %c%c%c [%c]\n",
                            treasure, treasure, treasure, treasure,
                            treasure, treasure, treasure, treasure);
                    // increment treasure count
                    player.treasureCount++;
                }
                else if (game.bombs[userPosition - 1])
                {
                    printf("===============> [%c] %c%c%c BOOOOOM %c%c%c [%c]\n",
                            bomb, bomb, bomb, bomb, bomb, bomb, bomb, bomb);
                    // decrement player lives
                    player.playerLives--;
                }
                else
                {
                    printf("===============> [%c] %c%c%cNothing found here%c%c%c [%c]\n",
                            undiscovered, undiscovered, undiscovered, undiscovered,
                            undiscovered, undiscovered, undiscovered, undiscovered);
                }

                // check if player still have lives
                if (player.playerLives == 0)
                {
                    printf("\nNo more LIVES remaining!\n");
                }
            }
        }
    } while (keepGoing);

    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");

    printf("You should play again and try to beat your score!\n");

    return 0;
}
