#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addedge(vector<int> adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void Dfsrec(vector<int> adj[],int s,bool visited[])
{
    visited[s]=true;
    cout<<s<<" ";
    for(int u : adj[s])
    {
        if(visited[u]==false)
            Dfsrec(adj,u,visited);
    }
}

void Dfs(vector<int> adj[], int v)   
{
    bool visited[v];
    for(int i=0; i<v;i++)
    {
        visited[i]=false;
    }

    for(int i=0; i<v ; i++)
    {
        if(visited[i]==false)
        {
            Dfsrec(adj, i, visited);
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

    Dfs(adj,v);

return 0;
}