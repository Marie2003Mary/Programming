#pragma once
#include <iostream>
namespace factor 
{
    long long  i, factor = 1;
    void print()
    {
        std::cout << ("������� �������� ��� ���������� ��� ����������");
        std::cin >> i;
        for (i; i > 1; i--) 
        {
            factor = factor * i;
        }
        std::cout << ("�������� ���������� : ") << factor;
    }
}