#include <iostream>

using namespace std;

int main(){
  cout << "Hello World!" << endl;
  cout << " Size of array: " ;
  int size;
  cin >> size ;
  int *arr = new int(size);
  int *temp = new int(size);
  cout << " Give the array : \n" ;
  for( int i = 0; i<6; i++){
    cin >> arr[i] ;
  }
  for( int i = 0; i<6; i++){
    cout << arr[i] << " " ;
  }
  sort( arr,temp 0, size-1);
  cout << endl;
  return 0;
}

int sort( int &a, int &temp, int beg, int end){
  int countInv =0;
  if(beg <=end) return 0;
  int mid = (beg+end)/2;
  countInv += sort(a, beg, mid);
  countInv += sort(a, mid+1, end);
  countInv += merge(a, beg, mid, end);
  return countInv;
}

int merge(int &a, int &t, int b, int m, int e){
  for( int ii=b; ii<=e; ii++)
    t[ii] = a[ii]; 
  int cInv =0;
  int i=b, j=m+1, k=b;
  for (int ii=b; a[:q

}

