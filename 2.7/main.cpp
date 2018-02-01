// 
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// Brute force - just compare all nodes in two lists
// O(n^2) time
// O(1) space
Node* doIntersectByReference(LinkedList &l1, LinkedList &l2) {
  Node *l1Cur = l1.getHead(), *l2Cur = l2.getHead(), *l2Head = l2.getHead();
  while(l1Cur) {
    while(l2Cur) {
      if (l1Cur == l2Cur) {
        return l1Cur;
      }
      l2Cur = l2Cur->next;
    }
    l2Cur = l2Head;
    l1Cur = l1Cur->next;
  }
  return 0;
}

int main() {
  LinkedList l1 = LinkedList(), l2 = LinkedList();
  Node *n = new Node();
  cout << "&n: " << n << '\n';
  n->data = 1234;
  l1.addNode(n);
  l1.addNode(10);
  l1.addNode(100);
  l1.addNode(1000);
  l1.print();
  l2.addNode(n);
  l2.addNode(9);
  l2.addNode(99);
  l2.addNode(999);
  l2.print();
  Node *intersected = doIntersectByReference(l1, l2);
  if (intersected) {
    cout << "Intersected node found. & = " << intersected << ", data = " << intersected->data << '\n';
  } else {
    cout << "No intersecting nodes found." << '\n';
  }

  return 0;
}