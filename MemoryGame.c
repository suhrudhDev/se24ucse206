#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4 // Size of the board (4x4)
#define NUM_CARDS (BOARD_SIZE * BOARD_SIZE / 2) // Half the board size, since we have pairs of cards

// Function to shuffle the cards randomly
void shuffleCards(int board[BOARD_SIZE][BOARD_SIZE], int cards[NUM_CARDS]) {
    int cardIndex = 0;
    
    // Fill the board with pairs of cards
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = i + 1;
    }

    // Duplicate the cards
    for (int i = NUM_CARDS; i < NUM_CARDS * 2; i++) {
        cards[i] = cards[i - NUM_CARDS];
    }

    // Shuffle the cards randomly
    for (int i = NUM_CARDS * 2 - 1; i >= 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }

    // Place the shuffled cards into the board
    cardIndex = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[cardIndex++];
        }
    }
}

// Function to display the board
void displayBoard(int board[BOARD_SIZE][BOARD_SIZE], int revealed[BOARD_SIZE][BOARD_SIZE]) {
    printf("\nBoard:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int isValidMove(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE);
}

// Main function for the Memory Game
int main() {
    int board[BOARD_SIZE][BOARD_SIZE];         // The board with card values
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0}; // Board to track which cards are revealed
    int cards[NUM_CARDS * 2];                  // Array of shuffled card values
    int row1, col1, row2, col2;
    int moves = 0;
    int pairsMatched = 0;

    // Initialize the random number generator
    srand(time(NULL));

    // Shuffle and initialize the cards
    shuffleCards(board, cards);

    // Game loop
    while (pairsMatched < NUM_CARDS) {
        displayBoard(board, revealed);

        // Get the first card selection
        printf("Select the first card (row and column): ");
        scanf("%d %d", &row1, &col1);
        if (!isValidMove(row1, col1) || revealed[row1][col1]) {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        // Reveal the first card
        revealed[row1][col1] = 1;
        displayBoard(board, revealed);

        // Get the second card selection
        printf("Select the second card (row and column): ");
        scanf("%d %d", &row2, &col2);
        if (!isValidMove(row2, col2) || revealed[row2][col2]) {
            printf("Invalid move! Please try again.\n");
            revealed[row1][col1] = 0; // Hide the first card again
            continue;
        }

        // Reveal the second card
        revealed[row2][col2] = 1;
        displayBoard(board, revealed);

        // Check if the cards match
        if (board[row1][col1] == board[row2][col2]) {
            printf("It's a match!\n");
            pairsMatched++;
        } else {
            printf("Not a match. Try again.\n");
            revealed[row1][col1] = 0; // Hide the first card
            revealed[row2][col2] = 0; // Hide the second card
        }

        moves++; // Increment the move count

        printf("\nMoves: %d\n", moves);
    }

    // Game over - player wins
    printf("\nCongratulations! You've matched all pairs in %d moves.\n", moves);
    return 0;
}