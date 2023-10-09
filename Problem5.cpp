/*
Mohammed Hisham Abdelzaher 20200483
Abdelrahman Mostafa Mohamed 20200827
*/

#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

TreeNode* insert(vector<int>& vec, int START, int END)
{
    if (START > END || START < 0 || END >= vec.size() || vec.empty())
    {
        return nullptr;
    }
    else
    {
        TreeNode* root = new TreeNode(vec[START]);                                                                    //[[0],[1,2],[3,4,5,6],[7,8,9,10,11,12,13,14]]
        root->left = insert(vec, START * 2 + 1, END);
        root->right = insert(vec, START * 2 + 2, END);
        return root;
    }
}

vector<int> stringToInt(string str)
{
    vector<int> data;
    int p_tmp = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '[' && str[i] != ']' && str[i] != ',')
        {
            p_tmp *= 10;
            p_tmp += str[i] - '0';
        }
        else if (i != 0)
        {
            data.push_back(p_tmp);
            p_tmp = 0;
        }
    }
    return data;
}

int main()
{
    TreeNode *FirstTree, *SecondTree;
    vector<int> pVec, qVec;
    string p, q;
    Solution s;

    cout << "---------- First Test Case ----------" << endl;
    /*                1                   1
     *               / \       ==        / \
     *              2   3               2   3
     */
    p = "[1,2,3]";
    q = "[1,2,3]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "---------- Second Test Case ----------" << endl;
    /*                1                   1
     *               /        !=         / \
     *              2                 null  3
     */
    p = "[1,2]";
    q = "[1,null,2]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "---------- Third Test Case ----------" << endl;
    /*                1                   1
     *               / \        !=       / \
     *              2   1               1   2
     */
    p = "[1,2,1]";
    q = "[1,1,2]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "---------- Fourth Test Case ----------" << endl;
    /*                1                   1
     *               / \                 / \
     *              2   3       !=      2   3
     *             / \ / \             / \ / \
     *            4  4 6  7           4  5 6  7
     */
    p = "[1,2,3,4,4,6,7]";
    q = "[1,2,3,4,5,6,7]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "---------- Fifth Test Case ----------" << endl;
    /*                1                   1
     *               / \                 / \
     *              2   3      !=       2  null
     *             / \                 / \
     *            4   5               4   5
     */
    p = "[1,2,3,4,5]";
    q = "[1,2,null,4,5]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "---------- Sixth Test Case ----------" << endl;
    /*                1                         1
     *              /   \                     /   \
     *             2     3                   2     3
     *           /  \   /  \       ==      /  \   /  \
     *          4    5  6   7             4    5  6   7
     *         / \  /                    / \  /
     *        8  9 10                   8  9 10
     */
    p = "[1,2,3,4,5,6,7,8,9,10]";
    q = "[1,2,3,4,5,6,7,8,9,10]";
    pVec = stringToInt(p);
    qVec = stringToInt(q);
    FirstTree = insert(pVec, 0, pVec.size() - 1);
    SecondTree = insert(qVec, 0, qVec.size() - 1);
    cout << "First Tree: " << p << endl;
    cout << "second Tree: " << q << endl;
    cout << "Result: " << boolalpha << s.isSameTree(FirstTree, SecondTree);
    FirstTree = nullptr;
    SecondTree = nullptr;
    pVec.clear();
    qVec.clear();
    cout << endl << endl;

    cout << "Program Finished" << endl;

    return 0;
}