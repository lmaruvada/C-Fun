#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


void insertInMatrix( int* matrix, int num, int x, int y){
  matrix[x*num+y] =1; 
  matrix[y*num+x] =1;
}
void printMatrix( int * matrix, int num){

   for(int i = 0; i<num; i++){
     for(int j =0; j<num; j++){
      cout << matrix[i*num+j] << "  " ;
     }
     cout << endl;
   }
}

void isConnected( int * matrix, int num){

  int c_size =0;
  queue<int> myq;
  int * close = new int[num];
  int * open = new int[num];
  for(int i =0; i<num; i++){
    close[i]=0;
    open[i]=0;
  }
  close[0] = 1; // get the first node
  open[0] =1;
  c_size++; // there is at least one node 
  for(int j = 0 , i=0; j<num; j++){
    if(matrix[j*num] == 1){
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
    for(int k =0; k<num; k++)
    for(int j = 0 ; j<num; j++){
      if(matrix[j*num+curr] == 1){
        if((close[j] ==0) && (open[j] == 0)){
          myq.push(j);
          open[j]=1;
        }
      }
    }
  } 
  if(c_size == num) 
    cout << " Is Connected \n";
  else 
    cout << " Is NOT Connected: " << "C_size: " << c_size << " num: " << num << endl;
}

int main (){

  int n =0;
  string s;
  
  ifstream ifs2("graph1.dat");
  if(getline(ifs2,s))
    n = stoi(s);

  cout << "Number of nodes: " << n << endl;
  auto mat = new int[n*n];

  int x=0,y=0;
  while(getline(ifs2, s)){
    size_t found = s.find(',');
    if(found!= std::string::npos){
      x = stoi(s.substr(0, found));
      y = stoi(s.substr(found+1));
      insertInMatrix( mat, n,x,y);
      cout << "x = " << x << " , y = " << y << endl;
    }
  }
  printMatrix(mat, n);
  isConnected(mat,n);
  return 0;
}
