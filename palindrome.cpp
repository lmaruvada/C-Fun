#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool palindrome(char * st, int len){
  int i = 0;
  int j = len-1;
  while(i<=j){
    if(st[i] != st[j])
      return false;
    i++;
    j--;
  }
  return true;
};

int main(){
  char str[200];
  cout << "Enter a string: " << endl;  
  gets (str);
  if(palindrome(str, strlen(str)))
    cout << "is true" << endl;
  else
    cout << "is false" << endl;
  return 0;
}
