#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Animal{
public:
    void speak(){
        cout<<"animal language!"<<endl;
    }

};
class Cat:public Animal{
private:
    string m_strName;
public:
    Cat(string n):m_strName(n){}
    void print_name(){
        cout<<"cat name: "<<m_strName<<endl;
    }

};
