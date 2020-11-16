#pragma once
#include <iostream>
namespace factorial
{
    /*void print() {
        int factor(int x)
        {
            if (x == 1) { return x; }
            int result = x * factor(x - 1);
        }
    }
    void print()
    {
        for (int i = 1; i <= 10; i++)
        {
            std::cout << i << " ";
        }
        std::cout  << "   " << factor(x) << std::endl;
    }*/
     int  n, factor1 = 1;
     void print()
     {
         for (n = 1;n < 11; n++)
         {
             factor1 = factor1 * n;
             std::cout << n << "   " << factor1 << std::endl;
         }
     } }

