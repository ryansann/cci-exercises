// StackSet.h
// Set of stacks implemented with a vector
// The Stacks we will use our the implementation in
//
//        [ size = 8, capacity = 5 ]
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
    int capacity, size;
    vector<Stack<T>*> stackSet;
  public:
    StackSet();
    ~StackSet();
    void push(StackNode<T> *n);
    StackNode<T> *pop();
    StackNode<T> *peek();
    bool isEmpty();
    void print();
    void clear();
};

template <typename T>
StackSet<T>::StackSet() {

}

template <typename T>
StackSet<T>::~StackSet() {
  
}

template <typename T>
void StackSet<T>::push(StackNode<T> *n) {
  
}

template <typename T>
StackNode<T> *StackSet<T>::pop() {
  
}

template <typename T>
StackNode<T> *StackSet<T>::peek() {
  
}

template <typename T>
bool StackSet<T>::isEmpty() {
  
}

template <typename T>
void StackSet<T>::print() {
  
}