#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int count =0;
int** input(int n,int m)
{
    int i,j;
    int u,v,w;
    int ** arr=(int **)malloc((n+5)*sizeof(int));
    for(i=0;i<=n;i++)
        arr[i]=(int *)malloc((n+5)*sizeof(int));

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            arr[i][j]=0;
    printf("Enter the edges : \n");
    for(i=0;i<m;i++)
    { 
        
        scanf("%d %d %d",&u,&v,&w);
        arr[u][v]=w;
        arr[v][u]=w;
    }

    return arr;
}


void prim(int **arr,int *visited,int *mst,int *dist,int n)
{
    int i;
    while(count<n)
    {
        int min=INT_MAX,minnode=-1;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0&&dist[i]<min)
                {
                    min=dist[i];
                    minnode=i;
                }
            
        }
        visited[minnode]=1;
        for(i=1;i<=n;i++)
        {
            if((arr[minnode][i]!=0)&&(visited[i]!=1))
            {
                if(arr[minnode][i]<dist[i])
                {
                    dist[i]=arr[minnode][i];
                    mst[i]=minnode;
                    // mst =i;

                }
            }
        }
        // printf("%d %d \n",mst,minnode);
        
        count++;

    }
}

int main()
{
    int **arr=NULL;
    int n,m,i;
    printf("Enter the number of nodes and edges \n");
    scanf("%d %d",&n,&m);
    
    arr=input(n,m);
    int *visited=(int *)malloc((n+2)*sizeof(int));
    for(i=1;i<=n;i++)
        visited[i]=0;
    
    int *mst=(int *)malloc((n+2)*sizeof(int));
    for(i=0;i<=n;i++)
        mst[i]=-1;

    int *dist=(int *)malloc((n+2)*sizeof(int));
    for(i=1;i<=n;i++)
        dist[i]=INT_MAX;
    dist[1]=0;

    prim(arr,visited,mst,dist,n);

    printf("MST : \n");
    for(i=2;i<=n;i++)
    {
        printf("%d %d \n",mst[i],i);
    }

}