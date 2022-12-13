#include<iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

int getsize(Node* root)
{
    if(root==NULL)
        return 0;
    else
        return 1+(getsize(root->left) + getsize(root->right));
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

    cout<<getsize(root);



return 0;
}