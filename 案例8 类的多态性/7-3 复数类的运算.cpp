
///////////////////////提交以下代码段////////////////////////
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class Complex
{
public:
    Complex(double r=0, double i=0):real(r), imag(i){    }
    Complex operator+(const Complex &c) const;//重载双目运算符'+'
    Complex operator-=(const Complex &c); //重载双目运算符'-='
    friend Complex operator-(const Complex &c1,const Complex &c2) ;//重载双目运算符'-'
    void Display() const;
private:
    double real;
    double imag;
};

void Complex::Display() const
{
    cout << "(" << real << ", " << imag << ")" << endl;
}

Complex Complex::operator+(const Complex &c) const {
    Complex t(this->real,this->imag);
    t.real+=c.real;
    t.imag+=c.imag;

    return t;
}

Complex Complex::operator-=(const Complex &c) {
    this->real-=c.real;
    this->imag-=c.imag;
    return *this;
}

Complex operator-(const Complex &c1, const Complex &c2) {
    Complex t(c1.real,c1.imag);
    t.real-=c2.real;
    t.imag-=c2.imag;

    return t;
}


int main()
{
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1+c2;
    c3.Display();
    c3 = c1-c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}
///////////////////////提交以上代码段////////////////////////