#include <iostream>
/*
    Name: Ahmed Sobhy Abd El-Hady Abd El-Rahman
    ID: 20200020

*/
using namespace std;
class Queue{
    const int max_length = 100;
private:
    int front;
    int rear;
    int length;
    int arr[100];
public:
        Queue(){
    front = -1;
    rear = -1;
    length = 0;
    }
// checking if Queue is empty or not
    bool isempty(){
    return length == 0;
        }
// Checking if Queue is full or not
    bool isfull(){
    return length == max_length;
    }
// Adding new element to Queue
    void enqueue(int element){
    if(isfull()){
        cout << "Queue is full" << endl;
    } else {
// If Queue is empty will add element at beginning
        if(front == -1 && rear == -1){
            rear ++;
            front ++;
            arr[rear] = element;
        } else {
            rear ++;
            arr[rear] = element;
        }

    }
    length++;
    }
// Removing element from Queue
    void dequeue(){
    if(isempty()){
        cout << "Queue is empty" << endl;
    } else if(front!= -1 && rear != -1 && front<= rear) {
        front ++;
        length --;
    }
    }
// Get the value of front
    int frontQueue(){

        return arr[front];
    }
// Get the value of rear
    int rearQueue(){
        return arr[rear];
    }
// print Queue elements
    void print(){
    for (int i = front; i <= rear ; i++){
        cout << arr[i] << " ";
    }
    }
// Function used to reduce 1 from each element when they buy ticket
    void reduction(int pos){
        int counter = 0;
    while(arr[pos]>0){
        for (int i = 0; i<length; i++)
            {
        arr[i] = arr[i]-1;
        if(arr[i]<0){
            continue;
        }
// Counter to calculate number of seconds
        counter ++;

            }
        }
    cout << "Time taken is: " << counter << " seconds" << endl;
    }

};
// Test case to check Queue Implementation
    void testQueueImplementation(){
        Queue q1;
        q1.enqueue(1);
        q1.enqueue(2);
        q1.enqueue(3);
        q1.enqueue(4);
        q1.enqueue(5);
        q1.print();
        cout << endl;
        q1.dequeue();
        q1.print();
        cout << endl;
        q1.enqueue(6);
        q1.print();
        cout << endl;
        q1.dequeue();
        q1.print();
        cout << endl;
    }
// Test Cases
    void testcase1(){
    int k = 2;
    Queue q1;
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(2);
    q1.reduction(k);
    }
    void testcase2(){
    int k = 0;
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.reduction(k);
    }
    void testcase3(){
    int k = 0;
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.reduction(k);
    }
    void testcase4(){
    int k = 2;
    Queue q1;
    q1.enqueue(0);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.reduction(k);
    }

int main()
{
testQueueImplementation();
cout << endl;
testcase1();
cout << endl;
testcase2();
cout << endl;
testcase3();
cout << endl;
testcase4();
}
