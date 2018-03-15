#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  ifstream word_file("wordsort.txt");
  istream_iterator<string> start(word_file), end;
  vector<string> words(start,end);
  cout << " \n\n words are read \n";
  for(auto str : words)
    cout << str << "\t";
  sort(words.begin(), words.end());
  cout << "\n\nwords are sorted\n";
  for(auto str : words)
    cout << str << "\t";
  cout << endl;
}
