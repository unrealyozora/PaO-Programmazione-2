/* 
Write a C++ program to implement a class called Shape with virtual member functions for calculating area and perimeter. 
Derive classes such as Circle, Rectangle, and Triangle from the Shape class and override virtual functions accordingly.
*/

#include <iostream>
#include <cmath>
using namespace std;
const double pi= 3.14159265358979323846;
class Shape{
    public:
        virtual double Area() const = 0;
        virtual double Perimeter() const = 0;
};

class Rectangle: public Shape{
    private:
        double base;
        double height;
    public:
        Rectangle(double b=1.0, double h=1.0): base(b), height(h){};
        double Area() const override{
            return base*height;
        }
        double Perimeter() const{
            return (2*base)+(2*height);
        }
};


class Triangle: public Shape{
    private:
        double l1;
        double l2;
        double l3;
    public:
        Triangle(double lato1=1.0, double lato2=1.0, double lato3=1.0): l1(lato1), l2(lato2), l3(lato3){};
        double Area() const{
            double s=(l1+l2+l3)/2;
            return sqrt((s*(s-l1)*(s-l2)*(s-l3)));
        }
        double Perimeter() const{
            return l1+l2+l3;
        }
};

class Circle: public Shape{
    private:
        double radius;
    public:
        Circle (double r=1.0): radius(r){};
        double Area() const override {
            return radius*radius*pi;
        }
        double Perimeter() const override{
            return 2*pi*radius;
        }
};


int main(){
    Rectangle prova1 (2.5, 6.7);
    Triangle prova1 (4.5, 6.7);
    Circle prova (4.5);
    cout << prova1.Area();
}



