#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
   { if(a>b)
        return a;
    else
    {
        return b;
    }
}
    
int rod_cut(int p[],int n)
{
    int val[n+1];
    int i,j;
    val[0]=0;
    for(i=1;i<=n;i++)
    {    int max_val=INT_MIN;
        for(j=0;j<i;j++)
        {
            max_val=max(max_val,p[j]+val[i-j-1]);
        }
        val[i]=max_val;
    }
    return val[n];
}

int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<rod_cut(p,n);
}

