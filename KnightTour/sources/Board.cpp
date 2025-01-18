#include "headers/Board.hpp"
#include <iomanip>

Board::Board(const int size)
    : std::vector<std::vector<int>>(size, std::vector<int>(size, -1))
{}

std::ostream&
operator<<(std::ostream& out, const Board& board)
{
    const int size = board.size();
    for (int i = 0; i < size; ++i) {
        out << '|'; 
        for (int j = 0; j < size; ++j) {
            out << std::setw(3) << board[i][j] << '|';
        }
        out << std::endl;
    }
    return out;
}

void
Board::reset()
{
    const int size = this->size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            (*this)[i][j] = -1;   
        }
    }
}

