#include <iostream>
#include <vector>
#include<string>
using namespace std;
void visualBoard(const vector<char>& board);
bool WIN_check(const vector<char>& board, char mark);
bool draw(const vector<char>& board);
void visualBoard(const vector<char>& board)
{
    cout << "\n";
    cout << " " << board[0] << " |" << board[1] << "  |" << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " |" << board[4] << "  |" << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " |" << board[7] << "  |" << board[8] << "\n";
    cout << "---|---|---\n";
}

bool WIN_check(const vector<char>& board, char mark)
{
    return ((board[0] == mark && board[1] == mark && board[2] == mark) || (board[3] == mark && board[4] == mark && board[5] == mark) || (board[6] == mark && board[7] == mark && board[8] == mark) || (board[0] == mark && board[3] == mark && board[6] == mark) || (board[1] == mark && board[4] == mark && board[7] == mark) || (board[2] == mark && board[5] == mark && board[8] == mark) || (board[0] == mark && board[4] == mark && board[8] == mark) || (board[2] == mark && board[4] == mark && board[6] == mark));
}

bool draw(const vector<char>& board)
{
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}
int main() {
    // Board Initialization
    vector<char> board(9, ' ');
    string player1, player2;
    char mark1, mark2;

    // Player names
    cout << "Enter Player 1 name: ";
    cin >> player1;
    cout << "Enter Player 2 name: ";
    cin >> player2;

    // Let Player 1 choose X or O
    do {
        cout << player1 << ", choose X or O: ";
        cin >> mark1;
        mark1 = toupper(mark1);
    } while (mark1 != 'X' && mark1 != 'O');

    // Assign the other mark to Player 2
    mark2 = (mark1 == 'X') ? 'O' : 'X';

    cout << player1 << " will play as " << mark1 << endl;
    cout << player2 << " will play as " << mark2 << endl;

    int currentPlayer = 1;
    int moves = 0;
    while (true) {
        visualBoard(board);

        // Get current player's name and mark
        string currentPlayerName = (currentPlayer == 1) ? player1 : player2;
        char currentMark = (currentPlayer == 1) ? mark1 : mark2;

        // Input position
        int position;
        do {
            cout << currentPlayerName << "'s turn (" << currentMark << "). Enter position (1-9): ";
            cin >> position;
        } while (position < 1 || position > 9 || board[position - 1] != ' ');

        // Place the mark
        board[position - 1] = currentMark;
        moves++;

        // Check for win or draw
        if (WIN_check(board, currentMark)) {
            visualBoard(board);
            cout << currentPlayerName << " wins! Congratulations!\n";
            break;
        }
        else if (draw(board)) {
            visualBoard(board);
            cout << "It's a draw! Well played both.\n";
            break;
        }

        // Switch player
        currentPlayer = 3 - currentPlayer; // Toggle between 1 and 2
    }

    return 0;
}