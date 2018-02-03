// AnimalShelter.h
// Maintains a queue of dogs and a queue of cats in the shelter
// Also tracks the oldest between the two lists for dequeueAny
//
//      last (enqueueDog)              first (dequeueDog)
//          |   next/prev              |
//         ___   |  ___      ___      ___
// dogs = | 7 |<-->| 4 |<-->| 3 |<-->| 2 |    [ size = 4 ]
//         ---      ---      ---      ---    
//                  
//      last (enqueueCat)              first (dequeueCat)
//          |   next/prev              |
//         ___   |  ___      ___      ___
// cats = | 8 |<-->| 6 |<-->| 5 |<-->| 1 |    [ size = 4 ]
//         ---      ---      ---      ---    
//
#pragma once

#include "Animal.h"
#include "../Queue/Queue.h"
#include "../Queue/QueueNode.h"

class AnimalShelter {
  private:
    Queue<Animal> *dogs, *cats;
    int curAnimal;
  public:
    AnimalShelter();
    ~AnimalShelter();
    QueueNode<Animal>* dequeueAny();
    QueueNode<Animal>* dequeueDog();
    QueueNode<Animal>* dequeueCat();
    void enqueue(QueueNode<Animal> *n);
    void enqueue(Animal animal);
    QueueNode<Animal>* peekDogs();
    QueueNode<Animal>* peekCats();
    bool isEmptyDogs();
    bool isEmptyCats();
    bool isEmpty();
    void printDogs();
    void printCats();
    void print();
    void clearDogs();
    void clearCats();
    void clear();
};