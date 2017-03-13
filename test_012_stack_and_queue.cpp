#include<iostream>
#include<algorithm>
#include "myExceptions.h"
#include <sstream>
using namespace std;

template <class T>
class stack{
protected:
    int length;
    int capacity;
    T * element;
public:
    stack(int capacity);
    bool empty(){return length==0;}
    int const size(){return length;}
    void insert(T theElement, int index);
    void erase(int theIndex);
    void push(T theElement);
    void pop();
    T & top();
    T & front();
    void output();
    void pop_queue();
};
 
template <class T>
void stack<T>::pop_queue(){
    copy(element + 1, element + length,element);
    element[--length].~T();

}

template <class T>
stack<T>::stack(int initcapacity = 10){
    capacity = initcapacity;
    element = new T[capacity];
    length = 0;
}

template<class T>
void stack<T>::insert(T theElement, int index){

   if (index < 0 || index > length)
   {// invalid index
        ostringstream s;
        s << "index = " << index << " size = " << length;
        throw illegalIndex(s.str());
   } 
    copy(element + index, element + length, element + index + 1);
    element[index] =   theElement;
    length++;

}

template<class T>
void stack<T>::erase(int theIndex){
    copy(element + theIndex + 1, element + length, element + theIndex);
    element[--length].~T();

}

template<class T>
void stack<T>::push(T theElement){
    element[++length] = theElement;
}

template<class T>
void stack<T>::pop(){
    //this->erase(length);
    element[--length].~T();

}

template <class T>
T & stack<T>::top(){
    return element[length-1];
}


template <class T>
void stack<T>::output(){

    for (int i = 0 ; i < length ; i++){
        cout << element[i] << " " ;
    }
    cout << endl;
}

template <class T>
T & stack<T>::front(){
   return element[0];     
}

int main(){
    cout << "hello word! " << endl;
    
    stack<int> ss(10);
    cout << ss.size() << endl;

    ss.insert(1,0);
    ss.insert (2,1);
    ss.insert(3,0);
    ss.push(4);
    ss.pop();
    cout << "output of ss :";
    ss.output() ;
    cout << endl;;
    ss.pop_queue();
    cout << "output of ss :";
    ss.output();
    cout << endl;;
    cout << "ss top is : " << ss.top() << endl;
    cout << "ss front is : " << ss.front() << endl;

    if (ss.empty()){
        cout << "s is empty! " << endl;
    }
    else {
        cout << "s size: "  << ss.size() << endl;
    }

    cout << "s size: "  << ss.size() << endl;

    return 0;

}
