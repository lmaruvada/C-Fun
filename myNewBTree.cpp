#include <iostream>
#include <memory>
#include <vector>
using namespace std;
struct node
{
  int key_value;
  unique_ptr<node> left;
  unique_ptr<node> right;
  node(int & k) :key_value(k), left(nullptr), right(nullptr){ };
};

class btree {
    public:
        btree(): root(nullptr){};

        void insert(int key);
        unique_ptr<node> search(int key);
        unique_ptr<node>& getRoot() {return root;};
        void getInOrder(unique_ptr<node> & n, vector<int>& inOrder);
        void getPreOrder(unique_ptr<node> & n, vector<int>& preOrder);
        void getPostOrder(unique_ptr<node> & n, vector<int>& postOrder);

    private:
        unique_ptr<node> search(int key, unique_ptr<node> leaf);
        unique_ptr<node> root;
};
void btree::insert(int key) {
  unique_ptr<node> n{new node(key)}; 
  if(root == nullptr){
    root = move(n);
  }
  else {
    node * temp = root.get(); 
    node * prev = root.get(); 
    while(temp != nullptr){
      prev = temp;
      if(temp->key_value < key)
        temp = temp->right.get();
      else
        temp = temp->left.get();
    }
    if(prev->key_value < key)
      prev->right = move(n);
    else
      prev->left = move(n);
  }
};
unique_ptr<node>btree::search(int key, unique_ptr<node>leaf)
{
  if(leaf!=nullptr)
  {
    if(key==leaf->key_value)
      return move(leaf);
    if(key<leaf->key_value)
      return search(key, move(leaf->left));
    else
      return search(key, move(leaf->right));
  }
  else return nullptr;
}
void btree::getInOrder(unique_ptr<node> & n, vector<int>& inOrder){
  if(n==nullptr)
    return;
  getInOrder(n->left, inOrder);
  inOrder.push_back(n->key_value);
  getInOrder(n->right, inOrder);
}
void btree::getPreOrder(unique_ptr<node> & n, vector<int>& preOrder){
  if(n==nullptr)
    return;
  preOrder.push_back(n->key_value);
  getPreOrder(n->left, preOrder);
  getPreOrder(n->right, preOrder);
}
void btree::getPostOrder(unique_ptr<node> & n, vector<int>& postOrder){
  if(n==nullptr)
    return;
  getPostOrder(n->left, postOrder);
  getPostOrder(n->right, postOrder);
  postOrder.push_back(n->key_value);
}

unique_ptr<node> btree::search(int key)
{
  return search(key, move(root));
}
void printTree(vector<int>& myvector){
  cout << "\nPrinting vector: " ; 
  for (auto e : myvector)
        std::cout << ' ' << e;
  std::cout << '\n';
}

bool compare(unique_ptr<node> t1, unique_ptr<node> t2){
  if( (t1== NULL) && (t2 == NULL))
   return true;
  if(( t1 != NULL) && (t2 != NULL))
  {
    return (
             (t1->key_value == t2->key_value) &&
             compare(move(t1->left), move(t2->left)) &&
             compare(move(t1->right), move(t2->right))
            );
  }
  return false;
}

auto main() -> int {

  btree myBTree; 
  vector<int> input{6,3,8,2,5,7,9,1,4};

  for(auto e : input)
    myBTree.insert(e);

  vector<int> in;
  vector<int> pre;
  vector<int> post;

  for(auto e: input)
    cout << e << " " ;
  cout << "\nInOrder:";
  myBTree.getInOrder(myBTree.getRoot(), in);
  printTree(in);
  cout << "\nPreOrder:";
  myBTree.getPreOrder(myBTree.getRoot(), pre);
  printTree(pre);
  cout << "\nPostOrder:";
  myBTree.getPostOrder(myBTree.getRoot(), post);
  printTree(post);
  cout << endl;

  auto myBTree2 = unique_ptr<btree>{new btree{}};
  for(auto e : pre){
    myBTree2->insert(e);
  }
  if(compare (move(myBTree.getRoot()), move(myBTree2->getRoot())))
    cout << "Success in PreOrder\n";
  else
    cout << "Failure in PreOrder\n";

  auto myBTree3 = unique_ptr<btree>{new btree{}};
  for(auto e : in){
    myBTree3->insert(e);
  }
  if(compare (move(myBTree.getRoot()), move(myBTree3->getRoot())))
    cout << "Success in InOrder\n";
  else
    cout << "Failure in InOrder\n";

  auto myBTree4 = unique_ptr<btree>{new btree{}};
  for(auto e : post){
    myBTree4->insert(e);
  }
  if(compare (move(myBTree.getRoot()), move(myBTree4->getRoot())))
    cout << "Success in PostOrder\n";
  else
    cout << "Failure in PostOrder\n";

}
