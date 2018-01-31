#pragma once
#include "Node.h"

class LinkedList {
  private:
    Node *head;
    Node *cur;
    Node *tmp;
  public:
    LinkedList();
    void addNode(int data);
    void deleteNode(int data);
    void removeDupes(int data);
    void print();
};