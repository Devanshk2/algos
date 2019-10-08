#include <bits/stdc++.h>
using namespace std;

void merge(int first_array[], int size_of_first_array, int second_array[], int size_of_second_array, int third_array[], int size_of_third_array, int a[], int size_of_merged_array)
{
    int i = 0, j = 0, m = 0, k = 0;
    while (i < size_of_first_array && j < size_of_second_array && m < size_of_third_array)
    {
        if (first_array[i] <= second_array[j])
        {
            if (first_array[i] <= third_array[m])
            {
                a[k] = first_array[i];
                i++;
            }
            else
            {
                a[k] = third_array[m];
                m++;
            }
        }
        else
        {
            if (second_array[j] <= third_array[m])
            {
                a[k] = second_array[j];
                j++;
            }
            else
            {
                a[k] = third_array[m];
                m++;
            }
        }
        k++;
    }
    while (i < size_of_first_array && j < size_of_second_array)
    {
        if (first_array[i] <= second_array[j])
        {
            a[k] = first_array[i];
            i++;
        }
        else
        {
            a[k] = second_array[j];
            j++;
        }
        k++;
    }
    while (i < size_of_first_array && m < size_of_third_array)
    {
        if (first_array[i] <= third_array[m])
        {
            a[k] = first_array[i];
            i++;
        }
        else
        {
            a[k] = third_array[m];
            m++;
        }
        k++;
    }
    while (j < size_of_second_array && m < size_of_third_array)
    {
        if (second_array[j] < third_array[m])
        {
            a[k] = second_array[j];
            j++;
        }
        else
        {
            a[k] = third_array[m];
            m++;
        }
        k++;
    }
    while (i < size_of_first_array)
    {
        a[k] = first_array[i];
        i++;
        k++;
    }
    while (j < size_of_second_array)
    {
        a[k] = second_array[j];
        j++;
        k++;
    }
    while (m < size_of_third_array)
    {
        a[k] = third_array[m];
        m++;
        k++;
    }
}

void merge_sort(int a[], int n)
{
    if (n == 2)
    {
        if (a[0] <= a[1])
            return;
        else
        {
            int temp = a[1];
            a[1] = a[0];
            a[0] = temp;
        }
    }
    if (n < 2)
        return;
    int part1 = n / 3;
    int part2 = n / 3;
    int part3 = n - 2 * (n / 3);
    int first_array[part1], second_array[part2], third_array[part3];
    for (int i = 0; i < part1; i++)
        first_array[i] = a[i];
    for (int i = part1; i < part1 + part2; i++)
        second_array[i - part1] = a[i];
    for (int i = part1 + part2; i < n; i++)
        third_array[i - part2 - part1] = a[i];
    merge_sort(first_array, part1);

    merge_sort(second_array, part2);
    merge_sort(third_array, part3);
    merge(first_array, part1, second_array, part2, third_array, part3, a, n);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    merge_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}