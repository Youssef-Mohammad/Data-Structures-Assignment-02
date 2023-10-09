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
	node* behind;
	T info;
};

template<class T>
class Queue
{
public:
	int length;
	node<T>* first;
	node<T>* last;
	node<T>* tmp;

	Queue()
	{
		length = 0;
		first = NULL;
		last = NULL;
		tmp = NULL;
	}

	~Queue()
	{
		for (int i = 0; i < length; i++)
		{
			tmp = first;
			first = first->behind;
			delete tmp;
		}
	}

	void push(T value)
	{
		if (length == 0)
		{
			first = new node<T>;
			first->info = value;
			last = first;
			first->behind = NULL;
			length++;
		}
		else
		{
			last->behind = new node<T>;
			last = last->behind;
			last->info = value;
			last->behind = NULL;
			length++;
			}
	}

	void pop()
	{
		tmp = first;
		first = first->behind;
		length--;
		delete tmp;
	}

	void printQueue()
	{
		tmp = first;
		for (int i = 0; i < length; i++)
		{
			cout << tmp->info <<endl;
			tmp = tmp->behind;
		}
	}

};

class Stack
{
public:

	Queue<int> q1;

	void push(int value)
	{
		q1.push(value);
		for (int i = 0; i < q1.length - 1; i++)
		{
			q1.push(q1.first->info);
			q1.pop();
		}
	}

	void pop()
	{
		if (q1.length > 0)
		{
			q1.pop();
		}
	}

	int top()
	{
		return q1.first->info;
	}

	void printStack()
	{
		q1.printQueue();
	}
};

int main()
{
	Stack s1;
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);

	s1.pop();
	s1.pop();

	cout << "Top of The Stack: " << s1.top() << endl;
	cout << endl << "Stack: " << endl;
	s1.printStack();

	return 0;
}