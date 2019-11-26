#include"Graph.h"

int main(){
   int infi = inf/2;
   vector<vertex> G;
   vector<vector<int>> adj = {{0,3,8,infi,-4},{infi,0,infi,1,7},{infi,4,0,infi,infi},{2,infi,-5,0,infi},{infi,infi,infi,6,0}};

   G = create(5);

   vector<vector<int>> W = Floyd_Warshall(adj);

   assert(W[0][0] == 0);
   assert(W[0][1] == 1);
   assert(W[0][2] == -3);
   assert(W[0][3] == 2);
   assert(W[0][4] == -4);
   assert(W[1][0] == 3);
   assert(W[1][1] == 0);
   assert(W[1][2] == -4);
   assert(W[1][3] == 1);
   assert(W[1][4] == -1);
   assert(W[2][0] == 7);
   assert(W[2][1] == 4);
   assert(W[2][2] == 0);
   assert(W[2][3] == 5);
   assert(W[2][4] == 3);
   assert(W[3][0] == 2);
   assert(W[3][1] == -1);
   assert(W[3][2] == -5);
   assert(W[3][3] == 0);
   assert(W[3][4] == -2);
   assert(W[4][0] == 8);
   assert(W[4][1] == 5);
   assert(W[4][2] == 1);
   assert(W[4][3] == 6);
   assert(W[4][4] == 0);
}