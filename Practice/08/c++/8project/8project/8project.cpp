#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double c1, c2;
	string z;
	cout << ("Введите первое значение,знак и второе значение") << endl;
	cin >> c1 >> z >> c2;
	if (z == "+")
		cout << ("Результат вычисления:") << c1 + c2;
	if (z == "-")
		cout << ("Результат вычисления:") << c1 - c2;
	if (z == "*")
		cout << ("Результат вычисления:") << c1 * c2;
	if (z == "/")
		cout << ("Результат вычисления:") << c1 / c2;
}
