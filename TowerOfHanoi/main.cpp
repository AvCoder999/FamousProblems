#include <iostream>
#include <cmath>
#include <unistd.h>

int getValue(const std::string& prompt);
const bool isInteractive = ::isatty(STDIN_FILENO);
void swapPegs(char& first, char& second, char& third);
void hanoy(const int count, char first, char second, char third);

int
main()
{
    const int count = getValue("Input disc count: "); 
    if (count <= 0) {
        std::cout << "Error 1: Invalid value. Count must be positive. " << std::endl;
        return 1;
    }
    
    std::cout << "From A to C" << std::endl;
    char first = 'A', second = 'B', third = 'C';
    hanoy(count, first, second, third);
    return 0;
}

void
hanoy(const int count, char first, char second, char third)
{
    if (count % 2 == 0) {
        char temp = second;
        second = third;
        third = temp;
    }

    const int lastIndex = ::pow(2, count) - 1;
    bool array[lastIndex] = {false};
    int maxPower = (lastIndex + 1) / 2; /// biggest power of 2 
    while (maxPower >= 4) {
        for (int i = maxPower; i < lastIndex; i += maxPower) {
            array[i] = !array[i];
        }
        maxPower /= 2;
    }
    
    for (int i = 1; i <= lastIndex; ++i) {
        std::cout << i++ << ") " << first << " -> " << third << std::endl;
        if (i >= lastIndex) {
            break;
        }
        if (1 == array[i]) {
            std::cout << i << ") " << second << " -> " << first << std::endl;
            swapPegs(first, second, third);
            continue;
        }
        std::cout << i << ") " << first << " -> " << second << std::endl;
        swapPegs(first, second, third);
    }
    
}

int
getValue(const std::string& prompt)
{
    if (isInteractive) {
        std::cout << prompt;
    }
    int result;
    std::cin >> result;
    return result;
}

void
swapPegs(char& first, char& second, char& third)
{
    const char temp = third;
    third = second;
    second = first;
    first = temp;
}

