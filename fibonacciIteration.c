#include<stdio.h>

void main()
{
    int n,fibo,fst=0,scnd=1,i;
    printf("Enter the term you want to find : ");
    scanf("%d",&n);
    if(n==0)
        fibo=fst;
    else if(n==1)
        fibo=scnd;
    else
    {
        for(i=2;i<=n;i++)
        {
            fibo=fst+scnd;
            fst=scnd;
            scnd=fibo;
        }
    }
    printf("fibbonaci's %d term is : %d",n,fibo);
}