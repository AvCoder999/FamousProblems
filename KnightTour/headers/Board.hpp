#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <iostream>

const int SIZE = 8;
class Board;
std::ostream&
operator<<(std::ostream& out, const Board& board);

class Board : public std::vector<std::vector<int>>
{
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
public:
    Board();
    void reset();
};

#endif /// __BOARD_HPP__

