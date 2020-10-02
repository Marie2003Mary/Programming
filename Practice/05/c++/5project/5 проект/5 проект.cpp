#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x0, v0, t,xt;
	double g = 9.8;
	cout << "Введите значения параметров x0,v0,t" << endl;
	cin >> x0 >> v0>> t;
	xt= x0+(v0 * t) - (g*t * t) / 2;
	cout << "Расстояние, которое объект преодолеет с учётом введённых пользователем параметров"<< abs(xt-x0);
}

