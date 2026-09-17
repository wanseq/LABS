#include <iostream>
using namespace std;

int main() {
    float x, y;

    cout << "Введіть для точки М координату по X: ";
    cin >> x;

    cout << "Введіть для точки М координату по Y: ";
    cin >> y;

    int N = (x * y <= 0) ? 4 : ((x * x + y * y <= 25) ? 2 : 3);

    cout << "\t РЕЗУЛЬТАТ: \n";
    cout << "Точка М(" << x << ";" << y << ") належить області N = " << N << endl;

    system("pause");
    return 0;
}