#include <iostream>
#include <string>

using namespace std;

void underlineString(string const& s) {
  string line(s.length(), '=');
  cout << s << endl;
  cout << line << endl;
}

int main(){
  cout << "Please entr a string: " ;
  string str{};
  getline(cin, str);
  //cin >> str;
  cout << endl;
  underlineString(str);
}
