#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    const int p = 37;
    int u = 0;
    int n = 0;
    int b = 0;
    int k = 0;
    int black[18] = { 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35 };
    int a[p];
    for (int i = 0; i < p; i++)
    {
        a[i] = 0;
    }
    while (true)
    {
        cin >> u;
        if (u < 0)
        {
            break;
        }
        else
        {
            a[u]++;
            for (int i = 0; i <= 17; i++)
            {
                if (u == black[i])
                {
                    b++;
                    break;
                }
                else if (i == 17)
                {
                    k++;
                    break;
                }
            }

        }
        for (int i = 0; i < p; i++)
        {
            if (a[i] > n)
            {
                n = a[i];
            }
        }
        for (int i = 0; i < p; i++)
        {
            if (a[i] == n)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < p; i++)
        {
            if (a[i] == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl << "Красные: " << k << " Черные: " << b << endl;
    }
}