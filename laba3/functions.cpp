#include "functions.h"


void InputArraySize(int32_t& arraySize)
{
    std::cout << "Input size of array: ";
    std::cin >> arraySize;
    if (arraySize < 1)
    {
        throw std::invalid_argument("Error. Size of array must be at least 1");
    }
}

void CreateArray(double*& array, int32_t arraySize)
{
    array = new double[arraySize];
}

void DeleteArray(double*& array, int32_t arraySize)
{
    delete[] array;
}

void SelectingMethod(double* array, int32_t arraySize)
{
    int32_t choice{};
    std::cout << "Select the method of filling the array:\n1 - Enter from the keyboard \n2 - Fill with random numbers\n";
    std::cin >> choice;
    if (choice == 1)
    {
        InputArrayWithKeyboard(array, arraySize);
    }
    if (choice == 2)
    {
        InputRandomArray(array, arraySize);
    }
    else if (choice != 1 && choice != 2)
    {
        throw std::invalid_argument("Error. Incorrect way to fill array.");
    }
}

void InputArrayWithKeyboard(double* array, int32_t arraySize)
{
    std::cout << "\nInput Array: ";
    for (int32_t i{ 0 }; i < arraySize; ++i)
    {
        std::cin >> array[i];
    }
}

void InputRandomArray(double* array, int32_t arraySize)
{
    int32_t beginningOfInterval{}, endOfInterval{};
    std::cout << "\nInput intervals border: ";
    std::cin >> beginningOfInterval >> endOfInterval;
    if (beginningOfInterval > endOfInterval)
    {
        throw std::invalid_argument("\nError. Interval start must be less than or equal to interval end");
    }
    srand(time(0));
    for (int32_t i = 0; i < arraySize; ++i)
    {
        array[i] = beginningOfInterval + rand() % (endOfInterval - beginningOfInterval + 1);
    }
}

void OutputArray(double* array, int32_t arraySize)
{
    for (int32_t i = 0; i < arraySize; ++i)
    {
        std::cout << array[i] << ' ';
    }
}

void SwapMaxMinElements(double* array, int32_t arraySize)
{
    int32_t firstMinIndex{}, firstMaxIndex{};
    for (int32_t i = 1; i < arraySize; ++i)
    {
        if (abs(array[i]) < abs(array[firstMinIndex]))
        {
            firstMinIndex = i;
        }
        if (abs(array[i]) > abs(array[firstMaxIndex]))
        {
            firstMaxIndex = i;
        }
    }
    double temp = array[firstMinIndex];
    array[firstMinIndex] = array[firstMaxIndex];
    array[firstMaxIndex] = temp;
}

double SumAfterLastMin(double* array, int32_t arraySize)
{
    int32_t lastMinIndex{};
    for (int32_t i = 1; i < arraySize; ++i)
    {
        if (abs(array[i]) <= abs(array[lastMinIndex]))
        {
            lastMinIndex = i;
        }
    }
    double sum{};
    for (int32_t i = lastMinIndex + 1; i < arraySize; ++i)
    {
        sum += array[i];
    }
    return sum;
}

void ReplacingNegativesWithSquares(double* array, int32_t arraySize)
{
    for (int32_t i = 0; i < arraySize; ++i)
    {
        if (array[i] < 0)
        {
            array[i] = array[i] * array[i];
        }
    }
}

void SortArray(double* array, int32_t arraySize)
{
    for (int32_t i = 0; i < arraySize - 1; ++i)
    {
        for (int32_t j = 0; j < arraySize - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                double variable = array[j];
                array[j] = array[j + 1];
                array[j + 1] = variable;
            }
        }
    }
}

void DeleteElementsForStrictlyIncreasing(double* array, int32_t& arraySize)
{
    int j{};
    for (int32_t i = 1; i < arraySize; ++i)
    {
        if (array[i] > array[j])
        {
            array[++j] = array[i];
        }
    }
    arraySize = j + 1;
}

double ProductBetweenLastMinAndLastMax(double* array, int32_t arraySize)
{
    int32_t lastMinElement{}, lastMaxElement{};
    for (int32_t i = 1; i < arraySize; ++i)
    {
        if (array[i] <= array[lastMinElement])
        {
            lastMinElement = i;
        }
        if (array[i] >= array[lastMaxElement])
        {
            lastMaxElement = i;
        }
    }
    int32_t start{}, end{};
    if (lastMinElement < lastMaxElement)
    {
        start = lastMinElement;
        end = lastMaxElement;
    }
    else
    {
        start = lastMaxElement;
        end = lastMinElement;
    }

    double product = 1;
    for (int32_t i = start + 1; i < end; ++i)
    {
        product *= array[i];
    }
    return product;
}

void SortEvenIndexedElements(double* array, int32_t arraySize)
{
    for (int32_t i = 0; i < arraySize; i += 2)
    {
        for (int32_t j = i + 2; j < arraySize; j += 2)
        {
            if (array[j] < array[i])
            {
                double variable = array[i];
                array[i] = array[j];
                array[j] = variable;
            }
        }
    }
}