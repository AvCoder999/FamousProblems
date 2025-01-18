#include "headers/Board.hpp"
#include <iomanip>

Board::Board()
    : std::vector<std::vector<int>>(SIZE, std::vector<int>(SIZE, -1))
{}

std::ostream&
operator<<(std::ostream& out, const Board& board)
{
    for (int i = 0; i < SIZE; ++i) {
        out << '|'; 
        for (int j = 0; j < SIZE; ++j) {
            out << std::setw(3) << board[i][j] << '|';
        }
        out << std::endl;
    }
    return out;
}

void
Board::reset()
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            (*this)[i][j] = -1;   
        }
    }
}

