#include <iostream>
#include <vector>

using namespace std;

void print_board(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

bool check_winner(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool is_board_full(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char current_player = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        print_board(board);

        int row, col;
        cout << "Enter the row (0, 1, or 2): ";
        cin >> row;
        cout << "Enter the column (0, 1, or 2): ";
        cin >> col;

        if (board[row][col] == ' ') {
            board[row][col] = current_player;

            if (check_winner(board, current_player)) {
                print_board(board);
                cout << "Player " << current_player << " wins!" << endl;
                break;
            } else if (is_board_full(board)) {
                print_board(board);
                cout << "It's a tie!" << endl;
                break;
            } else {
                current_player = (current_player == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "That position is already taken. Try again." << endl;
        }
    }

    return 0;
}

