// Find kth to last element in list
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

Node* LinkedList::getKthFromLast(int k) {
  return new Node();
}

int main() {

  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.addNode(10);
  list.print();
  Node* n = list.getKthFromLast(2);

  return 0;
}