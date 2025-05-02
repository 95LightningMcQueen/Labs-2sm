#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdint>


void enterMatrixSize(int32_t&);
bool checkMatrixSize(int32_t);
int32_t** createMatrix(int32_t);
void deleteMatrix(int32_t**, int32_t);
void slectingMethod(int32_t**, int32_t);
void fillMatrixFromKeyboard(int32_t**, int32_t);
void fillMatrixRandom(int32_t**, int32_t, int32_t, int32_t);
void printMatrix(int32_t**, int32_t);
void firstTask(int32_t**, int32_t);
int32_t findFirstNonNegativeColumn(int32_t**, int32_t);