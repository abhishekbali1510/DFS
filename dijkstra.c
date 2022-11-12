#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int **input(int **temp,int numOfNodes,int numOfEdges)
{
    
    temp= malloc((numOfNodes+1)*sizeof(int));
    for(int i=0;i<=numOfNodes;i++)
        temp[i]=malloc((numOfNodes+1)*sizeof(int));
    int u,v,w;
    for(int i=0;i<numOfEdges;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        temp[u][v]=w;
        temp[v][u]=w;
    }
    return temp;
}

int findSmallest(int *visited,int *shortestPath,int numOfNodes)
{
    int min=INT_MAX,flag=0,minIndex=0;
    for(int i=1;i<=numOfNodes;i++)
    {
        if(!visited[i]&&shortestPath[i]<min)
            {
                min=shortestPath[i];
                flag=1;
                minIndex=i;
            }
    }
    if(flag==1)
        return minIndex;
    else 
        return flag;
}

void Dijkstra(int **adjMatrix,int *visited,int *shortestPath,int numOfNodes)
{
    while(findSmallest(visited,shortestPath,numOfNodes))
    {
        int node=findSmallest(visited,shortestPath,numOfNodes);
        for(int i=1;i<=numOfNodes;i++)
        {
            if(adjMatrix[node][i]!=0)
            {
                if(shortestPath[i]>shortestPath[node]+adjMatrix[node][i])
                {
                    shortestPath[i]=shortestPath[node]+adjMatrix[node][i];
                }
                
            }
        }
        visited[node]=1;
    }
}

void main()
{
    // Input block start

    int **adjMatrix;
    int numOfNodes,numOfEdges;
    printf("Enter number of nodes & edges : ");
    scanf("%d %d",&numOfNodes,&numOfEdges);

    printf("Enter Edges : ");
    adjMatrix=input(adjMatrix,numOfNodes,numOfEdges);

    // Input block close

    printf("Adjacency Matrix : \n");
    for(int i=1;i<=numOfNodes;i++)
    {
        for(int j=1;j<=numOfNodes;j++)
        {
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }

    int shortestPath[numOfNodes+1];
    for(int node=1;node<=numOfNodes;node++)
        shortestPath[node]=INT_MAX;
    shortestPath[1]=0;

    int visited[numOfNodes+1];
    for(int node=1;node<=numOfNodes;node++)
        visited[node]=0;
    
    Dijkstra(adjMatrix,visited,shortestPath,numOfNodes);

    printf("\nDistance for node 1 : ");
    for(int node=1;node<=numOfNodes;node++)
        printf("%d ",shortestPath[node]);
}