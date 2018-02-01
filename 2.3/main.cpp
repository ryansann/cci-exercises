// delete middle node with only access to it
#include <iostream>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// helper - this is just to grab a middle node for input into deleteNodeWithoutHead
// O(n) time
// O(1) space
Node* LinkedList::getMiddleNode() {
  if (length <= 2) {
    cout << "No middle node to get" << '\n';
    return 0;
  }
  int middleNodeDistance = length / 2; // get some node roughly in the middle
  cur = head;
  while (cur && middleNodeDistance) {
    cur = cur->next;
    middleNodeDistance--;
  }
  return cur;
}

// make sure to update length since we wont use other delete method
// O(n) time
// O(1) space
void LinkedList::deleteNodeWithoutHead(Node *n) {
  Node *prev = 0;
  Node *next = n->next;
  while(next) {
    n->data = next->data;
    prev = n;
    n = n->next;
    next = n->next;
  }
  prev->next = 0;
  delete n;
  length--;
}

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.addNode(10);
  list.print();
  Node *middle = list.getMiddleNode();
  cout << "Middle node to delete: " << middle->data << '\n';
  list.deleteNodeWithoutHead(middle);
  list.print();

  return 0;
}