#include <string>
using namespace std;

class Employee{
  public:
    Employee(string first, string last, int sal): 
         firstName(first), lastName(last), salary(sal){};
    int getSalary() {return salary;}
    string getSortingName(){return lastName+", " +  firstName;} 
  private:
    string firstName;
    string lastName;
    int salary;
};
