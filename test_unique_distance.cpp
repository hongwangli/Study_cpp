#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance
#include <vector>       // std::vector
#include<list>
using namespace std;
bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10);

  list<int>::iterator first = mylist.begin();
  list<int>::iterator last = mylist.end();

  cout << "The distance is: " << distance(first,last) << '\n';

  int myints[] = {10,20,20,20,30,30,20,20,10,40};           // 10 20 20 20 30 30 20 20 10
  vector<int> myvector (myints,myints+10);
  vector<int>::iterator it;
  it = unique (myvector.begin(), myvector.end()); // it 为最后一个元素的下一个元素的指针
  
  cout << "it: " << *it << endl;
  for (int i =0; i < 10 ; i++){
    cout << "myvector: " << myvector[i] << endl;
  }
  cout << "myvector begin: " << *myvector.begin() << endl;
  cout << "it: " << *it << endl;
  int d = distance(myvector.begin(),it);
  cout << "d: " << d << endl; 
  myvector.resize( distance(myvector.begin(),it) ); // 10 20 30 20 10

  // using predicate comparison:
  unique (myvector.begin(), myvector.end(), myfunction);   // (no changes)
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
      cout << ' ' << *it;
  cout << '\n';
  return 0;
}
