#include<stdio.h>
#include<stdlib.h>

int stack[100],top=-1;
void push(int val)
{
    stack[++top]=val;
}

int pop()
{
    if(top==-1)
    {
        printf("invalid Expression");
        exit(1);
    }
    return stack[top--];
}

void main()
{
    int i,x,y;
    char postfix[100];
    
    printf("Enter Postfix expression ");
    scanf("%s",&postfix);
    
    for(i=0;postfix[i]!='\0';i++)
    {
        // printf("%c",postfix[i]);
        switch(postfix[i])
        {
            case '+':   x=pop();
                        y=pop();
                        push(x+y);
                        break;

            case '-':   x=pop();
                        y=pop();
                        push(x-y);
                        break;

            case '*':   x=pop();
                        y=pop();
                        push(x*y);
                        break;

            case '/':   x=pop();
                        y=pop();
                        push(x/y);
                        break;

            default:    x=postfix[i]-48;
                        push(x);
                        break;
        }
    }
    printf("output : %d",stack[0]);
}