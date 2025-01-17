#ifndef __KNIGHT_TOUR_HPP__
#define __KNIGHT_TOUR_HPP__

#include "Board.hpp"
#include <utility>
#include <iostream>

struct Knight : public std::pair<int, int> {
    Knight(const int row = 0, const int col = 0) : pair(row, col) {} 
};

std::ostream&
operator<<(std::ostream& out, const Knight& knight);


class KnightTour
{
private:
    static const int MOVE_COUNT = 8;
    static int moveX[MOVE_COUNT];
    static int moveY[MOVE_COUNT];
public:
    KnightTour(const int boardSize = 8, const int row = 0, const int col = 0);
    int run();
private:
    bool isSafe(const int row, const int col);
    bool brute_force(const int counter);
    bool solveTour(int x, int y, int moveCount);
private:
    Board board_;
    Knight knight_;
};

#endif /// __KNIGHT_TOUR_HPP__

