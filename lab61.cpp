#include <iostream>
#include <cstring>
using namespace std;

// Повертає код першого символа рядка (враховує UTF-8, кирилиця = 2 байти)
unsigned int firstCodePoint(const char* s)
{
    unsigned char c = s[0];
    if (c < 0x80) return c;                       // ASCII (1 байт)
    if ((c >> 5) == 0x6 && s[1])                  // 2 байти (кирилиця)
        return ((c & 0x1F) << 6) | (s[1] & 0x3F);
    if ((c >> 4) == 0xE && s[1] && s[2])          // 3 байти
        return ((c & 0x0F) << 12) | ((s[1] & 0x3F) << 6) | (s[2] & 0x3F);
    if ((c >> 3) == 0x1E && s[1] && s[2] && s[3]) // 4 байти
        return ((c & 0x07) << 18) | ((s[1] & 0x3F) << 12) |
               ((s[2] & 0x3F) << 6) | (s[3] & 0x3F);
    return c;
}

int main()
{
    int n;
    cout << "Введіть кількість рядків: ";
    cin >> n;
    cin.ignore();

    char* str_temp = new char[255]; 
    char** m_str = new char*[n];    
    if (!m_str)
    {
        cerr << "Помилка під час розподілу пам'яті";
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Уведіть " << i + 1 << "-ий рядок: ";
        cin.getline(str_temp, 255);
        m_str[i] = new char[strlen(str_temp) + 1];
        if (!m_str[i])
        {
            cerr << "Помилка під час розподілу пам'яті";
            return 1;
        }
        strcpy(m_str[i], str_temp);
    }
    delete[] str_temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (firstCodePoint(m_str[j]) < firstCodePoint(m_str[j + 1]))
            {
                char* tmp = m_str[j];
                m_str[j] = m_str[j + 1];
                m_str[j + 1] = tmp;
            }

    cout << "\nВідсортований масив рядків:\n";
    for (int i = 0; i < n; i++)
    {
        cout << m_str[i] << endl;
        delete[] m_str[i];
    }
    delete[] m_str;

    cout << "\nНатисніть Enter для завершення";
    cin.get();
    return 0;
}