#include"Graph.h"
#define tam 500 //Grau de precisão

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
