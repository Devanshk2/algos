#include<bits/stdc++.h>
using namespace std;

void merge(int left_array[],int size_of_left_array,int right_array[],int size_of_right_array,int a[],int size_of_merged_array)
{
    int i=0,j=0,k=0;
    while(i<size_of_left_array && j<size_of_right_array)
    {
        if(left_array[i]<=right_array[j])
        {
            a[k]=left_array[i];
            i++;
        }
        else
        {
            a[k]=right_array[j];
            j++;
        }
        k++;
    }
    while(i<size_of_left_array)
    {
        a[k]=left_array[i];
        i++;
        k++;
    }
    while(j<size_of_right_array)
    {
        a[k]=right_array[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int n)
{   if(n<2)
    return;
    int mid=n/2;
    int left_array[mid],right_array[n-mid];
    for(int i=0;i<mid;i++)
        left_array[i]=a[i];
    for(int i=mid;i<n;i++)
        right_array[i-mid]=a[i];
    merge_sort(left_array,mid);
    merge_sort(right_array,n-mid);
    merge(left_array,mid,right_array,n-mid,a,n);
}


int main()
{
    int n;
    int * sorted_array;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    merge_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i] << " ";
    }
}