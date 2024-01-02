#include <iostream>
#include <vector>
#include <iomanip>

const int N = 8; // Chessboard size

// Function to print the chessboard
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(2) << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a move is valid
bool isValidMove(int x, int y, const std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to find a Knight's Tour
bool knightTourUtil(int x, int y, int moveCount, std::vector<std::vector<int>>& board,
                    const std::vector<int>& moveX, const std::vector<int>& moveY) {
    if (moveCount == N * N) {
        // All squares are visited
        return true;
    }

    for (int i = 0; i < 8; ++i) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isValidMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;

            if (knightTourUtil(nextX, nextY, moveCount + 1, board, moveX, moveY)) {
                return true;
            }

            // Backtrack
            board[nextX][nextY] = -1;
        }
    }

    return false;
}

// Function to solve the Knight's Tour problem
void knightTour() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));

    // Possible moves for the knight
    std::vector<int> moveX = {2, 1, -1, -2, -2, -1, 1, 2};
    std::vector<int> moveY = {1, 2, 2, 1, -1, -2, -2, -1};

    // Start the tour from the top-left corner
    int startX = 0;
    int startY = 0;

    // Mark the starting position as visited
    board[startX][startY] = 0;

    // Attempt to find a Knight's Tour
    if (knightTourUtil(startX, startY, 1, board, moveX, moveY)) {
        std::cout << "Knight's Tour:\n";
        printBoard(board);
    } else {
        std::cout << "No solution exists.\n";
    }
}

int main() {
    knightTour();

    return 0;
}
