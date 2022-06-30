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

void BFS(vector<int> arr[],vector<int> &visited,int n)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        visited[q.front()]=1;
        int tmp=q.front();
        q.pop();
        for(int i=0;i<arr[tmp].size();i++)
        {
            if(visited[arr[tmp][i]]==0)
                q.push(arr[tmp][i]);
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


    cout<<"Traversal : ";
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            q.push(i);
            BFS(arr,visited,n);
            cout<<"\n";
        }
        
    }    
}