#include <iostream>        // Для введення/виведення
#include <fstream>         // Для запису результатів
#include <string>          // Для std::string
#include <cstring>         // Для роботи з C-строками
#include "string_utils.h"  // Підключення логіки роботи з рядками
#include "file_utils.h"    // Підключення логіки роботи з файлами

using namespace std;  // Стандартний простір імен

int main() {
    create_sample_file();  // Автоматичне створення sample.txt

    int choice;  // Змінна вибору
    do {
        // Меню користувача
        cout << "\n1. Замінити частину рядка (my_replace і string::replace)\n";
        cout << "2. Порахувати кількість слів у введеному рядку\n";
        cout << "3. Обробити файл (sample.txt) і зберегти у output.txt\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore();  // Очищення буфера

        switch (choice) {
            case 1: {
                string str;
                cout << "Введіть рядок: ";
                getline(cin, str);

                char c_str[256];
                strncpy(c_str, str.c_str(), sizeof(c_str));
                c_str[sizeof(c_str) - 1] = '\0';

                size_t pos, len;
                string repl;
                cout << "Введіть позицію для заміни: ";
                cin >> pos;
                cout << "Введіть довжину для заміни: ";
                cin >> len;
                cin.ignore();
                cout << "Введіть рядок для вставки: ";
                getline(cin, repl);

                string str_copy = str;
                if (pos <= str_copy.length())
                    str_copy.replace(pos, len, repl);
                cout << "Результат string::replace: " << str_copy << endl;

                my_replace(c_str, pos, len, repl.c_str());
                cout << "Результат my_replace: " << c_str << endl;

                ofstream result_file("result_task_1.txt", ios::app);
                if (result_file) {
                    result_file << "Рядок: " << str << "\nРезультат заміни: " << c_str << endl;
                    result_file.close();
                } else {
                    cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
                }

                break;
            }

            case 2: {
                string line;
                cout << "Введіть рядок для підрахунку слів: ";
                getline(cin, line);

                int count = count_words(line);
                cout << "Кількість слів: " << count << endl;

                ofstream result_file("result_task_2.txt", ios::app);
                if (result_file) {
                    result_file << "Рядок: " << line << "\nКількість слів: " << count << endl;
                    result_file.close();
                } else {
                    cerr << "Не вдалося відкрити файл для запису результатів!" << endl;
                }

                break;
            }

            case 3: {
                process_file();
                cout << "Файл оброблено. Перевірте output.txt." << endl;
                break;
            }

            case 0:
                cout << "Вихід..." << endl;
                break;

            default:
                cout << "Невірний вибір!" << endl;
        }
    } while (choice != 0);

    return 0;  // Завершення програми
}
