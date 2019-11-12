#include<bits/stdc++.h>
using namespace std;
void dfs(int** edge,int v,int s,bool visited[])
{
    cout<<s<<endl;
    visited[s]=true;
    for(int i=0;i<v;i++)
    {
        if(edge[s][i]!=0&& (!visited[i]))
           dfs(edge,v,i,visited);
    }
}

int main()
{
   int v,e,s,i,j,m,n;
   cin>>v>>e;
   int** edge=new int* [v] ;
   for(i=0;i<v;i++)
   {
       edge[i]=new int[v];
       for(j=0;j<v;j++)
        edge[i][j]=0;
   }
   for(i=0;i<e;i++)
   {
       cin>>m>>n;
       edge[m][n]=1;
       edge[n][m]=1;
   }
   cin>>s;
   bool visited[v];
    for(i=0;i<v;i++)
        visited[i]=false;
   dfs(edge,v,s,visited);
}