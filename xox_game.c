#include <stdio.h>
#include <string.h>

// Global variables
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char pl1[20], pl2[20];
char x = 'x', o = 'o';

// Function declarations
void board();
void rules();
int checkforwin();

int main() {
    FILE *result;
    int b, play = 1, score;
    char XO, symbol;

    printf("\n\t    WELCOME TO THE GAME \n\t\tTIC-TAC-TOE");
    printf("\n\t\t===========");

    rules(); // Display game rules
    printf("\n\nPress 1 to start the game: ");
    scanf("%d", &b);

    if (b != 1) {
        printf("\nYou should have pressed 1 to start. Goodbye!\n");
        return 0;
    }

    // Start the game
    printf("\n\nEnter name of player 1: ");
    scanf("%s", pl1);
    printf("\nEnter name of player 2: ");
    scanf("%s", pl2);

    board(); // Show the initial board

    // Main game loop
    do {
        play = (play % 2) ? 1 : 2; // Alternate between player 1 and player 2
        if (play == 1) {
            printf("%s, type any digit from 1-9: ", pl1);
        } else {
            printf("%s, type any digit from 1-9: ", pl2);
        }

        scanf(" %c", &XO); // Input the position where player wants to play
        symbol = (play == 1) ? x : o;

        // Update the board based on player input
        if (XO == '1' && a[0] == '1') a[0] = symbol;
        else if (XO == '2' && a[1] == '2') a[1] = symbol;
        else if (XO == '3' && a[2] == '3') a[2] = symbol;
        else if (XO == '4' && a[3] == '4') a[3] = symbol;
        else if (XO == '5' && a[4] == '5') a[4] = symbol;
        else if (XO == '6' && a[5] == '6') a[5] = symbol;
        else if (XO == '7' && a[6] == '7') a[6] = symbol;
        else if (XO == '8' && a[7] == '8') a[7] = symbol;
        else if (XO == '9' && a[8] == '9') a[8] = symbol;
        else {
            printf("\nInvalid move! Try again.\n");
            play--;
        }

        score = checkforwin(); // Check if there's a winner
        play++; // Move to the next player
        board(); // Display the updated board

    } while (score == -1);

    // Open a file to store the result (optional, not necessary in online compilers)
    result = fopen("leaderboard.txt", "a");

    // Check the result of the game
    if (score == 1) {
        if (play == 2) {
            printf("\n\nPlayer %s Wins!!\n", pl1);
            fprintf(result, "\n%s\t%s\tWinner: %s", pl1, pl2, pl1);
        } else {
            printf("\n\nPlayer %s Wins!!\n", pl2);
            fprintf(result, "\n%s\t%s\tWinner: %s", pl1, pl2, pl2);
        }
    } else {
        printf("\n\nGame Draws!!\n");
        fprintf(result, "\n%s\t%s\tDraw", pl1, pl2);
    }

    fclose(result); // Close the file

    return 0;
}

// Function to display the current board state
void board() {
    printf("\n\tTIC-TAC-TOE");
    printf("\n\t===========\n\n");
    printf("Player1 (X) = %s", pl1);
    printf("\nPlayer2 (O) = %s", pl2);
    printf("\n\n");

    printf("|--------------|\n");
    printf("| %c  | %c  | %c  |\n", a[0], a[1], a[2]);
    printf("|----|----|----|\n");
    printf("| %c  | %c  | %c  |\n", a[3], a[4], a[5]);
    printf("|----|----|----|\n");
    printf("| %c  | %c  | %c  |\n", a[6], a[7], a[8]);
    printf("|--------------|\n");
}

// Function to check if there is a winner
int checkforwin() {
    if (a[0] == a[1] && a[1] == a[2]) return 1;
    if (a[3] == a[4] && a[4] == a[5]) return 1;
    if (a[6] == a[7] && a[7] == a[8]) return 1;
    if (a[0] == a[3] && a[3] == a[6]) return 1;
    if (a[1] == a[4] && a[4] == a[7]) return 1;
    if (a[2] == a[5] && a[5] == a[8]) return 1;
    if (a[0] == a[4] && a[4] == a[8]) return 1;
    if (a[2] == a[4] && a[4] == a[6]) return 1;

    // Check if the board is full and there is no winner
    for (int i = 0; i < 9; i++) {
        if (a[i] != 'x' && a[i] != 'o') {
            return -1; // Game is still ongoing
        }
    }

    return 0; // It's a draw
}

// Function to display the rules of the game
void rules() {
    printf("\n\n\nRULES:-");
    printf("\n\t-> The game is played in a 3x3 grid.");
    printf("\n\t-> Players need to enter a number between 1-9 to place their symbol.");
    printf("\n\t-> The first one to get 3 symbols in a row wins!");
    printf("\n\t-> If no one gets 3 in a row, the match is a draw.");
}
