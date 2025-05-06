#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>


int main() 
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char name[100], result[150];
	strcpy(result, "Привет, ");
	std::cout << "Введите свое имя:\n";
	std::cin.getline(name, 100);
	strcat(result, name);
	strcat(result, " !\n");
	std::cout << result;
	return 0;
}