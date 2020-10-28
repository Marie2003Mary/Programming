#include <iostream>
#include <ctime>
using namespace std;
int main() 
{
	setlocale(LC_ALL, "rus");
	int a, x, i, k;
	while (1)
	{
			srand(time(0));
			a = 1 + rand() % 100;
			cout << "Введите число\n";
			cin >> x;
			for (i = 1; i < 5; i++)
			{
				if (x < a)
				{
				cout << "Загаданное значение больше введённого\n";
				}
				else if (x > a) 
				{
				cout << "Загаданное значение меньше введённого\n";

				}
				else 
				{
					cout << "Поздравляю! Вы угадали \n";
					break;
				}
				cin >> x;
			}
			if (x != a) 
			{
				cout << "Вы проиграли, загаданное значение - " << a;
			}
			cout << "\n" << "Хотите повторить? - введите 1\n";
			cin >> k;
			if (k != 1)
			{
				break;
			}
	}
		return 0;
}