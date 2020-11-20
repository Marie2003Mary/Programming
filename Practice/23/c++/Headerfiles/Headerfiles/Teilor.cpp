#include "teilor.h"
#include "factor.h"
#include <cmath> 

float teilor(float x) 
{
    float sin = 0;
    for (int i = 0; i < 5; i++)
    {
        sin = sin + pow(-1, i) * pow(x, 2 * i + 1) / factor(2 * i + 1);
    }
    return sin;
}