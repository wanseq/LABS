#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, z;
    cout << "Введіть значення x, y та z: ";
    cin >> x >> y >> z;

    double min = (x < y) ? x : y;
    double znamennyk = (min * min) - y;

    if (abs(znamennyk) < 1e-9) {
        cout << "Помилка: знаменник дорівнює нулю" << endl;
    } else {
        double x2 = x * x;
        double y2 = y * y;
        double xz = x * z;

        double max = (x2 > y2) ? x2 : y2;
        max = (max > xz) ? max : xz;

        double F = (max + x) / znamennyk;
        cout << "Значення F дорівнює: " << F << endl;
    }
    system("pause");
    return 0;
}