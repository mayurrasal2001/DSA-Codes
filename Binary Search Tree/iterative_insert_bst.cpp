#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int x)
    {
        key=x;
        left=right=NULL;
    }
};

Node *insert(Node* root, int x)
{
    Node *temp = new Node(x);
    Node *parent=NULL , *curr=root;
    while(curr!=NULL)      //this loop is only for the traversing
    {
        parent=curr;     //after every iteration parent will change
        if(curr->key > x)
            curr=curr->left;
        else if(curr->key < x)
                curr=curr->right;
        else 
            return root;
    }

    if(parent==NULL)
        return temp;
    if(parent->key > x)
            parent->left=temp;
    else
        parent->right=temp;
    return root;

    cout<<endl;
}

void printLevelorder(Node* root)
{
    if(root==NULL)
        return ;
    queue<Node *> q;
    q.push(root);

    while(q.empty()==false)
    {
        Node *curr = q.front();
        q.pop();
        cout<<curr->key<<"  ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
    cout<<endl;
}



int main(){
    Node* root = new Node(10);
    root->left = new Node(15);
    root->left->left = new Node(30);
    root->right= new Node(20);
    root->right->left= new Node(40);
    root->right->left->left= new Node(60);
    root->right->left->right= new Node(70);
    root->right->right= new Node(50);
    root->right->right->right= new Node(80);

    printLevelorder(root);

    cout<<insert(root,35)<<endl;
    printLevelorder(root);




    return 0;
}