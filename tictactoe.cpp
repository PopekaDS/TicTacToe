// Tic-Tac-Toe, by Al Sweigart
// The classic board game.
// This code is available at https://nostarch.com/big-book-small-python-programming
// #76 TIC-TAC-TOE

#include <iostream>
using namespace std;

char ALL_SPACES[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char X = 'X', O = 'O', BLANK = ' '; // Constants for string values.

char* getBlankBoard() {
    // Create a new, blank tic-tac-toe board.
    // Map of space numbers : 1 | 2 | 3
    //                        --+---+--
    //                        4 | 5 | 6 
    //                        --+---+--
    //                        7 | 8 | 9
    // Keys are 1 through 9, the values are X, O, or BLANK:
    char* board = new char[9];
    for (int i = 0; i < 9; i++) {
        board[i] = BLANK; // All spaces start as blank.
    }

    return board;
}

void getBoardStr(char* board) {
    // Return a text-representation of the board.
    cout << board[0] << " | " << board[1] << " | " << board[2] << "   1 2 3\n";
    cout << "--+---+--\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "   4 5 6\n";
    cout << "--+---+--\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "   7 8 9\n";
}

bool isValidSpace(char* board, int space) {
    // Returns True if the space on the board is a valid space number
    // and the space is blank.
    return (space >= 1 && space <= 9) and board[space - 1] == BLANK;
}

bool shortIsWinner(char* board, int first, int second, int three, char player) { // исправить
    if (board[first] == board[second] && board[second] == board[three] && board[three] == player) {
        return true;
    }

    return false;
}

bool isWinner(char* board, char player) {
    // Return True if player is a winner on this TTTBoard.
    // Shorter variable names used here for readablility:
    // Check for 3 marks across 3 rows, 3 columns, and 2 diagonals.
    if (shortIsWinner(board, 0, 1, 2, player))
        return true; // Across top

    if (shortIsWinner(board, 3, 4, 5, player))
        return true; // Across middle

    if (shortIsWinner(board, 6, 7, 8, player))
        return true; // Across bottom

    if (shortIsWinner(board, 0, 3, 6, player))
        return true; // Down left

    if (shortIsWinner(board, 1, 4, 7, player))
        return true; // Down middle

    if (shortIsWinner(board, 2, 5, 8, player))
        return true; // Down right

    if (shortIsWinner(board, 2, 4, 6, player))
        return true; // Diagonal

    if (shortIsWinner(board, 0, 4, 8, player))
        return true; // Diagonal

    return false;
}

bool isBoardFull(char* board) {
    // Return True if every space on the board has been taken.
    for (int i = 0; i < 9; i++) {
        if (board[i] == BLANK) {
            return false; // If any space is blank, return False.
        }
    }

    return true; // No spaces are blank, so return True.
}

void updateBoard(char* board, int space, char mark) {
    // Sets the space on the board to mark.
    board[space - 1] = mark;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n\n";
    char* gameBoard = new char[9]; // Create a TTT board dictionary.
    gameBoard = getBlankBoard();
    char currentPlayer = X, nextPlayer = O; // X goes first, O goes next.

    while (1) { // Main game loop.
        // Display the board on the screen:
        getBoardStr(gameBoard);

        // Keep asking the player until they enter a number 1-9:
        int move = 0;
        while (!isValidSpace(gameBoard, move)) {
            cout << "What is " << currentPlayer << "'s move? (1-9)\n";
            cout << "> "; cin >> move;
        }
        updateBoard(gameBoard, move, currentPlayer); // Make the move. 

        // Check if the game is over:
        if (isWinner(gameBoard, currentPlayer)) { // Check for a winner.
            getBoardStr(gameBoard);
            cout << currentPlayer << " has won the game!\n";
            break;
        } else if (isBoardFull(gameBoard)) { // Check for a tie.
            getBoardStr(gameBoard);
            cout << "The game is a tie!\n";
            break;
        }

        // Switch turns to the next player:
        swap(currentPlayer, nextPlayer);
    }
    cout << "Thanks for playing!\n";

    return 0;
}