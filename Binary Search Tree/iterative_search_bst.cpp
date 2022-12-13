#include<iostream>
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


//Property- In every node keys in left side of the node is always smaller and right side are greater
bool iterativeSearch(Node* root, int x)
{
    while(root!=NULL)
    {
        if(root->key==x)
            return true;
        else if(root->key > x)
                root=root->left;
             else
                root=root->right;
    }
    return false;
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

    cout<<iterativeSearch(root,77);

    return 0;
}