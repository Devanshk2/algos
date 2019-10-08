#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int lcs(char str1[],char str2[],int a,int b)
{
    int arr[a+1][b+1];
    for(int i=0;i<a+1;i++)
        for(int j=0;j<b+1;j++)
        {    if(i==0||j==0)
                arr[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                arr[i][j]=1+arr[i-1][j-1];
            else
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    return arr[a][b];
}
int main()
{
    int a,b;
    cin>>a>>b;
    char s1[a],s2[b];
    for(int i=0;i<a;i++)
        cin>>s1[i];
    for(int j=0;j<b;j++)
        cin>>s2[j];
    cout<<lcs(s1,s2,a,b);
}