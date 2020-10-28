
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int i,n;
    cout << ("Введите целое положительное число") << endl;
    cin >> i;
    for (n=2;n<=sqrt(i);n++){
        if (i % n == 0) {
            cout << ("Число ") << i << (" составное") << endl;
            break;
            return(0);
        }
        else cout << ("Число ") << i << (" простое") << endl;
        break;
   }
}  

