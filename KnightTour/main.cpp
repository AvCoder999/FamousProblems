#include "headers/KnightTour.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int
main()
{
    std::srand(::time(NULL));    
    
    int boardSize;
    std::cin >> boardSize;
    
    int initRow, initCol;
    std::cin >> initRow >> initCol; 
   
    KnightTour tour(boardSize, initRow, initCol);
    return tour.run();
}

