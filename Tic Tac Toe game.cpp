#include<iostream>
using namespace std;

string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;  // Player 1 starts, X
int position = 0;

void introduction() {
    cout << "Press [Enter] to begin:";
    getchar();
    cout << "\n";
    cout << "\n";
    cout << "Tic Tac Toe" << endl;
    cout << "Player 1) X\n";
    cout << "Player 2) O\n";

    // Displaying the board layout
    cout << "\t\t     |     |     \n";
    cout << "\t\t  1  |  2  |  3  \n";
    cout << "\t\t_____|_____|_____ \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  4  |  5  |  6  \n";
    cout << "\t\t_____|_____|_____ \n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  7  |  8  |  9  \n";
    cout << "\t\t     |     |     \n\n";
}

// Function to print the current state of the board
void print_board() {
    cout << "\t\t" << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "\t\t---|---|---\n";
    cout << "\t\t" << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "\t\t---|---|---\n";
    cout << "\t\t" << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n";
}

// Function to check if there's a winner
bool is_winner() {
    // Check horizontal, vertical and diagonal lines
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != " ") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != " ") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != " ") ||
        (board[0] == board[3] && board[3] == board[6] && board[0] != " ") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != " ") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != " ") ||
        (board[0] == board[4] && board[4] == board[8] && board[0] != " ") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != " ")) {
        return true;
    }
    return false;
}

// Function to take player's move
void player_move() {
    cout << "Player " << player << ", choose a position (1-9): ";
    cin >> position;

    // Adjust for 0-based index
    position--;

    if (position >= 0 && position < 9 && board[position] == " ") {
        board[position] = (player == 1) ? "X" : "O";  // Assign X or O based on the player
    } else {
        cout << "Invalid move, try again.\n";
        player_move();  // Recursively prompt for valid move
    }
}

// Function to switch players
void switch_player() {
    player = (player == 1) ? 2 : 1;
}

int main() {
    introduction();
    
    // Main game loop
    int turns = 0;
    while (turns < 9) {
        print_board();
        player_move();

        // Check if there's a winner
        if (is_winner()) {
            print_board();
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        switch_player();
        turns++;
    }

    if (turns == 9) {
        print_board();
        cout << "It's a tie!" << endl;
    }

    return 0;
}

