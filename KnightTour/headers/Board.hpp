#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <iostream>

class Board;
std::ostream&
operator<<(std::ostream& out, const Board& board);

class Board : public std::vector<std::vector<int>>
{
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
public:
    Board(const int size);
};

#endif /// __BOARD_HPP__

