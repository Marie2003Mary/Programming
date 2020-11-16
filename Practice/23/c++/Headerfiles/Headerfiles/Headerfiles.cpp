#include <iostream>
#include <iomanip>
#include "factor.h"
#include "teilor.h"
#include "repeat.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "n" << "   " << "n!" << std::endl;
    int n = 10;
    factorial::print();
    std::cout << std::endl;
    std::cout << "x" << "   " << "sin(x)" << std::endl;
    /*teilor::print();*/
}


