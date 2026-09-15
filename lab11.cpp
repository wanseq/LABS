#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 3.07, y = -1.04, z = 0.87;

    double p = (pow(sin(x + z), 2) + cos(x)) / (x + pow(abs(y), 4.0/3.0) * exp(abs(x - y)));

    cout << "Значення виразу дорівнює: " << p << endl;

    system("pause");
    return 0;
}