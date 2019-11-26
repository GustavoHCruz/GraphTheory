#include"Graph.h"

int main(){
   vector<vertex> G;
   vector<vector<int> > adj(5,vector<int>(5));

   enum{s,t,x,y,z};
   G = create(5);
   
   add_edge(&G[s],{t,y});
   add_edge(&G[t],{y,x});
   add_edge(&G[x],{z});
   add_edge(&G[y],{t,x,z});
   add_edge(&G[z],{s,x});

   adj[s][t] = 10;
   adj[s][y] = 5;
   adj[t][y] = 2;
   adj[t][x] = 1;
   adj[y][t] = 3;
   adj[y][x] = 9;
   adj[y][z] = 2;
   adj[x][z] = 4;
   adj[z][x] = 6;
   adj[z][s] = 7;

   Dijkstra(G,s,adj);

   assert(G[s].d == 0);
   assert(G[t].d == 8);
   assert(G[x].d == 9);
   assert(G[y].d == 5);
   assert(G[z].d == 7);
}