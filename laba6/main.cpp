#include <iostream>
#include <cstring>
#include <stdexcept>
#include "functions.h"

int main() 
{
    const int32_t MAX_INPUT = 300;    
    const int32_t MAX_RESULT = 1000;
    char inputStr[MAX_INPUT + 1]; 
    char seps[101];               
    char result[MAX_RESULT + 1];  

    try 
    {
        std::cout << "Enter a string (maximum " << MAX_INPUT << " characters): ";
        std::cin.getline(inputStr, MAX_INPUT + 1);
        if (std::strlen(inputStr) == 0) 
        {
            throw std::runtime_error("\nCannot solve the problem: empty string.");
        }
        std::cout << "\nEnter delimiter characters (if empty, the whole string is considered one word): ";
        std::cin.getline(seps, 101);
        FindLongestWords(inputStr, seps, result);
        std::cout << "\nThe longest words are: " << result;
    }
    catch (const std::runtime_error& e) 
    {
        std::cout << e.what();
    }
    return 0;
}