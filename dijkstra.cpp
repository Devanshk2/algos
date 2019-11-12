#include<bits/stdc++.h>
using namespace std;

int find_min_vertex(bool visited[],int distance[],int v);
void dijkstra(int** edge_weight,int v,int source)
{
    int distance[v];                // an array to store the minimum distance from source to that particular vertex
    bool visited[v];                // an array to check if a vertex is visited or not
    distance[source]=0;             // source to source distance is zero

    for(int i=0;i<v;i++)
    {
        int min_vertex= find_min_vertex(visited,distance,v);        //finding the minimum distance[i] in each iteration, filtering out the vertex already visited.
        visited[min_vertex]=true;
        
        //updating all destination distances from source to destination via min_vertex
        for(int j=0;j<v;j++)
        {
            if(edge_weight[min_vertex][j]!=0 && !visited[j])        
            {
                if(distance[min_vertex]+edge_weight[min_vertex][j]<distance[j])
                    distance[j]=distance[min_vertex]+edge_weight[min_vertex][j];
            }
        }
    }

    //printing the answer
    for(int i=0;i<v;i++)
        cout<<source<<" "<<i<<" "<<distance[i]<<'\n';
}
// a function to find the vertex which is nearest to vertex and is not visited.
int find_min_vertex(bool visited[],int distance[],int v)
{
    int min_vertex=-1;
    for(int i=0;i<v;i++)
    {
        if(!visited[i]&&(distance[i]<distance[min_vertex]||min_vertex==-1))
            min_vertex=i;
    }
    return min_vertex;
}

int main()
{
    int v,e,s,m,n,weight;
    int i,j;
    cin>>v>>e>>s;
    int ** edge_weight=new int* [v];
    for(i=0;i<v;i++)
    {
        edge_weight[i]=new int[v];
        for(j=0;j<v;j++)
            edge_weight[i][j]=0;
    }
    for(i=0;i<e;i++)
    {
        cin>>m>>n>>weight;
        edge_weight[m][n]=weight;
    }
    dijkstra(edge_weight,v,s);
}