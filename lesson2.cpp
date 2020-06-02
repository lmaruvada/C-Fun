#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

enum class State {kEmpty, kObstacle};

string CellString (State s){
  return (s==State::kObstacle)? "Poop" :  "0";
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
  for(int i =0; i<board.size(); i++){
    for(int j = 0; j < board[i].size(); j++){
      cout << CellString(board[i][j]) << " , ";
    }
    cout <<endl;
  }
}

int main(){
  auto readBoardVec = ReadBoardFile("1.board");
  PrintBoard(readBoardVec);
}
