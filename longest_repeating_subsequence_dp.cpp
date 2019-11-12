//implementation of longest repeating subsequence in c++
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    int x=a>b?a:b;
    return x;
}

int longest_repeating_subsequence(char x[],int n)
{   int i,j;
    int a[n+1][n+1];        //array to store lrs count 
    for(i =0;i<n+1;i++)
        for(j=0;j<n+1;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else
            {
                if(x[i-1]==x[j-1]&&i!=j)
                    a[i][j]=a[i-1][j-1]+1;
                else
                    a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
        }
    return a[n][n];
}

int main()
{
    int n;
    cin>>n;
    char s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    cout<<longest_repeating_subsequence(s,n);
    
}