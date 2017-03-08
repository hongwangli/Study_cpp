#include<iostream>
#include<algorithm>
#include<sstream>
#include<algorithm>  // find
#include "myExceptions.h"
using namespace std;

template <class T>
class arrayList{
protected:
    int listSize;
    int arrayLength;
    T * element;
    void checkIndex(int theIndex) const;
public:
    arrayList(int init_capacity );
    ~arrayList(){delete [] element;}
    bool empty()const {return listSize == 0;}
    int size() const {return listSize;}
    int capacity() const {return arrayLength;}
    void insert(int theIndex,const  T& theElement);
    int indexOf(const T& theElement) const;
    T& get(int theIndex) const;
    void erase(int theIndex);
};


template <class T>
arrayList<T>::arrayList(int init_capacity){
    arrayLength = init_capacity;
    element = new T[arrayLength];
    listSize = 0;
};

template<class Ta>
void arrayList<Ta>::erase(int theIndex){
    copy(element + theIndex +1, element + listSize, element + theIndex);
    //listSize--;
    element[--listSize].~Ta(); 
}

template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement){
    //copy_backward(element + theIndex, element +listSize, element + listSize + 1);
    copy(element + theIndex, element +listSize, element + theIndex + 1);
    element[theIndex] = theElement;
    listSize++;
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const{
    int result = find(element, element +listSize, theElement) - element;
    if (result== listSize) result = -1;
    return result;

}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}

template<class T>
T& arrayList<T>::get(int theIndex) const{
    //checkIndex(theIndex);
    T& result = element[theIndex];
    return result;

}

int main(){
    arrayList<int> al(10);
    if (al.empty()) cout << "this is a empty arrayList." << endl;
    else cout << "not a empty arrayList" << endl;
    cout << "arrayList listSize is :" << al.size() << endl;
    al.insert(0,1);
    al.insert(1,3);
    cout << "arrayList capacity is : " << al.capacity() << endl;
    cout << "arrayList size is : " << al.size() << endl;
    al.erase(0);
    
    cout << "al.get(0): " << al.get(0)<< endl;
    cout << "al.get(1): " << al.get(1)<< endl;
    cout << "al.get(2): " << al.get(2)<< endl;

    cout << "after erase arrayList size is : " << al.size() << endl;

    //int index = al.indexOf(4);
    //cout << "the index is " << index << endl;
    //int a = al.get(0);
    //int& b = al.get(0);
    //cout << "b: " << b << endl;
    //cout << "a: " << a << endl;
}
