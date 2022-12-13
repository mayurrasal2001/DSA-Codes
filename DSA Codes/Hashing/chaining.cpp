#include<iostream>
#include<list>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int>*table;

    MyHash(int b)
    {
        BUCKET = b;
        table  = new list<int>[b];
    }

    void insert(int key)
    {
        int i =key % BUCKET;
        table[i].push_back(key);
    }

    void remove(int key)
    {
        int i = key % BUCKET;
        table[i].remove(key);
    }

    bool search(int key)
    {
        int i = key % BUCKET;
        for(auto x: table[i])
        {
            if(x==key)
                return true;
        }
        return false;
    }

    void print()
    {
        for(int i=0; i<BUCKET;i++)
        {
            cout<<i;

            for(auto x: table[i])
                cout<<" --> "<<x;
            cout<<endl;
        }
        cout<<endl;
    }
};



int main()
{
    MyHash b(7);
    b.insert(41);
    b.insert(21);
    b.insert(20);
    b.insert(36);
    b.insert(50);
    b.print();
    cout<<b.search(20)<<endl;
    b.remove(20);
    b.print();
    cout<<b.search(20)<<endl;


    return 0;
}