#include "functions.h"


int main()
{
    int32_t arraySize{};
    try
    {
        InputArraySize(arraySize);
        double* array = nullptr;
        CreateArray(array, arraySize);
        SelectingMethod(array, arraySize);
        std::cout << "\nOriginal array: ";
        OutputArray(array, arraySize);
        SwapMaxMinElements(array, arraySize);
        std::cout << "\nArray after swapping of maximum and minimum (by absolute value) elements: ";
        OutputArray(array, arraySize);
        double sum = SumAfterLastMin(array, arraySize);
        std::cout << "\nSum of elements after the last min element is equal " << sum;
        ReplacingNegativesWithSquares(array, arraySize);
        std::cout << "\nArray after replacing negative elements with their squares: ";
        OutputArray(array, arraySize);
        SortArray(array, arraySize);
        std::cout << "\nArray after sorting in increasing order: ";
        OutputArray(array, arraySize);
        DeleteElementsForStrictlyIncreasing(array, arraySize);
        std::cout << "\nArray after removing duplicates for strictly increasing order: ";
        OutputArray(array, arraySize);
        double product = ProductBetweenLastMinAndLastMax(array, arraySize);
        std::cout << "\nProduct of elements between the last maximum and the last minimum element is equal to " << product;
        SortEvenIndexedElements(array, arraySize);
        std::cout << "\nArray after sorting even-indexed elements in ascending order: ";
        OutputArray(array, arraySize);
        DeleteArray(array, arraySize);
    }
    catch (const std::exception& error)
    {
        std::cout << error.what();
    }
    return 0;
}
