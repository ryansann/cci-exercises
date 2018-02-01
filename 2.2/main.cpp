// Find kth to last element in list
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// adding linked list length to class to simplify this implementation
// calculate how far from beginning kth from end is and return that node
// O(n) time
// O(1) space
Node* LinkedList::getKthFromLast(int k) {
  if (k > length) {
    cout << "No element " << k << " nodes from end of list" << '\n';
    return 0;
  } else {
    int numFromBeginning = length - k;
    cur = head;
    while(cur && numFromBeginning) {
      cur = cur->next;
      numFromBeginning--;
    }
    return cur;
  }
}

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.addNode(10);
  list.print();
  Node* n = list.getKthFromLast(4);
  cout << "Data: " << n->data << '\n';

  return 0;
}