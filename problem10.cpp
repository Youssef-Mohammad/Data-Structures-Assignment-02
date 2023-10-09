/*
    Mohamed Ahmed Hamed
    20200422
*/
#include <iostream>
#include <vector>
using namespace std;
struct node {
  int data;
  struct node *left;
  struct node *right;
};
struct node *newNode(int data) {
  node * n = new node;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
};
struct node * insert(node *root, int key)
{
    // If the tree is empty, return a new Node
    if (root == NULL)
        return newNode(key);
 
     
    if (root->data >= key)
    {
        root->left= insert(root->left , key);
    }
    else if (root->data < key )
        root->right= insert (root->right , key );
 
    return root;
}
// Traverse Inorder
void get_elements(struct node *temp,vector <int> &v){
  int element;
  if (temp != NULL) {
    get_elements(temp->left,v);
    v.push_back(temp->data);
    get_elements(temp->right,v);
  }
}
void cal_sum(struct node *temp , int element,int & sum){
   if(temp != NULL){
       if(temp->data <= element){
           sum += temp->data;
        }
       cal_sum(temp->right,element,sum);
       cal_sum(temp->left,element,sum);
   }
}
// function print each case
void print(int sum,int element,int num_case){
    cout<<"Case : "<<num_case<<endl;
    cout<<"k th smallest element is " <<element << " and sum of all the elements which is less or equal to "<<element<<" is "<<sum<<endl;
    cout<<"----------------------------------------------"<<endl;
}
void sum(struct node *temp ,int k,int num_case){
   vector <int> v;
   int sum = 0;
   // call function get_elements to get all elements in tree
   get_elements(temp,v);
   // return element from vector by (k-1) because vector starts index = 0
   int element =  v.at(k-1);
   // call function cal_sum() to return sum all elements then call function print to print sum;
   cal_sum(temp,element,sum);
   print(sum,element,num_case);
}
int main()
{
      // case 1
      struct node *root1 = NULL;
      root1 = insert(root1,90);
      root1 = insert(root1,80);
      root1 = insert(root1,92);
      root1 = insert(root1,150);
      root1 = insert(root1,140);
      root1 = insert(root1,160);
      root1 = insert(root1,200);
      root1 = insert(root1,150);
      sum(root1,1,1);
      
      
       
      // case 2
      struct node *root2 = NULL;
      root2 = insert(root2,60);
      root2 = insert(root2,49);
      root2 = insert(root2,50);
      root2 = insert(root2,75);
      root2 = insert(root2,71);
      root2 = insert(root2,80);
      sum(root2,4,2);
       
      
      
      // case 3
      struct node *root3 = NULL;
      root3 = insert(root3,200);
      root3 = insert(root3,150);
      root3 = insert(root3,140);
      root3 = insert(root3,230);
      root3 = insert(root3,300);
      root3 = insert(root3,250);
      root3 = insert(root3,400);
      sum(root3,4,3);
      
      
      // case 4
      struct node *root4 = NULL;
      root4 = insert(root4,300);
      root4 = insert(root4,200);
      root4 = insert(root4,100);
      root4 = insert(root4,250);
      root4 = insert(root4,400);
      root4 = insert(root4,350);
      root4 = insert(root4,500);
      root4 = insert(root4,600);
      root4 = insert(root4,450);
      sum(root4,6,4);
      
      
      
     
      // case 5
      struct node *root5 = NULL;
      root5 = insert(root5,54);
      root5 = insert(root5,51);
      root5 = insert(root5,49);
      root5 = insert(root5,52);
      root5 = insert(root5,75);
      root5 = insert(root5,74);
      root5 = insert(root5,85);
      sum(root5,3,5);
    return 0;
}



