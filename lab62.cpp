#include <iostream>
using namespace std;

int strLength(const char* s)
{
    if (*s == '\0')                // базовий випадок
        return 0;
   
        int add = ((*s & 0xC0) != 0x80) ? 1 : 0; // для мака
    return add + strLength(s + 1); 
}

int main()
{
    char str[255];
    cout << "Введіть рядок: ";
    cin.getline(str, 255);

    cout << "Довжина рядка: " << strLength(str) << endl;

    cout << "\nНатисніть Enter для завершення";
    cin.get();
    return 0;
}