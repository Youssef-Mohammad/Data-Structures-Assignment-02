#include<iostream>
using namespace std;

template<class T>
class BSTNode
{
public:
	T info;
	BSTNode* left;
	BSTNode* right;
	int length;

	BSTNode()
	{
		info = NULL;
		left = NULL;
		right = NULL;
		length = 0;
	}

	BSTNode(T data)
	{
		info = data;
		left = NULL;
		right = NULL;
		length = 0;
	}
};

template<class T>
class BSTFCI
{
private:
	void print(BSTNode<T>* Root)
	{
		//PreOrder
		if (Root != NULL)
		{
			cout << (Root == root?"":" ") << Root->info;
			print(Root->left);
			print(Root->right);
		}
	}
public:
	BSTNode<T>* root;
	BSTNode<T>* tmp;

	BSTFCI()
	{
		root = NULL;
		tmp = NULL;
	}

	T Min()
	{
		tmp = root;
		while (tmp->left != NULL)
		{
			tmp = tmp->left;
		}
		return tmp->info;
	}

	T Max()
	{
		tmp = root;
		while (tmp->right != NULL)
		{
			tmp = tmp->right;
		}
		return tmp->info;
	}
	void leftRotation(BSTNode<T>* node, BSTNode<T>* prev)
	{
		prev->right = tmp->left;
		tmp->left = prev;
	}

	void rightRotation(BSTNode<T>* node, BSTNode<T>* prev)
	{
		prev->left = tmp->right;
		tmp->right = prev;
	}

	void insert(T data)
	{
		BSTNode<T>* temp = root;
		BSTNode<T>* prev = NULL;

		while (temp != NULL)
		{
			prev = temp;
			if (temp->info < data)
			{
				temp = temp->right;
			}
			else
			{
				temp = temp->left;
			}
		}

		if (root == NULL)
		{
			root = new BSTNode<T>(data);
		}
		else if (prev->info < data)
		{
			prev->right = new BSTNode<T>(data);
		}
		else
		{
			prev->left = new BSTNode<T>(data);
		}
	}

	void deleteBtAddress(BSTNode<T>* tmp, BSTNode<T>* prev)
	{
		if (tmp->left == 0 && tmp->right == 0)
		{
			if (prev->info > tmp->info)
			{
				prev->left = NULL;
				delete tmp;
				tmp = NULL;
			}
			else if (prev->info < tmp->info)
			{
				prev->right = NULL;
				delete tmp;
				tmp = NULL;
			}
		}
		else if (tmp->left == 0)
		{
			prev->right = tmp->right;
			delete tmp;
			tmp = NULL;
		}
		else if (tmp->right == 0)
		{
			prev->left = tmp->left;
			delete tmp;
			tmp = NULL;
		}
		else
		{
			//Using Predessor
			BSTNode<T>* predessor = tmp->left;
			BSTNode<T>* predessorPrev = tmp;
			while (predessor->right != NULL)
			{
				predessorPrev = predessor;
				predessor = predessor->right;
			}
			tmp->info = predessor->info;
			deleteBtAddress(predessor, predessorPrev);

		}
	}

	void deleteByValue(T data)
	{
		if (data <= Max() && data >= Min())
		{
			tmp = root;
			BSTNode<T>* prev = tmp;
			bool found = false;

			while (tmp->info != data)
			{
				prev = tmp;
				if (data > tmp->info)
				{
					tmp = tmp->right;
				}
				else
				{
					tmp = tmp->left;
				}

				if (tmp->info == data)
				{
					found = true;
				}
			}

			if (found)
			{
				deleteBtAddress(tmp, prev);
			}
		}
	}

	int getHeight(BSTNode<T>* node)
	{
		if (node == NULL)
		{
			return 0;
		}

		return 1 + max(getHeight(node->left), getHeight(node->right));
	}

	bool isBalanced()
	{
		return (abs(getHeight(root->left) - getHeight(root->right)) <= 1);
	}

	void printTree()
	{

		print(root);

	}


	/*

	Point 1, 2 Problem 11
	Youssef Mohammed Abd El-Hay Ali
	20200669


	Point 3 of problem 11

	Ahmed Sobhy Abd El-Hady Abd El-Rahman
	20200020


	*/
    bool areIdentical(BSTNode<T>* root1,BSTNode<T>* root2)
    {
    if (root1 == NULL && root2 == NULL)
    {

        return true;
    }
    if (root1 == NULL || root2 == NULL){
        return false;
    }

//Checking if the data of both roots, left and right subtrees are the same
    if(root1->info == root2->info){

        if(areIdentical(root1->left, root2->left)){

                if(areIdentical(root1->right, root2->right))
    {
                        return true;
    }
            }
    }
    return 0;
}


// Returns True if T2 is SubTree of T1

    bool isSubTree(BSTNode<T>* T1,BSTNode<T>* T2){
        if (T1 == NULL){
            return false;
        }
        if (T2 == NULL){
            return true;
        }
        if (areIdentical(T1, T2)){
            return true;
        }

        if(isSubTree(T1->left, T2)|| isSubTree(T1->right, T2)){
            return true;
        }
        return 0;
    }
    
    
    
    /*
	    Point 3 of problem 11
        Mohamed Ahmed Hamed
    	20200422
   */
   
   void printRange( BSTNode<T>* r , int low , int high){
	    if(r != NULL){
	       if (  low < r->info ){
	           printRange(r->left,  low,  high);
	       }
          if (  low <= r->info &&  high >= r->info ){
              cout<<r->info<<" ";
          }
        
          printRange(r->right, low,  high);
	      
	    }
	}



};

// Test Cases for 11.2 of Problem 
    void testcase2_1(){
        BSTFCI<int> t1;
    	t1.insert(5);
    	t1.insert(4);
    	t1.insert(2);
    	t1.insert(6);
    	t1.insert(3);
    	t1.insert(7);
    	cout << t1.isBalanced()<<endl;

    }
    void testcase2_2(){
        BSTFCI<int> t2;
    	t2.insert(10);
    	t2.insert(9);
    	t2.insert(8);
    	t2.insert(7);
    	t2.insert(6);
    	t2.insert(5);
    	t2.insert(4);
    	t2.insert(3);
    	t2.insert(2);
    	t2.insert(1);
    	 
    	cout << t2.isBalanced()<<endl;

    }
    void testcase2_3(){
        BSTFCI<int> t3;
    	t3.insert(20);
    	t3.insert(40);
    	t3.insert(30);
    	t3.insert(10);
    	t3.insert(70);
    	t3.insert(90);
    	t3.insert(100);
    	 
    	cout << t3.isBalanced()<<endl;



    }
    void testcase2_4(){
        BSTFCI<int> t4;
    	t4.insert(5);
    	t4.insert(4);
    	t4.insert(2);
    	t4.insert(6);
    	t4.insert(3);
    	t4.insert(7);
    	t4.insert(10);
    	t4.insert(15);
    	 
    	cout << t4.isBalanced()<<endl;

    }
    void testcase2_5(){
        BSTFCI<float> t5;
    	t5.insert(5.5);
    	t5.insert(4.2);
    	t5.insert(2.4);
    	t5.insert(6);
    	t5.insert(7.9);
    	t5.insert(3);
    	t5.insert(20);
    	t5.insert(40.5);
    	t5.insert(60.4);
     
    	cout << t5.isBalanced()<<endl;


    }
// Test Cases for 11.3 of Problem
    void testcase3_1(){
    BSTFCI<int> t1;
    BSTFCI<int> t2;
	t1.insert(5);
    t1.insert(3);
    t1.insert(7);
    t1.insert(2);
    t1.insert(4);
    t1.insert(9);
    t1.insert(1);
    t1.insert(8);
    t1.insert(10);

    t2.insert(9);
    t2.insert(8);
    t2.insert(10);

    cout << "Test case number 1: " << endl;
if (t1.isSubTree(t1.root,t2.root)){
        cout << "Tree 2 is subtree of Tree 1" << " (True) " << endl;

    }else{
        cout << "Tree 2 is not a subtree of Tree 1" << " (False) " << endl;
    }



    }
    void testcase3_2(){
    BSTFCI<int> t1;
    BSTFCI<int> t3;
	t1.insert(5);
    t1.insert(3);
    t1.insert(7);
    t1.insert(2);
    t1.insert(4);
    t1.insert(9);
    t1.insert(1);
    t1.insert(8);
    t1.insert(10);

    t3.insert(3);
    t3.insert(1);
    t3.insert(2);
    t3.insert(4);

    cout << "Test case number 2: " << endl;

if (t1.isSubTree(t1.root,t3.root)){
        cout << "Tree 2 is subtree of Tree 1" << " (True) " << endl;

    }else{
        cout << "Tree 2 is not a subtree of Tree 1" << " (False) " << endl;
    }



    }
    void testcase3_3(){
    BSTFCI<int> t1;
    BSTFCI<int> t2;
	t1.insert(26);
    t1.insert(3);
    t1.insert(3);
    t1.insert(10);
    t1.insert(4);
    t1.insert(30);
    t1.insert(6);


    t2.insert(10);
    t2.insert(6);
    t2.insert(4);
    t2.insert(30);

    cout << "Test case number 3: " << endl;

if (t1.isSubTree(t1.root,t2.root)){
        cout << "Tree 2 is subtree of Tree 1" << " (True) " << endl;

    }else{
        cout << "Tree 2 is not a subtree of Tree 1" << " (False) " << endl;
    }


    }


    void testcase3_4(){
    BSTFCI<int> t1;
    BSTFCI<int> t2;
	t1.insert(9);
    t1.insert(8);
    t1.insert(10);

    t2.insert(3);
    t2.insert(2);
    t2.insert(4);
    t2.insert(1);

    cout << "Test case number 4: " << endl;


if (t1.isSubTree(t1.root,t2.root)){
        cout << "Tree 2 is subtree of Tree 1" << " (True) " << endl;

    }else{
        cout << "Tree 2 is not a subtree of Tree 1" << " (False) " << endl;
    }



    }
    void testcase3_5(){
    BSTFCI<int> t1;
    BSTFCI<int> t2;
	t1.insert(1);
    t1.insert(2);
    t1.insert(3);

    t2.insert(1);
    t2.insert(2);
    t2.insert(3);


    cout << "Test case number 5: " << endl;

if (t1.isSubTree(t1.root,t2.root)){
        cout << "Tree 2 is subtree of Tree 1" << " (True) " << endl;

    }else{
        cout << "Tree 2 is not a subtree of Tree 1" << " (False) " << endl;
    }



    }
    
// Test Cases for 11.4 of Problem 
    void testcase4_1(){
        BSTFCI<int> t1;
    	t1.insert(5);
    	t1.insert(4);
    	t1.insert(2);
    	t1.insert(6);
    	t1.insert(3);
    	t1.insert(7);
    	cout<<"case 1"<<endl;
    	cout<<"printRange = [ ";
        t1.printRange(t1.root,2,5);
        cout<<" ]"<<endl;

    }
    void testcase4_2(){
        BSTFCI<int> t2;
    	t2.insert(10);
    	t2.insert(9);
    	t2.insert(8);
    	t2.insert(7);
    	t2.insert(6);
    	t2.insert(5);
    	t2.insert(4);
    	t2.insert(3);
    	t2.insert(2);
    	t2.insert(1);
    	cout<<"case 2"<<endl;
    	cout<<"printRange = [ ";
        t2.printRange(t2.root,1,10);
        cout<<" ]"<<endl;

    }
    void testcase4_3(){
        BSTFCI<int> t3;
    	t3.insert(20);
    	t3.insert(40);
    	t3.insert(30);
    	t3.insert(10);
    	t3.insert(70);
    	t3.insert(90);
    	t3.insert(100);
    	cout<<"case 3"<<endl;
    	cout<<"printRange = [ ";
        t3.printRange(t3.root,20,50);
        cout<<" ]"<<endl;



    }
    void testcase4_4(){
        BSTFCI<int> t4;
    	t4.insert(5);
    	t4.insert(4);
    	t4.insert(2);
    	t4.insert(6);
    	t4.insert(3);
    	t4.insert(7);
    	t4.insert(10);
    	t4.insert(15);
    	cout<<"case 4"<<endl;
    	cout<<"printRange = [ ";
        t4.printRange(t4.root,2,5);
        cout<<" ]"<<endl;


    }
    void testcase4_5(){
        BSTFCI<float> t5;
    	t5.insert(5.5);
    	t5.insert(4.2);
    	t5.insert(2.4);
    	t5.insert(6);
    	t5.insert(7.9);
    	t5.insert(3);
    	t5.insert(20);
    	t5.insert(40.5);
    	t5.insert(60.4);
        cout<<"case 5"<<endl;
    	 cout<<"printRange = [ ";
        t5.printRange(t5.root,2,8);
        cout<<" ]"<<endl;


    }
   
int main()
{
    
cout<<"Point 2"<<endl;
    
// Test cases for point 2 of problem 11
testcase2_1();
testcase2_2();
testcase2_3();
testcase2_4();
testcase2_5();



/*
	testcases Point 3 of problem 11
	Ahmed Sobhy Abd El-Hady Abd El-Rahman
	20200020

*/
// Test cases for point 3 of problem 11
cout<<"Point 3"<<endl;
testcase3_1();
testcase3_2();
testcase3_3();
testcase3_4();
testcase3_5();


/*
	testcases Point 3 of problem 11
    Mohamed Ahmed Hamed
	20200422

*/
// Test cases for point 4 of problem 11
cout<<"Point 4"<<endl;
testcase4_1();
testcase4_2();
testcase4_3();
testcase4_4();
testcase4_5();

}