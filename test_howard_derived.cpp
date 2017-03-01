#include<iostream>

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
        string getname(){
            return basename;
        }
        int getdata(){
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

        string getDerivedName(){
            return derivedName;
        }
};

int main(){
    base b;
    cout << " name: " << b.getname() << "  basedata: " << b.getdata() << endl;
    base c("howard",28);
    cout << " name: " << c.getname() << "  basedata: " << c.getdata() << endl;
    derived d;
    cout << "base name: " << d.getname()<< " basedata: " << d.getdata()
         << " derivedname: " << d.getDerivedName() << endl;
    derived dd("howard",28,"hongwang");
    cout << "base name: " << dd.getname()<< " basedata: " << dd.getdata()
         << " derivedname: " << dd.getDerivedName() << endl;
    return 0;
}
