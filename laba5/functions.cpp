#include "functions.h"


void EnterMatrixSize(int32_t& n)
{
    std::cout << "Enter square matrix size (odd number between 3 and 101): ";
    std::cin >> n;
}

bool CheckMatrixSize(int32_t n)
{
    if (n < 3 || n > 101 || (n % 2) == 0)
    {
        return true;
    }
    return false;
}

int32_t** CreateMatrix(int32_t n)
{
    int32_t** matrix = new int32_t * [n];
    for (int32_t i = 0; i < n; ++i)
    {
        matrix[i] = new int32_t[n];
    }
    return matrix;
}

void DeleteMatrix(int32_t** matrix, int32_t n)
{
    for (int32_t i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void SelectingMethod(int32_t** matrix, int32_t n)
{
    int32_t choice = 0;
    std::cout << "Select the matrix filling method:\n";
    std::cout << "1 - Input from keyboard\n";
    std::cout << "2 - Fill with random numbers\n";
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;
    if (choice == 1)
    {
        FillMatrixFromKeyboard(matrix, n);
    }
    else if (choice == 2)
    {
        int32_t lower = 0, upper = 0;
        FillMatrixRandom(matrix, n, lower, upper);
    }
    else
    {
        std::cout << "Invalid filling method selection.\n";
        DeleteMatrix(matrix, n);
    }
}

void FillMatrixFromKeyboard(int32_t** matrix, int32_t n)
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

void FillMatrixRandom(int32_t** matrix, int32_t n, int32_t lower, int32_t upper)
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
        DeleteMatrix(matrix, n);
    }
}

void PrintMatrix(int32_t** matrix, int32_t n)
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

void FirstTask(int32_t** matrix, int32_t n)
{
    int32_t firstColumn = FindFirstNonNegativeColumn(matrix, n);
    if (firstColumn != -1)
    {
        std::cout << "\nNumber of the first column without negative elements: " << (firstColumn + 1) << "\n";
    }
    else
    {
        std::cout << "\nThere is no column without negative elements in the matrix.\n";
    }
}

int32_t FindFirstNonNegativeColumn(int32_t** matrix, int32_t n)
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

void SpiralTraversal(int32_t** matrix, int32_t n)
{
    int32_t center = n / 2;
    int32_t row = center, col = center;
    int32_t numberOfElements = n * n;
    int32_t count = 1;  // центральный элемент
    std::cout << matrix[row][col] << "  ";
    //направления: вверх, влево, вниз, вправо
    int32_t directions[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
    int32_t d = 0;
    int32_t steps = 1;
    while (count < numberOfElements)
    {
        for (int32_t rep = 0; rep < 2 && count < numberOfElements; ++rep)
        {
            for (int32_t i = 0; i < steps && count < numberOfElements; ++i)
            {
                row += directions[d][0];
                col += directions[d][1];
                std::cout << matrix[row][col] << "  ";
                count++;
            }
            d = (d + 1) % 4;
        }
        steps++;//увеличиваем длину следующего витка спирали
    }
    std::cout << "\n";
}
