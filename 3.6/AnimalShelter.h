// AnimalShelter.h
// Maintains a queue of dogs and a queue of cats in the shelter
// Also tracks the oldest between the two lists for dequeueAny
//
//      last (enqueueDog)              first (dequeueDog)
//          |   next/prev              |
//         ___   |  ___      ___      ___
// dogs = | 4 |<-->| 3 |<-->| 2 |<-->| 1 |    [ size = 4 ]
//         ---      ---      ---      ---    
//                  
//      last (enqueueCat)              first (dequeueCat)
//          |   next/prev              |
//         ___   |  ___      ___      ___
// cats = | 4 |<-->| 3 |<-->| 2 |<-->| 1 |    [ size = 4 ]
//         ---      ---      ---      ---    
//
#pragma once

#include <iostream>
#include "../Queue/Queue.h"
#include "../Queue/QueueNode.h"

using namespace std;

template <typename T>
class AnimalShelter {
  private:
    Queue<T> *dogs, *cats;
  public:
    AnimalShelter();
    ~AnimalShelter();
    QueueNode<T>* dequeueAny();
    QueueNode<T>* dequeueDog();
    QueueNode<T>* dequeueCat();
    void enqueue(QueueNode<T> *n);
    void enqueue(T data);
    QueueNode<T>* peekDogs();
    QueueNode<T>* peekCats();
    bool isEmptyDogs();
    bool isEmptyCats();
    void printDogs();
    void printCats();
    void print();
    void clearDogs();
    void clearCats();
    void clear();
};

template <typename T>
AnimalShelter<T>::AnimalShelter() {
 
}

template <typename T>
AnimalShelter<T>::~AnimalShelter() {
  clear();
}

template <typename T>
QueueNode<T> *AnimalShelter<T>::dequeueAny() {

}

template <typename T>
QueueNode<T> *AnimalShelter<T>::dequeueDog() {

}

template <typename T>
QueueNode<T> *AnimalShelter<T>::dequeueCat() {

}

template <typename T>
void AnimalShelter<T>::enqueue(QueueNode<T> *n) {

}

template <typename T>
void AnimalShelter<T>::enqueue(T data) {

}

template <typename T>
QueueNode<T> *AnimalShelter<T>::peekCats() {

}

template <typename T>
QueueNode<T> *AnimalShelter<T>::peekDogs() {

}

template <typename T>
bool AnimalShelter<T>::isEmptyDogs() {

}

template <typename T>
bool AnimalShelter<T>::isEmptyCats() {

}

template <typename T>
void AnimalShelter<T>::printDogs() {

}

template <typename T>
void AnimalShelter<T>::printCats() {

}

template <typename T>
void AnimalShelter<T>::print() {

}

template <typename T>
void AnimalShelter<T>::clearDogs() {

}

template <typename T>
void AnimalShelter<T>::clearCats() {

}

template <typename T>
void AnimalShelter<T>::clear() {

}