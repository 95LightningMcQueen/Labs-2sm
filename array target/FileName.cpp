#include <iostream>

void InputArraySize(int32_t&);
bool CheckSize(int32_t);
const int32_t MAX_SIZE{100};
void InputArray(int32_t*, int32_t);
void OutputArray(int32_t*, int32_t);
int32_t FindElement(int32_t*, int32_t, int32_t);

int main()
{
	int32_t array[MAX_SIZE], arraySize{}, arrayTarget{};
	InputArraySize(arraySize);
	if (!CheckSize(arraySize))
	{
		std::cout << "Wrong size :c";
	}
	else
	{
		std::cout << "\nInput elements of array: ";
		InputArray(array, arraySize);
		system("cls");
		std::cout << "Your Array: ";
		OutputArray(array, arraySize);
		std::cout << "\n\nInput target element to find: ";
		std::cin >> arrayTarget;
		int32_t result = FindElement(array, arraySize, arrayTarget);
		if (result != -1)
		{
			std::cout << "\nLast found element " << arrayTarget << " is at position: " << result;
		}
		else
		{
			std::cout << "\nElement " << arrayTarget << " is not found in the array";
		}
	}
	return 0;
}

void InputArraySize(int32_t& arraySize)
{
	std::cout << "Input size of array: ";
	std::cin >> arraySize;
}

bool CheckSize(int32_t arraySize)
{
	return arraySize > 0 && arraySize < MAX_SIZE;
}

void InputArray(int32_t* array, int32_t arraySize)
{
	for (size_t i{}; i < arraySize; ++i)
	{
		std::cin >> array[i];
	}
}

void OutputArray(int32_t* array, int32_t arraySize)
{
	for (size_t i{}; i < arraySize; ++i)
	{
		std::cout << array[i] << ' ';
	}
}

int32_t FindElement(int32_t* array, int32_t arraySize, int32_t arrayTarget)
{
	int32_t position = -1;
	for (int32_t i = 0; i < arraySize; ++i)
	{
		if (array[i] == arrayTarget)
		{
			position = i + 1;
		}
	}
	return position;
}
