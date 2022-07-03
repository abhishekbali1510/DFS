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



bool bipartiteDFS(int i,vector<int> arr[],vector<int> &visited,int n)
{
    for(int j=0;j<arr[i].size();j++)
    {
        if(visited[arr[i][j]]==-1)
        {
            visited[arr[i][j]]=!visited[i];
            return bipartiteDFS(arr[i][j],arr,visited,n);
        }
        else
        {
            if(visited[arr[i][j]]==visited[i])
                return false;
        }

    }
    return true;
}

int main()
{
    int n,m,parent=-1;
    cout<<"Enter number of nodes and edges : ";
    cin>>n>>m;
    vector<int> arr[n+1];
    
    cout<<"Enter the edges : ";
    input(arr,n,m); //arr is our list

    vector<int>visited(n+1);
    for(int i=1;i<=n;i++)
    visited[i]=-1;

    for(int i=1;i<=n;i++)
    {
        
        if(visited[i]==-1)
        {
            visited[i]=0;
            if(bipartiteDFS(i,arr,visited,n)==false)
            {
                cout<<"Not Bipartite";
                break;
            }
            
        }
        if(i==n-1)
            cout<<"Bipartite";   
    }    
}