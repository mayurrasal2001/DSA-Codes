#include<iostream>
using namespace std;

struct myHash{
    int *arr;
    int cap,size;

    myHash(int c)
    {
        cap=c;
        arr=new int[cap];
        size=0;

        for(int i=0;i<cap;i++)
        {
            arr[i]=-1;
        }
    }

    int hash(int key)
    {
        return key%cap;
    }

    void print()
    {
        {
            for(int i=0; i<cap; i++)
            {
                cout<<arr[i]<<" "; 
            }
            cout<<endl;
        }
    }


    bool search(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)
        {
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

    bool insert(int key)
    {
        if(size==cap)
            return false;
        int i=hash(key);
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key)
        {
            i=(i+1)%cap;
        }

        if(arr[i]==key)
            return false;
        else
        {
            arr[i]=key;
            size++;
            return true;
        }
    }

    bool erase(int key)
    {
        int h=hash(key);
        int i=h;
        while(arr[i]!=-1)      //
        {
            if(arr[i]==key)
            {
                arr[i]=-2;
                size--;
                return true;
            }
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }

};

int main(){
    myHash mh(7);
    mh.print();

    cout<<mh.insert(43)<<endl;   
    cout<<mh.insert(42)<<endl;   
    cout<<mh.insert(43)<<endl;   
    cout<<mh.insert(56)<<endl;   
    cout<<mh.insert(49)<<endl;  
    mh.print();
    cout<<mh.search(100)<<endl;
    cout<<mh.search(43)<<endl;
    cout<<mh.erase(45)<<endl;
    cout<<mh.erase(56)<<endl;
    cout<<mh.search(49)<<endl;
    mh.print();
    return 0;
}