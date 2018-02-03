#include <iostream>
#include "Animal.h"
#include "AnimalShelter.h"
#include "../Queue/QueueNode.h"

using namespace std;

int main() {
  Animal a = Animal("dog"), b = Animal("cat"), c = Animal("cat"), d = Animal("dog"), e = Animal("cat");
  AnimalShelter as = AnimalShelter();
  as.enqueue(a);
  as.enqueue(b);
  as.enqueue(c);
  as.enqueue(d);
  as.enqueue(e);
  as.print();
  QueueNode<Animal> *dogNode = as.dequeueDog();
  cout << "Dequeued dog: " << dogNode->data << '\n';
  return 0;
}