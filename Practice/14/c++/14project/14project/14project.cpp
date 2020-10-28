
#include <iostream>
using namespace std;
int main()
{  setlocale(LC_ALL, "Russian");
long long  n, k=0;
cout << ("Введите входные данные")<<endl;
cin>> n;
for ( int x = 1; x <= n;x*=2) {
	k++;
}
cout <<("Количество степеней двойки: ")<< k;
}


