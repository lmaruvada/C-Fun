#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isAnagram(string s1, string s2){
  if(s1.length() != s2.length())
    return false;
  map<char, int> map_st1;
  
  return true;

}

int main(){
  string s1 = "pear";
  string s2 = "pare";

  if(isAnagram(s1, s2))
    cout << "Strings are Anagram" <<endl;
  else
    cout << "Strings are NOT anagram" << endl;
}
