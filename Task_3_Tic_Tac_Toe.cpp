#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + count - 1;
            count++;
        }
    }
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " " << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << "\n";
}

bool updateBoard(int choice, char playerSymbol) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        return false;
    }

    board[row][col] = playerSymbol;
    return true;
}

bool checkWin(char playerSymbol) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol) return true;
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol) return true;
    }

    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol) return true;
    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        initBoard();
        char currentPlayer = 'X';
        bool gameOver = false;

        cout << "===================================" << endl;
        cout << "         TIC-TAC-TOE GAME" << endl;
        cout << "===================================" << endl;
        cout << "Player 1: X    Player 2: O" << endl;

        while (!gameOver) {
            displayBoard();

            int choice;
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> choice;

            bool valid = updateBoard(choice, currentPlayer);

            if (!valid) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!\n";
    return 0;
}