#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ver 8


int main()
{
    int n,i,j;
  int graph[9][9]= { { 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                    { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
dijik(graph,0);

}
void dijik(int graph[9][9],int source)
{
    int v,i,distance[9],parent[9]={-1};
    int vertex=ver;
    bool path[9];
    initialize(distance,path,source);
    while(vertex!=0)
    {
        int u=min_d(distance,path);
        path[u]=true;
        for(v=0;v<9;v++)
        {
            relax(u,v,graph,parent,distance,path);
        }
        vertex--;
    }
    printf("\nv\td\tp");
    for(i=0;i<9;i++)
    {
        printf("\n%d\t%d\t%d",i,distance[i],parent[i]);
    }

}
void initialize(int distance[9],bool path[9],int source)
{
    int i;
    for(i=0;i<9;i++)
    {
        distance[i]=100;
        path[i]=false;
    }
    distance[source]=0;
}
int min_d(int distance[],bool path[])
{
    int min=100,u,i;
    for(i=0;i<9;i++)
    {
        if(path[i]==false && distance[i]<=min)
        {
            min=distance[i];
            u=i;
        }
    }
    return u;
}
void relax(int u,int v,int graph[9][9],int parent[9],int distance[9],bool path[9])
{
    if(path[v]==false && graph[u][v]!=0 && distance[u]+graph[u][v]<distance[v])
    {
       distance[v]=distance[u]+graph[u][v];
       parent[v]=u;
    }
}
