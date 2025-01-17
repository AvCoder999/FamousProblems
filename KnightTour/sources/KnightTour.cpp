#include "headers/KnightTour.hpp"

int KnightTour::moveX[KnightTour::MOVE_COUNT] = {-2, -2, -1, -1, 1, 1, 2, 2 };
int KnightTour::moveY[KnightTour::MOVE_COUNT] = {-1, 1, -2, 2, -2, 2, -1, 1 };

KnightTour::KnightTour(const int boardSize, const int row, const int col)
    : board_(boardSize)
    , knight_(row, col)
{}


std::ostream&
operator<<(std::ostream& out, const Knight& knight)
{
    return out << knight.first << " : " << knight.second << std::endl;
}

bool
KnightTour::isSafe(const int row, const int col)
{
    return (row >= 0 && row < static_cast<int>(board_.size()) && 
            col >= 0 && col < static_cast<int>(board_.size()) &&
            0 == board_[row][col]);
}

int
KnightTour::run()
{
    /// board_[knight_.first][knight_.second] = 1;
    /// return !static_cast<int>(brute_force(1));
    
    std::cout << knight_ << std::endl;
    board_[knight_.first][knight_.second] = 1;
    solveTour(knight_.first, knight_.second, 2);
    std::cout << board_ << std::endl;
    return 0;
}

bool 
KnightTour::solveTour(int x, int y, int moveCount)
{
    if (moveCount == 64) {
        return true;  // All squares are visited
    }

    // Try all next moves
    for (int i = 0; i < 8; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isSafe(nextX, nextY)) {
            board_[nextX][nextY] = moveCount;  // Make the move
            if (solveTour(nextX, nextY, moveCount + 1)) {
                return true;
            }
            board_[nextX][nextY] = 0;  // Backtrack
        }
    }
    return false;  // No solution found
}

bool
KnightTour::brute_force(const int counter)
{
    /// std::cout << board_ << std::endl;
    if (64 == counter) {return true; }
    for (int i = 0; i < MOVE_COUNT; ++i) {
        const int newRow = knight_.first + moveX[i];
        const int newCol = knight_.second + moveY[i];
        if (isSafe(newRow, newCol)) {
            board_[newRow][newCol] = counter; 
            knight_.first = newRow;
            knight_.second = newCol;
            if (brute_force(counter + 1)) {
                return true;
            }
            board_[newRow][newCol] = 0;
            /// dzin het ber vor backtrackingy apah0ovvi
        }
    }
    return false;
}

