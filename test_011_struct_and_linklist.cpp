#include<iostream>
#include<string>
using namespace std;
struct people{
    string name;
    int age;
};
struct node{
    people peo;
    node *next;
    node(people x):peo(x),next(NULL){}; // struct的构造函数

};

class linkList{
private:
    node *head;
    int length;
public:
    linkList();
    ~linkList();
    void insert(people pp,int pos);
    void print();
    int size(){return length;}
    void erase();
    bool empty(){return length==0;}
};


linkList::linkList(){
    head = NULL;
    length = 0;
    cout << "hello" << endl;
}
linkList::~linkList(){
    node *temp;
    for (int i=0; i< length ; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void linkList::insert(people pp,int pos){

    node *currentNode;
    node *insertNode = new node(pp);
    currentNode = head;

    if (pos==0){
        insertNode->next = currentNode;
        head = insertNode;
        length++;
        return;
    }

    int index = 1;
    while( currentNode!=NULL and index < pos )
    {
        currentNode = currentNode->next;
        index++; 
    }
    if (currentNode ==NULL) {
        cout << "insert failed! " << endl;
        return;
    }
    insertNode->next = currentNode->next;
    currentNode->next = insertNode;
    length++;
}

void linkList::print(){
    if (head ==NULL){
        cout << "head is empty!" << endl;
        return;
    }
    node *currentNode;
    currentNode = head;
    while (currentNode!= NULL){
        cout << currentNode->peo.name <<" " <<  currentNode->peo.age << endl;
        currentNode = currentNode->next;
    }
}

void linkList::erase(){
    int pos =1; 
    if (pos==1){
        head = head->next;
        length--;
        return;
    }
    node *currentNode;
    currentNode = head;
    //cout << "temp-> name: "<< temp->name << endl; 

    int index = 1;
    while (currentNode!= NULL and index < pos-1 ){
        currentNode = currentNode->next;
        index++;
    }
    currentNode->next = currentNode->next->next;
    length--;
}

int main(){

     linkList hea;
     people p1,p2;
     p1.name = "howard"; p1.age = 28;
     p2.name = "mali";p2.age = 30;
     node *n = new node(p1);
     cout << "n->peo.name: " << n->peo.name << endl;
     hea.insert(p1,0);
     hea.insert(p2,1);
     cout <<  "-----------before erase ---------------" << endl;
     hea.print();
     hea.erase();
     cout <<  "-----------after erase ---------------" << endl;
     hea.print();
     cout << "size: " << hea.size() << endl;
     return 0;
}



