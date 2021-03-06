#include"Graph.h"

int main(){
   enum {a,b,c,d,e,f,g,h};
   vector<vertex> G = create(8);
   add_edge(&G[a],{b,c,d,e,f,g,h});
   add_edge(&G[b],{a,c,d,e,f,g,h});
   add_edge(&G[c],{a,b,d,e,f,g,h});
   add_edge(&G[d],{a,b,c,e,f,g,h});
   add_edge(&G[e],{a,b,c,d,f,g,h});
   add_edge(&G[f],{a,b,c,d,e,g,h});
   add_edge(&G[g],{a,b,c,d,e,f,h});
   add_edge(&G[h],{a,b,c,d,e,f,g});
   vector<vector<int>> w(8,vector<int>(8));
   w[0][1] = 20;
   w[0][2] = 32;
   w[0][3] = 20;
   w[0][4] = 32;
   w[0][5] = 28;
   w[0][6] = 45;
   w[0][7] = 41;
   w[1][0] = 20;
   w[1][2] = 14;
   w[1][3] = 28;
   w[1][4] = 32;
   w[1][5] = 20;
   w[1][6] = 40;
   w[1][7] = 22;
   w[2][0] = 32;
   w[2][1] = 14;
   w[2][3] = 42;
   w[2][4] = 45;
   w[2][5] = 32;
   w[2][6] = 51;
   w[2][7] = 22;
   w[3][0] = 20;
   w[3][1] = 28;
   w[3][2] = 42;
   w[3][4] = 14;
   w[3][5] = 20;
   w[3][6] = 28;
   w[3][7] = 41;
   w[4][0] = 31;
   w[4][1] = 32;
   w[4][2] = 45;
   w[4][3] = 14;
   w[4][5] = 14;
   w[4][6] = 14;
   w[4][7] = 36;
   w[5][0] = 28;
   w[5][1] = 20;
   w[5][2] = 31;
   w[5][3] = 20;
   w[5][4] = 14;
   w[5][6] = 20;
   w[5][7] = 22;
   w[6][0] = 45;
   w[6][1] = 40;
   w[6][2] = 51;
   w[6][3] = 28;
   w[6][4] = 14;
   w[6][5] = 20;
   w[6][7] = 36;
   w[7][0] = 41;
   w[7][1] = 22;
   w[7][2] = 22;
   w[7][3] = 41;
   w[7][4] = 36;
   w[7][5] = 22;
   w[7][6] = 36;

   vector<int> C = TSP_NN(G,a,w);

   assert(C[0] == a);
   assert(C[1] == b);
   assert(C[2] == c);
   assert(C[3] == h);
   assert(C[4] == f);
   assert(C[5] == e);
   assert(C[6] == d);
   assert(C[7] == g);
   assert(C[8] == a);
}