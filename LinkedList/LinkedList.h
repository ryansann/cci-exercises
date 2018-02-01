#pragma once
#include "Node.h"

class LinkedList {
  private:
    Node *head;
    Node *cur;
    Node *tmp;
    int length;
  public:
    LinkedList();
    void addNode(int data);
    void deleteNode(int data);
    void removeDupes(); // 2.1
    Node* getKthFromLast(int k); // 2.2
    void print();
};