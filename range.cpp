#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
#define MAXSPAN 52 // A-Za-z
char charData[] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e',
                          'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j',
                          'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o',
                          'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't',
                          'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 
                          'Z', 'z'};


struct leafNode{
  char val[3];
  leafNode * before;
  leafNode * next;
  bool  included;
  leafNode(char * charStr);
};

struct outerNode{
  char val[2];
  leafNode * leafNodeList[MAXSPAN];
  outerNode(char * charStr); 
};
outerNode::outerNode(char * charStr){
  val[0] = charStr[0];
  val[1] = charStr[1];
  char charToLeaf[2] ;
  for(int i = 0 ; i<  MAXSPAN ; i++){
    charToLeaf[0] = val[0]; 
    charToLeaf[1] = val[1];
    charToLeaf[2] = charData[i];
    leafNodeList[i] = new leafNode(charToLeaf);
  }
};

struct node{
  char val[1];
  outerNode * outerNodeList[MAXSPAN];
  node(char charStr); 
};
node::node(char charStr){
  val[0] = charStr;
  char charToOuter[2] ;
  for(int i = 0 ; i<  MAXSPAN ; i++){
    charToOuter[0] = val[0]; 
    charToOuter[1] = charData[i];
    outerNodeList[i] = new outerNode(charToOuter);
  }
};

struct rootNode{
  node * nodeList[MAXSPAN]; 
  rootNode();
};
rootNode::rootNode(){
  for(int i = 0 ; i<  MAXSPAN ; i++){
    nodeList[i] = new node(charData[i]);
  }
};
class myTree{
  rootNode * root;

  public: 
     myTree();
     void buildTree();
     void printTree(); 
     int  getPosition(char c);
};

leafNode * previous;
leafNode * beginLeafNode;
leafNode * endLeafNode;

leafNode::leafNode(char * charStr){
  strcpy(val, charStr);
  included = false; 
  previous  = this;
  if(strncmp(val, "AAA", 3) == 0){
     beginLeafNode  = this;
     before = NULL;
     next = NULL;
  }
  else if(strncmp(val, "zzz", 3) == 0){
     endLeafNode  = this;
     next = NULL;
  }
  else {
    previous->next = this;
    before = previous;
  }
};

myTree::myTree(){
  root = new rootNode;
};

void myTree::printTree(){
  for(int i = 0 ; i<  MAXSPAN ; i++){
    for(int j = 0 ; j<  MAXSPAN ; j++){
      for(int k =0; k< MAXSPAN; k++){
        cout << root->nodeList[i]->outerNodeList[j]->leafNodeList[k]->val << " "; 
      }
      cout << endl;
    }
  }
};

int myTree::getPosition(char c){
  int p = (c-'a');
  int P = (c-'A');
  if(0<=p<26) 
     return 2*p+1;
  if(0<=P<26)
     return 2*P;
  return -1;   
};

void myTree::insertRange(char * beg, char * end){
  int i , j, k;
  i = getPosition(beg[0]);
  j = getPosition(beg[1]);
  k = getPosition(beg[2]);
}

int main (){
   myTree myT;

   myT.insertRange("AaA" , "CaC");
   myT.printTree(); 
   
   return 0;
}
