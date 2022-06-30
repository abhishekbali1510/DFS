#include<stdio.h>
#include<stdlib.h>

int ** input(int **arr,int n,int m)
{
    arr=malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
        arr[i]=malloc((n+1)*sizeof(int));
    printf("Enter the edges : ");
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        arr[u][v]=1;
        arr[v][u]=1;
    }
    return arr;
}

void DFS(int i,int **arr,int *visited,int n)
{
    printf("%d ",i);
    visited[i]=1;
    for(int j=1;j<=n;j++)
    {
        if(arr[i][j]==1)
        {
            if(visited[j]==0)
            DFS(j,arr,visited,n);
        }
    }
}

int main()
{
    int **arr;
    int n,m;
    printf("Enter number of nodes and edges : ");
    scanf("%d %d",&n,&m);
    arr=input(arr,n,m);

    printf("Traversal : ");
    int *visited=malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)
        visited[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            DFS(i,arr,visited,n);
            printf("\n");
        }
    }
}