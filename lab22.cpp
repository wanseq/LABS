#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double x{},y{};
    double x0{4.6};
    double xk{5.8};
    double dx{0.2};
    double d{1.3};
    int Pr;
    int a;
    double x01, xk1, dx1, d1;

    do
    {
        cout << "Оберіть дію:" << endl;
        cout << "0 - вийти з програми" << endl;
        cout << "1 - знайти функцію" << endl;
        cout << "2 - ввести значення самому" << endl;

        cin >> Pr;

        switch (Pr)
        {
            case 0:
            {
                return 0;
            }

            case 1:
            {
   

        for(x=x0;x<=xk;x=x+dx)
        { 
        y = pow(x, 4) + cos(2 + pow(x, 3) - d);
        cout<<"x = "<< x << "  y = " << y << endl;
        }

                break;
            }

            case 2:
            {
                cout << "Введіть x0, xk, dx, d: " << endl;
                cin >> x01;
                cin >> xk1;
                cin >> dx1;
                cin >> d1;
                for(x=x01;x<=xk1;x=x+dx1)
        { 
        y = pow(x, 4) + cos(2 + pow(x, 3) - d);
        cout<<"x = "<< x << "  y = " << y << endl;
        }
                
                break;
            }

            default:
            {
                cout << "Неправильно введене значення Pr." << endl;
                break;
            }
        }

        cout << endl;
        cout << "Продовжити роботу?" << endl;
        cout << "6 - так, 7 - ні: ";
        cin >> a;

    } while (a != 7);

    return 0;
}