#include <iostream>
#include <string>

using namespace std;

int main(){
  cout << "Message? ";
  string message{};
  getline(cin, message);
 
  string flowerLine(message.length()+4 ,  '*');
  cout << endl;
  cout << flowerLine << endl;
  cout << "* " << message << " *\n";
  cout << flowerLine << endl;
}
