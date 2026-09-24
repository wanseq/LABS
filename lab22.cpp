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

    for(x=x0;x<=xk;x=x+dx)
    { 
    y = pow(x,4) + cos(2+pow(x,3)-d);
    cout<<"x = "<< x << "  y = " << y << endl;
    }

return 0;
}