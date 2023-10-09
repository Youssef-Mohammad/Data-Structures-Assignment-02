#include <iostream>
/*
    Name: Ahmed Sobhy Abd El-Hady Abd El-Rahman
    ID: 20200020
*/
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
    right(right) {}
};
class Solution {

public:
// Returns true if Tree is Symmetric of itself
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
        }

    bool isMirror(struct TreeNode* root1, struct TreeNode* root2)
        {
// if trees are empty then they're already symmetric and mirror of themselves
    if (root1 == NULL && root2 == NULL){
        return true;
    }
// left subtree of left tree must be mirror of right subtree of right tree
    if (root1 && root2 && root1->val == root2->val){
         if( isMirror(root1->left, root2->right)){
                if(isMirror(root1->right, root2->left)){

                return true;
            }
         }
    }
// condition of function will return false if they're not mirror of each other
        return false;
        }

};

//Test Cases
    void testcase1(){
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
 /* Shape of Tree
         1
       /   \
      /     \
     2       2
   /   \    /  \
  3     4  4    3
    */
    Solution s;
    cout << "Test case number 1: " << endl;
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "The Binary Tree is Symmetric" << " (True) " << endl;
    }
    else {
        cout << "The Binary Tree isn't Symmetric" << " (False) " << endl;
        }
    }

    void testcase2(){
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(NULL);
    root->right->right = new TreeNode(3);
 /* Shape of Tree
         1
       /    \
      /      \
     2        2
       \       \
        3       3

    */
    Solution s;
    cout << "Test case number 2: " << endl;
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "The Binary Tree is Symmetric" << " (True) " << endl;
    }
    else {
        cout << "The Binary Tree isn't Symmetric" << " (False) " << endl;
        }
    }

    void testcase3(){
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(2);
     /* Shape of Tree
         1
       /   \
      /     \
     2       2

    */
    Solution s;
    cout << "Test case number 3: " << endl;
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "The Binary Tree is Symmetric" << " (True) " << endl;
    }
    else {
        cout << "The Binary Tree isn't Symmetric" << " (False) " << endl;
        }
    }
    void testcase4(){
    TreeNode* root = new TreeNode(1);
     /* Shape of Tree
         1

    */
    Solution s;
    cout << "Test case number 4: " << endl;
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "The Binary Tree is Symmetric" << " (True) " << endl;
    }
    else {
        cout << "The Binary Tree isn't Symmetric" << " (False) " << endl;
        }
    }
    void testcase5(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
     /* Shape of Tree
        1
       /
      /
     2
    /
   3
    */
    Solution s;
    cout << "Test case number 5: " << endl;
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "The Binary Tree is Symmetric" << " (True) " << endl;
    }
    else {
        cout << "The Binary Tree isn't Symmetric" << " (False) " << endl;
        }
    }


int main()
{
testcase1();
cout << endl;
testcase2();
cout << endl;
testcase3();
cout << endl;
testcase4();
cout << endl;
testcase5();
}
