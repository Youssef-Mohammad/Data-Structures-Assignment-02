/*
Mohammed Hisham Abdelzaher 20200483
Abdelrahman Mostafa Mohamed 20200827
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int Val;
    Node *Left;
    Node *Right;
    Node(int x)
    {
        Val = x;
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

Node* root;

void flip(Node* node = root)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        flip(node->Left);
        flip(node->Right);
        swap(node->Left, node->Right);
    }
}

int main()
{
    cout << endl << "---------- First Test Case ----------" << endl;

    /*                   1                    1
     *                  / \                  / \
     *                 2   3       ->       3   2
     *                / \                      / \
     *               4  5                     5   4
     */

    root = new Node(1);
    root->Left = new Node(2);
    root->Right = new Node(3);
    root->Left->Left = new Node(4);
    root->Left->Right = new Node(5);

    cout << "Before flip" << endl;
    cout << "Root: " << root->Val << endl;
    cout << "Left: " << root->Left->Val << endl;
    cout << "Right: " << root->Right->Val << endl;
    cout << "Left Left: " << root->Left->Left->Val << endl;
    cout << "Left Right: " << root->Left->Right->Val << endl;

    flip();

    cout << endl << "After flip" << endl;
    cout << "Root: " << root->Val << endl;
    cout << "Left: " << root->Left->Val << endl;
    cout << "Right: " << root->Right->Val << endl;
    cout << "Right Left: " << root->Right->Left->Val << endl;
    cout << "Right Right: " << root->Right->Right->Val << endl;

    cout << endl << "---------- Second Test Case ----------" << endl;

    /*                   4                    4
     *                  / \                  / \
     *                 2   6       ->       6   2
     *                / \ / \              / \ / \
     *               1  3 5  7            7  5 3  1
     */

    Node* root2 = new Node(4,
                           new Node(2,
                                    new Node(1),
                                    new Node(3)),
                           new Node(6,
                                     new Node(5),
                                     new Node(7)));

    cout << "Before flip" << endl
         << "Root: " << root2->Val << endl
         << "Left: " << root2->Left->Val << endl
         << "Right: " << root2->Right->Val << endl
         << "Left Left: " << root2->Left->Left->Val << endl
         << "Left Right: " << root2->Left->Right->Val << endl
         << "Right Left: " << root2->Right->Left->Val << endl
         << "Right Right: " << root2->Right->Right->Val << endl;

    flip(root2);

    cout << endl << "After flip" << endl
         << "Root: " << root2->Val << endl
         << "Left: " << root2->Left->Val << endl
         << "Right: " << root2->Right->Val << endl
         << "Left Left: " << root2->Left->Left->Val << endl
         << "Left Right: " << root2->Left->Right->Val << endl
         << "Right Left: " << root2->Right->Left->Val << endl
         << "Right Right: " << root2->Right->Right->Val << endl;


    cout << endl << "---------- Third Test Case ----------" << endl;

    /*                   10                    10
     *                  /  \                  /  \
     *                 2   20       ->       20   2
     *                / \                        / \
     *               1   5                      5   1
     *                  / \                    / \
     *                 3   7                  7   3
     */

    Node* root3 = new Node(10);
    root3->Left = new Node(2);
    root3->Right = new Node(20);
    root3->Left->Left = new Node(1);
    root3->Left->Right = new Node(5);
    root3->Left->Right->Left = new Node(3);
    root3->Left->Right->Right = new Node(7);

    cout << "Before flip" << endl;
    cout << "Root: " << root3->Val << endl;
    cout << "Left: " << root3->Left->Val << endl;
    cout << "Right: " << root3->Right->Val << endl;
    cout << "Left Left: " << root3->Left->Left->Val << endl;
    cout << "Left Right: " << root3->Left->Right->Val << endl;
    cout << "Left Right Left: " << root3->Left->Right->Left->Val << endl;
    cout << "Left Right Right: " << root3->Left->Right->Right->Val << endl;

    flip(root3);

    cout << endl << "After flip" << endl;
    cout << "Root: " << root3->Val << endl;
    cout << "Left: " << root3->Left->Val << endl;
    cout << "Right: " << root3->Right->Val << endl;
    cout << "Right Left: " << root3->Right->Left->Val << endl;
    cout << "Right Right: " << root3->Right->Right->Val << endl;
    cout << "Right Left Left: " << root3->Right->Left->Left->Val << endl;
    cout << "Right Left Right: " << root3->Right->Left->Right->Val << endl;

    cout << endl << "---------- Fourth Test Case ----------" << endl;

    /*                   10                    10
     *                  /  \                  /  \
     *                 2   20       ->       20   2
     *                / \                        / \
     *               1   5                      5   1
     *                  / \                    / \
     *                 3   7                  7   3
     *                    / \                / \
     *                   6   9              9   6
     */

    Node* root4 = new Node(10);
    root4->Left = new Node(2);
    root4->Right = new Node(20);
    root4->Left->Left = new Node(1);
    root4->Left->Right = new Node(5);
    root4->Left->Right->Left = new Node(3);
    root4->Left->Right->Right = new Node(7);
    root4->Left->Right->Right->Left = new Node(6);
    root4->Left->Right->Right->Right = new Node(9);

    cout << "Before flip" << endl;
    cout << "Root: " << root4->Val << endl;
    cout << "Left: " << root4->Left->Val << endl;
    cout << "Right: " << root4->Right->Val << endl;
    cout << "Left Left: " << root4->Left->Left->Val << endl;
    cout << "Left Right: " << root4->Left->Right->Val << endl;
    cout << "Left Right Left: " << root4->Left->Right->Left->Val << endl;
    cout << "Left Right Right: " << root4->Left->Right->Right->Val << endl;
    cout << "Left Right Right Left: " << root4->Left->Right->Right->Left->Val << endl;
    cout << "Left Right Right Right: " << root4->Left->Right->Right->Right->Val << endl;

    flip(root4);

    cout << endl << "After flip" << endl;
    cout << "Root: " << root4->Val << endl;
    cout << "Left: " << root4->Left->Val << endl;
    cout << "Right: " << root4->Right->Val << endl;
    cout << "Right Left: " << root4->Right->Left->Val << endl;
    cout << "Right Right: " << root4->Right->Right->Val << endl;
    cout << "Right Left Left: " << root4->Right->Left->Left->Val << endl;
    cout << "Right Left Right: " << root4->Right->Left->Right->Val << endl;
    cout << "Right Left Left Left: " << root4->Right->Left->Left->Left->Val << endl;
    cout << "Right Left Left Right: " << root4->Right->Left->Left->Right->Val << endl;

    cout << endl << "---------- Fifth Test Case ----------" << endl;

    /*                   20                    20
     *                  /  \                  /  \
     *                 10   25       ->      25  10
     *                /  \                      /  \
     *               1   15                    15   1
     *                  /  \                  / \
     *                 14  18                18  14
     *                /   /  \              /  \   \
     *               12  16  19            19  16   12
     *              /  \   \                  /    /  \
     *             11  13  17                17   13  11
     */

    Node* root5 = new Node(20);
    root5->Left = new Node(10);
    root5->Right = new Node(25);
    root5->Left->Left = new Node(1);
    root5->Left->Right = new Node(15);
    root5->Left->Right->Left = new Node(14);
    root5->Left->Right->Right = new Node(18);
    root5->Left->Right->Left->Left = new Node(12);
    root5->Left->Right->Left->Left->Left = new Node(11);
    root5->Left->Right->Left->Left->Right = new Node(13);
    root5->Left->Right->Right->Left = new Node(16);
    root5->Left->Right->Right->Right = new Node(19);
    root5->Left->Right->Right->Left->Right = new Node(17);

    cout << "Before flip" << endl;
    cout << "Root: " << root5->Val << endl;
    cout << "Left: " << root5->Left->Val << endl;
    cout << "Right: " << root5->Right->Val << endl;
    cout << "Left Left: " << root5->Left->Left->Val << endl;
    cout << "Left Right: " << root5->Left->Right->Val << endl;
    cout << "Left Right Left: " << root5->Left->Right->Left->Val << endl;
    cout << "Left Right Right: " << root5->Left->Right->Right->Val << endl;
    cout << "Left Right Left Left: " << root5->Left->Right->Left->Left->Val << endl;
    cout << "Left Right Left Left Left: " << root5->Left->Right->Left->Left->Left->Val << endl;
    cout << "Left Right Left Left Right: " << root5->Left->Right->Left->Left->Right->Val << endl;
    cout << "Left Right Right Left: " << root5->Left->Right->Right->Left->Val << endl;
    cout << "Left Right Right Right: " << root5->Left->Right->Right->Right->Val << endl;
    cout << "Left Right Right Left Right: " << root5->Left->Right->Right->Left->Right->Val << endl;

    flip(root5);

    cout << endl << "After flip" << endl;
    cout << "Root: " << root5->Val << endl;
    cout << "Left: " << root5->Left->Val << endl;
    cout << "Right: " << root5->Right->Val << endl;
    cout << "Right Left: " << root5->Right->Left->Val << endl;
    cout << "Right Right: " << root5->Right->Right->Val << endl;
    cout << "Right Left Left: " << root5->Right->Left->Left->Val << endl;
    cout << "Right Left Right: " << root5->Right->Left->Right->Val << endl;
    cout << "Right Left Right Right: " << root5->Right->Left->Right->Right->Val << endl;
    cout << "Right Left Right Right Left: " << root5->Right->Left->Right->Right->Left->Val << endl;
    cout << "Right Left Right Right Right: " << root5->Right->Left->Right->Right->Right->Val << endl;
    cout << "Right Left Left Left: " << root5->Right->Left->Left->Left->Val << endl;
    cout << "Right Left Left Right: " << root5->Right->Left->Left->Right->Val << endl;
    cout << "Right Left Left Right Left: " << root5->Right->Left->Left->Right->Left->Val << endl;
    cout << endl << "Finished!" << endl;

    return 0;
}