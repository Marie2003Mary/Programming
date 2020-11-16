#include "factor.h"
#ifndef TEILOR_H
#define TEILOR_H
#define PI 3.14159265358979323
#include <cmath>  
namespace teilor
{
    int x, sin,a=0;
    void teilor()
    {
        for (x = 0; x <= (PI / 4.); PI / 180)
            sin = sin + pow(-1, a + 1) * pow(x, a + 3);
        factorial::print();
    }
}

#endif