#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//ax*x+b*x+c=0
	double a, b, c, x1, x2, x, d;
	cout << ("Введите значения a,b,c") << endl;
	cin >> a >> b >> c;
	d = (b * b) - (4 * a * c);
	if ((d >= 0) && (((a != 0) && (b != 0) && (c == 0)) || ((a != 0) && (c != 0) && (b == 0)) || ((b != 0) && (c != 0)))) {
		if (a != 0)
		{
			x1 = (-b - sqrt(d)) / (2 * a);
			x2 = (-b + sqrt(d)) / (2 * a);
			if (x1 == x2)
				cout << ("x=") << x1;
			else {
				cout << ("x1 = ") << x1 << endl;
				cout << ("x2 = ") << x2;
			}
		}
		else
		{
			x = (-c / b);
			cout << ("x = ") << x;
		}
	}
	if ((d < 0) || ((a == 0) && (b == 0) && (c != 0)))
		cout << ("Нет решения");
	if (((b == 0) && (c == 0) && (a != 0)) || ((a == 0) && (c == 0) && (b != 0))) {
		if (a != 0)
			cout << ("x = ") << (0 / a);
		if (b != 0)
			cout << ("x = ") << (0 / b);
	}
	if ((a == 0) && (b == 0) && (c == 0))
		cout << ("Все корни верны");
}
