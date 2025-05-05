#include <iostream>
#include <algorithm>  // ��� std::swap


// ---------------------------------------------------------------------
// ������� ��� ������ ������� �� �����
// ---------------------------------------------------------------------
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// ---------------------------------------------------------------------
// 1. ���������� ��������� (Insertion Sort)
// ����: �������� �� �������, ���� ������� ������� (key) � ��������� ���
// � ��������������� �����, ������� ������ ��������, ������� key.
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
// 2. ���������� �������� (Merge Sort)
// ����: ��������� ������ �� ��� �����, ���������� ��������� ��, 
// � ����� ���������� ��� ��������������� �����.
// ---------------------------------------------------------------------
void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;  // ������ ������ ����������
    int n2 = right - mid;     // ������ ������� ����������

    int* L = new int[n1];
    int* R = new int[n2];

    // �������� �������� � ��������� �������
    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    // ���������� ��������� ������� � ��������
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
// 3. ������� ���������� (Quick Sort)
// ����: ���������� ������� ������� (pivot), ����� �������� ������ pivot
// ������������ �����, � ������� � ������. ����� ���� ���������� �����������
// ���������� �����.
// ---------------------------------------------------------------------
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];  // ������� �������
    int i = low - 1;        // ������ ��� ��������� ������ pivot
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
// 4. ������������� ���������� (Heap Sort)
// ����: ��������� max-���� �� �������, ����� ��������������� ���������
// ���������� ������� (������) � ��������������� ����.
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
    // ���������� ����
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i);
    }
    // ���������� ��������� �� ����
    for (int i = n - 1; i > 0; i--) 
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ---------------------------------------------------------------------
// 5. ���������� ��������� (Bubble Sort)
// ����: �� ������ ������� ��������������� ���������� �������� �������� � 
// ������ �� �������, ���� ��� � �������� �������. ������ ����������� ��
// ������ ����������.
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
// 6. ���������� ��������� (Counting Sort)
// ����: ������������ ��������� ������� ����� (��� �������, ��� ��� ����� ��������������),
// ����� ��������������� ��������������� ������������������ �� ����������� ���������.
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
    return output; 
}

// ---------------------------------------------------------------------
// 7. ���������� ����� (Shell Sort)
// ����: ���������� ���������� ���������, ������� ���������� ��������,
// ��������� �� ����������� ���������� (gap). ���� ��� ���������� ����������� �� 1.
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
// 8. ���������� ������� (Selection Sort)
// ����: �� ������ ���� ������� ����������� ������� �� �����������������
// ����� ������� � ������ ��� ������� � ������ ��������� ���� �����.
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

// ---------------------------------------------------------------------
// ������� main: ������������� ������ ���� ����������. ��� ������ ����������
// ��������� ����� ��������� �������.
// ---------------------------------------------------------------------
int main() {
    int n = 10;
    int original[10] = { 29, 10, 14, 37, 13, 2, 55, 1, 9, 5 };

    int arrInsertion[10], arrMerge[10], arrQuick[10], arrHeap[10],
        arrBubble[10], arrCounting[10], arrShell[10], arrSelection[10];

    for (int i = 0; i < n; i++) {
        arrInsertion[i] = original[i];
        arrMerge[i] = original[i];
        arrQuick[i] = original[i];
        arrHeap[i] = original[i];
        arrBubble[i] = original[i];
        arrCounting[i] = original[i];
        arrShell[i] = original[i];
        arrSelection[i] = original[i];
    }

    std::cout << "Original array: ";
    printArray(original, n);

    insertionSort(arrInsertion, n);
    std::cout << "After Insertion Sort: ";
    printArray(arrInsertion, n);

    mergeSort(arrMerge, 0, n - 1);
    std::cout << "After Merge Sort: ";
    printArray(arrMerge, n);

    quickSort(arrQuick, 0, n - 1);
    std::cout << "After Quick Sort: ";
    printArray(arrQuick, n);

    heapSort(arrHeap, n);
    std::cout << "After Heap Sort: ";
    printArray(arrHeap, n);

    bubbleSort(arrBubble, n);
    std::cout << "After Bubble Sort: ";
    printArray(arrBubble, n);

    int* sortedCounting = countingSort(arrCounting, n);
    std::cout << "After Counting Sort: ";
    printArray(sortedCounting, n);
    delete[] sortedCounting;

    shellSort(arrShell, n);
    std::cout << "After Shell Sort: ";
    printArray(arrShell, n);

    selectionSort(arrSelection, n);
    std::cout << "After Selection Sort: ";
    printArray(arrSelection, n);

    return 0;
}