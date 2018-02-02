// Queue.h
// Templated Queue Implemented with doubly linked list
// NOTE: Definitions must go in .h file because of templating
#pragma once

#include <iostream>
#include "QueueNode.h"

using namespace std;

// Class Interface
template <typename T>
class Queue {
  private:
    int size;
    QueueNode<T> *first, *last, *tmp;
  public:
    Queue();
    ~Queue();
    QueueNode<T>* remove();
    void add(QueueNode<T> &n);
    void add(T data);
    QueueNode<T>* peek();
    bool isEmpty();
    void print();
    void clear();
};

// Class Definitions
template <typename T>
Queue<T>::Queue() {
  size = 0;
  first = 0;
  last = 0;
}

template <typename T>
Queue<T>::~Queue() {
  clear();
  return;
}

template <typename T>
QueueNode<T>* Queue<T>::remove() {
  if (first) {

  } else {
    return 0;
  }
}

template <typename T>
void Queue<T>::add(QueueNode<T> &n) {
  
  size++;
}

template <typename T>
void Queue<T>::add(T data) {
  QueueNode<T> *n = new QueueNode<T>();
  n->data = data;

  size++;
}

template <typename T>
QueueNode<T>* Queue<T>::peek() {
  return first;
}

template <typename T>
bool Queue<T>::isEmpty() {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}

template <typename T>
void Queue<T>::print() {
  tmp = last;
  while(tmp) {
    cout << tmp->data;
    tmp = tmp->next;
    if (tmp) {
      cout << " , ";
    }
  }
  cout << " [size=" << size << "]" << '\n';
}

template <typename T>
void Queue<T>::clear() {
  while(first) {
    tmp = first->next;
    delete first;
    first = tmp;
  }
  size = 0;
  first = 0;
  last = 0;
  tmp = 0;
  return;
}