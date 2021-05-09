#include <iostream>
using namespace std;
const double PI=3.14;

class Shape {
public:
    virtual double getArea()=0;
    virtual double getPerim()=0;
};

///////////////////////提交以下代码段////////////////////////
class Rectangle: public Shape {

    float  length;
    float  wide;
public:
    Rectangle(float length, float wide) : length(length), wide(wide) {}
    double getArea() override {
        return length*wide;
    }

    double getPerim() override {
        return 2*(length+wide);
    }


};
class Circle:public Shape{
    float redius;
public:
    explicit Circle(float redius) : redius(redius) {}

    double getArea() override {
        return PI*redius*redius;
    }

    double getPerim() override {
        return 2*PI*redius;
    }

};
void print(Shape *pShape) {
    printf("Area:%g\n"
           "Perimeter:%g\n",pShape->getArea(),pShape->getPerim());
}
///////////////////////提交以上代码段////////////////////////

int main(){
    double r,l,w;
    cin>>r;
    cin>>l>>w;
    Shape *p=NULL;
    p=new Circle(r);
    print(p);//输出圆面积与周长
    p=new Rectangle(l,w);
    print(p);//输出矩形面积与周长
    return 0;
}


