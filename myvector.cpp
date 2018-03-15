#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::vector;
using std::sort;

int main(){

  vector<int> v{1980, 1995, 2005, 2016};

  v.push_back (64);
  v.push_back(500);

  cout << "Number of elements in vector: " <<v.size() << '\n';
  
  cout << "vector's elements: " ;
  for(auto & e: v){
    cout << e << ' ';
  }
  cout << '\n';

  sort(begin(v), end(v));
  cout << "vector's elements after sort: " ;
  for(auto & e: v){
    cout << e << ' ';
  }
  cout << '\n';
}
