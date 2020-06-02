#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>> &m, vector<vector<bool>> &v, int i, int j){
  return((i<m.size()) && (j<m[0].size()) && !v[i][j]);
}
void Print(vector<vector<int>> &m, vector<vector<bool>> &v, int i, int j){
  cout << m[i][j] << " ";
  v[i][j]=true;
}
int main(){
  vector<vector<int>> matrix{{1,2,3,4},
                             {5,6,7,8},
                             {9,10,11,12},
                             {13,14,15,16}};
  int m= matrix.size();
  int n = matrix[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n,false));
  enum direction{right, down, left, up};
  int i(0), j(0);
  Print(matrix, visited, i, j);
  direction dir=right;
  while(1){
    if(dir==right){
      if(isValid(matrix, visited, i, j+1)){
        j++;
        Print(matrix, visited, i, j);
        continue;
      } else {
        if(isValid(matrix, visited, i+1, j)){
          dir = down;
          continue;
        } else {
          break;
        }
      }
    }
    if(dir==down){
      if(isValid(matrix, visited, i+1, j)){
        i++;
        Print(matrix, visited, i, j);
        continue;
      } else {
        if(isValid(matrix, visited, i, j-1)){
          dir = left;
          continue;
        } else {
          break;
        }
      }
    }
    if(dir==left){
      if(isValid(matrix, visited, i, j-1)){
        j--;
        Print(matrix, visited, i, j);
        continue;
      } else {
        if(isValid(matrix, visited, i-1, j)){
          dir = up;
          continue;
        } else {
          break;
        }
      }
    }
    if(dir==up){
      if(isValid(matrix, visited, i-1, j)){
        i--;
        Print(matrix, visited, i, j);
        continue;
      } else {
        if(isValid(matrix, visited, i, j+1)){
          dir = right;
          continue;
        } else {
          break;
        }
      }
    }
  }
}
