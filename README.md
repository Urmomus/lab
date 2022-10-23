# Вычисление суммы бесконечного ряда

## Задание

---

Кафедра 304    Курс: ИНФОРМАЦИОННЫЕ ТЕХНОЛОГИИ
Задание 1: Вычисление суммы бесконечного числового ряда

---

#### Вариант №11

Определить с заданной точностью сумму членов бесконечного степенного ряда:

$$ 1 + \displaystyle\sum_{n=1} \frac{x^{2n}}{(2n)!} = 1 + \frac{x^{2}}{2!} + \frac{x^{4}}{4!} + \frac{x^{6}}{6!} + ... $$

Предусмотреть ввод точности и печать: количества просуммированных элементов, суммы, разности суммы и точного значения, которое равно:

$$ \frac{e^{x} + e^{-x}}{2} = ch(x) $$

## Текст программы

```cpp
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
}

```
