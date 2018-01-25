#include <iostream>
#include "ArrayList.h"

using namespace std;

struct Person {
  const char *name;
};

int main() {

  ArrayList<int> myArrayList;

  int first = 1, second = 10, third = 100;

  myArrayList.appendElement(first);
  myArrayList.print();
  myArrayList.appendElement(second);
  myArrayList.print();
  myArrayList.appendElement(third);
  myArrayList.print();
  myArrayList.deleteElement(1);
  myArrayList.print();

  Person one, two, three;
  one.name = "Ryan Sanna";
  two.name = "Jeff Bridges";
  three.name = "Mr. Man";

  ArrayList<Person> people;
  people.appendElement(one);
  people.appendElement(two);
  people.appendElement(three);
  people.deleteElement(1);
  for(int i = 0; i < people.getSize(); i++) {
    cout << people[i].name << '\n';
  }

  return 0;

}