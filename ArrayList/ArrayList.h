// ArrayList.h
// Dynamically Resizing Templated Array

// Included Dependencies
#include <iostream>

// Include Guard
#ifndef __ARRAYLIST_H_INCLUDED__
#define __ARRAYLIST_H_INCLUDED__

// Class Interface
template <typename T>
class ArrayList {
  
  private:
    int size;
    T *arrayList;
    void resize(int newSize);

  public:
    // instance ops
    ArrayList();
    ArrayList(int s);
    ArrayList(const ArrayList<T> &original);
    ~ArrayList();

    // getters setters
    int getSize();
    void setSize(int s);

    // operator overloads
    T &operator[](int index);

    // array ops
    T get(int index);
    void insert(int index, T element);
    void append(T element);
    T pop();
    void print();

};

using namespace std;

// Class Definitions
// Public methods
template <typename T>
ArrayList<T>::ArrayList() {
  ArrayList(1);
}

template <typename T>
ArrayList<T>::ArrayList(int s) {
  setSize(s);
  arrayList = new T[size];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &original) {
  ArrayList<T> copy = ArrayList(original.getSize());
  memcpy(copy.arrayList, original.arrayList, size * sizeof(T));
  return copy;
}

template <typename T>
ArrayList<T>::~ArrayList() {
  delete[] arrayList;
}

template <typename T>
int ArrayList<T>::getSize() {
  return size;
}

template <typename T>
void ArrayList<T>::setSize(int s) {
  size = s;
}

template <typename T>
T &ArrayList<T>::operator[](int index) {
  if ((index - 1) > getSize()) {
    resize(2 * getSize()); // double the size
  }
  return arrayList[index]; // return reference
}

template <typename T>
T ArrayList<T>::get(int index) {
  return arrayList[index];
}

template <typename T>
void ArrayList<T>::insert(int index, T element) {
  arrayList[index] = element;
}

template <typename T>
void ArrayList<T>::append(T element) {
  return;
}

template <typename T>
T ArrayList<T>::pop() {
  return;
}

template <typename T>
void ArrayList<T>::print() {
  for(int i = 0; i < getSize(); i++) {
    cout << "ArrayList[" << i << "] = " << arrayList[i] << '\n';
  }
}

// Private methods
template <typename T>
void ArrayList<T>::resize(int newSize) {
  T *temp = new T[newSize];
  for(int i = 0; i < getSize(); i++) {
    temp[i] = arrayList[i];
  };
  delete[] arrayList;
  arrayList = temp;
  setSize(newSize);
}

#endif