#include<stdio.h>
#include<stdlib.h>

int **input(int **temp,int n,int m)
{
    
    temp= malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++)
        temp[i]=malloc((n+1)*sizeof(int));
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        temp[u][v]=1;
        temp[v][u]=1;
    }
    return temp;
}

int arr[500],front=0,rear=0,n,capacity=500,elements=0;
void enqueue(int x)
{
    
    if(elements==capacity)
    {
	printf("queue overflow");
    }
    else
    {
	arr[rear]=x;
	elements++;
	rear=(rear+1)%500;
    }
}

int dequeue()
{

    if(elements==0)
    {
        printf("queue underflow");
    }
    else
    {
        elements--;
        front=(front+1)%10;
    }
    return arr[front-1];
}

int isEmptyQueue()
{
    if(elements==0)
        return 1;
    else 
        return 0;
}

void BFS(int **arr,int *visited,int n)
{
    while(!isEmptyQueue())
    {
        int temp=dequeue();
        printf("%d ",temp);
        visited[temp]=1;
        for(int x=1;x<=n;x++)
        {
            if(arr[temp][x])
            {
                if(visited[x]==0)
                {
                    enqueue(x);
                }
            }
        }
    }
}



int main()
{
    int **arr;
    int n,m;
    printf("Enter number of nodes & edges : ");
    scanf("%d %d",&n,&m);

    printf("Enter Edges : ");
    arr=input(arr,n,m);

    int *visited=malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)
        visited[i]=0;
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            enqueue(i);
            BFS(arr,visited,n);
            printf("-- ");
        }
    }
}
