#include "file_utils.h"     // Заголовок з описом
#include "string_utils.h"   // Підключення функцій роботи з рядками
#include <fstream>          // Для роботи з файлами
#include <iostream>         // Для повідомлень про помилки

using namespace std;  // Стандартний простір імен

// Створення sample.txt з 10 рядками
void create_sample_file() {
    ofstream file("sample.txt");  // Відкриття файлу для запису
    if (!file) {  // Якщо помилка відкриття
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }
    // Запис 10 рядків у файл
    file << "привіт світ" << endl;
    file << "я люблю програмування" << endl;
    file << "це тестовий рядок" << endl;
    file << "штучний інтелект змінює світ" << endl;
    file << "це п’ята стрічка" << endl;
    file << "ми вивчаємо C++" << endl;
    file << "ХАІ найкращий" << endl;
    file << "лабораторна робота" << endl;
    file << "треба рахувати слова" << endl;
    file << "остання стрічка" << endl;
    file.close();  // Закриття файлу
}

// Обробка sample.txt: перевірка і підрахунок слів
void process_file() {
    ifstream file("sample.txt");  // Відкриття для читання
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    ofstream out("output.txt");  // Вихідний файл
    if (!out) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    string line;  // Рядок з файлу
    while (getline(file, line)) {  // Зчитування по рядках
        if (is_valid(line)) {  // Якщо рядок коректний
            int count = count_words(line);  // Підрахунок слів
            out << "Рядок: \"" << line << "\" має " << count << " слів." << endl;
        } else {
            out << "Рядок \"" << line << "\" недопустимий." << endl;
        }
    }

    file.close();  // Закриття файлів
    out.close();
}
