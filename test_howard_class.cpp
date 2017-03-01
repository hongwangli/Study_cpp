#include<iostream>
using namespace std;

class Point{
public: 
    //void setPoint(int x, int y){
    //    xpos = x;
    //    ypos = y;
    //}
    Point(int x, int y){
        xpos = x;
        ypos = y;
    }
    void printPoint(){
        cout << "x = " << xpos << endl;
        cout << "y = " << ypos << endl;
    } 
private:
    int xpos;
    int ypos;
};

int main(){
    Point p(3,5);
    p.printPoint();

    return 0;
}
