// Implementation of Jarnik-Prim Algorithm to find MST in a graph 

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
void isConnected( bool ** matrix, int size){

  int c_size =0;
  queue<int> myq;
  int * close = new int[size];
  int * open = new int[size];
  for(int i =0; i<size; ++i){
    close[i]=0;
    open[i]=0;
  }
  close[0] = 1; // get the first node
  open[0] =1;
  c_size++; // there is at least one node
  for(int j = 0 , i=0; j<size; ++j){
    if(matrix[i][j]){
      if(close[j] ==0){
        open[j] =1;
        myq.push(j);
      }
    }
  }
  int curr;
  while(!myq.empty()){
    curr = myq.front();
    myq.pop();
    close[curr] =1;
    c_size++;
    for(int i =0; i<size; ++i)
    for(int j = 0 ; j<size; ++j){
      if(matrix[i][j]){
        if((close[j] ==0) && (open[j] == 0)){
          myq.push(j);
          open[j]=1;
        }
      }
    }
  }
  if(c_size == size)
    cout << " Is Connected \n";
  else
    cout << " Is NOT Connected: " << "C_size: " << c_size << " size: " << size << endl;
}
int find(int * parent, int i){
  if(parent[i] == -1)
    return 1;
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

void addToEdgeList(vector<edge *> & el, int ival, int size, bool ** matrix
              , bool * close, int** cost){
  for(int j = 0; j < size; ++j){
    if(matrix[ival][j]){
      if(!close[j]){
        vector<edge *>::iterator it;
        it = el.begin();
        it = el.insert(it, new edge(ival,j,cost[ival][j]));
      }
    }
  }
  sort(begin(el), end(el), [](edge * e1, edge * e2) { return e1->cost > e2->cost;});
}

void primAlgo(bool** matrix, int** c, int size){
  bool  close[size];
  
  for(int i=0; i<size; ++i){
    close[i] = false;
  }

  close[0] = true;

  vector<edge *> edgeList;
  vector<edge *> MSTedgeList;
  addToEdgeList(edgeList, 0, size, matrix, close, c);

  do {
    edge* elem;
    elem = edgeList.back();
    edgeList.pop_back();
    if(!close[elem->n2]){
      MSTedgeList.push_back(elem);
      close[elem->n2]=true;
      addToEdgeList(edgeList, elem->n2, size, matrix, close, c);
    }
  } while (!edgeList.empty());
  int total_cost=0;
  cout << "Jarnik-Prim's MST: \n"; 
  for(int i =0; i<MSTedgeList.size(); i++){
    cout << "(" << MSTedgeList[i]->n1 <<  " , " << MSTedgeList[i]->n2 << ") -> ";
    cout << MSTedgeList[i]->cost << endl;
    total_cost += MSTedgeList[i]->cost;
  }
  cout << "Jarnik-Prim's MST cost: " << total_cost << endl; 
}

int main(){
  int size =7;
  bool** graph;
  int** color;
  int** cost;
  srand(time(0));
 
  // allocate space for graph, cost and color
  graph = new bool*[size];
  color = new int*[size];
  cost = new int*[size];
  for(int i=0; i<size; ++i){
    graph[i] = new bool[size];
    color[i] = new int[size];
    cost[i] = new int[size];
  }

  for(int i=0; i<size; ++i)
    for(int j=i; j<size; ++j){
        graph[i][j] = false;
        cost[i][j] = 0;
    }

  
  // read data from file to populate graph and cost
  ifstream mfile("prim_data.txt");
  int i, j, c;
  while(mfile >> i >> j >> c ){
    graph[i][j] = graph[j][i] = true;
    cost[i][j] = cost[j][i] = c;
  } 
  
  // Verify if the graph is connected
  isConnected(graph, size);

  primAlgo(graph, cost, size);

  return 0;
}
