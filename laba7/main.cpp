#include <iostream>
#include <string>
#include <stdexcept>
#include "functions.h"


int main() 
{
    try 
    {
        std::cout << "Enter a string: ";
        std::string input{};
        if (!std::getline(std::cin, input)) 
        {
            throw std::runtime_error("\nError reading string.");
        }
        std::string result{ processInput(input) };
        if (result.empty()) 
        {
            std::cout << "\nNo solution exists.";
        }
        else 
        {
            std::cout << "\nResult: " << result;
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what();
    }
    return 0;
}