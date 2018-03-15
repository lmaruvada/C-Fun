#include <iostream>
using namespace std;

void Swap(int& a, int& b){
  int temp{a};
  a=b;
  b=temp;
}

int main(){
  int x{2};
  int y{8};
  cout << "Before swap : x = " << x << " ; y = " << y << endl;
  Swap(x, y);
  cout << "After swap : x = " << x << " ; y = " << y << endl;
}
