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
#include "../Stack/Stack.h"
#include "../Stack/StackNode.h"

using namespace std;

// Class Interface
template <typename T>
class MinStack {
  private:
    Stack<T> *s1, *s2;
    StackNode<T> *s1Top, *s2Top;
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
  s1 = new Stack<T>();
  s2 = new Stack<T>();
  s1Top = 0;
  s2Top = 0;
}

template <typename T>
MinStack<T>::~MinStack() {
  clear();
  return;
}

template <typename T>
StackNode<T>* MinStack<T>::pop() {
  return s1->pop();
}

template <typename T>
void MinStack<T>::push(StackNode<T> *n) {
  s1Top = s1->peek();
  if (s1Top) { // we have elements and need to insert into the right place
    s1Top = s1->pop(); // take off first element
    while(s1Top) { // could improve this loop (I don't like the break statement)
      if (n->data < s1Top->data) {
        s1->push(s1Top);
        s1->push(n);
        break; 
      } else {
        s2->push(s1Top);
      }
      s1Top = s1->pop();
    }
    s2Top = s2->pop();
    while(s2Top) {
      s1->push(s2Top);
      s2Top = s2->pop();
    }
  } else { // no elements
    s1->push(n);
  }
}

template <typename T>
void MinStack<T>::push(T data) {
  StackNode<T> *n = new StackNode<T>();
  n->data = data;
  push(n);
}

template <typename T>
StackNode<T>* MinStack<T>::peek() {
  return s1->peek();
}

template <typename T>
bool MinStack<T>::isEmpty() {
  return s1->isEmpty();
}

template <typename T>
int MinStack<T>::getSize() {
  return s1->getSize();
}

template <typename T>
void MinStack<T>::print() {
  s1->print();
}

template <typename T>
void MinStack<T>::clear() {
  s1->clear();
  delete s1;
  delete s2;
}