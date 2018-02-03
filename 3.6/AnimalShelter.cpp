#include "AnimalShelter.h"
#include "Animal.h"
#include "../Queue/Queue.h"
#include "../Queue/QueueNode.h"

using namespace std;

AnimalShelter::AnimalShelter() {
  dogs = new Queue<Animal>();
  cats = new Queue<Animal>();
  curAnimal = 1;
}

AnimalShelter::~AnimalShelter() {
  clear();
}

QueueNode<Animal> *AnimalShelter::dequeueAny() {
  QueueNode<Animal> *cat = cats->peek(), *dog = dogs->peek();
  if (cat->data.getOrder() < dog->data.getOrder()) {
    return dequeueCat();
  } else {
    return dequeueDog();
  }
}

QueueNode<Animal> *AnimalShelter::dequeueDog() {
  return dogs->dequeue();
}

QueueNode<Animal> *AnimalShelter::dequeueCat() {
  return cats->dequeue();
}

void AnimalShelter::enqueue(QueueNode<Animal> *n) {
  curAnimal++;
  if (n->data.isDog()) {
    dogs->enqueue(n);
  } else {
    cats->enqueue(n);
  }
}

void AnimalShelter::enqueue(Animal animal) {
  animal.setOrder(curAnimal);
  QueueNode<Animal> *n = new QueueNode<Animal>();
  n->data = animal;
  enqueue(n);
}

QueueNode<Animal> *AnimalShelter::peekCats() {
  return cats->peek();
}

QueueNode<Animal> *AnimalShelter::peekDogs() {
  return dogs->peek();
}

bool AnimalShelter::isEmptyDogs() {
  return dogs->isEmpty();
}

bool AnimalShelter::isEmptyCats() {
  return cats->isEmpty();
}

bool AnimalShelter::isEmpty() {
  return dogs->isEmpty() && cats->isEmpty();
}

void AnimalShelter::printDogs() {
  cout << "Dogs: ";
  dogs->print();
}

void AnimalShelter::printCats() {
  cout << "Cats: ";
  cats->print();
}

void AnimalShelter::print() {
  printDogs();
  printCats();
}

void AnimalShelter::clearDogs() {
  dogs->clear();
  delete dogs;
}

void AnimalShelter::clearCats() {
  cats->clear();
  delete cats;
}

void AnimalShelter::clear() {
  clearDogs();
  clearCats();
}