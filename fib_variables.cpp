//time-o(n),space-o(1)
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    int a=0,b=1,c,i;
    for(i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    cin>> n;
    cout<<fib(n);
}