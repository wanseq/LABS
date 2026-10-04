#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int N {10};
    double a[N] {};
    int Pr {0};

    srand(time(nullptr));

    do
    {
        cout << "\n0 - вийти з програми" << endl;
        cout << "1 - ввести елементи з клавіатури" << endl;
        cout << "2 - заповнити випадковими числами" << endl;
        cin >> Pr;

        switch (Pr)
        {
            case 0:

                break;

            case 1:

                cout << "Введіть " << N << " елементів:" << endl;
                for (int i {0}; i < N; i++)
                    cin >> a[i];
                break;

            case 2:

                for (int i {0}; i < N; i++)
                    a[i] = rand() % 21 - 10;
                break;

            default:

                cout << "Неправильний вибір!" << endl;
                continue;
        }

        if (Pr == 0)
            break;
            cout << "\n------------------------------------------------------------" << endl;
             cout << "\nВведенний масив: ";
        for (int i {0}; i < N; i++)
        {
        cout << a[i] << " ";
        }
        cout << endl;

        int first {-1}, last {-1};

        for (int i {0}; i < N; i++)
        {
            if (a[i] > 0)
            {
                if (first == -1)
                    first = i;

                last = i;
            }
        }

        if (first != -1)
        {
            double temp {a[first]};
            a[first] = a[last];
            a[last] = temp;
        }
        else
            cout << "Додатних елементів немає." << endl;

        cout << "Результат:       ";
        for (int i {0}; i < N; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "\n------------------------------------------------------------" << endl;

    } while (Pr != 0);

    return 0;
}