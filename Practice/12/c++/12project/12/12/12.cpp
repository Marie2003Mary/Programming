#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    long long  i,factor=1;
    cout << ("Введите значения для вычисления его факториала") << endl;
    cin >> i;
    for (i; i > 1;i-- ) {
        factor = factor * i;
    }
    cout << ("Значение факториала : ")<<factor;
}

