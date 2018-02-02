// StackSet.h
// Set of stacks implemented with a vector
// The Stacks we will use our the implementation in
// We'll never have a stack with 0 elements in this implementation
//
//        [ numStacks = 2, numElements = 8, capacity = 5 ]
//         ___     ___     ___     ___     ___
//        | e |-->| d |-->| c |-->| b |-->| a |      
//         ---     ---     ---     ---     ---
//          |
//         ___     ___     ___
// top -> | h |-->| g |-->| f |
//         ---     ---     ---
//
#pragma once

#include <iostream>
#include <vector>
#include "../Stack/Stack.h"
#include "../Stack/StackNode.h"

using namespace std;

template <typename T>
class StackSet {
  private:
    unsigned int capacity;
    static const unsigned int defaultCapacity = 5;
    vector<Stack<T>*> stackSet;
    Stack<T> * stackPtr;
  public:
    StackSet();
    StackSet(unsigned int cap);
    ~StackSet();
    void push(T data);
    void push(StackNode<T> *n);
    StackNode<T> *pop();
    StackNode<T> *peek();
    int getNumStacks();
    int getNumElements();
    bool isEmpty();
    void print();
    void clear();
};

template <typename T>
StackSet<T>::StackSet() {
  StackSet(defaultCapacity);
}

template <typename T>
StackSet<T>::StackSet(unsigned int cap) {
  capacity = cap;
  stackPtr = 0;
}

template <typename T>
StackSet<T>::~StackSet() {
  clear();
}

template <typename T>
void StackSet<T>::push(T data) {
  StackNode<T> *newNode = new StackNode<T>();
  newNode->data = data;
  push(newNode);
}

template <typename T>
void StackSet<T>::push(StackNode<T> *n) {
  if (!stackSet.empty()) { // we have a stack
    stackPtr = stackSet.back();
    if (stackPtr->getSize() < capacity) { // we have room in this stack
      stackPtr->push(n);
    } else { // we need a new stack to not exceed capacity in current stack
      stackPtr = new Stack<T>();
      stackSet.push_back(stackPtr);
      stackPtr->push(n);
    }
  } else { // we have no stacks
    stackPtr = new Stack<T>();
    stackSet.push_back(stackPtr);
    stackPtr->push(n);
  }
}

template <typename T>
StackNode<T> *StackSet<T>::pop() {
  if (!stackSet.empty()) {
    stackPtr = stackSet.back();
    StackNode<T> *n = stackPtr->pop();
    if (stackPtr->getSize() == 0) { // pop caused size to go to 0 - remove and deallocate stack
      stackSet.pop_back();
      delete stackPtr;
    }
  } else { // no stacks to pop from
    return 0;
  }
}

template <typename T>
StackNode<T> *StackSet<T>::peek() {
  if (!stackSet.empty()) { // we have a stack to peek at
    stackPtr = stackSet.back();
    return stackPtr->peek();
  } else { // no stacks in set
    return 0;
  }
}

template <typename T>
int StackSet<T>::getNumStacks() {
  return stackSet.size();
}

template <typename T>
int StackSet<T>::getNumElements() {
  int numElements = 0;
  for (typename vector<Stack<T>*>::iterator it = stackSet.begin(); it != stackSet.end(); it++) {
    numElements += (*it)->getSize();
  }
  return numElements;
}

template <typename T>
bool StackSet<T>::isEmpty() {
  if (stackSet.empty()) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
void StackSet<T>::print() {
  cout << "StackSet:" << '\n';
  for (typename vector<Stack<T>*>::iterator it = stackSet.begin(); it != stackSet.end(); it++) {
    cout << it - stackSet.begin() << ": ";
    (*it)->print();
  }
}

template <typename T>
void StackSet<T>::clear() {
  for (typename vector<Stack<T>*>::iterator it = stackSet.begin(); it != stackSet.end(); it++) {
    (*it)->clear();
    delete *it;
  }
}