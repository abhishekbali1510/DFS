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
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr[n+1];
    
    input(arr,n,m); //arr is our list

    for(int i=1;i<=n;i++)
    {
        cout<<i<<"->";
        for(auto it:arr[i])
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}