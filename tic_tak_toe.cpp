#include <bits/stdc++.h>
using namespace std;

#define COMPUTER 1
#define HUMAN 2
#define SIDE 3
#define COMPUTERMOVE 'O'
#define HUMANMOVE 'X'

// Function to display the board
void showBoard(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            cout << board[i][j];
            if (j < SIDE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIDE - 1) cout << "---|---|---\n";
    }
    cout << endl;
}

// Function to display instructions
void showInstructions() {
    cout << "Choose a cell numbered from 1 to 9 as below and play:\n";
    int count = 1;
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            cout << count++;
            if (j < SIDE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIDE - 1) cout << "--|---|--\n";
    }
    cout << endl;
}

// Function to initialize the board
void initialise(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++)
        for (int j = 0; j < SIDE; j++)
            board[i][j] = '*';
}

// Function to declare the winner
void declareWinner(int whoseTurn) {
    if (whoseTurn == COMPUTER)
        cout << "COMPUTER has won!\n";
    else
        cout << "HUMAN has won!\n";
}

// Check if any row is crossed
bool rowCrossed(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '*')
            return true;
    }
    return false;
}

// Check if any column is crossed
bool columnCrossed(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '*')
            return true;
    }
    return false;
}

// Check if any diagonal is crossed
bool diagonalCrossed(char board[][SIDE]) {
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*')
        return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*')
        return true;
    return false;
}

// Check if the game is over
bool gameOver(char board[][SIDE]) {
    return rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board);
}

// Minimax algorithm to calculate the best move
int minimax(char board[][SIDE], int depth, bool isAI) {
    if (gameOver(board)) {
        return isAI ? -10 : 10;
    }
    if (depth == SIDE * SIDE) {
        return 0;
    }

    int bestScore = isAI ? -1000 : 1000;

    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (board[i][j] == '*') {
                board[i][j] = isAI ? COMPUTERMOVE : HUMANMOVE;
                int score = minimax(board, depth + 1, !isAI);
                board[i][j] = '*';

                bestScore = isAI ? max(bestScore, score) : min(bestScore, score);
            }
        }
    }
    return bestScore;
}

// Function to find the best move for the computer
int bestMove(char board[][SIDE], int moveIndex) {
    int bestScore = -1000, move = -1;

    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (board[i][j] == '*') {
                board[i][j] = COMPUTERMOVE;
                int score = minimax(board, moveIndex + 1, false);
                board[i][j] = '*';

                if (score > bestScore) {
                    bestScore = score;
                    move = i * SIDE + j;
                }
            }
        }
    }
    return move;
}

// Function to play Tic-Tac-Toe
void playTicTacToe(int whoseTurn) {
    char board[SIDE][SIDE];
    initialise(board);
    showInstructions();

    int moveIndex = 0;

    while (!gameOver(board) && moveIndex < SIDE * SIDE) {
        int move;
        if (whoseTurn == COMPUTER) {
            move = bestMove(board, moveIndex);
            board[move / SIDE][move % SIDE] = COMPUTERMOVE;
            cout << "COMPUTER has placed O in cell " << move + 1 << endl;
        } else {
            cout << "Enter your move (1-9): ";
            cin >> move;
            move--;
            if (move < 0 || move >= SIDE * SIDE || board[move / SIDE][move % SIDE] != '*') {
                cout << "Invalid move! Try again.\n";
                continue;
            }
            board[move / SIDE][move % SIDE] = HUMANMOVE;
        }

        showBoard(board);
        whoseTurn = (whoseTurn == COMPUTER) ? HUMAN : COMPUTER;
        moveIndex++;
    }

    if (!gameOver(board)) {
        cout << "It's a draw!\n";
    } else {
        declareWinner(whoseTurn == COMPUTER ? HUMAN : COMPUTER);
    }
}

int main() {
    char choice;
    do {
        cout << "Do you want to start first? (y/n): ";
        cin >> choice;
        if (choice == 'y')
            playTicTacToe(HUMAN);
        else if (choice == 'n')
            playTicTacToe(COMPUTER);
        else
            cout << "Invalid choice! Try again.\n";

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
