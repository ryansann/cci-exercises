// Queue.h
// Templated Queue Implemented with doubly linked list
//
//  last (enqueue)              first (dequeue)
//    |   next/prev              |
//   ___   |  ___      ___      ___
//  | a |<-->| b |<-->| c |<-->| d |    [ size = 4 ]
//   ---      ---      ---      ---
//
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
    QueueNode<T>* dequeue();
    void enqueue(QueueNode<T> *n);
    void enqueue(T data);
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
  tmp = 0;
}

template <typename T>
Queue<T>::~Queue() {
  clear();
  return;
}

template <typename T>
QueueNode<T>* Queue<T>::dequeue() {
  if (first) {
    tmp = first;
    first = first->prev; // new first node
    first->next = 0; // no node in front of first
    tmp->prev = 0; // dequeue'd node has no prev (and next since it was first previously)
    size--; // list is one node smaller now
    return tmp;
  } else { // nothing to dequeue
    return 0;
  }
}

template <typename T>
void Queue<T>::enqueue(QueueNode<T> *n) {
  if (last) { // we have a node to connect to
    tmp = last;
    last = n; // new last
    tmp->prev = last; // tmp is now second to last
    last->next = tmp; // tmp is after new last
  } else { // this is the first node (gets first and last pointers)
    first = n; // new first
    last = n; // new last
    n->prev = 0; // no prev since it is last
    n->next = 0; // no next since it is first
  }
  size++;
}

template <typename T>
void Queue<T>::enqueue(T data) {
  QueueNode<T> *n = new QueueNode<T>();
  n->data = data;
  enqueue(n);
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
  // delete from front to back to enforce FIFO
  while(first) {
    tmp = first->prev;
    delete first;
    first = tmp;
  }
  size = 0;
  first = 0;
  last = 0;
  tmp = 0;
  return;
}