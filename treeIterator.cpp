#include<iostream>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
class Node{
  public:
    int data;
    Node * left;
    Node * right;
    Node(int val): data(val),left(NULL), right(NULL){};
    Node (): data(0), left(NULL), right(NULL){};
};
void buildTree(int * arr, int size, Node * nodeArr){

  for(int i=0; i<size; i++){
    if(arr[i]!=0){
      if(i==0){
        nodeArr[0].data= arr[i];
      }
      else{
        nodeArr[i].data = arr[i];
        int parentPos= (i-1)/2;
        //Node parent = nodeArr[parentPos];
        if(i%2 == 1)
           nodeArr[parentPos].left=&nodeArr[i];
        else
           nodeArr[parentPos].right=&nodeArr[i];
      }
    }
  }
  return ;
}

class BSTIterator{
  stack<Node *> iteratorStack;
  void pushAll(Node * r);
  public:
  BSTIterator(Node * node){ pushAll(node);};
  bool hasNext(){ return !iteratorStack.empty();};
  int next();
};
void BSTIterator::pushAll(Node * r){
  while(r != NULL){
    iteratorStack.push(r); 
    r = r->left;
  }
};
int BSTIterator::next(){
  Node * temp = iteratorStack.top();
  iteratorStack.pop();
  pushAll(temp->right);
  return temp->data;
};

int main(){
  int n;
  int num;
  cin>> n;
  int inputArr[n];
  for (int i =0; i<n; i++){
    cin>> num;
    inputArr[i]=num;
  }
  Node  root[n];
  buildTree(inputArr, n, root);
  BSTIterator myIter(root);
  cout <<"\nReading BST through iterator:" << endl;
  while(myIter.hasNext())
    cout << myIter.next() << " ";
  return 0;
}
