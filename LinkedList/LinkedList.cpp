#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

// initialize an empty linked list
LinkedList::LinkedList() {
  head = 0;
  cur = 0;
  tmp = 0;
}

void LinkedList::addNode(int data) {
  // create our new node
  Node *n = new Node();
  n->data = data;
  // add new node as new head
  tmp = head;
  head = n;
  n->next = tmp;
  cur = head;
}

void LinkedList::deleteNode(int data) {
  cur = head; // reset current to head
  tmp = head; // reset tmp to head
  // cur ptr will lag behind by one element
  while (tmp != 0) {
    tmp = tmp->next;
    if (tmp->data == data) {
      cur->next = tmp->next;
      delete tmp;
    }
    cur = cur->next;
  }
}

void LinkedList::print() {
  int nodeCount = 0;
  while(cur) {
    cout << "Node[" << nodeCount << "]: " << cur->data << " --> ";
    nodeCount++;
    cur = cur->next;
  }
}