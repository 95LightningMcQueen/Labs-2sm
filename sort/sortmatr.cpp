#include <iostream>
#include <algorithm>  // Для std::swap
#include <cstdlib>    // Для std::rand, std::srand
#include <ctime>      // Для std::time

// ---------------------------------------------------------------------
// Функция allocateMatrix
// Идея: Динамически выделяет память для матрицы размером rows x cols.
// ---------------------------------------------------------------------
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// ---------------------------------------------------------------------
// Функция freeMatrix
// Идея: Освобождает память, выделенную для матрицы.
// ---------------------------------------------------------------------
void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// ---------------------------------------------------------------------
// Функция fillMatrix
// Идея: Заполняет матрицу, предоставляя пользователю выбор метода:
//       1 — ручной ввод,
//       2 — рандомное заполнение (числа от 0 до 99).
// ---------------------------------------------------------------------
void fillMatrix(int** matrix, int rows, int cols)
{
    int method;
    std::cout << "Choose matrix fill method:\n";
    std::cout << "1: Manual input\n";
    std::cout << "2: Random fill\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> method;

    if (method == 1) {
        std::cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Element [" << i << "][" << j << "]: ";
                std::cin >> matrix[i][j];
            }
        }
    }
    else if (method == 2) {
        std::srand((unsigned)std::time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = std::rand() % 100;  // random number from 0 to 99
            }
        }
        std::cout << "Matrix filled with random numbers.\n";
    }
    else {
        std::cout << "Invalid choice, using random fill.\n";
        std::srand((unsigned)std::time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = std::rand() % 100;
            }
        }
        std::cout << "Matrix filled with random numbers.\n";
    }
}

// ---------------------------------------------------------------------
// Функция printMatrix
// Идея: Выводит матрицу на экран.
// ---------------------------------------------------------------------
void printMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// ---------------------------------------------------------------------
// Функция copyMatrix
// Идея: Копирует содержимое одной матрицы в другую.
// ---------------------------------------------------------------------
void copyMatrix(int** source, int** dest, int rows, int cols)
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            dest[i][j] = source[i][j];
        }
    }
}

// ---------------------------------------------------------------------
// 1. Сортировка вставками (Insertion Sort)
// Идея: Проходим по массиву, берём текущий элемент (key) и вставляем его
// в отсортированную часть, сдвигая вправо элементы, большие key.
// ---------------------------------------------------------------------
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ---------------------------------------------------------------------
// 2. Сортировка слиянием (Merge Sort)
// Идея: Разбиваем массив на две части, рекурсивно сортируем их, 
// а затем объединяем две отсортированные части.
// ---------------------------------------------------------------------
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;  // Размер левого подмассива
    int n2 = right - mid;     // Размер правого подмассива

    int* L = new int[n1];
    int* R = new int[n2];

    // Копируем элементы в временные массивы
    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    // Объединяем временные массивы в основной
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1) 
    {
        arr[k++] = L[i++];
    }
    while (j < n2) 
    {
        arr[k++] = R[j++];
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// ---------------------------------------------------------------------
// 3. Быстрая сортировка (Quick Sort)
// Идея: Выбирается опорный элемент (pivot), затем элементы меньше pivot
// перемещаются влево, а большие – вправо. После чего рекурсивно сортируются
// полученные части.
// ---------------------------------------------------------------------
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Опорный элемент
    int i = low - 1;        // Индекс для элементов меньше pivot
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ---------------------------------------------------------------------
// 4. Пирамидальная сортировка (Heap Sort)
// Идея: Построить max-кучу из массива, затем последовательно извлекать
// наибольший элемент (корень) и восстанавливать кучу.
// ---------------------------------------------------------------------
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) 
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Построение кучи
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i);
    }
    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; i--) 
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ---------------------------------------------------------------------
// 5. Сортировка пузырьком (Bubble Sort)
// Идея: На каждом проходе последовательно сравниваем соседние элементы и 
// меняем их местами, если они в неверном порядке.
// ---------------------------------------------------------------------
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ---------------------------------------------------------------------
// 6. Сортировка подсчётом (Counting Sort)
// Идея: Подсчитываем вхождения каждого числа (при условии, что все числа неотсрицательны),
// затем восстанавливаем отсортированную последовательность по накопленным счетчикам.
// ---------------------------------------------------------------------
int* countingSort(int arr[], int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max_val)
            max_val = arr[i];
    }
    int range = max_val + 1;
    int* count = new int[range];
    for (int i = 0; i < range; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    int* output = new int[n];
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    delete[] count;
    return output;  // Не забудьте освободить выделенную память в main!
}

// ---------------------------------------------------------------------
// 7. Сортировка Шелла (Shell Sort)
// Идея: Улучшенная сортировка вставками, которая сравнивает элементы,
// отстоящие на определённое расстояние (gap). Этот шаг постепенно уменьшается до 1.
// ---------------------------------------------------------------------
void shellSort(int arr[], int n)
{
    int gap = n / 2;
    while (gap > 0) 
    {
        for (int i = gap; i < n; i++) 
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) 
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

// ---------------------------------------------------------------------
// 8. Сортировка выбором (Selection Sort)
// Идея: Для каждой позиции в массиве находим минимальный элемент в неотсортированной
// части и меняем его с первым элементом этой части.
// ---------------------------------------------------------------------
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

// =====================================================================
// Main function (all comments in English)
// =====================================================================
int main()
{
    // Ask user for number of rows and columns
    int rows, cols;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Allocate and fill the original matrix
    int** original = allocateMatrix(rows, cols);
    fillMatrix(original, rows, cols);

    // Allocate matrices for each sorting algorithm and copy the original matrix into them
    int** mInsertion = allocateMatrix(rows, cols);
    int** mMerge = allocateMatrix(rows, cols);
    int** mQuick = allocateMatrix(rows, cols);
    int** mHeap = allocateMatrix(rows, cols);
    int** mBubble = allocateMatrix(rows, cols);
    int** mCounting = allocateMatrix(rows, cols);
    int** mShell = allocateMatrix(rows, cols);
    int** mSelection = allocateMatrix(rows, cols);

    copyMatrix(original, mInsertion, rows, cols);
    copyMatrix(original, mMerge, rows, cols);
    copyMatrix(original, mQuick, rows, cols);
    copyMatrix(original, mHeap, rows, cols);
    copyMatrix(original, mBubble, rows, cols);
    copyMatrix(original, mCounting, rows, cols);
    copyMatrix(original, mShell, rows, cols);
    copyMatrix(original, mSelection, rows, cols);

    std::cout << "\nOriginal matrix:\n";
    printMatrix(original, rows, cols);

    // For each matrix, sort each row using the corresponding sorting algorithm

    // Insertion Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        insertionSort(mInsertion[i], cols);
    }
    std::cout << "\nAfter Insertion Sort (each row sorted):\n";
    printMatrix(mInsertion, rows, cols);

    // Merge Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        mergeSort(mMerge[i], 0, cols - 1);
    }
    std::cout << "\nAfter Merge Sort (each row sorted):\n";
    printMatrix(mMerge, rows, cols);

    // Quick Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        quickSort(mQuick[i], 0, cols - 1);
    }
    std::cout << "\nAfter Quick Sort (each row sorted):\n";
    printMatrix(mQuick, rows, cols);

    // Heap Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        heapSort(mHeap[i], cols);
    }
    std::cout << "\nAfter Heap Sort (each row sorted):\n";
    printMatrix(mHeap, rows, cols);

    // Bubble Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        bubbleSort(mBubble[i], cols);
    }
    std::cout << "\nAfter Bubble Sort (each row sorted):\n";
    printMatrix(mBubble, rows, cols);

    // Counting Sort for each row
    // (Note: countingSort returns a new array; copy the result back)
    for (int i = 0; i < rows; i++) 
    {
        int* sortedRow = countingSort(mCounting[i], cols);
        for (int j = 0; j < cols; j++) 
        {
            mCounting[i][j] = sortedRow[j];
        }
        delete[] sortedRow;
    }
    std::cout << "\nAfter Counting Sort (each row sorted):\n";
    printMatrix(mCounting, rows, cols);

    // Shell Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        shellSort(mShell[i], cols);
    }
    std::cout << "\nAfter Shell Sort (each row sorted):\n";
    printMatrix(mShell, rows, cols);

    // Selection Sort for each row
    for (int i = 0; i < rows; i++) 
    {
        selectionSort(mSelection[i], cols);
    }
    std::cout << "\nAfter Selection Sort (each row sorted):\n";
    printMatrix(mSelection, rows, cols);

    // Free all allocated memory
    freeMatrix(original, rows);
    freeMatrix(mInsertion, rows);
    freeMatrix(mMerge, rows);
    freeMatrix(mQuick, rows);
    freeMatrix(mHeap, rows);
    freeMatrix(mBubble, rows);
    freeMatrix(mCounting, rows);
    freeMatrix(mShell, rows);
    freeMatrix(mSelection, rows);

    return 0;
}
