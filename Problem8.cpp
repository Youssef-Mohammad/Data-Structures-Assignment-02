/*
Mohammed Hisham Abdelzaher 20200483
Abdelrahman Mostafa Mohamed 20200827
*/

#include <iostream>
using namespace std;

class Node
{
public:
    char Val;
    Node *Left;
    Node *Right;
    Node(int val)
    {
        Val = val;
        Left = nullptr;
        Right = nullptr;
    }
    Node(int val, Node *left, Node *right)
    {
        Val = val;
        Left = left;
        Right = right;
    }
};

void printPostOrder (string preorder, string inorder)
{
    if (preorder.length() == 0)
    {
        return;
    }
    char root = preorder[0];
    int rootIndex = inorder.find(root);
    string leftPreorder = preorder.substr(1, rootIndex);
    string rightPreorder = preorder.substr(rootIndex + 1);
    string leftInorder = inorder.substr(0, rootIndex);
    string rightInorder = inorder.substr(rootIndex + 1);
    printPostOrder(leftPreorder, leftInorder);
    printPostOrder(rightPreorder, rightInorder);
    cout<<root;
}

int main()
{
    cout << "---------- First Test Case ----------" << endl;
    /*              A
     *             / \
     *            B   C
     *           / \
     *          F   G
     */
    string PreOrder = "ABFGC";
    string InOrder = "FBGAC";
    printPostOrder(PreOrder, InOrder);
    cout << endl;
    cout << "---------- Second Test Case ----------" << endl;
    /*              J
     *             / \
     *            K   I
     *           / \ / \
     *          M  N P  F
     */
    PreOrder = "JKMNIPF";
    InOrder = "MKNJPIF";
    printPostOrder(PreOrder, InOrder);
    cout << endl;
    cout << "---------- Third Test Case ----------" << endl;
    /*              A
     *             / \
     *            B   C
     *           / \ / \
     *          D  E F  G
     *         / \
     *        H   I
     */
    PreOrder = "ABDHIECFG";
    InOrder = "HDIBEAFCG";
    printPostOrder(PreOrder, InOrder);
    cout << endl;
    cout << "---------- Fourth Test Case ----------" << endl;
    /*             G
    *             / \
    *            H   I
    *           / \ / \
    *          J  K L  M
    *         / \
    *        N   P
    */
    PreOrder = "GHJNPKILM";
    InOrder = "NJPHKGLIM";
    printPostOrder(PreOrder, InOrder);
    cout << endl;
    cout << "---------- Fifth Test Case ----------" << endl;
    /*             S
    *             / \
    *            T   U
    *           / \ / \
    *          V  W N  Z
    *         / \
    *        X   Y
    */
    PreOrder = "STVXYWUNZ";
    InOrder = "XVYTWSNUZ";
    printPostOrder(PreOrder, InOrder);
    cout << endl;


    return 0;
}