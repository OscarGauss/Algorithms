#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList(1000);
int nodes,edges;
///Depth First Search (DFS) Orde( V+E )
bool Visited[1000];
void dfs(int u){
    Visited[u]=1;
    for(int j=0 ; j<AdjList[u].size() ; j++){
        if(! Visited[ AdjList[u][j].first ] ){
            dfs(AdjList[u][j].first);
        }
    }
}
///Breaf First Search (BFS)
vi layer(10000,-1);//capas distancia desde el nodo inicial, layer of de distance from source
vi parent(10000,-1);
void bfs(int s){
    layer[s]=0; //distance from source s to s is 0
    queue <int> q;q.push(s);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i=0 ; i<AdjList[u].size() ; i++){
            ii v = AdjList[u][i];
            if(layer[v.first]==-1){
                layer[v.first] = layer[u]+1;
                parent[v.first] = u;
                q.push(v.first);
            }
        }
    }
    for(int i=0 ; i<nodes ; i++){
        printf("%d -> %d\n",i,layer[i]);
    }
}

int main(){
    int node,neighbor,weight;
    while(scanf("%d %d",&nodes,&edges)!=EOF){
        for(int i=0;i<edges;i++){
            scanf("%d %d %d",&node,&neighbor,&weight);
            AdjList[node].push_back(make_pair(neighbor,weight));
        }
        //se termino de leer los nodos y sus adyacencias con sus respectivos pesos
        //AdjList[u] -> vector de pairs de u
        //AdjList[u][v] -> pair de vecinos y pesos de u
        //AdjList[u][v].first -> u vecino v, AdjList[u][v].second -> peso entre u y v
        memset(Visited,0,sizeof(Visited));
        dfs(1);
        bfs(1);
    }
    return 0;
}
