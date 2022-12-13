#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node*right;

    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};

void iterativeinorder(Node *root)
{
    stack<Node*>st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }

        curr=st.top();
        st.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
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

    iterativeinorder(root);

    return 0;
}