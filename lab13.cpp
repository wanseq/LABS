#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N = 0;
    float x, y;

    cout << "Введіть для точки М координату по X: ";
    cin >> x;

    cout << "Введіть для точки М координату по Y: ";
    cin >> y;

    if (x >= 0 && y >= 0) {
        if ((x * x + y * y) <= 25) {
            N = 1;
        } else {
            N = 3;
        }
    } 
    else if (x <= 0 && y <= 0) {
        if ((x * x + y * y) <= 25) {
            N = 2;
        } else {
            N = 3;
        }
    } 
    else {
        N = 4;
    }

    cout << "\t РЕЗУЛЬТАТ: \n";
    cout << "Точка М(" << x << ";" << y << ") належить області N = " << N << endl;

    system("pause");
    return 0;
}