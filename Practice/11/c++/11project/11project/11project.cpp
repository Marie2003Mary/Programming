#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int z, s, r = 1;
	double r2 = 1;
	cout << ("Введите число, а затем степень числа") << endl;
	cin >> z;
	cin >> s;
	if (s >= 0) {
		while (s != 0) {
			r = r * z;
			s = s - 1;
		}cout << r;
	}
	else
	{
		while (s != 0) {
			r2 = r2 * z;
			s = s + 1;
		}cout << 1 / r2;
	}

}

