#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double z {0.5236};
    const double eps {0.00001};
    double u, S;

    int Pr, n, k;
    int a;

    do
    {
    cout << "Оберіть дію:" << endl;
    cout << "0 - вийти з програми" << endl;
    cout << "1 - знайти n-й елемент ряду" << endl;
    cout << "2 - знайти суму n перших елементів" << endl;
    cout << "3 - знайти суму ряду з точністю eps" << endl;

    cin >> Pr;

        if (Pr == 0)
        {
            break;
        }

        if (Pr >= 1 && Pr <= 3)
        {
            switch (Pr)
            {
                case 1:
                {
                cout << "Введіть номер елемента n: ";
                cin >> n;

                u = z;

                    for (k = 0; k < n; k++)
                    {
                        u *= (-z * z) /
                            ((2 * k + 2) * (2 * k + 3));
                    }

                    cout << "n-й елемент ряду = " << u << endl;

                    break;
                }

                case 2:
                {
                cout << "Введіть кількість елементів n: ";
                cin >> n;

                u = z;
                S = 0;

                    for (k = 0; k < n; k++)
                    {
                        S = S + u;

                        u = u * (-z * z) /
                            ((2 * k + 2) * (2 * k + 3));
                    }

                    cout << "Сума перших " << n
                         << " елементів = " << S << endl;

                    break;
                }

                case 3:
                {
                u = z;
                S = 0;
                k = 0;

                    while (fabs(u) >= eps)
                    {
                        S = S + u;

                        u = u * (-z * z) /
                            ((2 * k + 2) * (2 * k + 3));

                        k++;
                    }

                    cout << "Сума ряду = " << S << endl;
                    cout << "Перевірка sin(z) = " << sin(z) << endl;

                    break;
                }
            }
        }
        else
        {
            cout << "Неправильно введене значення Pr." << endl;
        }

        cout << endl;
        cout << "Продовжити роботу?" << endl;
        cout << "6 - так, 7 - ні: ";
        cin >> a;

    } while (a != 7);

    return 0;
}