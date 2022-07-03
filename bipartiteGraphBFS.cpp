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

queue<int>q;

bool bipartiteBFS(vector<int> arr[],vector<int> &visited,int n)
{

   while(!q.empty())
   {
        int temp=q.front();
        q.pop();
        for(int i=0;i<arr[temp].size();i++)
        {
            if(visited[arr[temp][i]]==-1)
            {
                q.push(arr[temp][i]);
                visited[arr[temp][i]]=!visited[temp];
            }
            else
            {
                if(visited[arr[temp][i]]==visited[temp])
                {
                    return false;
                }
            }
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
            q.push(i);
            visited[i]=0;
            if(bipartiteBFS(arr,visited,n)==false)
            {
                cout<<"Not Bipartite";
                break;
            }
            
        }
        if(i==n-1)
            cout<<"Bipartite";   
    }    
}