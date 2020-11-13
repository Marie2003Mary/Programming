#pragma once
#include <iostream>
namespace factor 
{
    long long  i, factor = 1;
    void print()
    {
        std::cout << ("Введите значения для вычисления его факториала");
        std::cin >> i;
        for (i; i > 1; i--) 
        {
            factor = factor * i;
        }
        std::cout << ("Значение факториала : ") << factor;
    }
}