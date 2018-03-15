#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::vector;
using std::string;

int main(){

  vector<string> v{"Connie", "meow"};

  v.push_back ("C64");
  v.push_back("Amiga500");

  cout << "Number of elements in vector: " <<v.size() << '\n';
  
  cout << "vector's elements: " ;
  for(auto const & e: v){
    cout << e << ' ';
  }
  cout << '\n';
}
