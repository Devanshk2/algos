//implementation of longest pallindromic subsequence using recursion
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    int x=a>b?a:b;
    return x;
}

int lps(char x[],int n,int start,int end)//initially start=0,end=n-1
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
    {
        if(x[start]==x[end])
            return lps(x,n-2,1,n-2)+2;
        else
            return max(lps(x,n-1,start+1,end),lps(x,n-1,start,end-1));
    }
    
}

int main()
{
    int n;
    cin>>n;
    char x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    cout<<lps(x,n,0,n-1);
}