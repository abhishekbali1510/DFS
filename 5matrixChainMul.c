#include<stdio.h>
#include<limits.h>
void main()
{
    int numOfMatrices;
    scanf("%d",&numOfMatrices);
    int matrices[numOfMatrices+1];
    for(int i=0;i<=numOfMatrices;i++)
        scanf("%d",&matrices[i]);
    
    int mulOfmatrix[numOfMatrices+1][numOfMatrices+1];
    for(int i=1;i<=numOfMatrices;i++)
    {
        mulOfmatrix[i][i]=0;
    }
    for(int p=2;p<=numOfMatrices;p++)
    {
        int i=1;
        int j=p+i-1;
        while(j<=numOfMatrices)
        {
            int min=INT_MAX;
            for(int x=i;x<j;x++)
            {
                
                if(min>mulOfmatrix[i][x]+mulOfmatrix[x+1][j]+matrices[i-1]*matrices[x]*matrices[j])
                    min=mulOfmatrix[i][x]+mulOfmatrix[x+1][j]+matrices[i-1]*matrices[x]*matrices[j];
            }
            mulOfmatrix[i][j]=min;
            i++;
            j=p+i-1;
        }
        
    }
    printf("%d",mulOfmatrix[1][numOfMatrices]);
    // for(int i=1;i<=numOfMatrices;i++)
    // {
    //     for(int j=1;j<=numOfMatrices;j++)
    //     {
    //         printf("%d ",mulOfmatrix[i][j]);
            
    //     }
    //     printf("\n");
    // }
}