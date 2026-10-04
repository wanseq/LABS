#include <iostream>
using namespace std;

int main()
{
    const int m {2}, n {3}, g {2};
    double A[m][n] {}, B[n][g] {}, C[m][g] {};
    int row1 {0}, row2 {0};

    cout << "Введіть матрицю A (" << m << " x " << n << "):" << endl;
    for (int i {0}; i < m; i++)
    {
        for (int j {0}; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Введіть матрицю B (" << n << " x " << g << "):" << endl;
    for (int i {0}; i < n; i++)
    {
        for (int j {0}; j < g; j++)
        {
            cin >> B[i][j];
        }
    }
    
    for (int i {0}; i < m; i++)
    {
        for (int j {0}; j < g; j++)
        {
            for (int k {0}; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Матриця C = A * B:" << endl;
    for (int i {0}; i < m; i++)
    {
        for (int j {0}; j < g; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    do
    {
        cout << "Введіть номери двох рядків B (від 1 до "
             << n << "):" << endl;
        cin >> row1 >> row2;

    } while (row1 < 1 || row1 > n || row2 < 1 || row2 > n);

    row1--;
    row2--;

    // Обмін рядків B
    for (int j {0}; j < g; j++)
    {
        double temp {B[row1][j]};
        B[row1][j] = B[row2][j];
        B[row2][j] = temp;
    }

    cout << "Матриця B після обміну рядків:" << endl;
    for (int i {0}; i < n; i++)
    {
        for (int j {0}; j < g; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}