#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int h1, h2, m1, m2;
	string t;
	cout << ("Укажите время прихода первого человека:");
	cin >> h1 >> t >> m1;
	cout << endl;
	cout << ("Укажите время прихода второго человека:");
	cin >> h2 >> t >> m2;
	cout << endl;
	if ((0 <= h1 <= 23) && (0 <= m1 <= 59) && (0 <= h2 <= 23) && (0 <= m2 <= 59)) {
		if (((h1 == h2) && ((m2 - m1) <= 15)) || ((h1 != h2) && (abs(m2 - m1) >= 45)))
			cout << ("Встреча состоится");
		if (((h1 != h2) && ((m1 - m2) < 45)) || ((h1 == h2) && (abs(m1 - m2) > 15)))
			cout << ("Встреча не состоится");
	}

}