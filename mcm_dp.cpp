#include<bits/stdc++.h>
using namespace std;
int mcm(int p[],int n)
{
    int a[n][n],i,j,k,min,q;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    for(int d=1;d<n-1;d++)
    {    for(i=1;i<n-d;i++)
        {
            j=i+d;
            min=10000;
            for(k=i;k<=j-1;k++)
            {
                q=a[i][k]+a[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<min)
                {
                    min=q;
                }
            }
            a[i][j]=min;
        }
        
    }
    return a[1][n-1];
}
int main()
{
    int n;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
        cout<<mcm(p,n);
}