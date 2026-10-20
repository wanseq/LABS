#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
using namespace std;

int inputSize()
{
    int n;
    do
    {
        cin >> n;

        if (n <= 0)
            cout << "Введіть додатне число: ";
    }
    while (n <= 0);

    return n;
}

int inputMode()
{
    int mode;

    do
    {
        cout << "1 - ввести вручну\n";
        cout << "2 - випадкові числа\n";
        cin >> mode;
    }
    while (mode != 1 && mode != 2);

    return mode;
}

void fillArray(int* a, int n, int mode)
{
    for (int i = 0; i < n; i++)
    {
        if (mode == 1)
        {
            cout << "[" << i << "] = ";
            cin >> a[i];
        }
        else
        {
            a[i] = rand() % 21 - 10;
        }
    }
}

void printArray(int* a, int n)
{
    if (n == 0)
    {
        cout << "Масив порожній\n";
        return;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

bool contains(int* a, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            return true;
    }

    return false;
}

int** createMatrix(int m, int n, int mode)
{
    int** a = new int*[m];

    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            if (mode == 1)
            {
                cout << "[" << i << "][" << j << "] = ";
                cin >> a[i][j];
            }
            else
            {
                a[i][j] = rand() % 21 - 10;
            }
        }
    }

    return a;
}

void printMatrix(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";

        cout << endl;
    }
}

void deleteMatrix(int** a, int m)
{
    for (int i = 0; i < m; i++)
        delete[] a[i];

    delete[] a;
}

// Завдання 1
void task1()
{
    cout << "Кількість елементів: ";
    int n = inputSize();
    int mode = inputMode();

    int* a = new int[n];
    fillArray(a, n, mode);

    cout << "Початковий масив: ";
    printArray(a, n);

    int count = 0;

    for (int i = 1; i < n; i += 2)
    {
        if (a[i] < 0)
            count++;
    }

    cout << "Від'ємних елементів з непарним індексом: ";
    cout << count << endl;

    int size = n / 3;
    int* b = new int[size];
    int k = 0;

    for (int i = 2; i < n; i += 3)
    {
        b[k] = a[i];
        k++;
    }

    cout << "Кожний третій елемент: ";
    printArray(b, size);

    delete[] a;
    delete[] b;
}

// завдання 2 та 3
void task2_3(int task)
{
    cout << "Кількість елементів A: ";
    int n = inputSize();

    cout << "Кількість елементів B: ";
    int m = inputSize();

    int mode = inputMode();

    int* a = new int[n]; // створення масивів
    int* b = new int[m];

    cout << "Заповнення A:\n"; // заповнення масивів
    fillArray(a, n, mode);

    cout << "Заповнення B:\n";
    fillArray(b, m, mode);

    cout << "A: ";  // виведення масивів
    printArray(a, n);

    cout << "B: ";
    printArray(b, m);

    int* c = new int[m];
    int k = 0;

    for (int i = 0; i < m; i++)
    {
        bool found = contains(a, n, b[i]);

        if ((task == 2 && !found) ||
            (task == 3 && found))
        {
            c[k] = b[i];
            k++;
        }
    }

    cout << "Результат: ";
    printArray(c, k);

    delete[] a;
    delete[] b;
    delete[] c;
}

int* rowSums(int** a, int m, int n)
{
    int* result = new int[m];

    for (int i = 0; i < m; i++)
    {
        int minValue = a[i][0];
        int maxValue = a[i][0];

        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minValue)
                minValue = a[i][j];

            if (a[i][j] > maxValue)
                maxValue = a[i][j];
        }

        result[i] = minValue + maxValue;
    }

    return result;
}

int* diagonal(int** a, int m, int n, int& size) // функція для отримання головної діагоналі
{
    size = (m < n) ? m : n;
    int* result = new int[size];

    for (int i = 0; i < size; i++)
        result[i] = a[i][i];

    return result;
}

void task4_5(int task)
{
    cout << "Кількість рядків: ";
    int m = inputSize();

    cout << "Кількість стовпців: ";
    int n = inputSize();

    int mode = inputMode();
    int** a = createMatrix(m, n, mode);

    cout << "Матриця:\n";
    printMatrix(a, m, n);

    int size;
    int* result;

    if (task == 4)
    {
        size = m;
        result = rowSums(a, m, n);
        cout << "Суми мінімуму та максимуму кожного рядка: ";
    }
    else
    {
        result = diagonal(a, m, n, size);
        cout << "Елементи головної діагоналі: ";
    }

    printArray(result, size);

    delete[] result;
    deleteMatrix(a, m);
}

int main()
{
    srand(time(0));
    int choice;

    do
    {
        cout << "\nОберіть завдання:\n";
        cout << "1 - від'ємні елементи та кожний третій\n";
        cout << "2 - елементи B, яких немає в A\n";
        cout << "3 - спільні елементи A та B\n";
        cout << "4 - суми мінімуму та максимуму рядків\n";
        cout << "5 - головна діагональ\n";
        cout << "100 - вихід\n";

        cin >> choice;

        switch (choice)
        {
            case 1:
                task1();
                break;

            case 2:
            case 3:
                task2_3(choice);
                break;

            case 4:
            case 5:
                task4_5(choice);
                break;

            case 100:
                break;

            default:
                cout << "Неправильний вибір\n";
        }
    }
    while (choice != 100);

    return 0;
}