#include"Graph.h"

int main(){
	//EXEMPLO 1
	//		r -- s    t -- u
	//		|    |    |    |
	//		v    w -- x    y
	
	enum {r,s,t,u,v,w,x,y};

	vector<vertex> G1;
	G1 = create(8);
	add_edge(&G1[r],{s,v});
	add_edge(&G1[s],{r,w});
	add_edge(&G1[t],{u,x});
	add_edge(&G1[u],{t,y});
	add_edge(&G1[v],{r});
	add_edge(&G1[w],{s,x});
	add_edge(&G1[x],{t,w});
	add_edge(&G1[y],{u});

	BFS(G1,s);

	assert(G1[r].father == s);
	assert(G1[r].color == BLACK);
	assert(G1[r].d == 1);

	assert(G1[s].father == NIL);
	assert(G1[s].color == BLACK);
	assert(G1[s].d == 0);

	assert(G1[t].father == x);
	assert(G1[t].color == BLACK);
	assert(G1[t].d == 3);

	assert(G1[u].father == t);
	assert(G1[u].color == BLACK);
	assert(G1[u].d == 4);

	assert(G1[v].father == r);
	assert(G1[v].color == BLACK);
	assert(G1[v].d == 2);

	assert(G1[w].father == s);
	assert(G1[w].color == BLACK);
	assert(G1[w].d == 1);

	assert(G1[x].father == w);
	assert(G1[x].color == BLACK);
	assert(G1[x].d == 2);

	assert(G1[y].father == u);
	assert(G1[y].color == BLACK);
	assert(G1[y].d == 5);

	assert(diameter(G1) == 7);
	
	//EXEMPLO 2
	//      a -- c -- e
	//      |    |    |
	//      b    d    f
	
   enum {a,b,c,d,e,f};

   vector<vertex> G2;
   G2 = create(6);
   add_edge(&G2[a],{b,c});
   add_edge(&G2[b],{a});
   add_edge(&G2[c],{a,d,e});
   add_edge(&G2[d],{c});
   add_edge(&G2[e],{c,f});
   add_edge(&G2[f],{e});

   BFS(G2,a);

   assert(G2[a].father == NIL);
	assert(G2[a].color == BLACK);
	assert(G2[a].d == 0);

	assert(G2[b].father == a);
	assert(G2[b].color == BLACK);
	assert(G2[b].d == 1);

	assert(G2[c].father == a);
	assert(G2[c].color == BLACK);
	assert(G2[c].d == 1);

	assert(G2[d].father == c);
	assert(G2[d].color == BLACK);
	assert(G2[d].d == 2);

	assert(G2[e].father == c);
	assert(G2[e].color == BLACK);
	assert(G2[e].d == 2);

	assert(G2[f].father == e);
	assert(G2[f].color == BLACK);
	assert(G2[f].d == 3);

   assert(diameter(G2) == 4);
}