#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> v{1,2,3,4};

  cout << "Vector is: " << endl;
  for(auto elem: v){
    cout<< elem <<endl;
  }
  vector<int> * vptr;
  vptr = &v;
  cout<<"First element of v deref from pointer: " << (*vptr)[0] << endl;

}
