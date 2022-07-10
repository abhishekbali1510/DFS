#include<bits/stdc++.h>

using namespace std;

void input(vector<int> *arr,int n,int m)
{
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
}

queue<int> q;

void shortestPath(vector<int> *arr,vector<int> &dist,int n)
{
    q.push(0);
    dist[0]=0;

    while(!q.empty())
    {
        int tmp=q.front();
        q.pop();
        for(int i=0;i<arr[tmp].size();i++)
        {
            int distance=dist[tmp]+1;
            if(distance<dist[arr[tmp][i]])
            {
                dist[arr[tmp][i]]=distance;
                q.push(arr[tmp][i]);
            }
        }
    }

}

int main()
{
    int m,n;
    cout<<"Enter number of nodes and edges : \n";
    cin>>n>>m;
    cout<<"Enter all the edges : \n";
    vector<int>arr[n+1];
    
    input(arr,n,m);

    vector<int> dist(n+1,INT_MAX);

    shortestPath(arr,dist,n);
    
    for(auto it:dist)
        cout<<it<<" ";
}