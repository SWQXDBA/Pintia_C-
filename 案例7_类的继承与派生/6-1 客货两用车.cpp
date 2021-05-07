#include <iostream>
#include <cstdio>
using namespace std;
class CAR{
protected:
    double speed;
public:
    CAR(double sp):speed(sp){
        printf("��������(%g����/Сʱ)\n",speed);
    }

    virtual void Show()const{
        printf("����: %g����/Сʱ\n",speed);
    }
};
class BUS:virtual public CAR{
protected:
    int seat;

public:
    BUS(double speed,int seats):CAR(speed),seat(seats){
        printf("�����ͳ�(%d��)\n",seat);
    }
    virtual void Show()const{
        printf("�ͳ�: %g����/Сʱ, %d��\n",speed,seat);
    }
};
class TRUCK:virtual public CAR{
protected:
    double load;
public:
    TRUCK(double sp, double load) : CAR(sp), load(load) {
        printf("��������(%g��)\n",load);
    }
    virtual void Show()const{
        printf("����: %g����/Сʱ, %g��\n",speed,load);
    }

};
class VAN:public BUS,TRUCK{
public:
    VAN( double speed, int seats, double load) : CAR(speed), BUS(speed, seats), TRUCK(speed, load) {
        printf("�����ͻ����ó�\n");
    }
    void Show()const{
        printf("�ͻ����ó�: %g����/Сʱ, %d��, %g��\n",speed,seat,load);
    };
};



void Test(const CAR &x)
{
    x.Show();
}

int main()
{
    VAN a(80.5, 6, 1.2);
    Test(a);
    return 0;
}