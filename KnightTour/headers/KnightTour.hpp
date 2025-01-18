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

enum Approach { ITERATIVE, RECURSIVE };

class KnightTour
{
private:
    static const int MOVE_COUNT = 8;
    static const int moveX[MOVE_COUNT];
    static const int moveY[MOVE_COUNT];
    static std::vector<std::vector<int>> accessibility;
private:
    static void resetAccessTable();
public:
    KnightTour(const int row = 0, const int col = 0);
    int run(const Approach& version = ITERATIVE);
private:
    bool isSafe(const int row, const int col);
    bool brute_force(const int x, const int y, const int moveCount);
    bool Warnsdorff_method(const int x, const int y);
    void moveKnight();
    void updateAccessTable();
    bool isClosedTour(const int x, const int y);
private:
    Knight knight_;
    Board board_;
};

#endif /// __KNIGHT_TOUR_HPP__

