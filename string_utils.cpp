#include "string_utils.h"  // Підключення заголовку з описами функцій
#include <cstring>         // Для роботи з C-рядками
#include <cctype>          // Для перевірки символів

// Реалізація функції заміни частини C-рядка
void my_replace(char* str, size_t pos, size_t len, const char* repl) {
    size_t i = 0;  // Індекс для заміни символів
    while (repl[i] != '\0' && i < len && pos + i < strlen(str)) {
        str[pos + i] = repl[i];  // Заміна символу
        i++;  // Перехід до наступного символу
    }
}

// Функція підрахунку слів у рядку
int count_words(const std::string& str) {
    int count = 0;        // Лічильник слів
    bool in_word = false; // Прапорець початку слова

    for (char ch : str) {           // Прохід по кожному символу
        if (ch != ' ') {            // Якщо це не пробіл
            if (!in_word) {         // Якщо ми ще не в слові
                in_word = true;     // Початок нового слова
                count++;            // Збільшення лічильника
            }
        } else {
            in_word = false;        // Кінець слова
        }
    }

    return count;  // Повертаємо кількість слів
}

// Перевірка рядка на допустимі символи
bool is_valid(const std::string& str) {
    for (char ch : str) {  // Проходимо по кожному символу
        // Якщо символ не літера, не цифра, не пробіл і не підкреслення
        if (!(isalpha((unsigned char)ch) || isdigit((unsigned char)ch) || ch == ' ' || ch == '_'))
            return false;  // Рядок недопустимий
    }
    return true;  // Усі символи допустимі
}
