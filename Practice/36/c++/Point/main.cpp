#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
const auto PI = 3.141592653589793;

enum coord_system{Cartesian,Polar};

class Point{

private:
    double x;
    double y;

 public:
    double ra1,ra2;

    Point(double a1 = 0  ,double a2 = 0 , coord_system sys = Cartesian){

        if(sys == Cartesian){
            this->x=a1;
            this->y=a2;
        }
         else {
              x = a1*cos(a2);
              y = a1*sin(a2);
            }
        }
     ~Point() {};
     double get_r()
    {
        double r = pow(((x*x)+(y*y)),1/2);
        return r;
    }
    double get_phi()
   {
       double phi = atan2(y,x);
       return phi;
   }
     double get_x()
    {
        return x;
    }
      double get_y()
    { 
        return y;
    }
      void set_r(double r)
      {
          double ph = get_phi();
          x=  r *cos(ph);
          y =  r *sin(ph);
      }
      void set_phi(double ph)
      {

          double ra = get_r();
          x = ra *cos(ph);
          y = ra * sin(ph);
      }
    void set_x(double a1_)
    {
        this->x=a1_;

    }
    void set_y(double a2_)
    {
        this->y=a2_;

    }

    bool operator==(Point p ) {
        if (fabs(this->x-p.x) < exp(-10) && (fabs(this->y-p.y) < exp(-10)))
            return true;
        else
            return false;
    }
    bool operator!=(Point p){

        return (!(*this == p)) ? true : false;

    }
    friend std::istream& operator >> (std::istream& in, Point& p) {

        in.ignore(1);
        in >> p.x;
        in.ignore(1);
        in >> p.y;
        in.ignore(1);

        return in;
    }
    friend std::ostream& operator << (std::ostream& out, Point& p) {

        out << "(" << p.x << ", " << p.y << ")  ";

        return out;



    }

};


int main() {
    std::vector<Point> original;
    std::ifstream fin("C:/Users/Mary/Desktop/Programming/Practice/36/c++/Point");
    if (!fin.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    } else {
        while (!fin.eof()) {
            Point p;
            fin >> p;
            fin.ignore(2); // Точки разделены двумя символами ", "
            original.push_back(p);
        }
        fin.close();
    }

    std::vector<Point> simulacrum(original);
    for (auto& p : simulacrum) {
        std::cout << p;
        p.set_x(p.get_x() + 10);
        p.set_phi(p.get_phi() + 180*PI/180);
        p.set_y(-p.get_y());
        p.set_x(-p.get_x() - 10);
        std::cout << p << std::endl;
    }

    if (std::equal(original.begin(), original.end(), simulacrum.begin()))
        std::cout << "\nIt works!\n";
    else
        std::cout << "\nIt not works!\n";
}
