#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    int x=a>b?a:b;
    return x;
}

int lps(char x[],int n)
{
    int a[n][n];            //array containing count of length of lps
    for(int i=0;i<n;i++)    
        for(int j=0;j<n;j++)
            a[i][j]=0;
    for(int i=0;i<n;i++)
        a[i][i]=1;
    for(int d=1;d<n;d++)    //d=ending index - starting index ,means the length of the string considered 
        for(int i=0;i<n-d;i++)  //i=starting index 
            for(j=i+d;j<n;j++)  //j=ending index
            {
                if(x[i]==x[j])
                    a[i][j]=a[i+1][j-1]+2;
                else
                    a[i][j]=max(a[i][j-1],a[i+1][j]);
            }
    return a[0][n-1];
}

int main()
{
    int n;
    cin>>n;
    char x[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    cout<<lps(x,n);
}