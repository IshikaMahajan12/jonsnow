#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        return false;
    board[row][col] = currentMarker;
    return true;
}

int winner() {
    // Rows & Columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;
    return 0;
}

void swapTurn() {
    currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    currentMarker = 'X';
    currentPlayer = 1;

    drawBoard();
    for (int turn = 0; turn < 9; turn++) {
        cout << "Player " << currentPlayer << " (" << currentMarker << "), choose your slot (1-9): ";
        int slot; cin >> slot;
        if (!placeMarker(slot)) {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }
        drawBoard();
        int win = winner();
        if (win != 0) {
            cout << "Player " << win << " wins!\n";
            return 0;
        }
        swapTurn();
    }
    cout << "It's a draw!\n";
}
