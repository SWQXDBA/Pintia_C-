#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
//class Student
//{public:
//    Student(int n,string nam,char s )
//    {num=n;
//        name=nam;
//        sex=s; }
//    ~Student( ) { }
//protected:
//    int num;
//    string name;
//    char sex ;
//};
class Student1: public Student{
private:
    int age;
    string address;
public:
    Student1(int n, const string &nam, char s, int age, const string &address) : Student(n, nam, s), age(age),
                                                                                 address(address) {}
    void show(){
        printf("num: %d\n"
               "name: %s\n"
               "sex: %c\n"
               "age: %d\n"
               "address: %s\n\n",num,name.c_str(),sex,age,address.c_str());
    }
};