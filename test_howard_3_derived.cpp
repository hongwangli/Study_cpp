#include<iostream>
#include<stdio.h>
using namespace std;

class base{
    private:
        string basename;
        int basedata;
    public:
        base():basename("unname"),basedata(0)
        {}
        base(string bn, int bd):basename(bn),basedata(bd)
        {}
        string getname()  {
            return basename;
        }
        int getdata()  {
            return basedata;
        }
};

class derived:public base{
    private:
        string derivedName;
    public:
        derived():base(),derivedName("unnamed derived")
        {}
        derived(string bn,int bd,string dn):base(bn,bd),derivedName(dn)
        {}
        derived(string bn,int bd):base(bn,bd)
        {}
        string getDerivedName() {
            return derivedName;
        }
};


//void show(string& info, derived& b) 
void show(string& info, base& b) 
//派生类的对象同时是类型为基类的对象，相反则不成立
//即派生类对象同时属于基类和派生类。基类对象类型只能是基类
{
    info.append("Name is ");
    info.append(b.getname());
    info.append(", baseData is ");
    char buffer[10];
    sprintf(buffer,"%d",b.getdata());
        info.append(buffer);
}


int main(){
    string s;
    base bb("howard",28);
    show(s,bb);
    cout << s << endl;

    derived d("howard",28);
    string ss;
    show(ss,d);
    cout << ss << endl;
    //cout << b.getname() << endl;
    //cout << " name: " << b.getname() << "  basedata: " << b.getdata() << endl;
    //base c("howard",28);
    //cout << " name: " << c.getname() << "  basedata: " << c.getdata() << endl;
    //derived d;
    //cout << "base name: " << d.getname()<< " basedata: " << d.getdata()
    //     << " derivedname: " << d.getDerivedName() << endl;
    //derived dd("howard",28,"hongwang");
    //cout << "base name: " << dd.getname()<< " basedata: " << dd.getdata()
    //     << " derivedname: " << dd.getDerivedName() << endl;
    return 0;
}
