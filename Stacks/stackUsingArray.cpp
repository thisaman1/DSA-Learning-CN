#include<iostream>
#include<climits>
using namespace std;


class stackUsingArray{

    int *data;
    int capacity;
    int nextIndex;

    public:

    //constructor
    stackUsingArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    //Insertion using push 
    void push(int element){
        if(nextIndex == capacity){
            int *newdata = new int[2*capacity];
            for(int i=0;i<nextIndex;i++){
                newdata[i] = data[i];
            }
            capacity = 2*capacity;
            delete[] data;
            data = newdata;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    //Deletion using pop
    int pop(){
        if(isEmpty){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    //Access to top element using top
    int top(){
        if(isEmpty){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

    //Size of stack using size
    int size(){
        return nextIndex;
    }

    //Check whether stack is empty using isEmpty
    bool isEmpty(){
        return nextIndex==0;
    }

};