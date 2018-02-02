// Stack.h
// Stack to store data
// NOTE: Definitions must go in .h file because of templating
#pragma once

// Included Dependencies
#include <iostream>
#include "StackNode.h"

using namespace std;

// Class Interface
template <typename T>
class Stack {
  private:
    int size;
    StackNode<T> *top;
    StackNode<T> *tmp;
  public:
    Stack();
    ~Stack();
    StackNode<T>& pop();
    void push(StackNode<T> &n);
    void push(T data);
    StackNode<T>& peek();
    bool isEmpty();
    void clear();
};

// Class Definitions
template <typename T>
Stack<T>::Stack() {
  size = 0;
  top = 0;
}

template <typename T>
Stack<T>::~Stack() {
  clear();
  return;
}

template <typename T>
StackNode<T>& Stack<T>::pop() {
  if (top) {
    tmp = top;
    top = tmp->next;
    size--;
    return tmp;
  } else {
    return 0;
  }
}

template <typename T>
void Stack<T>::push(StackNode<T> &n) {
  n->next = top;
  top = n;
  size++;
}

template <typename T>
void Stack<T>::push(T data) {
  StackNode<T> *n = new StackNode<T>();
  n->data = data;
  n->next = top;
  top = n;
  size++;
}

template <typename T>
StackNode<T>& Stack<T>::peek() {
  return top;
}

template <typename T>
bool Stack<T>::isEmpty() {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
void Stack<T>::clear() {
  while(top) {
    tmp = top->next;
    delete top;
    top = tmp;
  }
  size = 0;
  top = 0;
  return;
}