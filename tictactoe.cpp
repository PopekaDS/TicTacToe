/*
def main():
    print('Welcome to Tic-Tac-Toe!')
    gameBoard = getBlankBoard()  # Create a TTT board dictionary.
    currentPlayer, nextPlayer = X, O  # X goes first, O goes next.

    while True:  # Main game loop.
        # Display the board on the screen:
        print(getBoardStr(gameBoard))

        # Keep asking the player until they enter a number 1-9:
        move = None
        while not isValidSpace(gameBoard, move):
            print('What is {}\'s move? (1-9)'.format(currentPlayer))
            move = input('> ')
        updateBoard(gameBoard, move, currentPlayer)  # Make the move.

        # Check if the game is over:
        if isWinner(gameBoard, currentPlayer):  # Check for a winner.
            print(getBoardStr(gameBoard))
            print(currentPlayer + ' has won the game!')
            break
        elif isBoardFull(gameBoard):  # Check for a tie.
            print(getBoardStr(gameBoard))
            print('The game is a tie!')
            break
        # Switch turns to the next player:
        currentPlayer, nextPlayer = nextPlayer, currentPlayer
    print('Thanks for playing!')






def isValidSpace(board, space):
    """Returns True if the space on the board is a valid space number
    and the space is blank."""
    return space in ALL_SPACES and board[space] == BLANK


def isWinner(board, player):
    """Return True if player is a winner on this TTTBoard."""
    # Shorter variable names used here for readablility:
    b, p = board, player
    # Check for 3 marks across 3 rows, 3 columns, and 2 diagonals.
    return ((b['1'] == b['2'] == b['3'] == p) or  # Across top
            (b['4'] == b['5'] == b['6'] == p) or  # Across middle
            (b['7'] == b['8'] == b['9'] == p) or  # Across bottom
            (b['1'] == b['4'] == b['7'] == p) or  # Down left
            (b['2'] == b['5'] == b['8'] == p) or  # Down middle
            (b['3'] == b['6'] == b['9'] == p) or  # Down right
            (b['3'] == b['5'] == b['7'] == p) or  # Diagonal
            (b['1'] == b['5'] == b['9'] == p))    # Diagonal

def isBoardFull(board):
    """Return True if every space on the board has been taken."""
    for space in ALL_SPACES:
        if board[space] == BLANK:
            return False  # If any space is blank, return False.
    return True  # No spaces are blank, so return True.


def updateBoard(board, space, mark):
    """Sets the space on the board to mark."""
    board[space] = mark


*/

// Tic-Tac-Toe, by Al Sweigart al@inventwithpython.com
// The classic board game.
// This code is available at https ://nostarch.com/big-book-small-python-programming

#include <iostream>
// #include <vector>
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

int main() {



    char* board = new char[9];
    board = getBlankBoard();
    getBoardStr(board);



    return 0;
}
