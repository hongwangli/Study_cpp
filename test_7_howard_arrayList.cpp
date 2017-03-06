#include<iostream>
#include<algorithm>
#include<sstream>
#include<algorithm>  // find
using namespace std;

template <class T>
class arrayList{
protected:
    int listSize;
    int arrayLength;
    T * element;
public:
    arrayList(int init_capacity );
    ~arrayList(){delete [] element;}
    bool empty()const {return listSize == 0;}
    int size() const {return listSize;}
    int capacity() const {return arrayLength;}
    void insert(int theIndex,const  T& theElement);
    int indexOf(const T& theElement) const;
    T& get(int theIndex) const;
};

template <class T>
arrayList<T>::arrayList(int init_capacity){
    arrayLength = init_capacity;
    element = new T[arrayLength];
    listSize = 0;
};

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
T& arrayList<T>::get(int theIndex) const{

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
    cout << "hello " << endl;
    int index = al.indexOf(4);
    cout << "the index is " << index << endl;
    int a = al.get(0);
    int& b = al.get(0);
    cout << "b: " << b << endl;
    cout << "a: " << a << endl;
}
