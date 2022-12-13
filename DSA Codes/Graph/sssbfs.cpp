#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int v , int u)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void bfs(vector<int>adj[], int v, int s)
{
    bool visited[v];
    for(int i = 0; i < v ; i++)
    {
        visited[i]=false;
    }

    queue<int>q;
    visited[s]=true;
    q.push(s);

    while(q.empty()==false)
    {
        int u = q.front();
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

int main()
{
    int v = 5;
    bool visited[v];
    vector<int> adj[v];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);

    bfs(adj,v,0);

}