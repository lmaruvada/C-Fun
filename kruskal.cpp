// Implementation of Kruskal Algorithm to find MST in a graph 

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

double prob(){
  return (static_cast<double>(rand())/RAND_MAX);
}
struct edge{
     int n1, n2, cost;
     edge(int node1, int node2, int edge_cost):n1(node1), n2(node2), cost(edge_cost){};
     edge():n1(0), n2(0), cost(0){};
};

int find(int * parent, int i){
  if(parent[i] == -1)
    return i;
  return find(parent, parent[i]);
}

void Union(int * parent, int x, int y){
  int xfound = find(parent, x);
  int yfound = find(parent, y);
  parent[xfound] = yfound; 
} 

bool isCycle(vector<edge * > graph_vector, int size){
  int parent[size];
  for(int i=0; i<size; i++)
    parent[i] = -1;
  
  for(int i=0; i<graph_vector.size(); i++){
    int x = find(parent, graph_vector[i]->n1);
    int y = find(parent, graph_vector[i]->n2);
    if(x==y)
      return true;
    Union(parent, x, y);
  }
  return false;
}

int main(){
  int size =7;
  srand(time(0));
  vector<edge *> graph;
  vector<edge *> kruskalMST;
  vector<edge *>::iterator it;
  it = graph.begin();
 
  
  // read data from file to populate graph 
  ifstream mfile("prim_data.txt");
  int i, j, c;
  while(mfile >> i >> j >> c ){
     it = graph.insert(it, new edge(i,j,c));
  } 
  sort(begin(graph), end(graph), [](edge * e1, edge * e2) { return e1->cost < e2->cost;});
  edge * candidate;
  candidate = graph[0];
  kruskalMST.push_back(candidate);
  candidate = graph[1];
  kruskalMST.push_back(candidate);
  for(int i=2; ((i< graph.size()) && (kruskalMST.size() != (size-1))); i++){
    candidate = graph[i];
    kruskalMST.push_back(candidate);
    if(isCycle(kruskalMST, size)){ 
      cout << "There is a cycle:\n";
      for(int j =0; j<kruskalMST.size(); j++){
        cout << "(" << kruskalMST[j]->n1 << "," << kruskalMST[j]->n2 << ") -> ";
        cout << kruskalMST[j]->cost << endl; 
      }
      cout << "**********************\n";
      kruskalMST.pop_back();
    }
  } 

  cout << "Number of edges in kruskalMST: " << kruskalMST.size() << endl; 
  if(kruskalMST.size() == (size -1)){
    cout << " There is a Kruskal MST.\n";
    for(int j =0; j<kruskalMST.size(); j++){
      cout << "(" << kruskalMST[j]->n1 << "," << kruskalMST[j]->n2 << ") -> ";
      cout << kruskalMST[j]->cost << endl; 
    }
    cout << "**********************\n";
  }
  else
    cout << " There is NO Kruskal MST.";


  return 0;
}
