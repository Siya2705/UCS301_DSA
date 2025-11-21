#include <iostream>
using namespace std;

int parent[100];

int findSet(int x){
    if(parent[x]==x) return x;
    return parent[x] = findSet(parent[x]);
}

void unionSet(int a,int b){
    a=findSet(a);
    b=findSet(b);
    parent[b]=a;
}

struct Edge{
    int u,v,w;
};

int main(){
    int n,e;
    cin>>n>>e;

    int adj[100][100];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            adj[i][j]=0;

    Edge edges[100];
    for(int i=0;i<e;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        adj[edges[i].u][edges[i].v]=edges[i].w;
        adj[edges[i].v][edges[i].u]=edges[i].w;
    }

    for(int i=0;i<n;i++) parent[i]=i;

    for(int i=0;i<e-1;i++)
        for(int j=0;j<e-i-1;j++)
            if(edges[j].w > edges[j+1].w){
                Edge t = edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=t;
            }

    int kruskalCost=0;
    for(int i=0;i<e;i++){
        int u=findSet(edges[i].u);
        int v=findSet(edges[i].v);
        if(u!=v){
            kruskalCost += edges[i].w;
            unionSet(u,v);
        }
    }

    int key[100], parent2[100];
    bool mst[100]={false};
    for(int i=0;i<n;i++) key[i]=999999, parent2[i]=-1;
    key[0]=0;

    for(int k=0;k<n;k++){
        int u=-1;
        for(int i=0;i<n;i++)
            if(!mst[i] && (u==-1 || key[i]<key[u])) u=i;

        mst[u]=true;

        for(int v=0;v<n;v++){
            if(adj[u][v] && !mst[v] && adj[u][v] < key[v]){
                key[v]=adj[u][v];
                parent2[v]=u;
            }
        }
    }

    int primCost=0;
    for(int i=1;i<n;i++)
        primCost += adj[i][parent2[i]];

    cout<<kruskalCost<<endl;
    cout<<primCost<<endl;

    return 0;
}
