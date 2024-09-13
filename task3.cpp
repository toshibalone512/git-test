#include <iostream>

// Function prototypes
void displayBoard(char board[]);
bool checkWin(char board[], char player);
bool checkDraw(char board[]);

int main()
{
    // Initialize the board with empty spaces
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;

    std::cout << "Welcome to Tic Tac Toe!" << std::endl;

    // Game loop
    while (!gameWon && !draw)
    {
        displayBoard(board);

        // Get the current player's move
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        std::cin >> move;

        // Validate the move
        if (move < 1 || move > 9 || board[move - 1] != ' ')
        {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }

        // Make the move
        board[move - 1] = currentPlayer;

        // Check if the current player has won
        gameWon = checkWin(board, currentPlayer);

        // Check for draw
        draw = checkDraw(board);

        // Switch to the next player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    displayBoard(board);

    if (gameWon)
    {
        // Switch back to the winning player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        std::cout << "Congratulations! Player " << currentPlayer << " wins!" << std::endl;
    }
    else if (draw)
    {
        std::cout << "It's a draw!" << std::endl;
    }

    return 0;
}

// Function to display the Tic Tac Toe board
void displayBoard(char board[])
{
    std::cout << "\n";
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
    std::cout << "\n";
}

// Function to check if the current player has won
bool checkWin(char board[], char player)
{
    // Check rows, columns, and diagonals
    return ((board[0] == player && board[1] == player && board[2] == player) || // Row 1
            (board[3] == player && board[4] == player && board[5] == player) || // Row 2
            (board[6] == player && board[7] == player && board[8] == player) || // Row 3
            (board[0] == player && board[3] == player && board[6] == player) || // Column 1
            (board[1] == player && board[4] == player && board[7] == player) || // Column 2
            (board[2] == player && board[5] == player && board[8] == player) || // Column 3
            (board[0] == player && board[4] == player && board[8] == player) || // Diagonal 1
            (board[2] == player && board[4] == player && board[6] == player));  // Diagonal 2
}

// Function to check if the game is a draw
bool checkDraw(char board[])
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            return false;
        }
    }
    return true;
}
