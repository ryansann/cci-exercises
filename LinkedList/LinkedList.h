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
    ~LinkedList();
    void addNode(int data);
    void addNode(Node* n); // 2.7
    void deleteNode(int data);
    void removeDupes(); // 2.1
    Node* getKthFromLast(int k); // 2.2
    void deleteNodeWithoutHead(Node *n); // 2.3
    void partitionList(int x); // 2.4
    bool isPalindromePermutation(); // 2.6
    LinkedList buildReverseList(); // 2.6
    bool operator==(const LinkedList &rhs); // 2.6
    Node* getLoopNode(); // 2.8
    int getLength() const;
    Node* getHead() const;
    void clear();
    void print();
};