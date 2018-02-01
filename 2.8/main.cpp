// Find node at beginning of linked list loop
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// Looks for a loop in the list
// if found, it returns a pointer to the Node at beginning of loop
// otherwise returns a null pointer
// O(n) time
// O(1) space
Node* LinkedList::getLoopNode() {
  // use runners approach (cycle finding algorithm)
  cur = head; // slow ptr
  tmp = head; // fast ptr
  while(cur && tmp && tmp->next) {
    cur = cur->next;
    tmp = tmp->next->next;
    if (cur == tmp) { // found a loop
      cur = head; // reset cur to beginning
      // incrementing both one node at a time
      // the beginning node is where cur & tmp are equal
      while(1) {
        cur = cur->next;
        tmp = tmp->next;
        if (cur == tmp) {
          return cur; // this is the beginning loop node
        }
      }
    }
  }
  return 0;
}

int main() {
  LinkedList list = LinkedList();
  Node *one = new Node(), *two = new Node();
  one->data = 2;
  two->data = 4;
  list.addNode(two);
  list.addNode(3);
  list.addNode(one);
  list.addNode(1);
  two->next = one; // create loop
  cout << "Loop node data: " << list.getLoopNode()->data << '\n';

  return 0;
}