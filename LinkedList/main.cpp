// Tests for LinkedList class
#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {

  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.print();

  return 0;
}