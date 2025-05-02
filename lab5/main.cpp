#include "functions.h"


int main()
{
    int32_t n = 0;
    enterMatrixSize(n);
    if (checkMatrixSize(n))
    {
        std::cout << "Invalid matrix size.\n";
    }
    else
    {
        int32_t** matrix = createMatrix(n);
        slectingMethod(matrix, n);
        printMatrix(matrix, n);
        // 1 ������: ����� ������ �������, � ������� ����������� ������������� ��������.
        firstTask(matrix, n);
        deleteMatrix(matrix, n);
    }
    return 0;
}