#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols, rows2, cols2;

    cout << "Введите количество строк первой матрицы: ";
    cin >> rows;

    cout << "Введите количество столбцов первой матрицы: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "\nВведите элементы первой матрицы:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Введите количество строк второй матрицы: ";
    cin >> rows2;

    cout << "Введите количество столбцов второй матрицы: ";
    cin >> cols2;

    vector<vector<int>> matrix2(rows2, vector<int>(cols2));

    cout << "\nВведите элементы второй матрицы:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix2[i][j];
        }
    }

vector<vector<int>> matrixMult(rows, vector<int>(cols2, 0));


for (int i = 0; i < rows; i++) {        
    for (int j = 0; j < cols2; j++) {     
        matrixMult[i][j] = 0;             
        
        for (int k = 0; k < cols; k++) { 
            matrixMult[i][j] += matrix[i][k] * matrix2[k][j];
        }
    }
}
    cout << "\nВаша первая матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n"; 
    }

    cout << "\nВаша вторая матрица:\n";
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << "\n"; 
    }

    cout << "\nМножество матриц:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrixMult[i][j] << " ";
        }
        cout << "\n"; 
    }
    

    return 0;
}