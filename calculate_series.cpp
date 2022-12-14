/************************************************************
 *                                                          *
 *           Информатика и вычислительная техника           *
 *                                                          *
 ************************************************************
 *  Project type: ConsoleApplication                        *
 *  Project name: lab                                       *
 *  Language: cpp gcc version 9.4.0                         *
 *  Programmers: М3О-111Б-22                                *
 *               Яковченко Николай Романович;               *
 *               Деккер Сергей Альбертович                  *
 *  Modigied by:                                            *
 *  Created: 18.10.2022                                     *
 *  Comment: FirstProgramm (Подсчёт суммы ряда)             *
 ************************************************************/


// Подключение библиотек
#include <iostream>
#include <cmath>
using namespace std;


int main() // Начало программы
{
    setlocale(LC_ALL, "rus"); // Подключение русского языка

    int n;                    // Число итераций
    unsigned long long doubleFactorial; // Текущее значение удвоенного факториала
    double difference;        // Разность текущей и точной сумм
    double currentSum;        // Сумма
    double exactSum;          // Точное значение суммы
    double x;                 // Переменная
    double eps;               // Точность
    double numerator;         // Числитель

    cout << "Введите точность: ";
    cin >> eps;               // Ввод точности
    cout << eps << endl;      // Эхо-печать

    if (eps <= 0)             // Валидация входящих данных
    {
        cout << "Заданная точность должна быть больше нуля" << endl; // Вывод сообщения об ошибке
        return 1; // Завершение работы программы со статусом 1 в случае некорректности введённых данных
    }

    cout << "Введите X: ";
    cin >> x;                 // Ввод переменной x
    cout << x << endl;        // Эхо-печать

    // Инициализация переменных
    n = 1;
    doubleFactorial = 1;
    currentSum = 1;
    numerator = 1;

    exactSum = (exp(x) + exp(-x)) / 2;       // Подсчёт точной суммы
    difference = abs(currentSum - exactSum); // Подсчёт разности

    while (difference > eps) // Начало цикла
    {
        // Вычисление суммы ряда
        doubleFactorial = doubleFactorial * (2 * n) * (2 * n - 1);
        numerator = numerator * x * x;
        currentSum += numerator / doubleFactorial;
        n += 1;
        difference = abs(currentSum - exactSum);
    } // Конец цикла

    // Вывод значений переменных
    cout << "Сумма членов: " << currentSum << endl;
    cout << "Точное значение: " << exactSum << endl;
    cout << "Число слагаемых: " << n << endl;
    cout << "Разность суммы и точного значения: " << difference << endl;
    return 0; // Возврат значения 0
} // Конец программы
