// ArrayList.h
// Dynamically Resizing Templated Array
// NOTE: Definitions must go in .h file because of templating

// Included Dependencies
#include <iostream>

// Include Guard
#ifndef __ARRAYLIST_H_INCLUDED__
#define __ARRAYLIST_H_INCLUDED__

// Class Interface
template <typename T>
class ArrayList {
  
  private:
    const static int initialCapacity = 2; // initial number of elements
    const static int reallocationMultiplier = 2; // multiplier for reallocating array
    int size; // this tracks numnber of elements in arrayList
    int maxCapacity; // this tracks current max capacity of arrayList
    T *arrayList;

  public:
    // instance ops
    ArrayList();
    ArrayList(const ArrayList<T> &original);
    ~ArrayList();

    // operator overloads
    T &operator[](int index);

    // getters
    int getSize();

    // array ops
    void appendElement(T &element);
    void deleteElement(unsigned int index);
    void clear();
    void print();

};

using namespace std;

// Class Definitions
template <typename T>
ArrayList<T>::ArrayList() {
  size = 0;
  maxCapacity = initialCapacity;
  arrayList = new T[maxCapacity];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &original) {
  // this could be made more efficient by reducing number of resize opts
  ArrayList<T> copy = ArrayList();
  for(int i = 0; i < size; i++) {
    copy.append(original[i]);
  }
  return copy;
}

template <typename T>
ArrayList<T>::~ArrayList() {
  clear();
}

template <typename T>
T &ArrayList<T>::operator[](int index) {
  return arrayList[index]; // return reference
}

template <typename T>
int ArrayList<T>::getSize() {
  return size;
}

// Resize logic is in this method
template <typename T>
void ArrayList<T>::appendElement(T &element) {
  cout << "Appending element with address: " << &element << '\n';
  if ((size + 1) > maxCapacity) { // we hit the upper bound on the number of T elements arrayList can hold
    cout << "Resize Operation Triggered" << '\n';
    maxCapacity *= reallocationMultiplier;
    T *temp = new T[maxCapacity]; // allocate a bigger chunk of memory for arrayList
    for (int i = 0; i < size; i++) {
      temp[i] = arrayList[i]; // copy our values over O(n)
    }
    delete[] arrayList; // free old array memory
    arrayList = temp; // set arrayList to larger memory array
  }
  arrayList[size] = element; // perform append operation
  size++;
  return;
}

template <typename T>
void ArrayList<T>::deleteElement(unsigned int index) {
  if (index > (size - 1)) { // not in arrayList
    return;
  } else if (size == 1) { // arrayList is only one element, so clear it
    clear();
  } else { // shift elements past index over one to left
    for (int i =  index; i < size; i++) {
      arrayList[i] = arrayList[i + 1];
    }
    size--;
  }
}

template <typename T>
void ArrayList<T>::clear() {
  if (arrayList) {
    delete[] arrayList; // free memory allocated for arrayList
    size = 0;
    arrayList = new T[initialCapacity];
    maxCapacity = initialCapacity;
  }
}

template <typename T>
void ArrayList<T>::print() {
  cout << "Current arrayList size = " << size << '\n';
  cout << "Current arrayList capacity = " << maxCapacity << '\n';
  for(int i = 0; i < size; i++) {
    cout << "ArrayList[" << i << "] = " << "&" << &arrayList[i] << '\n';
  }
}

#endif