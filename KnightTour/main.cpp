#include "headers/KnightTour.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int
main()
{
    std::srand(::time(NULL));    
    /*
    int boardSize;
    std::cin >> boardSize;
    
    int initRow, initCol;
    std::cin >> initRow >> initCol; 
    KnightTour tour(boardSize, initRow, initCol);
    */
    KnightTour tour(8, ::rand() % 8, ::rand() % 8);
    /// KnightTour tour(8, 4, 5);
    return tour.run();
}

