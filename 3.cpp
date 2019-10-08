#include<bits/stdc++.h>
using namespace std;
int partition(int* a,int start,int end)
{
    int pivot=a[end];
    int part_index=start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            int temp=a[i];
            a[i]=a[part_index];
            a[part_index]=temp;
            part_index++;
        }
    }
    int x=a[end];
    a[end]=a[part_index];
    a[part_index]=x;
    return part_index;
}
void quicksort(int* a,int start,int end)
{
    if(start<end)
    {
        int p=partition(a,start,end);
        quicksort(a,start,p-1);
        quicksort(a,p+1,end);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]+" ";
}