#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");

    int n, doubleFactorial;
    double difference, currentSum, exactSum, x, eps, numerator;

    cout << "Введите точность: ";
    cin >> eps;
    cout << eps << endl;

    if (eps <= 0)
    {
        cout << "Заданная точность должна быть больше нуля" << endl;
        return 1;
    }

    cout << "Введите X: ";
    cin >> x;
    cout << x << endl;

    n = 1;
    doubleFactorial = 1;
    currentSum = 1;
    numerator = 1;

    exactSum = (exp(x) + exp(-x)) / 2;
    difference = abs(currentSum - exactSum);

    while (difference > eps)
    {
        doubleFactorial = doubleFactorial * (2 * n) * (2 * n - 1);
        numerator = numerator * x * x;
        currentSum += numerator / doubleFactorial;
        n += 1;
        difference = abs(currentSum - exactSum);
    }

    cout << "Сумма членов: " << currentSum << endl;
    cout << "Точное значение: " << exactSum << endl;
    cout << "Число слагаемых: " << n << endl;
    cout << "Разность суммы и точного значения: " << difference << endl;
}
