// MinStack.h
// MinStack implemented with Stack
// Smallest elements will appear on the top of the stack regardless of push order
//    top
//     |   next
//    ___  |  ___     ___     ___     ___
//   | 1 |-->| 2 |-->| 3 |-->| 4 |-->| 5 |     [ size = 5 ] 
//    ---     ---     ---     ---     ---
//
#pragma once

// Included Dependencies
#include <iostream>
#include "../Stack/StackNode.h"

using namespace std;

// Class Interface
template <typename T>
class MinStack {
  private:
    Stack<T> *s1, *s2;
  public:
    MinStack();
    ~MinStack();
    StackNode<T>* pop();
    void push(StackNode<T> *n);
    void push(T data);
    StackNode<T>* peek();
    bool isEmpty();
    int getSize();
    void print();
    void clear();
};

// Class Definitions
template <typename T>
MinStack<T>::MinStack() {
  
}

template <typename T>
MinStack<T>::~MinStack() {
  clear();
  return;
}

template <typename T>
StackNode<T>* MinStack<T>::pop() {
  
}

template <typename T>
void MinStack<T>::push(StackNode<T> *n) {
  
}

template <typename T>
void MinStack<T>::push(T data) {
  StackNode<T> *n = new StackNode<T>();
  n->data = data;
  push(n);
}

template <typename T>
StackNode<T>* MinStack<T>::peek() {

}

template <typename T>
bool MinStack<T>::isEmpty() {
  
}

template <typename T>
int MinStack<T>::getSize() {

}

template <typename T>
void MinStack<T>::print() {
  
}

template <typename T>
void MinStack<T>::clear() {
  
}