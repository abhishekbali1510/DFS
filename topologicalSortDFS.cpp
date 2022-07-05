// topological sort works on DAG(Directed Acyclic Grpah)
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
        // arr[v].push_back(u); because of directed graph
    }
}

stack<int>stck;

void topoSort(int i,vector<int> arr[],vector<int> &visited,int n)
{
   visited[i]=1;
   for(int j=0;j<arr[i].size();j++)
   {
        if(visited[arr[i][j]]==0)
        {
            topoSort(arr[i][j],arr,visited,n);
        }   
   }
   stck.push(i);
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
    {
        visited[i]=0;
        
    }

    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            topoSort(i,arr,visited,n);
            
        }
          
    }  
    while(!stck.empty()) 
    {
        cout <<" "<<stck.top();
        stck.pop(); 
    } 
}