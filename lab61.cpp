#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// Завдання:
// Створити динамічний масив рядків, заповнити його
// рядками, введеними користувачем, та відсортувати
// рядки за кодом першого символу в порядку спадання.
// Забезпечити коректну обробку символів UTF-8,
// зокрема кирилиці. Вивести відсортований масив
// рядків та звільнити виділену динамічну пам'ять.

// Алфавіт (українська + російська) у порядку алфавіту, мала й велика літери поруч.
// Кирилична літера в UTF-8 займає 2 байти, тому одна пара («аА») = 4 байти.
const char* ALPHABET = "аАбБвВгГґҐдДеЕєЄёЁжЖзЗиИіІїЇйЙкКлЛмМнНоОпПрРсСтТуУфФхХцЦчЧшШщЩъЪыЫьЬэЭюЮяЯ";

// Номер першої літери рядка в алфавіті (-1, якщо її там немає)
int letterRank(const char* s)
{
    if (!s[0])
        return -1;

    char letter[3] = { s[0], s[1], '\0' };
    const char* p = strstr(ALPHABET, letter);

    return p ? (p - ALPHABET) / 4 : -1;
}

// порівняння для сортування за спаданням
bool byRankDesc(const char* a, const char* b)
{
    return letterRank(a) > letterRank(b);
}

int main()
{
    int n;
    cout << "Введіть кількість рядків: ";
    while (!(cin >> n) || n < 1)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Введіть додатне число: ";
    }
    cin.ignore(1000, '\n');

    char str_temp[255];
    char** m_str = new char*[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Уведіть " << i + 1 << "-ий рядок: ";
        cin.getline(str_temp, 255);
        m_str[i] = new char[strlen(str_temp) + 1];
        strcpy(m_str[i], str_temp);
    }

    stable_sort(m_str, m_str + n, byRankDesc);

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
