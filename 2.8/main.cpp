// Find node at beginning of linked list loop
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;



int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.addNode(10);
  list.print();

  return 0;
}