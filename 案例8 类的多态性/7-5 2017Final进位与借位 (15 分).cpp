#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;

int forgetSub(int x, int y) {

    ///题目规定被减数比减数大 所以不考虑减数比被减数长的情况
    //把x转成字符串
    string str = to_string(x);
    char *chars = new char[str.length()+1];
    strcpy(chars, str.c_str());
    //把y转成字符串
    string str2 = to_string(y);
    char *chars2 = new char[str.length()+1];
    //减数可能会比被减数短，此时先把减数数组初始化为0；
    for (int i = 0; i < str.length(); i++)
        chars2[i] = '0';
    //chars2+str.length()-str2.length()表示跳过差值部分 如
    //   11111
    //  -   21
    //此时先初始化减数数组为00000
    //然后先跳过差值3的地址，达到减数的‘2’
    //拷贝后变成00021;
    strcpy(chars2 + str.length() - str2.length(),  str2.c_str());

    //创建用于储存结果的数组
    int *result = new int[str.length()];
    for (int i = 0; i <= str.length()-1; i++) {
        result[str.length()-1-i] = chars[i] - chars2[i];
        //如果被减数大于减数则正常，否则结果+10模拟借位。
        if (result[str.length()-1-i] < 0)
            result[str.length()-1-i] += 10;

    }
    int ret = 0;
    //把数组转换成int
    for (int i = str.length() - 1; i >= 0; i--) {
        ret += result[i];
        if (i != 0)
            ret *= 10;
    }
    delete [] chars;
    delete [] chars2;
    return ret;
}

int forgetAdd(int x, int y) {

    //同理 先转化成数组
    string s1 = to_string(x);
    string s2 = to_string(y);
    string str = s1.length()>=s2.length()?s1:s2;
    string str2 = str==s1?s2:s1;
    //此时str的长度一定大于等于str2的
    //获取更长的那一个

    char *chars = new char[str.length()+1];
    strcpy(chars,str.c_str());
    char *chars2 = new char[str.length()+1];

    for (int i = 0; i < str.length(); i++)
        chars2[i] = '0';


    strcpy(chars2 + str.length() - str2.length(), str2.c_str());

    //创建用于储存结果的数组
    int *result = new int[str.length()];
    for (int i = 0; i <= str.length()-1; i++) {
        result[str.length()-1-i] = chars[i]-'0' + chars2[i]-'0';

        if (result[str.length()-1-i] >=10)
            result[str.length()-1-i] %=10;

    }
    int ret = 0;
    //把数组转换成int
    for (int i = str.length() - 1; i >= 0; i--) {
        ret += result[i];
        if (i != 0)
            ret *= 10;
    }
    delete [] chars;
    delete [] chars2;
    return ret;
}

class Group {
public:

    virtual int add(int x, int y) = 0;//输出加法的运算结果

    virtual int sub(int x, int y) = 0;//输出减法的运算结果

};

//正确地完成三位整数加减法
class GroupA : public Group {
public:
    int add(int x, int y) override {
        return x + y;
    }

    int sub(int x, int y) override {
        return x - y;
    }
};

//可以正确地完成三位整数的加法，但对于减法运算来说，总是忘记借位的处理
class GroupB : public Group {
public:

    int add(int x, int y) override {
        return x + y;
    }

    int sub(int x, int y) override {
        return forgetSub(x, y);
    }

};

//总是忘记加法的进位，也总是忘记减法的借位
class GroupC : public Group {
public:
    int add(int x, int y) override {
        return forgetAdd(x, y);
    }

    int sub(int x, int y) override {
        return forgetSub(x, y);
    }
};

int main(){


    int studentNum;
    cin >> studentNum;
    int *type= new int[studentNum];
    for(int i=0;i<studentNum;i++){
        cin>>type[i];
    }
    int stu=-1;
    while(true){
        cin>>stu;
        if(stu==0)
            break;
        int t = type[stu-1];
        Group *g=nullptr;
        if(t==1)
            g = new GroupA();
        else if(t==2)
            g = new GroupB();
        else if(t==3)
            g = new GroupC();

        char f;
        int x,y;
        cin>>x>>f>>y;
        int result;
        if(f=='+'){
            result= g->add(x,y);
        }else{
            result=  g->sub(x,y);
        }
        printf("%d\n",result);


    }
}