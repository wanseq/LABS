#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a;
    double x, y, z;
    cout << "Введіть значення x та z: ";
    cin >> x >> z;
    do{
    cout << "Введіть значення a (ціле, в межах 1-40): ";
    cin >> a;
    if (a < 1 || a > 40) {
        cout << "Помилка: введіть число a ше раз" << endl;
    }
    else {
        if (a >= 1 && a <= 5) {
            y = sin(x * y + exp(pow(x, 2))) - log(x) + 3.0 / z;
        }
        else if (a >= 6 && a < 15) {
            y = pow(sin(x), 2) * (pow(x, 2) - 1) + sqrt(pow(cos(pow(x, 2) + 2.5), 2)) + exp(4 * cos(z));
        }
        else {
            y = ((x + 10.0) / (z + 3.0)) * ((12.0 + pow(x, 2)) / 3.0) - pow(z, z + 2.0) + sqrt(cos(pow(x, 2)));
        }
        cout << "Значення y дорівнює: " << y << endl;
        break;
    }

    } while(45);
    system("pause");
    return 0;
}