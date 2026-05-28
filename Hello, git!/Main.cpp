#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "mod_2.h"
using namespace std;

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double numbers[100];
    int count = 0;
    char outputfile[256];

    if (argc > 3) {
        count = atoi(argv[1]);
        for (int i = 0; i < count; i++) {
            numbers[i] = atof(argv[2 + i]);
        }
        strcpy(outputfile, argv[argc - 1]);
    }
    else {
        char filename[256];
        cout << "Введіть ім'я вхідного файлу: ";
        cin >> filename;
        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "Помилка відкриття файлу!";
            return 1;
        }
        fin >> count;
        for (int i = 0; i < count; i++) {
            fin >> numbers[i];
        }
        fin.close();
        cout << "Введіть ім'я вихідного файлу: ";
        cin >> outputfile;
    }

    sortByFrac(numbers, count, fracPart);

    int good = 0, bad = 0, neutral = 0;
    countCategories(numbers, count, good, bad, neutral);

    ofstream fout(outputfile);
    if (!fout.is_open()) {
        cout << "Помилка відкриття вихідного файлу!";
        return 1;
    }
    fout << "Відсортована послідовність:\n";
    for (int i = 0; i < count; i++) {
        fout << numbers[i] << " ";
    }
    fout << "\n";
    fout << "Кількість 'гарних': " << good << "\n";
    fout << "Кількість 'поганих': " << bad << "\n";
    fout << "Кількість 'ніяких': " << neutral << "\n";
    fout.close();

    cout << "Результат записано у файл.";
    return 0;
}