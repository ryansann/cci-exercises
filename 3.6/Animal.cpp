#include <string>
#include <iostream>
#include "Animal.h"

Animal::Animal() {
  type = "none";
  order = -1;
}

Animal::Animal(string t) {
  type = t;
}

int Animal::getOrder() const {
  return order;
}

void Animal::setOrder(int o) {
  order = o;
}

void Animal::setType(string t) {
  type = t;
}

string Animal::getType() const {
  return type;
}

bool Animal::isCat() {
  if (type == "cat") {
    return true;
  } else {
    return false;
  }
}

bool Animal::isDog() {
  if (type == "dog") {
    return true;
  } else {
    return false;
  }
}

ostream& operator<<(ostream& os, Animal const &a) {
  os << "[type=" << a.getType() << "|order= " << a.getOrder() << "]"; 
  return os;
}