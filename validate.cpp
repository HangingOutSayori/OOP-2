#include "validate.h"
// Функция для проверки номера телефона по российским стандартам
bool isValidRussianPhoneNumber(const string& number) {
    // Регулярное выражение для проверки российских номеров телефонов
    regex pattern("(\\+7|8)\\d{10}"); // Формат: +7XXXXXXXXXX или 8XXXXXXXXXX

    // Проверка соответствия номера шаблону
    return regex_match(number, pattern);
}
// Функция для проверки имени
bool isValidName(const string& name) {
    // Регулярное выражение для проверки имени
    regex pattern("[a-zA-Zа-яА-ЯёЁ' -]+"); // Разрешены буквы, пробелы и апостроф

    // Проверка соответствия имени шаблону
    return regex_match(name, pattern);
}
