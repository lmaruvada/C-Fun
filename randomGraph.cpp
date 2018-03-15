// Random Graph generator. 
// Input : size and density of graph when prompted. 
// Output: In file graph_data.txt. First line is size of graph. 
//         Subsequent lines have ( begin_vertex, end_vertex, Edge cost, edge color).

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

double prob(){
  return (static_cast<double>(rand())/RAND_MAX);
}
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

int main(){
  int size =15;
  double density;
  cout << "Graph size: \n";
  cin >> size;
  cout << "Graph density(0,1): \n";
  cin >> density;
  bool** graph;
  int** color;
  int** cost;
  srand(time(0));
 
  graph = new bool*[size];
  color = new int*[size];
  cost = new int*[size];
  for(int i=0; i<size; ++i){
    graph[i] = new bool[size];
    color[i] = new int[size];
    cost[i] = new int[size];
  }
  
  for(int i=0; i<size; ++i)
    for(int j=i; j<size; ++j)
      if(i==j) 
        graph[i][j] = false;
      else 
        graph[i][j]=graph[j][i] = (prob() < density);

  for(int i=0; i<size; ++i)
    for(int j=i; j<size; ++j)
      if(graph[i][j]){
        color[i][j] = color[j][i] = rand()%3;
        cost[i][j] = cost[j][i] = prob()*30;
      }
  
  isConnected(graph, size);

  ofstream outp("graph_data.txt");
  outp << size << endl;
  for(int i=0; i< size; ++i)
    for(int j=0; j<size; ++j){
      if(graph[i][j])
        outp << i << "\t" << j << "\t" << cost[i][j] << "\t" << color[i][j] << endl;
    } 
  return 0;
}
