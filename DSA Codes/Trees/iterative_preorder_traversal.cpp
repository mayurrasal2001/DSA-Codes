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

void iterativepreorder(Node* root)
{
    if(root==NULL)
        return;
    stack<Node *>st;
    st.push(root);
    while(st.empty()==false)
    {
        Node *curr=st.top();
        cout<<curr->key<<" ";
        st.pop();
        if(curr->right!=NULL)
            st.push(curr->right);
        if(curr->left!=NULL)
            st.push(curr->left);
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

    iterativepreorder(root);

    return 0;
}