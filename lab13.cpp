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

    if (x * y <= 0) { 
          N = 4;
    } 
    else {
        N = ((x * x + y * y) <= 25) ? 2 : 3;
    } 
 
    

    cout << "\t РЕЗУЛЬТАТ: \n";
    cout << "Точка М(" << x << ";" << y << ") належить області N = " << N << endl;

    system("pause");
    return 0;
}