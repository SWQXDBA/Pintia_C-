#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

class Person
{
protected:
    int NO;//编号
public:
    virtual void display()=0;//输出相关信息
};
class Student:public Person{
    int sorces[5];
    int quekao=0;
    float sum=0;
public:
    Student(int num, int s1,int s2,int s3,int s4,int s5) :Person(){
        NO=num;
        int cnt=0;
        sorces[0]=s1;
        sorces[1]=s2;
        sorces[2]=s3;
        sorces[3]=s4;
        sorces[4]=s5;
        for(int i:sorces){
            if(i==-1)
                quekao++;
            else{
                cnt++;
                sum+=i;
            }

        }
        sum/=cnt;

    }

    void display() override {
        if(quekao!=5)
            printf("%d %d %.1f\n",NO,quekao,sum);
        else
            printf("%d %d\n",NO,quekao);
    }
};
class Teacher:public Person{
    int n1;
    int n2;
    int n3;
public:
    Teacher(int N, int n1, int n2, int n3) :Person(), n1(n1), n2(n2), n3(n3) {
        NO=N;
    }
    void display() override {
        printf("%d %d\n",NO,n1+n2+n3);
    }
};
int main(){
    Person *PP[10]={NULL};
    int flag = 1;
    int size=0;
    while(flag!=0){
        cin>>flag;
        if(flag==1) {
            int N;
            int s1, s2, s3, s4, s5;
            cin >> N >> s1 >> s2 >> s3 >> s4 >> s5;
            PP[size] = new Student(N, s1, s2, s3, s4, s5);
            size++;
        }else if(flag==2){
            int N;
            int s1, s2, s3;
            cin >> N >> s1 >> s2 >> s3 ;
            PP[size] = new Teacher(N, s1, s2, s3);
            size++;
        }else
            break;

    }
    for(Person  *person:PP){
        if(person!=nullptr){
            person->display();
        }else
            break;
    }
    return 0;

}