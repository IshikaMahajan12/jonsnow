#include <iostream>
#include <limits>
using namespace std;

char boardAI[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoardAI() {
    for (int i=0; i<3; i++) {
        cout << " " << boardAI[i][0] << " | " << boardAI[i][1] << " | " << boardAI[i][2] << "\n";
        if (i<2) cout << "---|---|---\n";
    }
    cout << endl;
}

bool isMovesLeft() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (boardAI[i][j] != 'X' && boardAI[i][j] != 'O')
                return true;
    return false;
}

int evaluate() {
    for (int row=0; row<3; row++)
        if (boardAI[row][0]==boardAI[row][1] && boardAI[row][1]==boardAI[row][2])
            return (boardAI[row][0]=='O') ? +10 : -10;

    for (int col=0; col<3; col++)
        if (boardAI[0][col]==boardAI[1][col] && boardAI[1][col]==boardAI[2][col])
            return (boardAI[0][col]=='O') ? +10 : -10;

    if (boardAI[0][0]==boardAI[1][1] && boardAI[1][1]==boardAI[2][2])
        return (boardAI[0][0]=='O') ? +10 : -10;

    if (boardAI[0][2]==boardAI[1][1] && boardAI[1][1]==boardAI[2][0])
        return (boardAI[0][2]=='O') ? +10 : -10;

    return 0;
}

int minimax(bool isMax) {
    int score = evaluate();
    if (score == 10 || score == -10) return score;
    if (!isMovesLeft()) return 0;

    if (isMax) {
        int best = -1000;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
            if (boardAI[i][j] != 'X' && boardAI[i][j] != 'O') {
                char backup = boardAI[i][j];
                boardAI[i][j] = 'O';
                best = max(best, minimax(false));
                boardAI[i][j] = backup;
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
            if (boardAI[i][j] != 'X' && boardAI[i][j] != 'O') {
                char backup = boardAI[i][j];
                boardAI[i][j] = 'X';
                best = min(best, minimax(true));
                boardAI[i][j] = backup;
            }
        }
        return best;
    }
}

pair<int,int> findBestMove() {
    int bestVal = -1000;
    pair<int,int> bestMove = {-1,-1};
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) {
        if (boardAI[i][j] != 'X' && boardAI[i][j] != 'O') {
            char backup = boardAI[i][j];
            boardAI[i][j] = 'O';
            int moveVal = minimax(false);
            boardAI[i][j] = backup;
            if (moveVal > bestVal) {
                bestMove = {i,j};
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}

int main() {
    cout << "Tic Tac Toe with AI\n";
    drawBoardAI();
    for (int turn=0; turn<9; turn++) {
        if (turn%2==0) {
            int move;
            cout << "Enter your move (1-9): ";
            cin >> move;
            int r=(move-1)/3, c=(move-1)%3;
            if (boardAI[r][c]=='X' || boardAI[r][c]=='O') {
                cout << "Invalid move!\n"; turn--; continue;
            }
            boardAI[r][c]='X';
        } else {
            cout << "AI is thinking...\n";
            auto best = findBestMove();
            boardAI[best.first][best.second]='O';
        }
        drawBoardAI();
        int score=evaluate();
        if (score==10) { cout << "AI wins!\n"; return 0; }
        else if (score==-10) { cout << "You win!\n"; return 0; }
        else if (!isMovesLeft()) { cout << "It's a draw!\n"; return 0; }
    }
}
