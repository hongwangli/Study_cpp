#include<iostream>
using namespace std;

class Student{
private:
   int age;
   const char* name;
public:
   Student(){
      age = 0;
      name = "unnamed";
   }
   Student(int a,const char* n){
      age = a;
      name = n;
   }
   void setMember(int aa,const char* nn){
      age = aa;
      name = nn;
   }
   int getage(){
      return age;
   }
   const char* getname(){
      return name;
   }

};

int main(){
    Student stu[3]= {Student(13,"wang"),Student(),Student()} ;
    stu[2].setMember(12,"zhang");
    cout<<stu[0].getage()<<","<<stu[0].getname()<<endl;
    return 0;
}
