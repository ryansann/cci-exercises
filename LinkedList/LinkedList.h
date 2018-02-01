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
    void deleteNodeWithoutHead(Node *n); // 2.3
    void partitionList(int x); // 2.4
    Node* getMiddleNode();
    Node* getHead();
    void print();
};