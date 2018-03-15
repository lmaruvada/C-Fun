// Write a generic sum function for various data types

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T sum (vector<T>& myarr){
   T tot =0;
   for(int i =0; i<myarr.size(); i++)
   {
     cout << "myaarr[" << i<< "] " <<  myarr[i] << " : Tot " << tot << endl;
     tot += myarr[i];
    }
   return tot;
}

string sum (vector<string>& myarr){
   string tot ;
   for(int i =0; i<myarr.size(); i++)
   {
     cout << "myaarr[" << i<< "] " <<  myarr[i] << " : Tot " << tot << endl;
     tot = tot + myarr[i] + " ";
    }
   return tot;
}

int main(){
  vector<int> arr1(5, 20);
  cout<< "Sum of integers: " << sum(arr1) << endl;

  vector<double> arr2(5, 20.123);
  cout<< "Sum of doubles: " << sum(arr2) << endl;

  vector<string> arr3(5, "Lalitha");
  cout<< "Sum of strings: " << sum(arr3) << endl;

 return 0;
}
