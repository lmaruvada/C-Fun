#include <iostream>
#include <vector>
using namespace std;
struct node
{
  int key_value;
  node *left;
  node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        void destroy_tree();
        node * getRoot() {return root;};
        void getInOrder(node * n, vector<int>& inOrder);
        void getPreOrder(node * n, vector<int>& preOrder);
        void getPostOrder(node * n, vector<int>& postOrder);
        

    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        
        node *root;
};
btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}
void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}
void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}
void btree::getInOrder(node * n, vector<int>& inOrder){
  if(n==NULL)
    return;
  getInOrder(n->left, inOrder);
  inOrder.push_back(n->key_value);
  getInOrder(n->right, inOrder);
}
void btree::getPreOrder(node * n, vector<int>& preOrder){
  if(n==NULL)
    return;
  preOrder.push_back(n->key_value);
  getPreOrder(n->left, preOrder);
  getPreOrder(n->right, preOrder);
}
void btree::getPostOrder(node * n, vector<int>& postOrder){
  if(n==NULL)
    return;
  getPostOrder(n->left, postOrder);
  getPostOrder(n->right, postOrder);
  postOrder.push_back(n->key_value);
}
node *btree::search(int key)
{
  return search(key, root);
}
void btree::destroy_tree()
{
  destroy_tree(root);
}
void printTree(vector<int> myvector){
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        std::cout << ' ' << *it;
  std::cout << '\n';
}
bool compare(node * t1, node * t2){
  if( (t1== NULL) && (t2 == NULL))
   return true;
  if(( t1 != NULL) && (t2 != NULL))
  {
    return (
             (t1->key_value == t2->key_value) &&
             compare(t1->left, t2->left) && 
             compare(t1->right, t2->right)
            );
  }
  return false;
}

int main(){
  
  btree * myBTree = new btree;
  int  input[9] = {6,3,8,2,5,7,9,1,4};
  
  for(int i=0; i<9; i++)
    myBTree->insert(input[i]);
  vector<int> in;
  vector<int> pre;
  vector<int> post;

  for(int i = 0; i<9; i++)
    cout << input[i] << " " ;
  cout << "\n";
  myBTree->getInOrder(myBTree->getRoot(), in); 
  myBTree->getPreOrder(myBTree->getRoot(), pre); 
  myBTree->getPostOrder(myBTree->getRoot(), post); 

  printTree(pre);
  btree * myBTree2 = new btree;
  for (std::vector<int>::iterator it = pre.begin() ; it != pre.end(); ++it){
    myBTree2->insert(*it);
  }
  if(compare (myBTree->getRoot(), myBTree2->getRoot()))
    cout << "Success in PreOrder\n";
  else
    cout << "Failure in PreOrder\n";


  printTree(in);
  btree * myBTree3 = new btree;
  for (std::vector<int>::iterator it = in.begin() ; it != in.end(); ++it){
    myBTree3->insert(*it);
  }
  if(compare (myBTree->getRoot(), myBTree3->getRoot()))
    cout << "Success in InOrder\n";
  else 
    cout << "Failure in InOrder\n";


  printTree(post);
  btree * myBTree4 = new btree;
  for (std::vector<int>::iterator it = post.begin() ; it != post.end(); ++it){
    myBTree4->insert(*it);
  }
  if(compare (myBTree->getRoot(), myBTree4->getRoot()))
    cout << "Success in PostOrder\n";
  else 
    cout << "Failure in PostOrder\n";

}
