#include<bits/stdc++.h>
using namespace std;
int lcs(char str1[],char str2[],int a,int b)
{
    if(a==0||b==0)
        return 0;
    else if(str1[a-1]==str2[b-1])
        return 1+lcs(str1,str2,a-1,b-1);
    else
    {
        return max(lcs(str1,str2,a-1,b),lcs(str1,str2,a,b-1));
    }
    
}

int main()
{
    int a,b,x;
    cin>>a>>b;
    char str1[a], str2[b];
    for(int i=0;i<a;i++)
        cin>>str1[i];
    for(int j=0;j<b;j++)
        cin>>str2[j];
       x=lcs(str1,str2,a,b);
       cout<<x;

}