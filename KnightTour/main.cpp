#include "headers/KnightTour.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int
main()
{
    std::srand(::time(NULL));    
    
    int initRow, initCol;
    std::cin >> initRow >> initCol; 
   
    KnightTour tour(initRow, initCol);
    return tour.run();
}

