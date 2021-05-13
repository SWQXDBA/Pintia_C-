#include <iostream>
#include <cmath>
using namespace std;

class shape {// 形状类
public:
    double getArea()  // 求面积
    {return -1;}
    double getPerimeter() // 求周长
    {return -1;}
};
///////////////////////提交以下代码段////////////////////////
class RegularPolygon:public shape{
    double n;
    double s;
public:
    RegularPolygon(double n, double s) : n(n), s(s) {}
    double getArea() {
        return n*s*s/(tan(3.1415926/n)*4);
    }
    double getPerimeter(){
        return  n*s;
    }
};
///////////////////////提交以上代码段////////////////////////
int main()
{
    int n;
    double s;

    cin>>n>>s;
    RegularPolygon p(n,s);
    cout<<p.getArea()<<endl;

    cout<<p.getPerimeter()<<endl;

    return 0;
}