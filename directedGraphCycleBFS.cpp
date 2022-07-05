// kahn's algo for topological sort 
// if topological sort not exist
//  then its a cyclic graph
#include<bits/stdc++.h>

using namespace std;
int count=0;

void input(vector<int> arr[],int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
       
    }
}

queue<int>q;

void directCycleBFS(vector<int>arr[],vector<int>indeg,int n)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<arr[i].size();j++)
        {
            indeg[arr[i][j]]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        ::count++;
        // cout<<tmp<<" ";
        for(int i=0;i<arr[tmp].size();i++)
        {
            indeg[arr[tmp][i]]--;
            if(indeg[arr[tmp][i]]==0)
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
    
    cout<<"Enter the edges : \n";
    input(arr,n,m); //arr is our list

    vector<int> indeg(n+1,0);
    
    directCycleBFS(arr,indeg,n);
    if(::count == n)
    {
        cout<<"Cycle not exist ";
    }
    else
    {
        cout<<"Cycle exist ";
    }
}