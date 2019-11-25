#include"Graph.h"

int index;

void modified_DFS_Visit(vector<vertex> &G,int u,vector<int> &list){
   int v;

   G[u].color = GRAY;
   G[u].d = timer++;

   for(int i=0;i<G[u].adj.size();i++){
      v = G[u].adj[i];
      if(G[v].color == WHITE){
         G[v].parent = G[u].name;
         DFS_Visit(G,v);
      }
   }
   G[u].f = timer++;
   G[u].color = BLACK;
   list[index++] = G[u].name;
}

vector<int> Topological_Sort(vector<vertex> &G){
   vector<int> list;

   for(int u=0;u<G.size();u++){
      G[u].color = WHITE;
      G[u].parent = NIL;
   }
   timer = 1;
   index = 0;

   for(int u=0;u<G.size();u++)
      if(G[u].color == WHITE)
         modified_DFS_Visit(G,u,list);

   return list;
}