#include"Graph.h"

int main(){
   vector<vertex> G;
   vector<edge_list> adj(10);

   enum{s,t,x,y,z};
   
   G = create(5);

   adj[0].u = s;
   adj[0].v = t;
   adj[0].w = 6;

   adj[1].u = s;
   adj[1].v = y;
   adj[1].w = 7;

   adj[2].u = t;
   adj[2].v = x;
   adj[2].w = 5;

   adj[3].u = x;
   adj[3].v = t;
   adj[3].w = -2;

   adj[4].u = t;
   adj[4].v = y;
   adj[4].w = 8;

   adj[5].u = t;
   adj[5].v = z;
   adj[5].w = -4;

   adj[6].u = y;
   adj[6].v = z;
   adj[6].w = 9;

   adj[7].u = z;
   adj[7].v = x;
   adj[7].w = 7;

   adj[8].u = y;
   adj[8].v = x;
   adj[8].w = -3;

   adj[9].u = z;
   adj[9].v = s;
   adj[9].w = 2;

   Bellman_Ford(G,adj,s);

   assert(G[s].d == 0);
   assert(G[s].parent == NIL);
   assert(G[t].d == 2);
   assert(G[t].parent == x);
   assert(G[x].d == 4);
   assert(G[x].parent == y);
   assert(G[y].d == 7);
   assert(G[y].parent == s);
   assert(G[z].d = -2);
   assert(G[z].parent == t);
}