/*
    Mohamed Ahmed Hamed
    20200422
*/
#include <iostream>
using namespace std;
// struct node
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// create new node
struct node *newNode(int data) {
  node * n = new node;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
};

bool  check_nodes(node* n1, node* n2)
{
    // If both left and right subtrees are NULL , return true
     
    if (n1 == NULL && n2 == NULL) {
        return true;
    }
 
    // If one of the trees is NULL and other is not, return false
   
    if (n1 == NULL || n2 == NULL) {
        return false;
    }
 
    return  check_nodes(n1->left, n2->right) &&  check_nodes(n1->right, n2->left);
}
bool IsFoldable(node* root)
{
    if (root == NULL) {
        return true;
    }
    return check_nodes(root->left, root->right);
}
// function print 
void print(bool check, int num_case){
    cout<<"case "<<num_case<<" : ";
    if(check){
        cout << "Tree is foldable";
    }else{
        cout << "Tree is not foldable";
    }
    cout<<endl<<"------------------------------------------------"<<endl;
}
 

int main()
{
    // case 1
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(5);
    print(IsFoldable(root1),1);
    
    // case 2
    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->right->right = newNode(5);
    root2->left->right = newNode(6);
    root2->right->left = newNode(4);
    print(IsFoldable(root2),2);
    
    
    // case 3
    node* root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);
    root3->right->right = newNode(5);
    root3->left->left = newNode(4);
    print(IsFoldable(root3),3);
    
    // case 4
    node* root4 = newNode(1);
    root4->left = newNode(4);
    root4->right = newNode(2);
    root4->right->left = newNode(3);
    root4->left->right = newNode(5);
    print(IsFoldable(root4),4);
    
    
    // case 5
    node* root5 = newNode(1);
    root5->left = newNode(2);
    root5->right = newNode(3);
    root5->right->right = newNode(5);
    print(IsFoldable(root5),5);
    
    return 0;
}

