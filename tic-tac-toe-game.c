#include <stdio.h>

char board[3][3];  // 3x3 Tic Tac Toe board

// Function to initialize the board
void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to display the board
void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Function to check if there is a winner
int checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

// Function to check if the board is full (draw)
int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {
    int row, col;
    char player = 'X';
    int gameOver = 0;

    initBoard();

    printf("🎮 Welcome to Tic Tac Toe!\n");
    printf("Player 1: X,  Player 2: O\n");

    while (!gameOver) {
        displayBoard();
        printf("Player %c, enter your move (row[1-3] and column[1-3]): ", player);
        scanf("%d %d", &row, &col);
        row--; col--;  // adjust for 0-based indexing

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = player;

        if (checkWinner()) {
            displayBoard();
            printf("🎉 Player %c wins!\n", player);
            gameOver = 1;
        } else if (isDraw()) {
            displayBoard();
            printf("🤝 It's a draw!\n");
            gameOver = 1;
        } else {
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
