#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int adj[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>adj[i][j];

    int src;
    cin>>src;

    int dist[100], vis[100]={0};
    for(int i=0;i<n;i++) dist[i]=999999;
    dist[src]=0;

    for(int k=0;k<n;k++){
        int u=-1;
        for(int i=0;i<n;i++)
            if(!vis[i] && (u==-1 || dist[i]<dist[u])) u=i;

        vis[u]=1;

        for(int v=0;v<n;v++)
            if(adj[u][v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    for(int i=0;i<n;i++)
        cout<<dist[i]<<" ";
}
