#include<locale>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите сумму,затем начальное и конечное значения диапазонов" << endl;
    int s, l1, r1, l2, r2, x1, x2, step;
    step = 0;
    x1 = 0;
    x2 = 0;
    cin >> s >> l1 >> r1 >> l2 >> r2;
    if ((s > (r1 + r2)) || (s < (l1 + l2)))
    {
        cout << -1;
    }
    else
    {
        if ((s - l1) >= l2)
        {
            if (s <= (l1 + r2))
            {
                cout << l1 << " " << s - l1;
            }
            else
            {
                step = abs(s - (l1 + r2));
                if ((l1 + step) < r1 && (r2 - step) > l2)
                {
                    cout << l1 + step << " " << s - (l1 + step);
                }
                else
                {
                    cout << -1;
                }
            }
        }
    }


}