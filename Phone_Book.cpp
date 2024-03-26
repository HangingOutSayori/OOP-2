#include "validate.h"
// Структура для представления записи в телефонной книге
struct Contact {
    string fullName;
    string phoneNumber;
};

// Класс для работы с телефонной книгой
class PhoneBook {
private:
    vector<Contact> contacts;
    string filename;

    // Функция для сохранения данных телефонной книги в файл
    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.fullName << "," << contact.phoneNumber << endl;
            }
            file.close();
        }
        else {
            cout << "Невозможно открыть файл для записи." << endl;
        }
    }

    // Функция для загрузки данных телефонной книги из файла
    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                size_t pos = line.find(',');
                if (pos != string::npos) {
                    string name = line.substr(0, pos);
                    string number = line.substr(pos + 1);
                    contacts.push_back({ name, number });
                }
            }
            file.close();
        }
        else {
            cout << "Файл не найден. Создание новой телефонной книги." << endl;
        }
    }
   

public:
    // Конструктор
    PhoneBook(const string& filename) : filename(filename) {
        loadFromFile();
    }

    // Деструктор
    ~PhoneBook() {
        saveToFile();
    }


    // Добавление контакта в телефонную книгу
    void addContact(const string& fullName, const string& phoneNumber) {
        // Проверка наличия контакта
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.fullName == fullName;
            });
        if (it != contacts.end()) {
            cout << "Контакт уже существует." << endl;
            return;
        }

        // Проверка имени
        if (!isValidName(fullName)) {
            cout << "Неверный формат имени. Пожалуйста, используйте только буквы, пробелы и апостроф." << endl;
            return;
        }

        // Проверка номера телефона
        if (!isValidRussianPhoneNumber(phoneNumber)) {
            cout << "Неверный формат номера телефона. Пожалуйста, введите российский номер телефона в формате +7XXXXXXXXXX или 8XXXXXXXXXX." << endl;
            return;
        }

        // Добавление нового контакта
        contacts.push_back({ fullName, phoneNumber });
        cout << "Контакт успешно добавлен." << endl;
    }

    // Удаление контакта из телефонной книги
    void removeContact(const string& fullName) {
        // Поиск контакта
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.fullName == fullName;
            });
        if (it != contacts.end()) {
            contacts.erase(it);
            cout << "Контакт успешно удалён." << endl;
        }
        else {
            cout << "Контакт не найден." << endl;
        }
    }

    // Поиск контакта по ФИО
    void searchContact(const string& fullName) {
        auto it = find_if(contacts.begin(), contacts.end(), [&](const Contact& contact) {
            return contact.fullName == fullName;
            });
        if (it != contacts.end()) {
            cout << "Контакт найден: " << it->fullName << ", " << it->phoneNumber << endl;
        }
        else {
            cout << "Контакт не найден." << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    // Создание телефонной книги
    PhoneBook phoneBook("phonebook.txt");

    // Меню для взаимодействия с пользователем
    while (true) {
        cout << "Меню:\n";
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Поиск контакта\n";
        cout << "4. Выйти\n";
        cout << "Введите ваш выбор: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string fullName, phoneNumber;
            cout << "Введите полное имя: ";
            cin.ignore(); // Очистка буфера перед чтением строки
            getline(cin, fullName);
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            cin.ignore(); // Очистка буфера после чтения номера телефона
            phoneBook.addContact(fullName, phoneNumber);
            break;
        }
        case 2: {
            string fullName;
            cout << "Введите полное имя для удаления: ";
            cin.ignore(); // Очистка буфера перед чтением строки
            getline(cin, fullName);
            phoneBook.removeContact(fullName);
            break;
        }
        case 3: {
            string fullName;
            cout << "Введите полное имя для поиска: ";
            cin.ignore(); // Очистка буфера перед чтением строки
            getline(cin, fullName);
            phoneBook.searchContact(fullName);
            break;
        }
        case 4: {
            cout << "Завершение программы." << endl;
            return 0;
        }
        default:
            cout << "Неверный выбор. Пожалуйста, введите снова." << endl;
        }
    }

    return 0;
}
