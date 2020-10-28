#include<locale>
#include <iostream>
#include <string>
using namespace std;
int main()
{   
    setlocale(LC_ALL, "ru");
    int n,b,k;
    b = 0;
    bool f = true;
    cout << "Введите количество билетов \n";
    cin >> n;
    cout << "Введите  номера билетов через пробел\n";
    string a{};
    for ( k= 1; k <= n; k++)
    {
        cin >> a;
        if (a[0] == 'a' && a[4] == '5' && a[5] == '5' && a[6] == '6' && a[7] == '6' && a[8] == '1')
            {
             cout << a << ' ';
            }
        else
        {
            b++;
        }
    }
    if(b==n)
    {
    cout << "-1";
    }
    return 0;
} 

