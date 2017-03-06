#include <iostream>
#include <stdio.h>
using namespace std;
class base
{
    public:
        std::string basePublic()
        {
            return std::string("this is public base");
        }
    protected:
        std::string baseProtected()
        {
            return std::string("this is protected base");
        }
    private:
        std::string basePrivate()
        {
            return std::string("this is private base");
        }
};

class derived:public base
{
    public:
        std::string derivedPubPublic()
        {
            return basePublic()+= " in derived public inherit base public";
        }
        
        std::string derivedPubProtected()
        {    
            return baseProtected()+= " in derived public inherit base protected";
        }

        //string derivedPubPrivate(){
        //    return basePrivate() += " in derived public inherit base private";
        //}
    protected:
        string derivedProPublic(){
            return basePublic() += " in derived protected inherit base public"; 
        }
        string derivedProProtected(){
            return baseProtected() += " in derived protected inherit base protected"; 
        }
        //string derivedProPrivate(){
        //    return basePrivate() += " in derived protected inherit base private"
        //}
    private:
        string derivedPriPublic(){
            return basePublic() += " in derived private inherit base public"; 
        }
        string derivedPriProtected(){
            return baseProtected() += " in derived private inherit base protected"; 
        }
        //string derivedPriPrivate(){
        //    return basePrivate() += " in derived private inherit base private"; 
        //}
};

class deepDerived:public derived{
    public:
        string deepDerivedPublic(){
            return derivedPubPublic() += " in deep derived public inherit from ";
        }
        string deepDerivedProtected(){
            return derivedPubProtected() += " in deep derived ";
        }
};

int main(int argc,char* argv[])
{
    base b;
    cout << "base:" << b.basePublic() << endl;
    //基类对象不能访问基类的protected成员
    //cout << b.baseProtected() << endl;
    //cout << b.basePivate() << endl;
    
    derived dpub;
    cout << "derived access base public :" << dpub.basePublic() << endl;
    //cout << "derived access base protected: " << dpub.baseProtected() << endl;

    cout << "derived PubPublic:" << dpub.derivedPubPublic() << endl; 
    //在派生类内部直接访问protected成员和访问派生类对象public继承访问基类的protected成员都是可行的。
    cout << "derived PubProtected: " << dpub.derivedPubProtected() << endl; 
    
    //cout << "derived ProPublic: " << dpub.derivedProPublic() << endl;
    //cout << "derived ProProtectd: " << dpub.derivedProProtected() << endl;
    
    //cout << "derived priPublic: " << dpub.derivedPriPublic() << endl;
    //cout << "derived priProtected: " << dpub.derivedPriProtected() << endl;


    //deepDerived dd;
    //cout << "deepDerived basePublic: " << dd.basePublic() << endl;
    //cout << "deepDerived deepDerivedPublic: " << dd.deepDerivedPubPublic() << endl;
    //cout << "deepDerived deepDerivedProtected: " << dd.deepDerivedPubProtected() << endl;
}


