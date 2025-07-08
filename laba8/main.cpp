#include "functions.h"

int main() 
{
    try 
    {
        Task();
    }
    catch (const std::exception& e) 
    {
        std::cout << "Unable to solve the problem: " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cout << "Unknown error occurred" << std::endl;
    }
    return 0;
}