#include<iostream>
#include<queue>
using namespace std;

void addEdge(vector<int>adj[], int v, int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void dfsrec(vector<int>adj[], int s, bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";

    for(int u: adj[s])
    {
        if(visited[u]==false)
        dfsrec(adj,u,visited);
    }
}
void dfsconn(vector<int>adj[], int v)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }
    dfsrec(adj,0,visited);
}

int main()
{
    int v=4;
    vector<int>adj[v];
    bool visited[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);

    dfsconn(adj,0);
}