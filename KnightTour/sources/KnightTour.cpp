#include "headers/KnightTour.hpp"

/// int KnightTour::moveX[KnightTour::MOVE_COUNT] = {-2, -2, -1, -1, 1, 1, 2, 2 };
/// int KnightTour::moveY[KnightTour::MOVE_COUNT] = {-1, 1, -2, 2, -2, 2, -1, 1 };

int KnightTour::moveX[KnightTour::MOVE_COUNT] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int KnightTour::moveY[KnightTour::MOVE_COUNT] = { 1, 2, 2, 1, -1, -2, -2, -1 };

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
            -1 == board_[row][col]);
}

int
KnightTour::run()
{
    board_[knight_.first][knight_.second] = 0;
    brute_force(knight_.first, knight_.second, 1);
    std::cout << board_ << std::endl;
    board_.reset();
    return 0;
}

bool 
KnightTour::brute_force(const int x, const int y, const int counter)
{
    /// std::cout << board_ << std::endl;
    if (counter == static_cast<int>(board_.size() * board_.size())) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        const int nextX = x + moveX[i];
        const int nextY = y + moveY[i];

        if (isSafe(nextX, nextY)) {
            board_[nextX][nextY] = counter; 
            if (brute_force(nextX, nextY, counter + 1)) {
                return true;
            }
            board_[nextX][nextY] = -1;
        }
    }
    return false; 
}

