#include"Graph.h"
#define tam 500 //Grau de precisão

void MST_Prim(vector<vertex> &G,vector<vector<short> > &adj,int r){
	short u,v;
	
	for(u=0;u<G.size();u++){
		G[u].key = inf;
		G[u].father = NIL;
		G[u].visited = false;
	}
	G[r].key = 0;
	G[r].visited = true;
	
	vector<short> priority_list(G.size());

	for(int i=0;i<G.size();i++){
		priority_list[i] = G[i].name;
	}

	while(priority_list.size() > 0){
		u = priority_list[0];
		priority_list.erase(priority_list.begin());
		G[u].visited = true;
		for(int i=0;i<G.size();i++){
			v = i;
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
	vector<vector<short> > adj(n,vector<short>(n));
	random_device rd;
	uniform_int_distribution<> dis(0,32766);
	
	for(short i=0;i<n;i++){
		G[i].name = i;
		adj[i][i] = inf;
		for(short j=i+1;j<n;j++){
			adj[i][j] = dis(rd);
			adj[j][i] = adj[i][j];
		}
	}

	MST_Prim(G,adj,0);
	
	return G;
}

int main(){
	vector<vertex> G;
	
	for(int n=250;n<=2000;n+=250){
		float media = 0;
		for(int i=0;i<tam;i++){
			G = RTP(n);
			assert(check_tree(G) == true);
			media += diameter(G);
		}
		cout << media/tam << endl;
	}
}
