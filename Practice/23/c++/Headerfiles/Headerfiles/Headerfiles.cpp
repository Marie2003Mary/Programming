#include <iostream>
#include <iomanip>
#include "factor.h"
#include "teilor.h"
#include "repeat.h"
#define PI 3.14159265358979323
#include <cmath> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "n" << "   " << "n!" <<endl;
    for (int m = 1; m < 11; m++)
    {
        cout << m << "   " << factor(m) << endl;
    }
    cout << std::endl;

    cout << "x" << "   " << "sin(x)" << endl;
    for (float x = 0; x <= PI/4; x+= PI/180)
    {
        cout << x << "   " << setprecision(4) <<teilor(x)<< endl;
    }
    cout << endl;
    int k = 10;
    cout << "k" << "    " << "c(k,10)" << endl;
    for (int n = 1; n <= k; n++) 
    {
        cout << n << "    " << repeat(n, k) << endl;

    }
}

