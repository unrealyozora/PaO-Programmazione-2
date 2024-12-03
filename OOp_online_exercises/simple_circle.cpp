#include <iostream>
using namespace std;
const double pi= 3.14159265358979323846;
class Circle{
    private:
        double radius;
    public:
        Circle (double r=1.0): radius(r){};
        double area() const;
        double circumference() const;
};

double Circle::area() const{
    return (radius*radius*pi);
}

double Circle::circumference()const{
    return (2*pi*radius);
}

int main(){
    Circle prova(5.67);
    cout<<"L'area del cerchio è " << prova.area()<<endl;
    cout<<"La circonferenza del cerchio è " << prova.circumference();
}
