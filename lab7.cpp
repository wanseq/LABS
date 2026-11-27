#include <iostream>
#include <cstring>   // strcmp
using namespace std;

const int N = 20; // кількість книг

// Одна книга
struct Book {
    char author[30];   // прізвище
    char title[50];    // назва
    int  year;         // рік видання

    void print() const {
        cout << author << " | " << title << " | " << year << "\n"; // метод, який не дає змінити стан об'єкта
    }
};

// уся Бібліотека
struct Library {
    Book* books;   // вказівник на динамічний масив книг
    int   count;   // кількість книг

    // назви книг автора за 2019-2023
    void findAuthor(const char* author) const {
        bool found = false;
        for (int i = 0; i < count; ++i) { // i - індекс книги
            if (strcmp(books[i].author, author) == 0 &&
                books[i].year >= 2019 && books[i].year <= 2023) {
                cout << "  " << books[i].title << " (" << books[i].year << ")\n";
                found = true;
            }
        }
        if (!found) cout << "  Таких книг не знайдено\n";
    }

    // сортування по першій букві прізвища автора
    void sortFirstLetter() {
        for (int i = 0; i < count - 1; ++i)
            for (int j = 0; j < count - 1 - i; ++j)
                if (books[j].author[0] > books[j + 1].author[0]) {
                    Book tmp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = tmp;
                }
    }

    // заміна року на 2023
    bool zmina(const char* title) {
        for (int i = 0; i < count; ++i)
            if (strcmp(books[i].title, title) == 0) {
                books[i].year = 2023;
                return true;
            }
        return false;
    }

    void print() const {
        for (int i = 0; i < count; ++i) books[i].print();
    }
};

int main() {
    Library lib;
    lib.count = N;

    // виділяємо пам'ять у купі (heap) під N книг і одразу заповнюємо
    lib.books = new Book[lib.count] {
        {"Shevchenko", "Kobzar", 2019},      {"Franko", "Zakhar Berkut", 2021},
        {"Kotsiubynsky", "Intermezzo", 2018},{"Ukrainka", "Lisova pisnya", 2022},
        {"Shevchenko", "Haidamaky", 2023},   {"Stroustrup", "C++ Programming", 2020},
        {"Franko", "Moses", 2017},           {"Zhadan", "Voroshylovgrad", 2019},
        {"Andrukhovych", "Recreations", 2016},{"Kotsiubynsky", "Fata Morgana", 2021},
        {"Ukrainka", "Kassandra", 2015},     {"Zabuzhko", "Fieldwork", 2022},
        {"Shevchenko", "Kateryna", 2014},    {"Stroustrup", "Tour of C++", 2023},
        {"Franko", "Boryslav", 2020},        {"Zhadan", "Mesopotamia", 2018},
        {"Andrukhovych", "Moscoviada", 2021},{"Zabuzhko", "Museum", 2023},
        {"Kotsiubynsky", "Shadows", 2013},   {"Ukrainka", "Contra spem", 2019}
    };

    char author[30], title[50]; // масиви для введення прізвища автора та назви книги

    cout << "Введіть прізвище автора: ";
    cin.getline(author, 30); // бере строчку прізвища
    cout << "Книги автора за 2019-2023:\n";
    lib.findAuthor(author);

    lib.sortFirstLetter();
    cout << "\nПісля сортування прізвищ за першою буквою:\n";
    lib.print();

    cout << "\nПеревидана книга: ";
    cin.getline(title, 50); // бере строчку назви книги
    if (lib.zmina(title)) cout << "Рік змінено на 2023.\n";
    else cout << "Книга не знайдена.\n";

    cout << "\nФінальний список:\n";
    lib.print();

    delete[] lib.books; // звільняємо пам'ять
    lib.books = nullptr;
    return 0;
}
