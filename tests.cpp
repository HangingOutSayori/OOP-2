#include"tests.h"

void testIsValidRussianPhoneNumber() {
    // Проверка корректных номеров телефонов
    assert(isValidRussianPhoneNumber("+79261234567"));
    assert(isValidRussianPhoneNumber("89261234567"));
    assert(isValidRussianPhoneNumber("+79991234567"));
    assert(isValidRussianPhoneNumber("89991234567"));

    // Проверка некорректных номеров телефонов
    assert(!isValidRussianPhoneNumber("+7926123456"));    // Неправильная длина
    assert(!isValidRussianPhoneNumber("8926123456"));     // Неправильная длина
    assert(!isValidRussianPhoneNumber("+792612345678"));  // Неправильная длина
    assert(!isValidRussianPhoneNumber("892612345678"));   // Неправильная длина
    assert(!isValidRussianPhoneNumber("+69261234567"));   // Неправильный код страны
    assert(!isValidRussianPhoneNumber("99261234567"));    // Неправильный код страны
    assert(!isValidRussianPhoneNumber("+7926A234567"));   // Недопустимый символ
    assert(!isValidRussianPhoneNumber("8-926-123-45-67"));// Недопустимый символ
    assert(!isValidRussianPhoneNumber("+1-123-456-7890")); // Неправильный код страны

    cout << "tests ok" << endl;
}

void testIsValidName() {
    // Проверка корректных имен
    assert(isValidName("John Smith"));
    assert(isValidName("Иван Петров"));
    assert(isValidName("Mary O'Brien"));
    assert(isValidName("Алексей Дорошенко-Смирнов"));
    assert(isValidName("Анна-Мария"));

    // Проверка некорректных имен
    assert(!isValidName("12345"));          // Недопустимые символы
    assert(!isValidName("John123"));        // Недопустимые символы
    assert(!isValidName("John$Smith"));     // Недопустимые символы
    assert(!isValidName(""));               // Пустая строка
    assert(!isValidName("John_Smith"));     // Недопустимые символы
    assert(!isValidName("Иван123"));        // Недопустимые символы
    assert(!isValidName(""));               // Пустая строка

    cout << "tests ok" << endl;
}

int main() {
    testIsValidName();
    testIsValidRussianPhoneNumber();
    return 0;
}
