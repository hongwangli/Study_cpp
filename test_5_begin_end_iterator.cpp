#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ivec(10,1);
    //int *a; a = ivec.begin() //error
    vector<int>::iterator it;
    it = ivec.begin();
    cout << "it: " << *it << endl;
    cout <<"begin: " << *ivec.begin() << endl; // .begin() 类型为迭代器，指向第一个元素的指针
    cout << "end: " << *ivec.end() << endl; // .end() 类型为迭代器，指向最后一个元素的下一个元素 
    for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter){
        *iter=2; //使用 * 访问迭代器所指向的元素
        cout << "iter: "<< *iter << endl;
    }
}
