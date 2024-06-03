#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

// Function prototypes
void initializeBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
int checkWin(char board[][BOARD_SIZE], char player);
int checkDraw(char board[][BOARD_SIZE]);
int isValidMove(char board[][BOARD_SIZE], int row, int col);
void playGame();

int main() {
    playGame();
    return 0;
}

// Function to initialize the board with empty spaces
void initializeBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

// Function to check if a player has won
int checkWin(char board[][BOARD_SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1; // Column win
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Diagonal win
    }
    return 0; // No win
}

// Function to check if the game is a draw
int checkDraw(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game not a draw
            }
        }
    }
    return 1; // Game is a draw
}

// Function to check if a move is valid
int isValidMove(char board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        return 0; // Invalid move
    }
    return 1; // Valid move
}

// Function to play the game
void playGame() {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer = 'X';
    int row, col;

    initializeBoard(board);

    do {
        // Print the board
        printf("\nCurrent Board:\n");
        printBoard(board);

        // Get the player's move
        do {
            printf("\nPlayer %c, enter your move (row and column): ", currentPlayer);
            scanf("%d %d", &row, &col);
        } while (!isValidMove(board, row, col));

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printf("\nPlayer %c wins!\n", currentPlayer);
            printBoard(board);
            return;
        }

        // Check for a draw
        if (checkDraw(board)) {
            printf("\nThe game is a draw!\n");
            printBoard(board);
            return;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (1); // Infinite loop until a win or draw
}
