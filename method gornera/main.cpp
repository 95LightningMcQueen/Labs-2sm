#include <iostream>

void InputSize(int32_t& size) 
{
    std::cout << "Input size: " << std::endl;
    std::cin >> size;
    if (size <= 0) 
    {
        throw std::invalid_argument("Wrong size");
    }
}

void createArray(double*& array, int32_t size) 
{
    array = new double[size];
}

void fillArray(double* array, int32_t size) 
{
    std::cout << "Input coefficients:" << std::endl;
    for (int32_t i{ size - 1 }; i >= 0; --i) 
    {
        std::cin >> array[i];
    }
}

double inputNumber(double& x) 
{
    std::cout << "Enter a x value: \n";
    std::cin >> x;
    return x;
}

double hornerMethod(double* coefficients, int32_t size, double x) 
{
    int32_t degree = size;
    double result = coefficients[0];
    for (int32_t i = 1; i <= degree; ++i) 
    {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() 
{
    int32_t size{};
    try 
    {
        InputSize(size);
        double* coefficients = nullptr;
        createArray(coefficients, size);
        fillArray(coefficients, size);
        double x{};
        inputNumber(x);
        std::cout << "Result is: " << hornerMethod(coefficients, size, x) << std::endl;
        delete[] coefficients;
    }
    catch (std::invalid_argument& e) 
    {
        std::cout << e.what();
    }
    return 0;
}

//double** mtr = new double* [m]

//for (size_t i{};i<m;++i)
//{
//    for (size_t i{}; i < n; ++j)
//    {
//        std::cin >> mtr[i][j];
//    }
//}