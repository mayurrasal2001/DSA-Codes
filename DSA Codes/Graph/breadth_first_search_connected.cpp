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

void bfsconne( vector<int> adj[],int v, int s)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }
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
int main(){
    int v=4;
    vector<int> adj[v];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,1,3);

    printgraph(adj,v);
    bfsconne(adj,v,0);


return 0;
}