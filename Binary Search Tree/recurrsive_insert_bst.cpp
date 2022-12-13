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
    if(root==NULL)
        return new Node(x);
    else if(root->key > x)
            root->left=insert(root->left,x);   //starting root->left= is for linking the created Node
    else if(root->key < x)
            root->right=insert(root->right,x);
    return root;
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

    cout<<insert(root,8)<<endl;

    printLevelorder(root);

    return 0;
}