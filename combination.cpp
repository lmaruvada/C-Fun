#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

// Get all sets from a vector of numbers. Each set can have max of m elements
using namespace std;

set<set<int>> getSet(vector<int> ids, int m){
  set<set<int>> ret;
  queue<set<int>> tempRet;
  vector<int> cset;
  for(auto i: ids){
    if(find(begin(cset), end(cset), i) == cset.end())
      cset.emplace_back(i);
  }
  //cout << "size of cset " << cset.size() << endl;
  for(auto i : cset){
    set<int> temp;
    temp.insert(i);
    ret.insert(temp);
    tempRet.push(temp);
  }
  //cout << "size of queue " << ret.size() << endl;
  bool done = false;
  while(!done){
    auto r = tempRet.front();
    tempRet.pop();
    for(auto elempos = r.size() ; elempos < cset.size(); elempos++){
      auto tempr = r;
      tempr.insert(cset[elempos]);
      //cout << "size of tempr " << tempr.size() << endl;
      if(tempr.size()>m){
        done = true;
      }
      else if(tempr.size() > r.size()){
        tempRet.push(tempr);
        ret.insert(tempr);
        //cout << "size of queue " << ret.size() << endl;
      }
    }
  }
  //cout << "size of queue " << ret.size() << endl;
  return ret;
}
int main(){
  vector<int> ids {1,2,3,1,2,3,4};
  int m{3};
  
  auto sets = getSet(ids, m); 
  for (auto s: sets){
    cout << "{ ";
    for(auto elem: s){
      cout << elem << " ";
    }
    cout << " }" <<endl;
  }

}
