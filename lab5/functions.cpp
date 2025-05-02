#include "functions.h"


void enterMatrixSize(int32_t& n)
{
    std::cout << "Enter square matrix size (odd number between 3 and 101): ";
    std::cin >> n;
}

bool checkMatrixSize(int32_t n)
{
    if (n < 3 || n > 101 || (n % 2) == 0)
    {
        return true;
    }
    return false;
}

int32_t** createMatrix(int32_t n)
{
    int32_t** matrix = new int32_t * [n];
    for (int32_t i = 0; i < n; ++i)
    {
        matrix[i] = new int32_t[n];
    }
    return matrix;
}

void deleteMatrix(int32_t** matrix, int32_t n)
{
    for (int32_t i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void slectingMethod(int32_t** matrix, int32_t n)
{
    int32_t choice = 0;
    std::cout << "Select the matrix filling method:\n";
    std::cout << "1 - Input from keyboard\n";
    std::cout << "2 - Fill with random numbers\n";
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;
    if (choice == 1)
    {
        fillMatrixFromKeyboard(matrix, n);
    }
    else if (choice == 2)
    {
        int32_t lower = 0, upper = 0;
        fillMatrixRandom(matrix, n, lower, upper);
    }
    else
    {
        std::cout << "Invalid filling method selection.\n";
        deleteMatrix(matrix, n);
    }
}

void fillMatrixFromKeyboard(int32_t** matrix, int32_t n)
{
    for (int32_t i = 0; i < n; ++i)
    {
        for (int32_t j = 0; j < n; ++j)
        {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void fillMatrixRandom(int32_t** matrix, int32_t n, int32_t lower, int32_t upper)
{
    std::cout << "Enter lower bound: ";
    std::cin >> lower;
    std::cout << "Enter upper bound: ";
    std::cin >> upper;
    if (upper > lower)
    {
        std::srand(static_cast<uint32_t>(std::time(0)));
        for (int32_t i = 0; i < n; i++)
        {
            for (int32_t j = 0; j < n; j++)
            {
                matrix[i][j] = lower + std::rand() % (upper - lower + 1);
            }
        }
    }
    else
    {
        std::cout << "Invalid interval.\n";
        deleteMatrix(matrix, n);
    }
}

void printMatrix(int32_t** matrix, int32_t n)
{
    for (int32_t i = 0; i < n; ++i)
    {
        for (int32_t j = 0; j < n; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void firstTask(int32_t** matrix, int32_t n)
{
    int32_t firstColumn = findFirstNonNegativeColumn(matrix, n);
    if (firstColumn != -1)
    {
        std::cout << "\nNumber of the first column without negative elements: " << (firstColumn + 1) << "\n";
    }
    else
    {
        std::cout << "\nThere is no column without negative elements in the matrix.\n";
    }
}

int32_t findFirstNonNegativeColumn(int32_t** matrix, int32_t n)
{
    int32_t firstNonNegativeColumn = -1; // -1 означает, что такого столбца нет
    for (int32_t j = 0; j < n; ++j)
    {
        bool allNonNegative = true;
        for (int32_t i = 0; i < n; ++i)
        {
            if (matrix[i][j] < 0)
            {
                allNonNegative = false;
                break;
            }
        }
        if (allNonNegative == true)
        {
            firstNonNegativeColumn = j;
            break;
        }
    }
    return firstNonNegativeColumn;
}