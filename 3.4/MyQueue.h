// MyQueue.h
// Queue implemented with two stacks
//
//        [ size = 8 ]
//
//       top  
//        |___     ___     ___     ___     ___
// s1 ->  | 5 |-->| 4 |-->| 3 |-->| 2 |-->| 1 |      
//         ---     ---     ---     ---     ---     
//                  
//       top    
//        |___     ___     ___     ___     ___
// s2 ->  | 1 |-->| 2 |-->| 3 |-->| 4 |-->| 5 |
//         ---     ---     ---     ---     ---
//
#pragma once

#include <iostream>
#include "../Stack/Stack.h"
#include "../Stack/StackNode.h"

using namespace std;

template <typename T>
class MyQueue {
  private:
    Stack<T> *s1, *s2;
  public:
    MyQueue();
    ~MyQueue();
    StackNode<T>* dequeue();
    void enqueue(StackNode<T> *n);
    void enqueue(T data);
    StackNode<T>* peek();
    bool isEmpty();
    void print();
    void clear();
};

template <typename T>
MyQueue<T>::MyQueue() {
  
}

template <typename T>
MyQueue<T>::~MyQueue() {
  clear();
}

template <typename T>
StackNode<T> *MyQueue<T>::dequeue() {
  
}

template <typename T>
void MyQueue<T>::enqueue(StackNode<T> *n) {
  
}

template <typename T>
void MyQueue<T>::enqueue(T data) {
  
}

template <typename T>
StackNode<T> *MyQueue<T>::peek() {

}

template <typename T>
bool MyQueue<T>::isEmpty() {
  
}

template <typename T>
void MyQueue<T>::print() {
  
}

template <typename T>
void MyQueue<T>::clear() {
  
}