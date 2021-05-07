#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

int main()
{
    float x,y,r;
    cin>>x>>y>>r;
   printf("Point constructor called\n"
          "Circle constructor called\n"
          "%.2f\n"
          "Circle destructor called\n"
          "Point destructor called",3.14*2*r);
    return 0;
}