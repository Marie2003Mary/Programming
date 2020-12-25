#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include<windows.h>
#include <ctime>
using namespace std;

struct Student
{
    string name;
    int group;
    map<int, int> exam;
};
void vuvod(Student a)
{
	cout  << "| " << a.name << "\t|   ";
    cout << a.group << "   |  ";
    cout << a.exam[0] << "   |  ";
    cout << a.exam[1] << "   |  ";
    cout << a.exam[2] << "   |  ";
	cout << a.exam[3] << "   |" << endl;
}

Student vvod(Student a, string name, int group, int math, int his, int ph, int prog)
{
    map<int, int> m = { {0, math}, {1, his}, {2, ph}, {3, prog} };
    a.name = name;
    a.group = group;
    a.exam = m;
    return a;
}
Student* BozoSort(Student a[6]) {
	int r1, r2, k = 0, ind = 0, check = 0, prov = 0;
	while (1) {
		r1 = rand() % 6;
		r2 = rand() % 6;
		if (r1 != r2) {
			std::swap(a[r1], a[r2]);
			for (int i = 0; i < 5; i++) {
				while (1) {
					if (a[i].name[k] < a[i + 1].name[k]) {
						k = 0;
						ind++;
						break;
					}
					else if (a[i].name[k] == a[i + 1].name[k]) {
						k++;
					}
					else {
						ind = 0;
						k = 0;
						break;
					}
				}
			}
		}
		if (ind == 5) {
			for (int i = 0; i < 6; i++) 
			{
				for (int j = 0; j < 4; j++)
				{
					if (a[i].exam[j] == 2) 
					{
						if (prov == 0) {
							cout << "+---------------+-------+------+------+------+------+" << endl;
							cout << "| Name\t\t" << "| Group " << "| Math " << "| Phys " << "| Hist " << "| Prog |" << endl;
						}
						cout << "+---------------+-------+------+------+------+------+" << endl;
						vuvod(a[i]);
						prov = 1;
						break;
					}
				}
			}
			if (prov == 0) {
				std::cout << "Not found";
				break;
			}
			if (prov == 1) {
				cout << "+---------------+-------+------+------+------+------+" << endl;
				break;
			}
		}
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
    Student a[6];
    a[0] = vvod(a[0], "BulBul K", 5, 3, 4, 5, 3);
    a[1] = vvod(a[1], "AlipBlap V", 3, 3, 3, 2, 3);
    a[2] = vvod(a[2], "MilkNulk M", 2, 4, 4, 4, 4);
    a[3] = vvod(a[3], "ButNar A", 1, 5, 5, 5, 5);
	a[4] = vvod(a[4], "LlkFll D", 8, 5, 2, 3, 3);
	a[5] = vvod(a[5], "Jgjbopp D", 4, 2, 5, 3, 3);
	std::vector<Student>mas(6);
	mas[0] = a[0];
	BozoSort(a);
	vuvod(mas[0]);
	std::cout << "\n";
}