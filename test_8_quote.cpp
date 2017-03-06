#include<iostream>
using namespace std;

void swap(int &p1, int &p2) //此处函数的形参p1, p2都是引用
    { int p; p=p1; p1=p2; p2=p; }

float temp; //定义全局变量temp
float fn1(float r); //声明函数fn1
float &fn2(float r); //声明函数fn2
float fn1(float r) //定义函数fn1，它以返回值的方法返回函数值
{
    temp=(float)(r*r*3.14);
    return temp;
}
float &fn2(float r) //定义函数fn2，它以引用方式返回函数值
{
    temp=(float)(r*r*3.14);
    return temp;
}


int main(){
    //引用的声明方法：类型标识符 &引用名=目标变量名； 
    int a;
    int &ra = a;

    //引用作为参数,使用引用传递函数的参数，在内存中并没有产生实参的副本，它是直接对实参操作；
    int c = 10,d = 20;
    swap(c,d);
    cout << c << " " << d << endl;
    
    //常引用，const 类型标识符 &引用名=目标变量名；
    int b ;
    const int &rb=b;
    //rb=1; //错误
    b = 1; //正确
    cout << "b: " << b << endl;
    cout << "rb: " << rb << endl;

    // 引用作为返回值,形式： 类型标识符 &函数名（形参列表及类型说明）{函数体}

    float aa=fn1(10.0); //第1种情况，系统生成要返回值的副本（即临时变量）
    
    //float &bb=fn1(10.0); //第2种情况，可能会出错（不同 C++系统有不同规定）
    //不能从被调函数中返回一个临时变量或局部变量的引用
    
    float cc=fn2(10.0); //第3种情况，系统不生成返回值的副本
    //可以从被调函数中返回一个全局变量的引用
    
    float &dd=fn2(10.0); //第4种情况，系统不生成返回值的副本
    //可以从被调函数中返回一个全局变量的引用
    
    cout<<"aa: " << aa << "  cc: " <<cc << "  dd: " <<dd<<endl;

    cout << "hello world" << endl;
}
