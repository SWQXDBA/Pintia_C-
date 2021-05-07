#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
class Animal{
private:
    int m_nWeightBase;
protected:
    int m_nAgeBase;
public:
    void set_weight(int w){
        m_nWeightBase=w;
    }
    void set_age(int a){
        m_nAgeBase=a;
    }
    int get_weight(){
        return m_nWeightBase;
    }
};
class Cat: public Animal{
private:
    string m_strName;
public:
    Cat(const string &mStrName) : m_strName(mStrName) {}
    void   print_age(){
        printf("%s, age = %d\n",m_strName.c_str(),m_nAgeBase);
    }
};
