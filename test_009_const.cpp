#include<iostream>
using namespace std;

void testModifyConst(const int _x) {
 //_x=5;//编译出错
 cout << "hello" << endl;
 }

class Point{
    public :
    Point(int _x):x(_x){}

    void testConstFunction(int _x) const{
        //错误，在const成员函数中，不能修改任何类成员变量
        //x=_x;
        
        //错误，const成员函数不能调用非const成员函数，因为非const成员函数可以会修改成员变量
        //modify_x_2(_x);
        
        // modify_x 使用const修饰了 因此能够调用
        modify_x(_x);

        cout << "this is a test message." << endl;
    }

    void modify_x(int _x) const {
        //x=_x;
        cout << "this is a const function _x is : " << _x << endl;
        cout << "this is a const function  x is : " << x << endl;
    }

    void modify_x_2(int _x) {
        x=_x;
        cout << "this is not a const function x is : " << x << endl;
    }

    int x;
};


const int * mallocA(){  ///const data,non-const pointer
    int *a=new int(2);
    cout << "const embellish the return value of a function " << endl;
    cout << "in mallocA funciton a is : " << *a << endl;
    return a;
}


int main(){
    int a1=3;   ///non-const data
    a1 = 4;
    int a11 = 6;

    const int a2=a1;    ///const data
    //a2 = 4; //编译错误
    int const a22=a1;    ///const data
    //a22 = 5;

    int * a3 = &a1;   ///non-const data,non-const pointer

    const int * a4 = &a1;   ///const data,non-const pointer
    a1 = 5;
    a4 = &a11;
    cout << "const int * a4 : " << *a4 << endl;

    int * const a5 = &a1;   ///non-const data,const pointer
    //a5 = &a11;
    a1 = 9; 

    int const * const a6 = &a1;   ///const data,const pointer
    //a6 = &a11;
    a1 = 7;

    const int * const a7 = &a1;   ///const data,const pointer
    //a7 = &a11;
    a1 = 8; 

    Point p(3); 
    p.testConstFunction(4); // 用const修饰 所以不能修改 x的值
    p.modify_x_2(5);
    p.modify_x(6); //

    const int *a = mallocA();

    cout << "const int * a: " << *a << endl;
    //int *b = malloA(); //编译错误
    
    return 0;
}



