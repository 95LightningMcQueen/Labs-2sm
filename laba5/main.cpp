#include "functions.h"


int main()
{
    int32_t n = 0;
    EnterMatrixSize(n);
    try
    {
        if (CheckMatrixSize(n))
        {
            throw std::exception();
        }
        int32_t** matrix = CreateMatrix(n);
        SelectingMethod(matrix, n);
        PrintMatrix(matrix, n);
        // 1 задача: найти первый столбец, в котором отсутствуют отрицательные элементы.
        FirstTask(matrix, n);
        // 2 задача: осуществить обход матрицы по спирали, начиная с центра, против часовой стрелки, первый ход - вверх.
        std::cout << "\nSpiral traversal from the center:\n";
        SpiralTraversal(matrix, n);
        DeleteMatrix(matrix, n);
    }
    catch (const std::exception&)
    {
        std::cout << "Invalid matrix size.\n";
    }
    return 0;
}
