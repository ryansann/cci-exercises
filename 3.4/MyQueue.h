// MyQueue.h
// Queue implemented with two stacks
//
//       [ size = 8 ]
//
//       top  
//        |___     ___     ___     ___     ___
// s1 ->  | 5 |-->| 4 |-->| 3 |-->| 2 |-->| 1 |      
//         ---     ---     ---     ---     ---     
//                  
//       top    
//        |___     ___     ___     ___     ___
// s2 ->  | - |-->| - |-->| - |-->| - |-->| - |
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
    // enqueue state is when all elements are in s1 arranged newest at the top and oldest at the bottom
    // when false we are in dequeue state i.e. all elements in s2 arranged oldest on top to newest on bottom
    bool enqueueState;
    void copyStack(Stack<T> *src, Stack<T> *dest);
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
  s1 = new Stack<T>();
  s2 = new Stack<T>();
  enqueueState = true;
}

template <typename T>
MyQueue<T>::~MyQueue() {
  clear();
}

template <typename T>
void MyQueue<T>::copyStack(Stack<T> *src, Stack<T> *dest) {
  // copy all elements from src over to dest
  StackNode<T> *top = src->pop();
  while (top) {
    dest->push(top);
    top = src->pop();
  }
  enqueueState = !enqueueState;
}

template <typename T>
StackNode<T> *MyQueue<T>::dequeue() {
  if (enqueueState) {
    copyStack(s1, s2);
  }
  return s2->pop();
}

template <typename T>
void MyQueue<T>::enqueue(StackNode<T> *n) {
  if (!enqueueState) {
    copyStack(s2, s1);
  }
  s1->push(n);
}

template <typename T>
void MyQueue<T>::enqueue(T data) {
  StackNode<T> *newNode = StackNode<T>();
  newNode->data = data;
  enqueue(newNode);
}

template <typename T>
StackNode<T> *MyQueue<T>::peek() {
  if (enqueueState) {
    copyStack(s1, s2);
  }
  return s2->peek();
}

template <typename T>
bool MyQueue<T>::isEmpty() {
  if (s1->isEmpty() && s2->isEmpty()) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
void MyQueue<T>::print() {
  cout << "enqueueState: " << enqueueState << '\n';
  cout << "S1: ";
  s1->print();
  cout << "\nS2: ";
  s2->print();
}

template <typename T>
void MyQueue<T>::clear() {
  s1->clear();
  s2->clear();
  delete s1;
  delete s2;
}