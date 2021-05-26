#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;
#define PI  3.14159
//////////////////////////////////
//////////////////题目中未指定精度，不必过于纠结////////////////
///////////////////////////////////////
/////////////////////////////////////////

class CPoint{
    double x;
    double y;
public:
    CPoint(double x, double y) : x(x), y(y) {}

    virtual double GetArea() = 0;
    virtual double GetVolume()=0;
    void print(){
        printf("Center:(%g,%g)\n",x,y);
    }
};
class Cirle: public CPoint{
protected:
    double radius;
public:
    Cirle(double x, double y, double radius) : CPoint(x, y), radius(radius) {}
    double GetArea() override{
        return PI*radius*radius;
    }
    virtual double GetVolume()=0;
    void print(){
        CPoint::print();
        printf("radius=%g\n",radius);
    }
};
class Ccylinder: public Cirle{
    double height;
public:
    Ccylinder( double x, double y, double radius, double height) :  Cirle(x, y, radius),height(height) {}

public:
    double GetArea() override{
        double area = 0;
        area+=Cirle::GetArea()*2;
        area+=radius*PI*2*height;
        return area;
    }
    double GetVolume()override{
        return Cirle::GetArea()*height;
    }
    void print(){
        Cirle::print();
        printf("height:%g\n",height);
        printf("BasalArea:%g\n"
               "SupfaceArea:%g\n"
               "Volume:%g\n",Cirle::GetArea(),GetArea(),GetVolume());
    }
};
int main(){
    double x,y,r,h;
    cin>>x>>y>>r>>h;
    auto* c = new Ccylinder(x,y,r,h);
    c->print();

}