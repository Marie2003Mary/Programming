#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	//p=(a+b+c)/2 
	double a, b, c, x1, y1, x2, y2, y3, x3, p, S;
	int v;
	while (true)
	{
		cout << ("Выберите вариант расчёта площади треугольника 1-через длины сторон,2-через координаты вершин:");
		cin >> v;
		cout << endl;
		if ((v == 1) || (v == 2)) {
			if (v == 1) {
				cout << ("Введите длины сторон a,b,c") << endl;
				cin >> a >> b >> c;
				cout << endl;
				p = (a + b + c) / 2;
				S = sqrt(p * (p - a) * (p - b) * (p - c));
				if (((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b))
					cout << ("Такого треугольника не существует, т.к сумма двух сторон должна быть больше третьей стороны");
				else
				{
					cout << ("S = ") << S;
					break;
				}
			}
			while (true) {
				if (v == 2) {
					cout << ("Введите координаты вершин x1,y1 и т.д") << endl;
					cin >> x1 >> y1;
					cin >> x2 >> y2;
					cin >> x3 >> y3;
					cout << endl;
					S = 0.5 * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
					a = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
					b = sqrt(((x2 - x3) * (x2 - x3)) + ((y2 - y3) * (y2 - y3)));
					c = sqrt(((x1 - x3) * (x1 - x3)) + ((y1 - y3) * (y1 - y3)));
					if (((a + b) <= c) || ((b + c) <= a) || ((a + c) <= b))
						cout << ("Такого треугольника не существует, т.к сумма двух сторон должна быть больше третьей стороны");
					else {
						cout << ("S = ") << S;
						break;
					}
				}
			}
		}
		else
			cout << ("Введены некорректные данные") << endl;

	}
}


