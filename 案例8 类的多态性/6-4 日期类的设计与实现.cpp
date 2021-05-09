#include <string>
#include <iostream>
#include <string>
using namespace std;

///////////////////////提交以下代码段////////////////////////
 const string months [] = {nullptr,"January","February","March","April","May","June","July","August","September"
                                 ,"October","November","December"};
class MyDate{
private:
    int days [] = {-1,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month;
    int day;
    int year;
    static bool  isRun(int year){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ){
            return true;
        }
        return false;
    }
public:
    MyDate(int month, int day, int year) : month(month), day(day), year(year) {}

    void setDate(int i, int i1, int i2) {
        month=i,day=i1,year=i2;
    }

    MyDate() {
        month=1,day=1,year=1900;
    }

    friend ostream &operator<<(ostream &os, const MyDate &date) {
        os << months[date.month] <<" "<< " day: " << date.day << ", " << date.year;
        return os;
    }
    friend MyDate&  operator++(MyDate &date,int ){
        MyDate temp(date);
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
        if(isRun(date.year))
            date.days[2]=29;else{
            date.days[2]=28;
        }
        date.day+=d;
        if(date.day>date.days[date.month]){
            date.month+;
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
    }
};



///////////////////////提交以上代码段////////////////////////
int main()
{
    int m,d,y;
    MyDate d1,d2,d3;
    cin>>m>>d>>y;
    d1.setDate(m,d,y);

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