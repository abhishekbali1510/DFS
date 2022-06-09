#include<stdio.h>
#include<stdlib.h>
char stack[100],top=-1;
char str[100],pos[100];
int i,j=0;
int priority(char val)
{
    switch(val)
    {
        case '+':   return 1;

        case '-':   return 1;
        
        case '*':   return 2;
        
        case '/':   return 2;
        
        case '^':   return 3;
    }

    return 0;

}

void fun(char x)
{
    if(top==-1)
    {
        stack[++top]=x;
    }
    else if(x=='(')
    {
        stack[++top]=x;
    }
    else if(x==')')
    {
        while(stack[top]!='(')
        {
            pos[j++]=stack[top];
            top--;
        }
        top--;

    }
    else
    {
        while(priority(x)<=priority(stack[top]))
        {
            pos[j++]=stack[top];
            top--;
        }
        stack[++top]=x;
    }
    
}

int main()
{
   
    // input of infix sting
    printf("Enter the infix Expression : ");
    scanf("%s",&str);  

    for(i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
            case '+':   fun(str[i]);
                        break;
            case '-':   fun(str[i]);
                        break;
            case '*':   fun(str[i]);
                        break;
            case '/':   fun(str[i]);
                        break;
            case '^':   fun(str[i]);
                        break;
            case '(':   fun(str[i]);
                        break;
            case ')':   fun(str[i]);
                        break;
            default :   pos[j++]=str[i];
                        break;
        }
    }

    // emptying the stack
    while(top!=-1)
    {
        if(stack[top]=='(')
            continue;
        pos[j++]=stack[top];
        top--;
    }
    // printing of postfix string
    printf("%s\n",pos);
     
    return 0;
}