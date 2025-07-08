#ifndef HEADER
#define HEADER
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
void Task();

struct Student 
{
    std::string name;
    std::string surname;
    int course;
    std::string group;
    int grades[5];
};

int32_t CountFractionalDigits(double);
void Swap_double(double*, double*);
int32_t Partition(double arr[], int32_t, int32_t, bool);
void QuickSort(double arr[], int32_t, int32_t, bool);
void InsertionSort(double arr[], int32_t, bool);
void BubbleSort(double arr[], int32_t, bool);
void QsortByFractionalDigits(double arr[], int32_t);
void SelectionSort(double arr[], int32_t, bool);
void Merge(double arr[], int32_t, int32_t, int32_t, bool);
void MergeSort(double arr[], int32_t, int32_t, bool);
double CalculateAverage(const Student&);
void Swap_student(Student*, Student*);
int32_t Partition(Student arr[], int32_t, int32_t, bool);
void QuickSort(Student arr[], int32_t, int32_t, bool);
double* InputNumbers(int32_t&, int32_t);
Student* InputStudents(int32_t&, int32_t);
void OutputNumbers(double arr[], int32_t, int32_t);
void OutputStudents(Student arr[], int32_t, int32_t);
void SortNumbers(double*, int32_t, int32_t, int32_t);
void SortStudents(Student*, int32_t, int32_t);
void ProcessNumbers();
void ProcessStudents();
void Task();


#endif