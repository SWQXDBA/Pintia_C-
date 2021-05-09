#include <string>
#include <iostream>
#include <string>
using namespace std;

///////////////////////提交以下代码段////////////////////////


class MyDate{
private:
    int days [13]{};
    int month;
    int day;
    int year;
    //是否是闰年
    static bool  isRun(int year){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
            return true;
        }
        return false;
    }
public:
    void setDate(int newM, int newD, int newY) {
        //检测是否合法
        if(newM<=0||newD<=0||newM>12){
            month=1,day=1,year=1900;
            return;
        }
        //检测天是否合法
        int date[] = {-1,31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isRun(newY))
            date[2]=29;
        if(day>date[newM]){
            month=1,day=1,year=1900;
            return;
        }
        month=newM,day=newD,year=newY;


        if(isRun(newY))
            days[2]=29;

    }
    MyDate() {
        month=1,day=1,year=1900;
        int date[] = {-1,31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i=0;i<13;i++){
            days[i]=date[i];
        }
        if(isRun(year))
            days[2]=29;
    }
    friend ostream &operator<<(ostream &os, const MyDate &date) {
        //用于输出月份名称
        const string months [] = {"nullptr","January","February","March","April","May","June","July","August","September"
                ,"October","November","December"};
        os << months[date.month] <<" "<< date.day << ", " << date.year;
        return os;
    }
    friend MyDate operator++(MyDate &date,int ){
        MyDate temp(date);
        ++date;
        return temp;
    }
    friend MyDate& operator++(MyDate &date){
        if(isRun(date.year))
            date.days[2]=29;else{
            date.days[2]=28;
        }
        date.day++;
        if(date.day>date.days[date.month]){
            date.month++;
            date.day=1;
        }
        if(date.month>12){
            date.year++;
            date.month=1;
        }

        if(isRun(date.year))
            date.days[2]=29;else{
            date.days[2]=28;
        }
        return date;
    }

    friend MyDate operator+=(MyDate &date,int d){
        for(int i=0;i<d;i++)
            date++;
        return date;
    }
};



///////////////////////提交以上代码段////////////////////////
int main()
{

    int m,d,y;
    MyDate d1,d2,d3;
    cin>>m>>d>>y;
    d1.setDate(m,d,y);

    cout<<(d1+=7);
    cin>>m>>d>>y;
    d2.setDate(m,d,y);

    cin>>m>>d>>y;
    d3.setDate(m,d,y);

    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\n\nd1 += 7 is " << ( d1 += 7 );
    cout << "\n\n d2 is " << d2;
    cout << "\n++d2 is " << ++d2;
    cout << "\n\nTesting the prefix increment operator:\n"<< " d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;
    cout << " d3 is " << d3;
    cout << "\n\nTesting the postfix increment operator:\n"<< " d3 is " << d3 << endl;
    cout << "d3++ is " << d3++ << endl;
    cout << " d3 is " << d3 <<endl;

}