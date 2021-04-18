#include <iostream>
#include <cmath>
using namespace std;

bool equal(double a, double b, double e = 1E-10);

class Rational
{
private:
    double chisl, znam;
public:
    Rational()
    {
        this->chisl = 0;
        this->znam = 0;
    }
    Rational(int a, int b)
    {
        this->chisl = a;
        this->znam = b;
    }
    static int gcd(int p, int v) {
        int t;
        if (p < v) {
            t = p;
            p = v;
            v = t;
        }
        while (v != 0) {
            t = v;
            v = p % v;
            p = t;
        }
        return abs(p);
    }
    bool operator== (Rational x)
    {
        if (this->znam == 0 && x.chisl == 0)
        {
            return 0;
        }
        else
        {
            if ((this->chisl / this->znam) == (x.chisl / x.znam))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    char is_inf()
    {
        if (this->znam != 0)
        {
            return 0;
        }
        if (this->chisl == 0)
        {
            return 0;
        }
        return this->chisl > 0 ? 1 : -1;
    }
    Rational operator+(Rational x)
    {
        if ((this->znam == 0 && this->chisl == 0) || (x.znam == 0 && x.chisl == 0))
        {
            return Rational(0, 0);
        }
        if (this->is_inf() || x.is_inf())
        {
            if (this->is_inf() && x.is_inf())
            {
                auto sign = this->is_inf() + x.is_inf();
                return (sign == 0 && !(this->chisl + x.chisl)) ? Rational(0, 0) : Rational(sign * 1, 0);
            }
            return this->is_inf() ? *this : x;
        }
        return Rational(this->chisl * x.znam + this->znam * x.chisl, this->znam * x.znam);
    }
    Rational operator-(Rational x)
    {
        if ((this->znam == 0 && this->chisl == 0) || (x.znam == 0 && x.chisl == 0))
        {
            return Rational(0, 0);
        }
        if (this->is_inf() || x.is_inf())
        {
            if (this->is_inf() && x.is_inf())
            {
                auto sign = this->is_inf() + -x.is_inf();
                return (sign == 0 && !(this->chisl + x.chisl)) ? Rational(0, 0) : Rational(sign * 1, 0);
            }
            return this->is_inf() ? *this : Rational(-x.chisl, 0);
        }
        return Rational(this->chisl * x.znam - this->znam * x.chisl, this->znam * x.znam);
    }
    Rational operator*(Rational x)
    {
        return Rational(this->chisl * x.chisl, this->znam * x.znam);
    }
    Rational operator/(Rational x)
    {
        if ((this->znam == 0 && this->chisl == 0) || (x.znam == 0 && x.chisl == 0))
        {
            return Rational(0, 0);
        }
        if (this->is_inf() || x.is_inf())
        {
            if (this->is_inf() && x.is_inf())
            {
                return Rational(0, 0);
            }
            return this->is_inf() ?
                ((double(x) >= 0 && (double(*this) >= 0)
                    || (double(x) < 0 && (double(*this) < 0))))
                ? Rational(1, 0) : Rational(-1, 0) : Rational(0, 1);
        }
        return Rational(this->chisl * x.znam, this->znam * x.chisl);
    }
    operator double()
    {
        return this->chisl / this->znam;
    }
    operator bool()
    {
        if (this->znam != 0 && this->chisl == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int numerator()
    {
        return this->chisl;
    }
    int denominator()
    {
        return this->znam;
    }
    bool isNaN()
    {
        return (this->chisl == 0 && this->znam == 0) ? 1 : 0;
    }
};



int main()
{
    if (Rational::gcd(91, 65) == 13 &&
        Rational::gcd(10, 3) == 1 &&
        Rational::gcd(-10, 3) == 1 &&
        Rational::gcd(10, -3) == 1 &&
        Rational::gcd(-10, -3) == 1 &&
        Rational::gcd(30, 10) == 10 &&
        Rational::gcd(10, 30) == 10 &&
        Rational::gcd(0, 10) == 10 &&
        Rational::gcd(10, 0) == 10) std::cout << "gcd test passed\n";
    else std::cout << "gcd test failed\n";

    if (!Rational(22, 0).isNaN() &&
        !Rational(22, 9).isNaN() &&
        !Rational(0, 9).isNaN() &&
        !Rational(-22, 9).isNaN() &&
        !Rational(-22, 0).isNaN() &&
        Rational(0, 0).isNaN()
        ) std::cout << "isNaN test passed\n";
    else std::cout << "isNaN test failed\n";

    if (Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 0) == Rational(9, 0) &&
        !(Rational(22, 0) == Rational(22, 9)) &&
        !(Rational(22, 0) == Rational(-22, 9)) &&
        !(Rational(22, 0) == Rational(-22, 0)) &&
        !(Rational(22, 0) == Rational(0, 9)) &&
        !(Rational(22, 0) == Rational(0, 0)) &&

        Rational(22, 9) == Rational(22, 9) &&
        Rational(22, 9) == Rational(-22, -9) &&
        Rational(22, 9) == Rational(110, 45) &&
        Rational(22, 9) == Rational(-110, -45) &&
        !(Rational(22, 9) == Rational(-22, 9)) &&
        !(Rational(22, 9) == Rational(22, -9)) &&
        !(Rational(22, 9) == Rational(9, 22)) &&
        !(Rational(22, 9) == Rational(22, 0)) &&
        !(Rational(22, 9) == Rational(-22, 0)) &&
        !(Rational(22, 9) == Rational(0, 9)) &&
        !(Rational(22, 9) == Rational(0, 0)) &&

        Rational(0, 1) == Rational(0, 1) &&
        Rational(0, 1) == Rational(0, 9) &&
        Rational(0, 1) == Rational(0, -9) &&
        !(Rational(0, 1) == Rational(22, 9)) &&
        !(Rational(0, 1) == Rational(-22, 9)) &&
        !(Rational(0, 1) == Rational(22, 0)) &&
        !(Rational(0, 1) == Rational(-22, 0)) &&
        !(Rational(0, 1) == Rational(0, 0)) &&

        Rational(-22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) == Rational(22, -9) &&
        Rational(-22, 9) == Rational(-110, 45) &&
        Rational(-22, 9) == Rational(110, -45) &&
        !(Rational(-22, 9) == Rational(-22, -9)) &&
        !(Rational(-22, 9) == Rational(22, 9)) &&
        !(Rational(-22, 9) == Rational(9, -22)) &&
        !(Rational(-22, 9) == Rational(22, 0)) &&
        !(Rational(-22, 9) == Rational(-22, 0)) &&
        !(Rational(-22, 9) == Rational(0, 9)) &&
        !(Rational(-22, 9) == Rational(0, 0)) &&

        Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) == Rational(-9, 0) &&
        !(Rational(-22, 0) == Rational(22, 9)) &&
        !(Rational(-22, 0) == Rational(-22, 9)) &&
        !(Rational(-22, 0) == Rational(22, 0)) &&
        !(Rational(-22, 0) == Rational(0, 9)) &&
        !(Rational(-22, 0) == Rational(0, 0)) &&

        !(Rational(0, 0) == Rational(0, 0))
        ) std::cout << "Equality test passed\n";
    else std::cout << "Equality test failed\n";

    if (Rational(22, 0) + Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 9) + Rational(22, 0) == Rational(22, 0) &&
        Rational(0, 9) + Rational(22, 0) == Rational(22, 0) &&
        Rational(-22, 9) + Rational(22, 0) == Rational(22, 0) &&
        (Rational(-22, 0) + Rational(22, 0)).isNaN() &&

        Rational(22, 0) + Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) + Rational(22, 9) == Rational(44, 9) &&
        Rational(0, 9) + Rational(22, 9) == Rational(22, 9) &&
        Rational(-22, 9) + Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 0) + Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) + Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) + Rational(0, 1) == Rational(22, 9) &&
        Rational(0, 9) + Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) + Rational(0, 1) == Rational(-22, 9) &&
        Rational(-22, 0) + Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) + Rational(-22, 9) == Rational(22, 0) &&
        Rational(22, 9) + Rational(-22, 9) == Rational(0, 9) &&
        Rational(0, 9) + Rational(-22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) + Rational(-22, 9) == Rational(-44, 9) &&
        Rational(-22, 0) + Rational(-22, 9) == Rational(-22, 0) &&

        (Rational(22, 0) + Rational(-22, 0)).isNaN() &&
        Rational(22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(0, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 9) + Rational(-22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) + Rational(-22, 0) == Rational(-22, 0) &&

        (Rational(22, 0) + Rational(0, 0)).isNaN() &&
        (Rational(22, 9) + Rational(0, 0)).isNaN() &&
        (Rational(0, 9) + Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) + Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) + Rational(0, 0)).isNaN()
        ) std::cout << "Summation test passed\n";
    else std::cout << "Summation test failed\n";

    if ((Rational(22, 0) - Rational(22, 0)).isNaN() &&
        Rational(22, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(0, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 9) - Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) - Rational(22, 0) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) - Rational(22, 9) == Rational(0, 9) &&
        Rational(0, 9) - Rational(22, 9) == Rational(-22, 9) &&
        Rational(-22, 9) - Rational(22, 9) == Rational(-44, 9) &&
        Rational(-22, 0) - Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) - Rational(0, 1) == Rational(22, 9) &&
        Rational(0, 9) - Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) - Rational(0, 1) == Rational(-22, 9) &&
        Rational(-22, 0) - Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(-22, 9) == Rational(22, 0) &&
        Rational(22, 9) - Rational(-22, 9) == Rational(44, 9) &&
        Rational(0, 9) - Rational(-22, 9) == Rational(22, 9) &&
        Rational(-22, 9) - Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 0) - Rational(-22, 9) == Rational(-22, 0) &&

        Rational(22, 0) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(22, 9) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(0, 9) - Rational(-22, 0) == Rational(22, 0) &&
        Rational(-22, 9) - Rational(-22, 0) == Rational(22, 0) &&
        (Rational(-22, 0) - Rational(-22, 0)).isNaN() &&

        (Rational(22, 0) - Rational(0, 0)).isNaN() &&
        (Rational(22, 9) - Rational(0, 0)).isNaN() &&
        (Rational(0, 9) - Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) - Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) - Rational(0, 0)).isNaN()
        ) std::cout << "Subtraction test passed\n";
    else std::cout << "Subtraction test failed\n";

    if (Rational(22, 0) * Rational(22, 0) == Rational(22, 0) &&
        Rational(22, 9) * Rational(22, 0) == Rational(22, 0) &&
        (Rational(0, 9) * Rational(22, 0)).isNaN() &&
        Rational(-22, 9) * Rational(22, 0) == Rational(-22, 0) &&
        Rational(-22, 0) * Rational(22, 0) == Rational(-22, 0) &&

        Rational(22, 0) * Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) * Rational(22, 9) == Rational(22 * 22, 9 * 9) &&
        Rational(0, 9) * Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(22, 9) == Rational(-22 * 22, 9 * 9) &&
        Rational(-22, 0) * Rational(22, 9) == Rational(-22, 0) &&

        (Rational(22, 0) * Rational(0, 1)).isNaN() &&
        Rational(22, 9) * Rational(0, 1) == Rational(0, 9) &&
        Rational(0, 9) * Rational(0, 1) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(0, 1) == Rational(0, 9) &&
        (Rational(-22, 0) * Rational(0, 1)).isNaN() &&

        Rational(22, 0) * Rational(-22, 9) == Rational(-22, 0) &&
        Rational(22, 9) * Rational(-22, 9) == Rational(-22 * 22, 9 * 9) &&
        Rational(0, 9) * Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 9) * Rational(-22, 9) == Rational(22 * 22, 9 * 9) &&
        Rational(-22, 0) * Rational(-22, 9) == Rational(22, 0) &&

        Rational(22, 0) * Rational(-22, 0) == Rational(-22, 0) &&
        Rational(22, 9) * Rational(-22, 0) == Rational(-22, 0) &&
        (Rational(0, 9) * Rational(-22, 0)).isNaN() &&
        Rational(-22, 9) * Rational(-22, 0) == Rational(22, 0) &&
        Rational(-22, 0) * Rational(-22, 0) == Rational(22, 0) &&

        (Rational(22, 0) * Rational(0, 0)).isNaN() &&
        (Rational(22, 9) * Rational(0, 0)).isNaN() &&
        (Rational(0, 9) * Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) * Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) * Rational(0, 0)).isNaN()
        ) std::cout << "Multiplication test passed\n";
    else std::cout << "Multiplication test failed\n";

    if ((Rational(22, 0) / Rational(22, 0)).isNaN() &&
        Rational(22, 9) / Rational(22, 0) == Rational(0, 9) &&
        Rational(0, 9) / Rational(22, 0) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(22, 0) == Rational(0, 9) &&
        (Rational(-22, 0) / Rational(22, 0)).isNaN() &&

        Rational(22, 0) / Rational(22, 9) == Rational(22, 0) &&
        Rational(22, 9) / Rational(22, 9) == Rational(9, 9) &&
        Rational(0, 9) / Rational(22, 9) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(22, 9) == Rational(-9, 9) &&
        Rational(-22, 0) / Rational(22, 9) == Rational(-22, 0) &&

        Rational(22, 0) / Rational(0, 1) == Rational(22, 0) &&
        Rational(22, 9) / Rational(0, 1) == Rational(22, 0) &&
        (Rational(0, 9) / Rational(0, 1)).isNaN() &&
        Rational(-22, 9) / Rational(0, 1) == Rational(-22, 0) &&
        Rational(-22, 0) / Rational(0, 1) == Rational(-22, 0) &&

        Rational(22, 0) / Rational(-22, 9) == Rational(-22, 0) &&
        Rational(22, 9) / Rational(-22, 9) == Rational(-9, 9) &&
        Rational(0, 9) / Rational(-22, 9) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(-22, 9) == Rational(9, 9) &&
        Rational(-22, 0) / Rational(-22, 9) == Rational(22, 0) &&

        (Rational(22, 0) / Rational(-22, 0)).isNaN() &&
        Rational(22, 9) / Rational(-22, 0) == Rational(0, 9) &&
        Rational(0, 9) / Rational(-22, 0) == Rational(0, 9) &&
        Rational(-22, 9) / Rational(-22, 0) == Rational(0, 9) &&
        (Rational(-22, 0) / Rational(-22, 0)).isNaN() &&

        (Rational(22, 0) / Rational(0, 0)).isNaN() &&
        (Rational(22, 9) / Rational(0, 0)).isNaN() &&
        (Rational(0, 9) / Rational(0, 0)).isNaN() &&
        (Rational(-22, 9) / Rational(0, 0)).isNaN() &&
        (Rational(-22, 0) / Rational(0, 0)).isNaN()
        ) std::cout << "Division test passed\n";
    else std::cout << "Division test failed\n";

    if (equal(Rational(-22, -9), 22 / 9.0) &&
        equal(Rational(-9, -9), 1) &&
        equal(Rational(-6, -9), 6 / 9.0) &&
        equal(Rational(0, -9), 0) &&
        equal(Rational(6, -9), -6 / 9.0) &&
        equal(Rational(9, -9), -1) &&
        equal(Rational(22, -9), -22 / 9.0) &&
        std::isinf((double)Rational(-9, 0)) &&
        std::isnan((double)Rational(0, 0)) &&
        std::isinf((double)Rational(9, 0)) &&
        equal(Rational(-22, 9), -22 / 9.0) &&
        equal(Rational(-9, 9), -1) &&
        equal(Rational(-6, 9), -6 / 9.0) &&
        equal(Rational(0, 9), 0) &&
        equal(Rational(6, 9), 6 / 9.0) &&
        equal(Rational(9, 9), 1) &&
        equal(Rational(22, 9), 22 / 9.0)) std::cout << "Conversion to double test passed\n";
    else std::cout << "Conversion to double test failed\n";

    if (Rational(-22, -9) &&
        Rational(-9, -9) &&
        Rational(-6, -9) &&
        !Rational(0, -9) &&
        Rational(6, -9) &&
        Rational(9, -9) &&
        Rational(22, -9) &&
        Rational(-9, 0) &&
        Rational(0, 0) &&
        Rational(9, 0) &&
        Rational(-22, 9) &&
        Rational(-9, 9) &&
        Rational(-6, 9) &&
        !Rational(0, 9) &&
        Rational(6, 9) &&
        Rational(9, 9) &&
        Rational(22, 9)) std::cout << "Conversion to bool test passed\n";
    else std::cout << "Conversion to bool test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}
