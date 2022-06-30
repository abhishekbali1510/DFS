#include<iostream>

using namespace std;

// creating adjacency matrix
int **input(int **temp,int n,int m)
{
    
    temp=new int*[n+1];
    for(int i=0;i<=n;i++)
        temp[i]=new int[n+1];
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        temp[u][v]=1;
        temp[v][u]=1;
    }
    return temp;
}

int main()
{
    int **arr;
    int n,m;
    cin>>n>>m;

    arr=input(arr,n,m); //arr is our adjacency matrix
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}
