#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printgraph(vector<int> adj[],int v)
{
    for(int i=0; i<v; i++)
    {
        for(int x : adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

void bfsconnected( vector<int> adj[],int v,int s, bool visited[])
{

    queue<int> q;
    visited[s]=true;
    q.push(s);

    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";

        for(int v : adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}


void bfsdisconnected( vector<int> adj[],int v)
{
    bool visited[v+1];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i]==false)
        {
            bfsconnected(adj,v,i,visited);
        }
    }
}

int main(){
    int v=9;
    vector<int> adj[v];
    bool visited[v];

    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,4,5);
    addedge(adj,4,6);
    addedge(adj,7,8);

    bfsdisconnected(adj, 9);
    return 0;
}