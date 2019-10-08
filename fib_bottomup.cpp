//time-o(n),space-o(n)
#include<bits/stdc++.h>
using namespace std;
int fib(int a[],int n)
{
    if(a[n]>0)
        return a[n];
    if(n<2)
        a[n]=n;
    for(int i=2;i<=n;i++)
        a[i]=fib(a,i-1)+fib(a,i-2);
    return a[n];
}
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;i++)
        a[i]=-1;
    cout<<fib(a,n);

}