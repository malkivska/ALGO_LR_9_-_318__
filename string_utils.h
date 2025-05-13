#pragma once  // Захист від багаторазового включення файлу

#include <string>   // Для використання типу std::string

// Власна функція для заміни частини C-рядка
void my_replace(char* str, size_t pos, size_t len, const char* repl);

// Підрахунок кількості слів у рядку
int count_words(const std::string& str);

// Перевірка, чи рядок містить лише допустимі символи
bool is_valid(const std::string& str);
