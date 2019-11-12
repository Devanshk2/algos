#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

class Siddhartha
{
public:
    int a, b;
    char *str1, *str2;
    char **lcsData;
    Siddhartha(int q, int r)
    {
        a = q;
        b = r;
        str1 = new char[a];
        str2 = new char[b];
        lcsData = new char *[a + 1];
        for (int i = 0; i < a + 1; i++)
            lcsData[i] = new char[b + 1]; 
    }
    int lcs()
    {
        int arr[a + 1][b + 1];
        for (int i = 0; i < a + 1; i++)
            for (int j = 0; j < b + 1; j++)
            {
                if (i == 0 || j == 0)
                    arr[i][j] = 0;
                else if (str1[i - 1] == str2[j - 1])
                {
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                    lcsData[i][j] = 'd'; //d=diagonally up
                }
                else if (arr[i - 1][j] >= arr[i][j - 1])
                {
                    arr[i][j] = arr[i - 1][j];
                    lcsData[i][j] = 'u'; //u=up
                }
                else
                {
                    arr[i][j] = arr[i][j - 1];
                    lcsData[i][j] = 'l';
                }
                //arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        return arr[a][b];
    }
    void print_lcs(int i, int j) //initially i=length of first string, initially j=length of second string
    {
        if (i == 0 || j == 0)
            return;
        else if (lcsData[i][j] == 'd')
        {
            print_lcs(i - 1, j - 1);
            cout << str1[i - 1];
        }
        else if (lcsData[i][j] == 'l')
            print_lcs(i, j - 1);
        else
            print_lcs(i - 1, j);
    }
};

int main()
{
    int a, b;
    string s1, s2;
    cin >> s1 >> s2;
    a = s1.size(), b = s2.size();
    Siddhartha *devansh = new Siddhartha(a, b);
    for (int i = 0; i < a; i++)
        devansh->str1[i] = s1.at(i);
    for (int j = 0; j < b; j++)
        devansh->str2[j] = s2.at(j);
    cout << devansh->lcs() << "\n";
    devansh->print_lcs(a, b);
}