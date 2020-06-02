#include <iostream>
#include <vector>

using namespace std;
int getMax(vector<int> &a, int start, int end){
  int sum=0;
  for(auto i=start; i<=end; i++){
        sum+=a.at(i);
    }
  return sum;
}
vector<int> getLargestSum(vector<int> &arr){
  int max= 0, mi, mj;
  vector<int> ret;
  for(auto i=0; i<arr.size(); i++){
    for(auto j=i; j< arr.size(); j++){
       auto sum = getMax(arr, i, j);
       if(sum>max){
         max=sum;
         mi=i;
         mj=j;
       }
    }
  }
  for(auto i = mi; i<=mj; i++){
    ret.emplace_back(arr.at(i)); 
  }
  return ret;
}
int main(){
  vector<int> arr{21, 45, -67, 78};
  vector<vector<int>> matrix(arr.size(), vector<int>(arr.size(),0));
  auto ret = getLargestSum(arr);
  for(auto elem: ret){
    cout << elem << " " ;
  }
}

