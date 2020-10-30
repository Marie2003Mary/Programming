#include <iostream>
using namespace std;
int main()
{     setlocale(LC_ALL, "Russian");
    int a, b;
    cout<< "Введите два целых числа\n";
    cin >> a>> b;
    cout << "a+b = "<<a + b << endl;
    cout <<"a-b = " << a - b << endl;
    cout <<"a*b = " <<a * b << endl;
    cout <<"a/b = " << a / b << endl;
    double a1, b1;
    cout << "Введите два рациональных числа\n";
    cin >> a1 >> b1;
    cout << "a1+b2 = " << a1 + b1 << endl;
    cout << "a1-b2 = " << a1 - b1 << endl;
    cout << "a1*b2 = " << a1 * b1 << endl;
    cout << "a1/b2 = " << a1 / b1 << endl;
    int a2;
    double b2;
    cout << "Введите целое,а потом рациональное число\n";
    cin >> a2 >> b2;
    cout << "a2+b2 = " << a2 + b2 << endl;
    cout << "a2-b2 = " << a2 - b2 << endl;
    cout << "a2*b2 = " << a2 * b2 << endl;
    cout << "a2/b2 = " << a2 / b2 << endl;
    double a3;
    int b3;
    cout << "Введите рациональное,а потом целое число\n";
    cin >> a3 >> b3;
    cout << "a3+b3= " << a3 + b3 << endl;
    cout << "a3-b3 = " << a3 - b3 << endl;
    cout << "a3*b3 = " << a3 * b3 << endl;
    cout << "a3/b3 = " << a3 / b3 << endl;
}

