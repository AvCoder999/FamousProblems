#include "headers/KnightTour.hpp"

const int KnightTour::moveX[KnightTour::MOVE_COUNT] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int KnightTour::moveY[KnightTour::MOVE_COUNT] = { 1, 2, 2, 1, -1, -2, -2, -1 };
std::vector<std::vector<int>> KnightTour::accessibility = {
        {2, 3, 4, 4, 4, 4, 3, 2},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {2, 3, 4, 4, 4, 4, 3, 2}
    };

void 
KnightTour::resetAccessTable()
{
    accessibility = {
        {2, 3, 4, 4, 4, 4, 3, 2},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {2, 3, 4, 4, 4, 4, 3, 2}
    };
}

std::ostream&
operator<<(std::ostream& out, const Knight& knight)
{
    return out << knight.first << " : " << knight.second << std::endl;
}

KnightTour::KnightTour(const int row, const int col)
    : knight_(row, col)
    , board_()
{}

int
KnightTour::run(const Approach& version)
{
    if (ITERATIVE == version) {
        Warnsdorff_method(knight_.first, knight_.second);
        resetAccessTable();
    } else {
        board_[knight_.first][knight_.second] = 0;
        brute_force(knight_.first, knight_.second, 1);
    } 
    std::cout << board_ << std::endl;
    board_.reset();
    return 0;
}

bool 
KnightTour::brute_force(const int x, const int y, const int counter)
{
    /// std::cout << board_ << std::endl;
    if (counter == SIZE * SIZE) {
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

bool
KnightTour::isSafe(const int row, const int col)
{
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE &&-1 == board_[row][col]);
}

bool 
KnightTour::Warnsdorff_method(const int x, const int y)
{
    for (int value = 0; value < SIZE * SIZE; ++value) {
        board_[knight_.first][knight_.second] = value;
        /// std::cout << board_ << std::endl;
        moveKnight(); 
        updateAccessTable(); 
        
    }
    return isClosedTour(x, y);
}

void
KnightTour::moveKnight()
{
    int minAccess = 9;
    int counter = -1;
    for (int i = 0; i < MOVE_COUNT; ++i) {
        const int nextX = knight_.first + moveX[i];
        const int nextY = knight_.second + moveY[i];
        if (isSafe(nextX, nextY) && accessibility[nextX][nextY] < minAccess) {
            minAccess = accessibility[nextX][nextY];
            counter = i;
        }
    }
    knight_.first += moveX[counter];
    knight_.second += moveY[counter];
}

void 
KnightTour::updateAccessTable()
{
    for (int i = 0; i < MOVE_COUNT; ++i) {
        const int nextX = knight_.first + moveX[i];
        const int nextY = knight_.second + moveY[i];
        if (nextX >= 0 && nextX < SIZE && nextY >= 0 && nextY < SIZE) {
            --accessibility[nextX][nextY];
        }
    }
}

bool
KnightTour::isClosedTour(const int x, const int y)
{
    for (int i = 0; i < MOVE_COUNT; ++i) {
        const int nextX = x + moveX[i];
        const int nextY = y + moveY[i];
        if (std::pair<int, int>(nextX, nextY) == knight_) { 
            return true;
        }
    }
    return false;
}

