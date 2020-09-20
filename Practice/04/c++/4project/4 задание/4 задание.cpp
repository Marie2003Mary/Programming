#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c;
	cout << "Введите числовые значения переменных a и b" << endl;
	cin >> a >> b;
	c = a;
	a = b;
	b = c;
	cout << "Значение a= " << a << endl;
	cout << "Значение b =" << b;

}
