//посчитать сумму элементов строки с макс элементом матрицы и произведение элементов с мин элементом в столбце
#include <iostream>
#include <random>

int main()
{
	int32_t rows{}, cols{};
	std::cout << "Input rows, cols: ";
	std::cin >> rows >> cols;
	int32_t** mtr = new int32_t * [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		mtr[i] = new int32_t[cols];
	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution <int32_t> dis(-100, 100);
		}
	}
	int32_t maxNum{ mtr[0][0] }, minNum{ mtr[0][0] };
	size_t iMax{}, jMin{};
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			if (mtr[i][j] > maxNum)
			{
				maxNum = mtr[i][j];
				iMax = i;
			}
			if (mtr[i][j] <= minNum)
			{
				minNum = mtr[i][j];
				jMin = j;
			}
		}
	}
	int32_t sum{};
	for (size_t j = 0; j < cols; ++j)
	{
		sum += mtr[iMax][j];
	}
	int32_t product{};
	for (size_t i = 0; i < rows; ++i)
	{
		product *= mtr[i][jMin];
	}
	for (size_t i = 0; i < rows; ++i)
	{
		delete[]mtr[i];
		delete[]mtr;
	}
}