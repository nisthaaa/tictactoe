#include <iostream>
using namespace std;

// Function to print the current state of the game board
void printBoard(char board[3][3]) {
    cout << "Current Board State:" << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is over and return the winner
char checkWinner(char board[3][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Check if game is a tie
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return '-';
            }
        }
    }
    return 'T';
}

// Function to make a move for a given player
void makeMove(char board[3][3], char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row column): ";
    cin >> row >> col;
    while(row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
        cout << "Invalid move. Please try again." << endl;
        cout << "Player " << player << ", enter your move (row column): ";
        cin >> row >> col;
    }
    board[row][col] = player;
}

// Main function to play the game
int main() {
    char board[3][3] = {{'-', '-', '-'},
                        {'-', '-', '-'},
                        {'-', '-', '-'}};
    char currentPlayer = 'X';
    char winner = '-';
    while(winner == '-') {
        printBoard(board);
        makeMove(board, currentPlayer);
        winner = checkWinner(board);
        if(currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    printBoard(board);
    if(winner == 'T') {
        cout << "The game is a tie." << endl;
    } else {
        cout << "Player " << winner << " wins!" << endl;
    }
    return 0;
}
