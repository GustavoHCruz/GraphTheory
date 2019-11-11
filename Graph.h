#include<iostream>
#include<random>
#include<vector>
#include<queue>
#include<assert.h>
#include<algorithm>
#define NIL -1
#define inf 2147483647
enum {WHITE,GRAY,BLACK};

using namespace std;

struct vertex{
	int name;
	int father;
	int color;
	int d;
   int f; //DFS
	int p; //DisjointSet
	int rank; //DisjointSet
	int key; //Prim
	bool visited;
	vector<int> adj;
};

vector<vertex> create(int n){
	vector<vertex> G(n);
	
	for(int i=0;i<n;i++){
		G[i].name = i;
		G[i].father = NIL;
		G[i].color = WHITE;
		G[i].d = inf;
		G[i].p = NIL;
		G[i].rank = inf;
		G[i].key = inf;
		G[i].visited = false;
	}
	return G;
}

void add_edge(vertex *v,vector<int> adj){
	for(int i=0;i<adj.size();i++){
		v->adj.push_back(adj[i]);
	}
}

//======================================================================================= DisjointSet Implementation
void Make_Set(vector<vertex> &G,int x){
	G[x].p = G[x].name;
	G[x].rank = 0;
}

int Find_Set(vector<vertex> &G,int x){
	int u;
	
	if(G[x].name != G[x].p){
		u = Find_Set(G,G[x].p);
		G[x].p = G[u].name;
	}
	return G[x].p;
}

void Link(vector<vertex> &G,int x,int y){
	int u;
	
	if(G[x].rank > G[y].rank)
		G[y].p = G[x].name;
	else{
		u = Find_Set(G,y);
		G[x].p = u;
		if(G[u].rank == G[y].rank)
			G[y].rank++;
	}
}

void Union(vector<vertex> &G,int x,int y){
	x = Find_Set(G,x);
	y = Find_Set(G,y);
	Link(G,x,y);
}
//======================================================================================= DisjointSet End

//======================================================================================= BFS Implementation
void BFS(vector<vertex> &G,int s){ //Breadth First Search
	int u,v;

	for(int i=0;i<G.size();i++){
		G[i].d = inf;
		G[i].father = NIL;
		G[i].color = WHITE;
	}
	G[s].d = 0;
	G[s].father = NIL;
	G[s].color = GRAY;

	queue<vertex> Q;
	Q.push(G[s]);
	while(!Q.empty()){
		u = Q.front().name;
		Q.pop();
		for(int i=0;i<G[u].adj.size();i++){
			v = G[u].adj[i];
			if(G[v].color == WHITE){
				G[v].d = G[u].d + 1;
				G[v].color = GRAY;
				G[v].father = G[u].name;
				Q.push(G[v]);
			}
		}
		G[u].color = BLACK;
	}
}

int diameter(vector<vertex> G){
	int bigger,a,b;

	bigger = -1;
	BFS(G,0);
	for(int i=0;i<G.size();i++)
		if(bigger < G[i].d){
			bigger = G[i].d;
			a = i;
		}

	bigger = -1;
	BFS(G,a);
	for(int i=0;i<G.size();i++)
		if(bigger < G[i].d){
			bigger = G[i].d;
			b = i;
		}

	return G[b].d;
}
//======================================================================================= BFS End

//======================================================================================= DFS Implementation
int timer;

void DFS_Visit(vector<vertex> &G,int u){
   int v;

   G[u].color = GRAY;
   G[u].d = timer++;

   for(int i=0;i<G[u].adj.size();i++){
      v = G[u].adj[i];
      if(G[v].color == WHITE){
         G[v].father = G[u].name;
         DFS_Visit(G,v);
      }
   }
   G[u].f = timer++;
   G[u].color = BLACK;
}

void DFS(vector<vertex> &G){ //Depth First Search
   for(int u=0;u<G.size();u++){
      G[u].color = WHITE;
      G[u].father = NIL;
   }
   timer = 1;

   for(int u=0;u<G.size();u++)
      if(G[u].color == WHITE)
         DFS_Visit(G,u);
}
//======================================================================================= DFS End

//======================================================================================= Random Tree Random Walk Implementation
bool check_tree(vector<vertex> &G){
	random_device rd;
	uniform_int_distribution<> dis(0, G.size()-1);
	int edges=0;
	
	for(int i=0;i<G.size();i++)
		edges += G[i].adj.size();

	if((edges/2) != G.size()-1)
		return false;
	
	int s = dis(rd);
	
	BFS(G,s);
	
	for(int i=0;i<G.size();i++)
		if(G[i].d == inf)
			return false;
	return true;
}

vector<vertex> RTRW(int n){ //Random Tree Random Walk
	random_device rd;
	uniform_int_distribution<> dis(0, n-1);
	vector<vertex> G(n);
	int u,v,edges=0;
	
	for(int i=0;i<G.size();i++){
		G[i].visited = false;
		G[i].name = i;
	}
	u = dis(rd); //Randomizando um número
   G[u].visited = true;
	while(edges < n-1){
		v = dis(rd); //Randomizando um número
		if(G[v].visited == false){
			G[u].adj.push_back(v);
			G[v].adj.push_back(u);
			G[v].visited = true;
			edges++;
		}
		u = v;
	}
	return G;
}
//======================================================================================= Random Tree Random Walk End

//======================================================================================= Random Tree Kruskal Implementation
struct edge_list{
	int w;
	int u;
	int v;
};

bool sortByW(const edge_list &lhs, const edge_list &rhs){
	return lhs.w < rhs.w;
}

vector<vertex> MST_Kruskal(vector<vertex> &G,vector<vector<int> > &adj){
	vector<vertex> A(G.size());
	
	for(int i=0;i<G.size();i++){
		Make_Set(G,i);
		A[i].name = i;
	}
	
	vector<edge_list> edge_list((G.size())*(G.size()-1)/2);
	
	int k=0;
	for(int i=0;i<G.size();i++){
		for(int j=i+1;j<G.size();j++){
			edge_list[k].u = i;
			edge_list[k].v = j;
			edge_list[k++].w = adj[i][j];
		}
	}

	stable_sort(edge_list.begin(),edge_list.end(),sortByW);
	
	for(int i=0;i<edge_list.size();i++){
		if(Find_Set(G,edge_list[i].u) != Find_Set(G,edge_list[i].v)){
			A[edge_list[i].u].adj.push_back(edge_list[i].v);
			A[edge_list[i].v].adj.push_back(edge_list[i].u);
			Union(G,edge_list[i].u,edge_list[i].v);
		}
	}
	
	return A;
}

vector<vertex> RTK(int n){ //Random Tree Kruskal
	vector<vertex> G(n);
	vector<vector<int> > adj(n,vector<int>(n));
	random_device rd;
	uniform_int_distribution<> dis(0,2147483646);
	
	for(int i=0;i<n;i++){
		G[i].name = i;
		adj[i][i] = inf;
		for(int j=i+1;j<n;j++){
			adj[i][j] = dis(rd);
		}
	}
	return MST_Kruskal(G,adj);
}
//======================================================================================= Random Tree Kruskal End

//======================================================================================= Random Tree Prim Implementation
int extract_min(vector<vertex> &G,vector<int> &Q){
	int min = G[Q[0]].key,remove_index=0,aux;

	for(int i=1;i<Q.size();i++){
		if(G[Q[i]].key < min){
			min = G[Q[i]].key;
			remove_index = i;
		}
	}
	aux = G[Q[remove_index]].name;
	Q.erase(Q.begin()+remove_index);
	return aux;
}

void MST_Prim(vector<vertex> &G,vector<vector<int> > &adj,int r){
	int u,v;

	for(u=0;u<G.size();u++){
		G[u].key = inf;
		G[u].father = NIL;
		G[u].visited = false;
	}
	G[r].key = 0;
	
	vector<int> Q;

	for(int i=0;i<G.size();i++)
		Q.push_back(G[i].name);

	while(Q.size() > 0){
		u = extract_min(G,Q);
		G[u].visited = true;
		for(int v=0;v<G.size();v++){
			if(G[v].visited == false && adj[u][v] < G[v].key){
				G[v].father = u;
				G[v].key = adj[u][v];
			}
		}
	}

	for(int i=0;i<G.size();i++){
		if(G[i].father != NIL){
			G[i].adj.push_back(G[i].father);
			G[G[i].father].adj.push_back(i);
		}
	}
}

vector<vertex> RTP(int n){ //Random Tree Prim
	vector<vertex> G(n);
	vector<vector<int> > adj(n,vector<int>(n));
	random_device rd;
	uniform_int_distribution<> dis(0,2147483646);
	
	for(int i=0;i<n;i++){
		G[i].name = i;
		adj[i][i] = inf;
		for(int j=i+1;j<n;j++){
			adj[i][j] = dis(rd);
			adj[j][i] = adj[i][j];
		}
	}

	MST_Prim(G,adj,(dis(rd)%n));
	
	return G;
}
//======================================================================================= Random Tree Prim End