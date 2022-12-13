#include<iostream>
#include<cstring>
using namespace std;

struct node
{k
{k
 int PRN;
 char NAME[10];
 node*next;
};

char ch;
node*nnode;
node*president;
node*secretary;

class pinclub
{
public:
pinclub()
{
president=secretary=NULL;
}
void create();
void display();
void insert();
void deletefrombeg();
};

void pinclub::create()
{
do
{
nnode=new node;
nnode->next=NULL;
cout<<"\n enter your PRN here";
 cin>>nnode->PRN;
 cout<<"\n enter your NAME here";
 cin>>nnode->NAME;
 if (president==NULL)
 {
 president=secretary=nnode;
}
else
{
secretary->next=nnode;
secretary=nnode;
}
 cout<<"do you want add more member y or n";
cin>>ch;
 
}while(ch=='y');
}
void pinclub::display()
{
node*temp=president;
while(temp!=NULL)
{
cout<<temp->PRN<<" "<<temp->NAME<<endl;
temp=temp->next;
}
}
void pinclub::insert()
{
cout<<"adding new president";
nnode=new node;
nnode->next=NULL;
cout<<"\n enter your PRN here";
 cin>>nnode->PRN;
 cout<<"\n enter your NAME here";
 cin>>nnode->NAME;
nnode->next=president;
president=nnode;
}
void pinclub::deletefrombeg()
{
 cout<<"\n enter your PRN here";
 cin>>nnode->PRN;
 cout<<"\n enter your NAME here";
 cin>>nnode->NAME;
 node*temp;
 temp=president;
 president=president->next;
 delete(temp);
}
int main()
 {
 pinclub p1;
 p1.create();
 p1.display();
 p1.insert();
 p1.deletefrombeg();
 return 0;
 
 }
