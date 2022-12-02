#include<iostream>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int lengthmax=max(s1.size(),s2.size());
    int lengthmin=min(s1.size(),s2.size());

    int len[lengthmax+1][lengthmax+1];
    for(int i=0;i<=lengthmax;i++)
    {
        len[0][i]=0;
        len[i][0]=0;
    }    
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
            {
                len[i+1][j+1]=len[i][j]+1;
            }
            else
            {
                len[i+1][j+1]=max(len[i][j+1],len[i+1][j]);
            }
        }
        
    }
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
            cout<<len[i][j]<<" ";
        cout<<endl; 
    }
    cout<<"size of longest common subsequence : "<<len[lengthmin][lengthmin];
}