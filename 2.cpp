#include <bits/stdc++.h> 
using namespace std;  
  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);
       /*     int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;  */
        }  
    }  
    swap(&arr[i + 1], &arr[high]);
    /*int x=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=x;  */
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(a,0,n);
    for(int i=0;i<n;i++)
        cout<<a[i]+" ";
        return 0;
}