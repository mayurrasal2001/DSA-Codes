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

//floor means closest smaller value or equal to value---->this function will returns the address
Node *floor(Node *root, int x)
{
    Node *res=NULL;
    while(root!=NULL)
    {
        if(root->key==x)
            return root;
        else if(root->key > x)
            root=root->left;
        else if(root->key < x)
        {
            res=root;
            root=root->right;
        }
    }
    return res;
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

    cout<<floor(root, 78)<<endl;




    return 0;

}