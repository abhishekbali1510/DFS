#include<stdio.h>
#include<limits.h>

void OBST(int keys,int dummykeys,float*p,float*q)
{
    int e[keys + 2][keys + 2];
    int w[keys+2][keys+2];
    for(int i=1;i<=keys+1;i++)
    {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for(int l=1;l<=keys+1;l++)
    {
        for(int i=1;i<=keys-l+1;i++)
        {
            int j=i+l-1;
            e[i][j]=INT_MAX;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int r=i;r<=j;r++)
            {
                int t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j])
                {
                    e[i][j]=t;
                }
            }
        }
    }
    printf("\noptimal substructure matrix\n");
    for(int i=1;i<=keys+1;i++)
    {
        for(int j=0;j<=keys;j++)
        if(i<=j+1)
            printf("%d ",e[i][j]);
        printf("\n");
    }
    printf("expected cost : %d",e[1][5]);
}

void main()
{
    int keys,dummyKeys;
    scanf("%d %d",&keys,&dummyKeys);
    float p[keys+1];
    float q[dummyKeys+1];
    for(int i=1;i<=keys;i++)
    {
        scanf("%f",&p[i]);
    }
    for(int i=0;i<=keys;i++)
    {
        scanf("%f",&q[i]);
    }

    OBST(keys,dummyKeys,p,q);
}