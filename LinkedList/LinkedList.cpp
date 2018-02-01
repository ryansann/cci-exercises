#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

// initialize an empty linked list
LinkedList::LinkedList() {
  head = 0;
  cur = 0;
  tmp = 0;
  length = 0;
}

// this prepends a node with data to the linked list
void LinkedList::addNode(int data) {
  // create our new node
  Node *n = new Node();
  n->data = data;
  // add new node as new head
  tmp = head;
  head = n;
  n->next = tmp;
  cur = head;
  length++;
}

// this deletes the first node it finds that matches data
void LinkedList::deleteNode(int data) {
  Node *del = 0;
  cur = head;
  tmp = head;
  // tmp trails current / loop will exit once it finds a value to delete
  while(cur && cur->data != data) {
    tmp = cur;
    cur = cur->next;
  }
  // cur will be non null if we found data to delete
  if (cur) {
    del = cur;
    cout << "Removing node with data: " << del->data << '\n';
    cur = cur->next;
    if (tmp != head) {
      tmp->next = cur;
    } else {
      head = cur;
    }
    delete del;
    length--;
  } else {
    cout << "No node has data: " << data << ". Skipping delete operation" << '\n';
  }
  // reset pointers
  cur = head;
  tmp = head;
}

int LinkedList::getLength() const {
  return length;
}

// simple getter so passed around lists can be iterated starting at their head
Node* LinkedList::getHead() const {
  return head;
}

// simple print method for our linked list
void LinkedList::print() {
  cur = head;
  int nodeCount = 0;
  cout << "Length = " << length << " | List = ";
  while(cur && cur->next) {
    cout << cur->data << " --> ";
    nodeCount++;
    cur = cur->next;
  }
  cout << cur->data  << " -/->" << '\n';
}