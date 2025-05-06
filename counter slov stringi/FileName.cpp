#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


int main()
{
	char str[100];
	std::cout << "Input you sentence: \n";
	std::cin.getline(str, 100);
	int32_t counter{};
	char* token = strtok(str, ";.! ,");
	while (token != NULL)
	{
		std::cout << ++counter << ". ";
		std::cout << token << '\n';
		token = strtok(NULL, ";.! ,");
	}
	return 0;
}