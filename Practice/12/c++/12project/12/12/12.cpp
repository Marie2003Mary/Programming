#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    long long  r=1,n,factor=1;
    cout << ("Введите значения для вычисления его факториала") << endl;
    cin >> n;
    while (r <= n ) {
        factor = factor * r;
        r = r + 1;
    }
    cout << factor;
}

