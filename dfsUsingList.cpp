#include<bits/stdc++.h>

using namespace std;

// creating adjacency list
void input(vector<int> arr[],int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}



void DFS(int i,vector<int> arr[],vector<int> &visited,int n)
{
    cout<<i<<" ";
    visited[i]=1;
    for(int j=0;j<arr[i].size();j++)
    {
        if(visited[arr[i][j]]==0)
        {
            DFS(arr[i][j],arr,visited,n);
        }
    }
}

int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges : ";
    cin>>n>>m;
    vector<int> arr[n+1];
    
    cout<<"Enter the edges : ";
    input(arr,n,m); //arr is our list

    vector<int>visited(n+1);
    for(int i=1;i<=n;i++)
    visited[i]=0;

    cout<<"Traversal : ";
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            DFS(i,arr,visited,n);
            cout<<"\n";
        }
        
    }    
}