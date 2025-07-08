#include "functions.h"


int32_t CountFractionalDigits(double num) 
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(15) << num;
    std::string num_str = oss.str();

    size_t pos = num_str.find('.');
    if (pos == std::string::npos) return 0;

    size_t last_non_zero = num_str.find_last_not_of('0');
    if (last_non_zero == pos) return 0;
    if (last_non_zero != std::string::npos) 
    {
        num_str = num_str.substr(0, last_non_zero + 1);
    }
    return num_str.size() - pos - 1;
}

void Swap_double(double* a, double* b) 
{
    double t = *a;
    *a = *b;
    *b = t;
}

int32_t Partition(double arr[], int32_t low, int32_t high, bool ascending) 
{
    double pivot = arr[high];
    int32_t i = low - 1;

    for (int32_t j = low; j <= high - 1; j++) {
        if ((ascending && arr[j] < pivot) || (!ascending && arr[j] > pivot)) 
        {
            i++;
            Swap_double(&arr[i], &arr[j]);
        }
    }
    Swap_double(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort(double arr[], int32_t low, int32_t high, bool ascending) 
{
    if (low < high) 
    {
        int32_t pi = Partition(arr, low, high, ascending);
        QuickSort(arr, low, pi - 1, ascending);
        QuickSort(arr, pi + 1, high, ascending);
    }
}

void InsertionSort(double arr[], int32_t n, bool ascending) 
{
    for (int32_t i{ 1 }; i < n; i++) 
    {
        double key = arr[i];
        int32_t j{ i - 1 };

        while (j >= 0 && ((ascending && arr[j] > key) || (!ascending && arr[j] < key))) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void BubbleSort(double arr[], int32_t n, bool ascending) 
{
    bool swapped;
    for (int32_t i{}; i < n - 1; i++) 
    {
        swapped = false;
        for (int32_t j{}; j < n - i - 1; j++) 
        {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) 
            {
                Swap_double(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void QsortByFractionalDigits(double arr[], int32_t n) 
{
    bool swapped;
    for (int32_t i{}; i < n - 1; i++) 
    {
        swapped = false;
        for (int32_t j{}; j < n - i - 1; j++) 
        {
            if (CountFractionalDigits(arr[j]) < CountFractionalDigits(arr[j + 1])) 
            {
                Swap_double(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void SelectionSort(double arr[], int32_t n, bool ascending) 
{
    for (int32_t i{}; i < n - 1; i++) 
    {
        int32_t ext{ i };
        for (int32_t j{ i + 1 }; j < n; j++) 
        {
            bool condition = (ascending) ?
                (arr[j] < arr[ext]) :
                (arr[j] > arr[ext]);

            if (condition) 
            {
                ext = j;
            }
        }
        Swap_double(&arr[i], &arr[ext]);
    }
}


void Merge(double arr[], int32_t left, int32_t mid, int32_t right, bool ascending) 
{
    int32_t n1 = mid - left + 1;
    int32_t n2 = right - mid;

    double* L = new double[n1];
    double* R = new double[n2];

    for (int32_t i{}; i < n1; i++)
        L[i] = arr[left + i];
    for (int32_t j{}; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int32_t i{}, j{}, k{ left };

    while (i < n1 && j < n2) 
    {
        bool condition = (ascending) ?
            (L[i] <= R[j]) :
            (L[i] >= R[j]);

        if (condition) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void MergeSort(double arr[], int32_t left, int32_t right, bool ascending) 
{
    if (left < right) 
    {
        int32_t mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, ascending);
        MergeSort(arr, mid + 1, right, ascending);
        Merge(arr, left, mid, right, ascending);
    }
}

double CalculateAverage(const Student& s) 
{
    double sum = 0;
    for (int32_t i{}; i < 5; i++) 
    {
        sum += s.grades[i];
    }
    return sum / 5.0;
}

void Swap_student(Student* a, Student* b) 
{
    Student t = *a;
    *a = *b;
    *b = t;
}

int32_t Partition(Student arr[], int32_t low, int32_t high, bool ascending) 
{
    double pivot = CalculateAverage(arr[high]);
    int32_t i = low - 1;

    for (int32_t j = low; j <= high - 1; j++) 
    {
        double avg = CalculateAverage(arr[j]);
        if ((ascending && avg < pivot) || (!ascending && avg > pivot)) 
        {
            i++;
            Swap_student(&arr[i], &arr[j]);
        }
    }
    Swap_student(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort(Student arr[], int32_t low, int32_t high, bool ascending) 
{
    if (low < high) 
    {
        int32_t pi = Partition(arr, low, high, ascending);
        QuickSort(arr, low, pi - 1, ascending);
        QuickSort(arr, pi + 1, high, ascending);
    }
}


const int32_t MODE_EXIT{};
const int32_t MODE_NUMBERS{ 1 };
const int32_t MODE_STUDENTS{ 2 };
const int32_t INPUT_CONSOLE{};
const int32_t INPUT_FILE{ 1 };
const int32_t OUTPUT_CONSOLE{};
const int32_t OUTPUT_FILE{ 1 };
const int32_t SORT_QUICK{};
const int32_t SORT_INSERTION{ 1 };
const int32_t SORT_SELECTION{ 2 };
const int32_t SORT_MERGE{ 3 };
const int32_t SORT_BUBBLE{ 4 };
const int32_t SORT_QFRAC{ 5 };
const int32_t ORDER_ASC{};
const int32_t ORDER_DESC{ 1 };

double* InputNumbers(int32_t& n, int32_t source) 
{
    if (source == INPUT_CONSOLE) 
    {
        std::cout << "Enter number of elements: ";
        std::cin >> n;
        double* arr = new double[n];
        for (int32_t i{}; i < n; i++) 
        {
            std::cout << "Element " << i + 1 << ": ";
            std::cin >> arr[i];
        }
        return arr;
    }
    else 
    {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        std::ifstream file(filename);

        if (!file) 
        {
            std::cerr << "Error opening file!\n";
            n = 0;
            return nullptr;
        }

        double value;
        int32_t count{};
        while (file >> value) count++;

        file.clear();
        file.seekg(0);

        n = count;
        double* arr = new double[n];
        for (int32_t i{}; i < n; i++) 
        {
            file >> arr[i];
        }
        return arr;
    }
}

Student* InputStudents(int32_t& n, int32_t source) 
{
    if (source == INPUT_CONSOLE) 
    {
        std::cout << "Enter number of students: ";
        std::cin >> n;
        Student* arr = new Student[n];
        for (int32_t i{}; i < n; i++) 
        {
            std::cout << "Student " << i + 1 << ":\n";
            std::cout << "  Name: ";    std::cin >> arr[i].name;
            std::cout << "  Surname: "; std::cin >> arr[i].surname;
            std::cout << "  Course: ";  std::cin >> arr[i].course;
            std::cout << "  Group: ";   std::cin >> arr[i].group;
            std::cout << "  Grades (5): ";
            for (int32_t j{}; j < 5; j++) 
            {
                std::cin >> arr[i].grades[j];
            }
        }
        return arr;
    }
    else 
    {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        std::ifstream file(filename);

        if (!file) 
        {
            std::cerr << "Error opening file!\n";
            n = 0;
            return nullptr;
        }

        Student s;
        int32_t count{};
        while (file >> s.name >> s.surname >> s.course >> s.group) 
        {
            for (int32_t i{}; i < 5; i++) 
            {
                file >> s.grades[i];
            }
            count++;
        }

        file.clear();
        file.seekg(0);

        n = count;
        Student* arr = new Student[n];
        for (int32_t i{}; i < n; i++)
        {
            file >> arr[i].name >> arr[i].surname >> arr[i].course >> arr[i].group;
            for (int32_t j{}; j < 5; j++) 
            {
                file >> arr[i].grades[j];
            }
        }
        return arr;
    }
}

void OutputNumbers(double arr[], int32_t n, int32_t dest) 
{
    if (dest == OUTPUT_CONSOLE) 
    {
        for (int32_t i{}; i < n; i++) 
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
    else 
    {
        std::string filename;
        std::cout << "Enter output filename: ";
        std::cin >> filename;
        std::ofstream file(filename);
        for (int32_t i{}; i < n; i++) 
        {
            file << arr[i] << "\n";
        }
    }
}

void OutputStudents(Student arr[], int32_t n, int32_t dest) 
{
    if (dest == OUTPUT_CONSOLE) 
    {
        for (int32_t i{}; i < n; i++) 
        {
            std::cout << arr[i].name << " " << arr[i].surname << " "
                << arr[i].course << " " << arr[i].group << " [";
            for (int32_t j{}; j < 5; j++) 
            {
                std::cout << arr[i].grades[j];
                if (j < 4) std::cout << " ";
            }
            std::cout << "]\n";
        }
    }
    else 
    {
        std::string filename;
        std::cout << "Enter output filename: ";
        std::cin >> filename;
        std::ofstream file(filename);
        for (int32_t i{}; i < n; i++) 
        {
            file << arr[i].name << " " << arr[i].surname << " "
                << arr[i].course << " " << arr[i].group;
            for (int32_t j{}; j < 5; j++) 
            {
                file << " " << arr[i].grades[j];
            }
            file << "\n";
        }
    }
}

void SortNumbers(double* arr, int32_t n, int32_t method, int32_t order) 
{
    bool ascending = (order == ORDER_ASC);

    switch (method) 
    {
    case SORT_QUICK:
        QuickSort(arr, 0, n - 1, ascending);
        break;
    case SORT_INSERTION:
        InsertionSort(arr, n, ascending);
        break;
    case SORT_SELECTION:
        SelectionSort(arr, n, ascending);
        break;
    case SORT_MERGE:
        MergeSort(arr, 0, n - 1, ascending);
        break;
    case SORT_BUBBLE:
        BubbleSort(arr, n, ascending);
        break;
    case SORT_QFRAC:
        QsortByFractionalDigits(arr, n);
        break;
    default:
        std::cerr << "Invalid sort method\n";
    }
}


void SortStudents(Student* students, int32_t n, int32_t order) 
{
    bool ascending{ order == ORDER_ASC };
    QuickSort(students, 0, n - 1, ascending);
}

void ProcessNumbers() 
{
    int32_t input{}, output{};

    std::cout << "\nInput source (0-console, 1-file): ";
    std::cin >> input;

    std::cout << "Output destination (0-console, 1-file): ";
    std::cin >> output;

    int32_t n{};
    double* numbers = InputNumbers(n, input);
    if (!numbers || n == 0) return;

    int32_t order{};
    std::cout << "\nSort order (0-asc, 1-desc): ";
    std::cin >> order;

    int32_t method{};
    std::cout << "Sort methods:\n"
        << "0. Quick sort\n"
        << "1. Insertion sort\n"
        << "2. Selection sort\n"
        << "3. Merge sort\n"
        << "4. Bubble sort\n"
        << "5. Qsort by fractional digits\n"
        << "Choice: ";
    std::cin >> method;

    SortNumbers(numbers, n, method, order);
    OutputNumbers(numbers, n, output);
    delete[] numbers;
}

void ProcessStudents() 
{
    int input, output;

    std::cout << "\nInput source (0-console, 1-file): ";
    std::cin >> input;

    std::cout << "Output destination (0-console, 1-file): ";
    std::cin >> output;

    int32_t n{};
    Student* students = InputStudents(n, input);
    if (!students || n == 0) return;

    int32_t order{};
    std::cout << "\nSort order (0-asc, 1-desc): ";
    std::cin >> order;

    SortStudents(students, n, order);
    OutputStudents(students, n, output);
    delete[] students;
}

void Task() 
{
    while (true) 
    {
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Work with numbers\n";
        std::cout << "2. Work with students\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        int32_t mode;
        std::cin >> mode;
        std::cin.ignore();

        if (mode == MODE_EXIT) break;

        if (mode == MODE_NUMBERS) 
        {
            ProcessNumbers();
        }
        else if (mode == MODE_STUDENTS) 
        {
            ProcessStudents();
        }
    }
}