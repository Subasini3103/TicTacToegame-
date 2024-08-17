#include <stdio.h>
#include <stdbool.h>
// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}
// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
        []

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}
// Function to check if the board is full
bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}
// Function to play Tic Tac Toe
void playGame()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    printf("Let's start!\n");
     while (true)
    {
        printBoard(board);
        printf("Player %c, enter your move (row [1-3] column [1-3]): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ')
        {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row-1][col-1] = currentPlayer;
        if (checkWin(board, currentPlayer))
        {
            printBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }
else if (checkDraw(board))
        {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    playGame();
    return 0;
}
