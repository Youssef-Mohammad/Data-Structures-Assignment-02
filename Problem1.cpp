/*
Youssef Mohammed Abd El-Hay Ali
20200669
*/

#include<iostream>
using namespace std;

template<class T>
class node
{
public:
	T info;
	node* next = NULL;
	node* last = NULL;
};

template<class T>
class Stack
{
public:

	int length;
	node<T>* head;
	node<T>* end;
	node<T>* tmp;

	Stack()
	{
		length = 0;
		head = NULL;
		end = NULL;
		tmp = NULL;
	}

	~Stack()
	{
		if (length > 0)
		{
			while (end != head)
			{
				tmp = end;
				end = end->last;
				if (end == head)
				{
					delete head;
				}
				delete tmp;
			}
		}
	}

	void push(T data)
	{
		length++;
		tmp = new node<T>;
		tmp ->info = data;

		if (length == 1)
		{
			head = tmp;
			end = head;
			head->next = NULL;
			head->last = NULL;
		}
		else
		{
			end->next = tmp;
			tmp->last = end;
			end = end->next;
		}
		end->next = NULL;
	}

	
	void pop()
	{
		if (end != head && head != NULL)
		{
			tmp = end;
			end = end->last;
			end->next = NULL;
			delete tmp;
			length--;
		}
		else if (end == head && head != NULL)
		{
			delete head;
			length--;
		}
		else
		{
			cout << "Empty Stack!" << endl;
		}
	}

	
	void printStack()
	{
		node<T>* n = head;
		while (n != NULL)
		{
			cout << (n->info != "/" ? "/":"") << n->info;
			n = n->next;
		}
	}

};

void getCanonicalPath(string path)
{
	if (path[0] != '/' )
	{
		cout << "This is not a Valid Path!" << endl;
		return;
	}
	else
	{
		Stack<string> l1;
		string directory = "";
		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] != '/')
			{
				directory += path[i];
			}
			if ((path[i] == '/' && i != 0) || i == (path.length() -1))
			{
				if (directory == "..")
				{
					if (l1.length > 0)
					{
						l1.pop();
					}
					directory = "";
				}
				else if (directory == "." || directory == "")
				{
					directory = "";
				}
				else
				{
					l1.push(directory);
					directory = "";
				}
				
			}
		}
		if (l1.length == 0)
		{
			l1.push("/");
		}
		l1.printStack();
	}
}

int main()
{
	string path;
	bool again = true;
	while (again)
	{
		cout << endl << "Enter an Absolute Path: " << endl;
		cin >> path;

		getCanonicalPath(path);

		cout << endl << "Again?" << endl;
		cin >> path;

		if (path != "y" && path != "Y")
		{
			again = false;
		}
	}

	return 0;
}