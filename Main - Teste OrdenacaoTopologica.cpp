#include"Graph.h"

int main(){
   enum{r,s,t,u,v,w,x,y};

   vector<vertex> G;
   G = create(8);

   add_edge(&G[r],{v});
   add_edge(&G[s],{t,w,x});
   add_edge(&G[t],{x});
   add_edge(&G[u],{v});
   add_edge(&G[v],{s});
   add_edge(&G[w],{});
   add_edge(&G[x],{y});
   add_edge(&G[y],{});

   vector<int> list = Topological_Sort(G);

   assert(list[0] == u);
   assert(list[1] == r);
   assert(list[2] == v);
   assert(list[3] == s);
   assert(list[4] == w);
   assert(list[5] == t);
   assert(list[6] == x);
   assert(list[7] == y);
}