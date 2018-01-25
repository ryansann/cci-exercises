#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {

  ArrayList<int> myArrayList;

  int first = 1, second = 10, third = 100;

  myArrayList.appendElement(first);
  myArrayList.appendElement(second);
  myArrayList.print();
  myArrayList.appendElement(third);
  myArrayList.print();
  myArrayList.deleteElement(1);
  myArrayList.print();

  return 0;
  
}