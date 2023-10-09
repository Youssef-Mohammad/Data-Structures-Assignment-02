/*
Mohammed Hisham Abdelzaher 20200483
Abdelrahman Mostafa Mohamed 20200827
*/

#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
    char Val;
    TreeNode *l;
    TreeNode *r;
    explicit TreeNode(char val){
        this->Val=val;
        this->l=nullptr;
        this->r=nullptr;
    }
};

class stack{
public:
    TreeNode *treeNode;
    stack *n; //that points to nodes that in stack, and it may be used to check that's top is null or not
    stack(TreeNode *treeNode){
        this->treeNode=treeNode;
        n= nullptr;
    }
};

class Expression{
public:
    vector<char> vec;
    stack *top;
    Expression(){
        top= nullptr;
    }
    void clear(){
        top= nullptr;
    }
    void push(TreeNode *ptr){
        if(top== nullptr){
            top=new stack(ptr);
        }
        else {
            stack *node_ptr = new stack(ptr);
            node_ptr->n = top;
            top = node_ptr;
        }
    }

    TreeNode *pop() {
        if (top == nullptr) {
            cout<<"Underflow"<<endl;
            return nullptr;
        } else {
            TreeNode *ptr = top->treeNode;
            top = top->n;
            return ptr;
        }
    }
    TreeNode *peek()  {
        return top->treeNode;
    }
    static bool isDigit(char ch){
        return ch>='0' &&ch<='9';
    }
    static bool isOperator(char ch){
        return ch=='+'||ch=='-'||ch=='*'||ch=='/';
    }
    static int convertToDigit(char ch){
        return ch-'0';//'0'=49 and '1'=50 and '2'=51 so if we subtract 0 from any num like 2  -> 51-49 =2;
    }

    void insert(char value){
        if(isDigit(value)){
            TreeNode *ptr=new TreeNode(value);
            push(ptr);
        }
        else if(isOperator(value)){
            TreeNode *ptr=new TreeNode(value);
            ptr->l=pop();
            ptr->r=pop();
            push(ptr);
        } else{
            cout<<"Invalid Expression"<<endl;
            return;
        }
    }
    void buildTree(string expressionStr){
        for(int i= expressionStr.length() - 1; i >= 0; i--){
            insert(expressionStr[i]);
        }
    }
    void inOrder(TreeNode *ptr) {
        if (ptr != nullptr) {
            inOrder(ptr->l);
            vec.push_back(ptr->Val);
            inOrder(ptr->r);
        }
    }
    void infix(){
        inOrder(peek());
    }

};

double operation(vector<char> charVec, vector<double> numVec)
{
    double result = 0;
    bool plus, minus, mul, div;
    for(char i : charVec)
    {
        if (i == '*')
        {
            mul = true;
        }
        else if (i == '/')
        {
            div = true;
        }
        else if (i == '+')
        {
            plus = true;
        }
        else if (i == '-')
        {
            minus = true;
        }
    }
    if (mul)
    {
        for (int i=0; i < numVec.size(); i++)
        {
            if(charVec[i] == '*' && i < numVec.size() - 1)
            {
                result = numVec[i] * numVec[i + 1];
                numVec[i] = result;
                numVec.erase(numVec.begin() + i + 1);
                charVec.erase(charVec.begin() + i);
            }
        }
    }
    if (div)
    {
        for (int i=0; i < numVec.size(); i++)
        {
            if(charVec[i] == '/' && i < numVec.size() - 1)
            {
                result = numVec[i] / numVec[i + 1];
                numVec[i] = result;
                numVec.erase(numVec.begin() + i + 1);
                charVec.erase(charVec.begin() + i);
            }
        }
    }
    if (plus)
    {
        for (int i=0; i < numVec.size(); i++)
        {
            if(charVec[i] == '+' && i < numVec.size() - 1)
            {
                result = numVec[i] + numVec[i + 1];
                numVec[i] = result;
                numVec.erase(numVec.begin() + i + 1);
                charVec.erase(charVec.begin() + i);
            }
        }
    }
    if (minus)
    {
        for (int i=0; i < numVec.size(); i++)
        {
            if(charVec[i] == '-' && i < numVec.size() - 1)
            {
                result = numVec[i] - numVec[i + 1];
                numVec[i] = result;
                numVec.erase(numVec.begin() + i + 1);
                charVec.erase(charVec.begin() + i);
            }
        }
    }
    result = 0;
    for (double i : numVec)
    {
        result += i;
    }
    return result;
}

void fillVectors(Expression& exp, vector<char> &charVec, vector<double> &numVec)
{
    exp.infix();
    string str1((exp.vec).begin(), (exp.vec).end());
    for(char& i : str1)
    {
        if (exp.isDigit(i))
        {
            numVec.push_back(exp.convertToDigit(i));
        }
        else if (exp.isOperator(i))
        {
            charVec.push_back(i);
        }
    }
}

int main()
{
    cout << endl << "---------- First Test Case ----------" << endl;
    string ExpStr1 = "+3*4/82";                                                                                         // +3*4/82  ->  3+4*8/2
    Expression expression;
    vector<double> doubleVec;
    vector<char> charVec;
    expression.buildTree(ExpStr1);
    fillVectors(expression, charVec, doubleVec);
    cout << "Expression: " << ExpStr1 << endl;
    cout << "Evaluation: " << operation(charVec,doubleVec) <<endl;

    cout << endl << "---------- Second Test Case ----------" << endl;
    string ExpStr2 = "*4+5/93";                                                                                         // *4+5/93  ->  4*5+9/3
    Expression expression2;
    vector<double> doubleVec2;
    vector<char> charVec2;
    expression2.buildTree(ExpStr2);
    fillVectors(expression2, charVec2, doubleVec2);
    cout << "Expression: " << ExpStr2 << endl;
    cout << "Evaluation: " << operation(charVec2,doubleVec2) <<endl;

    cout << endl << "---------- Third Test Case ----------" << endl;
    string ExpStr3 = "*1+2/34";                                                                                         // *1+2/34  ->  1*2+3/4
    Expression expression3;
    vector<double> doubleVec3;
    vector<char> charVec3;
    expression3.buildTree(ExpStr3);
    fillVectors(expression3, charVec3, doubleVec3);
    cout << "Expression: " << ExpStr3 << endl;
    cout << "Evaluation: " << operation(charVec3,doubleVec3) <<endl;

    cout << endl << "---------- Fourth Test Case ----------" << endl;
    string ExpStr4 = "*6+1/95";                                                                                         // *6+1/95  ->  6*1+9/5
    Expression expression4;
    vector<double> doubleVec4;
    vector<char> charVec4;
    expression4.buildTree(ExpStr4);
    fillVectors(expression4, charVec4, doubleVec4);
    cout << "Expression: " << ExpStr4 << endl;
    cout << "Evaluation: " << operation(charVec4,doubleVec4) <<endl;

    cout << endl << "---------- Fifth Test Case ----------" << endl;
    string ExpStr5 = "/8+4*27";                                                                                         // /8+4*27  ->  8/4+2*7
    Expression expression5;
    vector<double> doubleVec5;
    vector<char> charVec5;
    expression5.buildTree(ExpStr5);
    fillVectors(expression5, charVec5, doubleVec5);
    cout << "Expression: " << ExpStr5 << endl;
    cout << "Evaluation: " << operation(charVec5,doubleVec5) <<endl;

    cout<<"\nfinished!\n";
    return 0;
}