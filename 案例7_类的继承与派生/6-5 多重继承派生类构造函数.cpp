#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
//class Teacher
//{public:
//    Teacher(string nam,int a,string t)
//    {name=nam;
//        age=a;
//        title=t;}
//    void display()
//    {cout<<"name:"<<name<<endl;
//        cout<<"age"<<age<<endl;
//        cout<<"title:"<<title<<endl;
//    }
//protected:
//    string name;
//    int age;
//    string title;
//};
//
//class Student
//{public:
//    Student(string nam,char s,float sco)
//    {name1=nam;
//        sex=s;
//        score=sco;}
//    void display1()
//    {cout<<"name:"<<name1<<endl;
//        cout<<"sex:"<<sex<<endl;
//        cout<<"score:"<<score<<endl;
//    }

//protected:
//    string name1;
//    char sex;
//    float score;
//};
class Graduate:public Teacher,public Student{
private:
    float wage;
public:

    Graduate(const string &name,int age,char sex,const string &title,float score,float wages):Teacher(name,age,title),
    Student(name,sex,score),wage(wages){}
    void show(){
        printf("name:%s\n"
               "age:%d\n"
               "sex:%c\n"
               "score:%g\n"
               "title:%s\n"
               "wages:%g\n",name.c_str(),age,sex,score,title.c_str(),wage);
    }
};