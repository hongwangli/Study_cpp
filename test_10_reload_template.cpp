#include<iostream>
using namespace std;

int sum(int a,int b){
    return a + b;
}

int sum (int a, int b, int c){
    return a + b + c;
}

float sum (int a, float b){
    return a + b;
}

template <class T>
T sum_2(T a, T b){
    return a + b;
}

int main(){
    int aa = 1, bb = 2, cc = 3, dd = 4;
    int ee = sum(aa,bb);
    cout << "ee: " << ee << endl;

    int ff = sum (aa,bb,cc);
    cout << "ff: " << ff << endl;

    float d = 2.3, c = 4.6;
    float gg = sum (aa,d);
    cout << "gg: " << gg << endl;

    float hh = sum_2(c,d);
    cout << "hh: " << hh << endl;

    int kk = sum_2(aa,bb);
    cout << "kk: " << kk << endl;
    cout << "hello: " << endl;
    return 0;
}
