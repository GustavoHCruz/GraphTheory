#include"Graph.h"

int main(){
   enum {a,b,c,d,e};
   vector<vertex> G = create(5);
   add_edge(&G[a],{b,c});
   add_edge(&G[b],{a,c});
   add_edge(&G[c],{a,b,d,e});
   add_edge(&G[d],{c,e});
   add_edge(&G[e],{c,d});
   vector<vector<bool>> visited(5,vector<bool>(5));
   for(int i=0;i<5;i++)
      for(int j=0;j<5;j++)
         visited[i][j] = 0;

   vector<int> C = Hierholzer(G,a,visited);

   assert(C[6] == a);
   assert(C[5] == b);
   assert(C[4] == c);
   assert(C[3] == d);
   assert(C[2] == e);
   assert(C[1] == c);
   assert(C[0] == a);
}