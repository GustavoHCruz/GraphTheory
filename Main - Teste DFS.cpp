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

   DFS(G);

   assert(G[r].d == 1);
	assert(G[r].f == 14);
	assert(G[r].father == NIL);
	
	assert(G[s].d == 3);
	assert(G[s].f == 12);
	assert(G[s].father == v);
	
	assert(G[t].d == 4);
	assert(G[t].f == 9);
	assert(G[t].father == s);
	
	assert(G[u].d == 15);
	assert(G[u].f == 16);
	assert(G[u].father == NIL);
	
	assert(G[v].d == 2);
	assert(G[v].f == 13);
	assert(G[v].father == r);
	
	assert(G[w].d == 10);
	assert(G[w].f == 11);
	assert(G[w].father == s);
	
	assert(G[x].d == 5);
	assert(G[x].f == 8);
	assert(G[x].father == t);
	
	assert(G[y].d == 6);
	assert(G[y].f == 7);
	assert(G[y].father == x);
}