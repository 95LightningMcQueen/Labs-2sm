#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>


void EnterMatrixSize(int32_t&);
bool CheckMatrixSize(int32_t);
int32_t** CreateMatrix(int32_t);
void DeleteMatrix(int32_t**, int32_t);
void SelectingMethod(int32_t**, int32_t);
void FillMatrixFromKeyboard(int32_t**, int32_t);
void FillMatrixRandom(int32_t**, int32_t, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t);
void FirstTask(int32_t**, int32_t);
int32_t FindFirstNonNegativeColumn(int32_t**, int32_t);
void SpiralTraversal(int32_t**, int32_t);
