#include <cmath>
#include <random>
#include <iostream>
#include <algorithm>
#include <queue>
#include "Employee.h"

using namespace std;

void printV( vector<int> & v){
  for(int i : v)
    cout << i << " " ;
  cout << "\n*******************************\n";
}

void printS( vector<Employee> & e){
  for(Employee i : e)
    cout << i.getSortingName() << ": " << i.getSalary() << endl;
  cout << "\n*******************************\n";
}

int main(){
  vector<int> v { 4,1,0,1,-2, 3,7,-6, 2,0,0, -9, 9};
  auto v2 =v;
  sort(begin(v2), end(v2));
  printV(v2);

  sort(begin(v2), end(v2), [](int elem1, int elem2){return elem1 > elem2;});
  printV(v2);

  sort(begin(v2), end(v2), [](int elem1, int elem2){return abs(elem1)>abs(elem2);});
  printV(v2);

  vector<Employee> staff{
    { "Kate", "Kana", 1000},
    { "Ellen", "June", 2000},
    { "Fake", "Name", 1000},
    { "Alan" , "Turing" , 2000},
    { "Grace" , "Hopper", 2000},
    { "Anita", "Borg", 2000}
  };
  
  sort(begin(staff), end(staff), 
    [](Employee e1, Employee e2){return e1.getSalary() < e2.getSalary();});

  printS(staff);
  sort(begin(staff), end(staff), 
    [](Employee e1, Employee e2){return e1.getSortingName() < e2.getSortingName();});

  printS(staff);
  stable_sort(begin(staff), end(staff), 
    [](Employee e1, Employee e2){return e1.getSalary() < e2.getSalary();});

  printS(staff);

  cout << "max element in v : " << *(max_element(begin(v), end(v))) << endl;
  cout << "min element in v : " << *(min_element(begin(v), end(v))) << endl;

  sort(begin(v2), end(v2));
  cout << "min element in v2 : " << *(begin(v2)) << endl;
  cout << "max element in v2 : " << *(end(v)-1) << endl;

  random_device randomdevice;
  mt19937 generator(randomdevice());

  printV(v2);
  shuffle(begin(v2), end(v2), generator);
  printV(v2);
  
  v2 = {1,5,4,2,9,7,3,8,2};
  cout << "Before Nth element: " << *(begin(v2) +4) << endl;
  nth_element(begin(v2), begin(v2)+4 , end(v2));
  cout << "After Nth element: " << *(begin(v2) +4) << endl;

  return 0;
}
