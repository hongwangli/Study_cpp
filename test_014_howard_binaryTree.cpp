#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *Rleaf, *Lleaf;
};

class binary_tree{
public:
    binary_tree();
    void insert(int d);
    void Preorder(Node  *temp);      //先序遍历 
    void Inorder(Node  *temp);      //中序遍历 
    void Postorder(Node  *temp);      //后序遍历 
    void display_pre() {Preorder(root); cout<<endl;}
    void display_in(){Inorder(root); cout << endl;}
    void display_post(){Postorder(root); cout << endl;}
    int NodeCount(Node *);
    int NodeSize(){return NodeCount(root);}
    int getdepth(Node *);
    int GetDepth(){return getdepth(root);}
    void LevelTraverse(Node *);
    void display_level(){LevelTraverse(root);cout << endl;}
private:
    Node *root;
};

void binary_tree::LevelTraverse(Node *r){

    if (r==NULL)
        return;
    queue<Node *> q;
    q.push(r);
    Node *current;
    while (!q.empty()){
       current = q.front(); 
       cout << current->data << " ";
       q.pop();
       if (current->Rleaf!=NULL)
            q.push(current->Rleaf);
       if (current->Lleaf!=NULL)
            q.push(current->Lleaf); 
    }
}



int binary_tree::getdepth(Node *r){
    if (r== NULL)
        return 0;
    int left = getdepth(r->Lleaf);
    int right = getdepth(r->Rleaf);
    int ret = max(left,right) + 1;
    return ret;

}

int binary_tree::NodeCount(Node *r){
    if (r == NULL)
        return 0;
    else {
        return NodeCount(r->Rleaf) + NodeCount(r->Lleaf) + 1; 
    }
}

binary_tree::binary_tree(){
    root = NULL;
}

void binary_tree::insert(int d){
    Node *back;
    Node *newNode = new Node;
    newNode->data = d;
    newNode->Rleaf = newNode->Lleaf = NULL;
    if (root == NULL){
        root = newNode;
        return;
    }
    
    Node *current = root;
    while (current != NULL){
        back = current;
        if (current->data < d)
            current = current-> Lleaf;
        else 
            current = current->Rleaf;
    }     
    if (back->data < d)
        back->Lleaf = newNode;
    else 
        back->Rleaf = newNode;
}

void binary_tree::Preorder(Node  *temp)    //这是前序遍历二叉树，采用了递归的方法。
{
    
    if(temp!=NULL)
    {   
        cout<<temp->data<<" ";
        Preorder(temp->Lleaf);
        Preorder(temp->Rleaf);
    }
}

void binary_tree::Postorder(Node  *temp)    //这是后序遍历二叉树，采用了递归的方法。
{
    
    if(temp!=NULL)
    {   
        Preorder(temp->Lleaf);
        Preorder(temp->Rleaf);
        cout<<temp->data<<" ";
    }
}

void binary_tree::Inorder(Node  *temp)    //这是中序遍历二叉树，采用了递归的方法。
{
    
    if(temp!=NULL)
    {   
        Preorder(temp->Lleaf);
        cout<<temp->data<<" ";
        Preorder(temp->Rleaf);
    }
}

int main(){
    binary_tree b;
    int array[] = {10,5,13,3,7,9,1,16,12};
    int k = sizeof(array)/sizeof(array[0]);
    cout << "输入顺序： ";
    for (int i=0; i < k; i++){
        cout << array[i]<< " ";
        b.insert(array[i]);
    }
    cout << endl;

    cout << "前序遍历结果： " << endl;
    b.display_pre();
    cout << "中序遍历结果： " << endl; 
    b.display_in();
    cout << "后序遍历结果： " << endl;
    b.display_post();
    cout << "层次遍历结果："  << endl;
    b.display_level();

    int c2 = b.NodeSize();
    cout << "count of node: " << c2 << endl;
    cout << "depth of the tree: " << b.GetDepth() << endl;

    //Node *test = new Node;
    ////Node *test; //error
    //test->data = 100;
    //cout << "test data :" << test->data << endl;
}
