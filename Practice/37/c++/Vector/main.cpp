#include <iostream>
#include <math.h>
using namespace std;

double sqr(double a);
bool equal(double a, double b, double e = 1E-10);

enum Coord_system { Cartesian, Polar };



class Point {
private:
    double x;
    double y;

public:
    Point(double a1 = 0, double a2 = 0, Coord_system coord_system = Cartesian){

        if (coord_system == Cartesian) {
            this-> x = a1;
            this-> y = a2;
        }
        else
        {
            x = a1 * cos(a2);
            y = a1 * sin(a2);
        }


    };

    double get_x() {
        return x;
    }
    double get_y() {
        return y;
    }
    double get_r() {
        return sqrt(x * x + y * y);
    }
    double get_phi() {
        return atan2(y, x);
    }

    void set_x(double a) {
        this->x = a;
    }
    void set_y(double a) {
        this->y = a;
    }

    void set_r(double a) {
        double fi = get_phi();
        x = a * cos(fi);
        y = a * sin(fi);

    }
    void set_phi(double fi) {
        double a = get_r();
        x = a * cos(fi);
        y = a * sin(fi);

    }
    bool operator ==(Point p) {
        if (fabs(this->x - p.x) < exp(-10) && fabs(this->y - p.y) < exp(-10))
            return true;
        else
            return false;
    }
};


class Vector {
public:

    Point unit_vectors;
    Vector() :unit_vectors(1, 0) {};
    Vector(Point end) :unit_vectors(end.get_x(), end.get_y()) {
    }
    Vector(Point begin, Point end) :unit_vectors(end.get_x() - begin.get_x(), end.get_y() - begin.get_y()) {
    }
    ~Vector() {}

    bool operator==(Vector second) {
        if (unit_vectors == second.unit_vectors)
            return true;
        else
            return false;
    }

    Vector operator-() {
        Point invert = unit_vectors;
        invert.set_x(-(invert.get_x()));
        invert.set_y(-(invert.get_y()));
        return Vector(invert);
    }


    Vector operator-(Vector second) {
        Point subtraction = unit_vectors;
        subtraction.set_x(unit_vectors.get_x() - second.unit_vectors.get_x());
        subtraction.set_y(unit_vectors.get_y() - second.unit_vectors.get_y());
        return Vector(subtraction);
    }



    Vector operator+(Vector other) {
        Point summation = unit_vectors;
        summation.set_x(unit_vectors.get_x() + other.unit_vectors.get_x());
        summation.set_y(unit_vectors.get_y() + other.unit_vectors.get_y());
        return Vector(summation);
    }


    Vector operator*(double multiplier) {
        Point Multiplication = unit_vectors;
        Multiplication.set_x(Multiplication.get_x() * multiplier);
        Multiplication.set_y(Multiplication.get_y() * multiplier);
        return Vector(Multiplication);
    }

    double length() {
        return unit_vectors.get_r();
    }

    double operator*(Vector second) {
        return length() * second.length() * cos(unit_vectors.get_phi() - second.unit_vectors.get_phi());
    }
};



int main()
{
    Vector a(Point(1, 2)), b(Point(-2, 0), Point(-1, 2));
    if (a == b && b == a) cout << "Equality test passed\n";
    else cout << "Equality test failed\n";

    Vector na(Point(-1, -2)), ox(Point(1, 0)), nox(Point(-1, 0)), oy(Point(0, 1)), noy(Point(0, -1));
    if (a == -na && na == -a && -ox == nox && -oy == noy) cout << "Invert test passed\n";
    else cout << "Invert test failed\n";

    if (ox + oy + oy == a && -ox == -a + oy + oy) cout << "Summation test passed\n";
    else cout << "Summation test failed\n";

    if (-ox + oy == oy - ox && -oy + ox == ox - oy) cout << "Subtraction test passed\n";
    else cout << "Subtraction test failed\n";

    if (ox * 3 == ox + ox + ox &&
        oy * 3 == oy + oy + oy &&
        ox * (-3) == -ox - ox - ox &&
        oy * (-3) == -oy - oy - oy) cout << "Multiplication by number test passed\n";
    else cout << "Multiplication by number test failed\n";

    if (equal(ox.length(), 1) &&
        equal(oy.length(), 1) &&
        equal((ox * 3 + oy * 4).length(), 5)) cout << "Length test passed\n";
    else cout << "Length test failed\n";

    if (equal(ox * ox, sqr(ox.length())) &&
        equal(oy * oy, sqr(oy.length())) &&
        equal((ox * 3 + oy * 4) * (ox * 3 + oy * 4), sqr((ox * 3 + oy * 4).length()))) cout << "Multiplication by Vector test passed\n";
    else cout << "Multiplication by Vector test failed\n";
}

bool equal(double a, double b, double e) {
    if (-e < a - b && a - b < e) return true;
    else return false;
}

double sqr(double a) {
    return a * a;
}
