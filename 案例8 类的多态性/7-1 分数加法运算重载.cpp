
///////////////////////提交以下代码段////////////////////////
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class FS{
public:
    int fz;
    int fm;
    FS operator + (const FS &f){
        //获取两个分母的最小公倍数 作为新的分母
        int newfm = getmin(f.fm,this->fm);
        //分子=分子*（新的分母与旧的分母的倍数）  就是分子分母同时扩大n倍
        this->fz=this->fz*(newfm/this->fm);
        //加数的分子同样需要扩大
        this->fz+=f.fz*(newfm/f.fm);
        //分母变成新的分母
        this->fm=newfm;
        //分子分母同时除以公因数
        int m;
        m=getmax(fz,fm);
        fz/=m;
        fm/=m;
        //置换负号
        if(!(fz<0&&fm<0)){
            if (fz<0||fm<0){
                fz=abs(fz);
                fz*=-1;
                fm=abs(fm);
            }
        }
        //需要解引用
        return *this;
    }
    FS(int fz, int fm) : fz(fz), fm(fm) {}

    friend ostream &operator<<(ostream &os, const FS &fs) {
        os << fs.fz << "z" << fs.fm<<"m";
        return os;
    }

private:
    //获得最小公倍数
    static int getmin(int a,int b){
        int nunm1=a,nunm2=b;
        int r;
        while(b!=0)
        {
            r= a % b;
            a = b;
            b = r;
        }

        return nunm1*nunm2/a;
    }
    //获得最大公因数
    static int getmax(int a,int b){
        int r;
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
};
int main(){
    int cnt;
    cin>>cnt;
    while(cnt--){
        int z,m;
        scanf("%dz%dm",&z,&m);
        FS fs1(z,m);
        scanf("%dz%dm",&z,&m);
        FS fs2(z,m);
        cout<<fs1+fs2<<endl;
    }


}
///////////////////////提交以上代码段////////////////////////