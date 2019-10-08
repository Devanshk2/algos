//fibonacci top-down memoized
//time-o(n),space-o(n)
#include <bits/stdc++.h>
using namespace std;
int fib(int a[],int n)
{
    if(a[n]!=-1)
        return a[n];
    else
    {
        if(n<2)
            a[n]=n;
        else
        {
            a[n]=fib(a,n-1)+fib(a,n-2);
        }
        return a[n];
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n+1;i++)
        a[i]=-1;
    cout<<fib(a,n);
    
}