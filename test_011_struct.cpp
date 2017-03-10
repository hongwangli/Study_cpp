#include<iostream>
#include<string>
using namespace std;
struct people{
    string name;
    int age;
    people *next;
};

class linkList{
private:
    people *head;
    int length;
public:
    linkList();
    ~linkList();
    void insert(string na, int ag,int pos);
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
    peopel *temp;
    for (int i=0; i< length ; i++){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void linkList::insert(string na, int ag,int pos){
    people *p = new people();
    p->name = na;
    p->age = ag;
    people *temp;
    temp = head;
    if (pos==0){
        p->next = temp;
        head = p;
        length++;
        return;
    }

    int index = 1;
    while(temp !=NULL and index < pos )
    {
        temp = temp->next;
        index++; 
    }
    p->next = temp->next;
    temp->next = p;
    length++;
}

void linkList::print(){
    if (head ==NULL){
        cout << "head is empty!" << endl;
        return;
    }
    people *t;
    t = head;
    while (t!= NULL){
        cout << t->name <<" " <<  t->age << endl;
        t = t->next;
    }
}

void linkList::erase(){
    int pos =1; 
    if (pos==1){
        head = head->next;
        length--;
        return;
    }
    people *temp = new people();
    temp = head;
    //cout << "temp-> name: "<< temp->name << endl; 

    int index = 1;
    while (temp!= NULL and index < pos-1 ){
        temp = temp->next;
        index++;
    }
    temp->next = temp->next->next;
    length--;
}

int main(){

     linkList hea;
     hea.insert("howard",28,0);
     hea.insert("mali",30,0);
     hea.insert("dandan",26,1);
     hea.insert("tuzi",24,2);
     hea.insert("jj",3,0);
     cout <<  "-----------before erase ---------------" << endl;
     hea.print();
     hea.erase();
     cout <<  "-----------after erase ---------------" << endl;
     hea.print();
     cout << "size: " << hea.size() << endl;
     //people *pp = new people();
     //pp->name = "pp_name";
     //pp->age = 3;
     //people *hh;
     
     //hh = pp;
     //cout << pp->name << endl;
     //cout << hh->name << endl;
     
     //people *p = new people();
     //p->name = "howard";
     //p->age = 28;
     //cout << p->name << endl;
     //people p[3];
     //p[0].name = "howard";
     //p[0].age = 28;
     //head = &p[0];
    //p[0].next = &p[1];
    //p[1].name = "mali";
    //p[1].age = 30;
    //p[1].next = &p[2];
    //p[2].name = "dandan";
    //p[2].age = 26;
    //p[2].next = NULL;
    //people *pp;
    //pp = p;
    //cout << pp->name << endl;
    //pp = pp->next;
    //cout << pp->name <<endl;
    //pp = pp->next;
    //cout << pp->name << endl;
    //pp = pp ->next;
    //cout << pp->name << endl;
    //while (pp != NULL){
    //    cout << pp->name << endl;
    //    pp = pp->next;
    //} 
    
    return 0;
}



