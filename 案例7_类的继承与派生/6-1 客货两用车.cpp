#include <iostream>
#include <cstdio>
using namespace std;
class CAR{
protected:
    double speed;
public:
    CAR(double sp):speed(sp){
        printf("创建汽车(%g公里/小时)\n",speed);
    }

    virtual void Show()const{
        printf("汽车: %g公里/小时\n",speed);
    }
};
class BUS:virtual public CAR{
protected:
    int seat;

public:
    BUS(double speed,int seats):CAR(speed),seat(seats){
        printf("创建客车(%d人)\n",seat);
    }
    virtual void Show()const{
        printf("客车: %g公里/小时, %d人\n",speed,seat);
    }
};
class TRUCK:virtual public CAR{
protected:
    double load;
public:
    TRUCK(double sp, double load) : CAR(sp), load(load) {
        printf("创建货车(%g吨)\n",load);
    }
    virtual void Show()const{
        printf("货车: %g公里/小时, %g吨\n",speed,load);
    }

};
class VAN:public BUS,TRUCK{
public:
    VAN( double speed, int seats, double load) : CAR(speed), BUS(speed, seats), TRUCK(speed, load) {
        printf("创建客货两用车\n");
    }
    void Show()const{
        printf("客货两用车: %g公里/小时, %d人, %g吨\n",speed,seat,load);
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