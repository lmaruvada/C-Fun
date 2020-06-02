#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

enum class State {kEmpty, kObstacle, kClosed, kPath};

string CellString (State s){
  switch(s){
    case State::kEmpty : return "0";
    case State::kObstacle : return "Poop";
    case State::kClosed : return "Closed";
    case State::kPath : return "Path";
    default : return "Unknown";
  }
}
vector<State> ParseLine(string line){
  vector<State> vec;
  int n;
  char c;
  istringstream my_line(line);
  while(my_line >> n >> c){
   if(n)
     vec.push_back(State::kObstacle);
   else
     vec.push_back(State::kEmpty);
  }
  return vec;
}
vector<vector<State>> ReadBoardFile(string fname){
  std::ifstream my_file(fname);
  vector<vector<State>> boardVec;
  if(my_file){
    cout << "The file has been created" <<endl;
    string line;
    while(getline(my_file, line)){
      boardVec.push_back(ParseLine(line));
    }
  }
  return boardVec;
}

void PrintBoard(vector<vector<State>> board){
  cout << "Print board: " << endl;
  for(auto row: board){
    for(auto elem : row){
      cout << CellString(elem) << " , ";
    }
    cout <<endl;
  }
}

bool Compare(vector<int> a, vector<int>b){
  return ((a[2]+a[3]) > (b[2] + b[3])) ;
}
//sorts the open list according to the sum of  h+g
void CellSort(vector<vector<int>> & open){
  sort(begin(open), end(open), Compare);
};

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> & openNodes, 
               vector<vector<State>>& board){
  vector<int> node{x,y,g,h};
  openNodes.push_back(node);
  board[x][y] = State::kClosed;
}
//computes the distance to the goal
int Heuristic(int x1, int y1, int x2, int y2){
  return (abs(x1 - x2) + abs(y1-y2));
};

//ensure thar the potential neighbor coordinates are on the grid and
// that the cell is open
bool CheckValidCell(int x, int y, vector<vector<State>> & board){
  if((x >= 0 && x<board.size()) && (y >= 0 && y<board[0].size())){
     return (board[x][y] == State::kEmpty) ;
  }
  return false;
}

//loops through the current node's neighbors and calls appropriate functions 
//to add neighbors to the open list
void ExpandNeighbors(vector<int> curr, vector<vector<int>>& open, 
                     vector<vector<State>>& board, int goal[2]){
  // directional deltas
  const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

  for(auto row : delta){
    auto newX = curr[0]+row[0];
    auto newY = curr[1]+row[1];
    if(CheckValidCell(newX, newY, board)){
      auto newG = curr[2]+1;
      auto newH = Heuristic(newX, newY, goal[0], goal[1]);
      AddToOpen(newX, newY, newG, newH, open, board); 
    }
  }
};
vector<vector<State>> Search(vector<vector<State>> board, int start[2], int goal[2]){
  
  vector<vector<int>> open{};
  AddToOpen(start[0], start[1], 0, Heuristic(start[0], start[1], goal[0], goal[1]), open, board);
  while(!open.empty()){
    CellSort(open);
    auto current = open.back();
    open.pop_back();

    int x = current[0];
    int y = current[1];
    board[x][y] = State::kPath;
    if((x == goal[0]) && (y== goal[1])) 
      return board;
    ExpandNeighbors(current, open, board, goal); 
  }
  cout << "No Path Found!" << endl;
  return vector<vector<State>>{};
}

int main(){
  int start[2]{0,0};
  int goal[2]{4,5};
  auto readBoardVec = ReadBoardFile("1.board");
  //PrintBoard(readBoardVec);
  auto solution = Search(readBoardVec, start, goal);
  PrintBoard(solution);
  cout << "Heuristic: " << Heuristic(0,0, 4, 5) << endl; 
}
