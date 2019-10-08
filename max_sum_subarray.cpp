#include<bits/stdc++.h>
using namespace std;
int mss(int p[],int n)
{
    int max_sum=INT_MIN,b;
    for(int i=0;i<n;i++)
    {
        b=b+a[i];
        if(max_sum<b)
            max_sum=b;
        if(b<0)
            b=0;
    }
    return max_sum;
}