#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
  stack<int> mystack;
  for (int i =0; i<10; i++) mystack.push(i*9);
  cout << "Size of mystack: " << mystack.size() << endl;
  while(!mystack.empty()){
    cout << ' ' << mystack.top();
    mystack.pop();
  }
  cout << endl;

  queue<int> myq;
  for (int i =0; i<10; i++) myq.push(i*9);
  cout << "Size of myq: " << myq.size() << endl;
  cout << "myq front is: " << myq.front() << endl;
  cout << "myq back is: " << myq.back() << endl;
  
  while(!myq.empty()){
    cout << ' ' << myq.front();
    myq.pop();
  }
  cout << endl;

  priority_queue<int> mypqTop;
  priority_queue<int> mypqLow;
  vector<int> input = {1, 7, 2, 8, 6, 9, 3, 0, 5, 11, 46, 32, 15};
  int topN = 5;
  int lowN = 5;

  // make a min heap
  for( int &x : input){
    if(mypqTop.size() < topN)
       mypqTop.push(x * (-1));
    else{
      if(((-1) * mypqTop.top()) < x) {
        mypqTop.pop();
        mypqTop.push(x * (-1));
      }
    }
  }
  
  // make a max heap
  for( int &x : input){
    if(mypqLow.size() < lowN)
       mypqLow.push(x);
    else{
      if(mypqLow.top() > x) {
        mypqLow.pop();
        mypqLow.push(x);
      }
    }
  }
  
  cout << "Numbers in stream: " ;
  for(int &x : input) 
    cout << x << ' ';
  cout << endl;
  cout << "Top " << topN << " numbers are: " ;
  while(!mypqTop.empty()){
    cout << ' ' << (mypqTop.top() * (-1)) ;
    mypqTop.pop();
  }
  cout << endl;
  cout << "Low " << lowN << " numbers are: " ;
  while(!mypqLow.empty()){
    cout << ' ' << (mypqLow.top()) ;
    mypqLow.pop();
  }
  return 0;
}
