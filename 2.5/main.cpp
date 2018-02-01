// Add two linked lists 
#include <iostream>
#include <cmath>
#include <string>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// helper
int getListSum(LinkedList l) {
  int accumulator = 0, powerCount = 0;
  Node *cur = l.getHead();
  while(cur) {
    accumulator += pow(10, powerCount) * cur->data;
    powerCount++;
    cur = cur->next;
  }
  return accumulator;
}

// helper
LinkedList buildSumList(int sum) {
  LinkedList sumList = LinkedList();
  string sumString = to_string(sum);
  // add 1s place last so it is add head of list
  for (string::iterator it = sumString.begin(); it != sumString.end(); it++) {
    sumList.addNode ((int) *it - 48);
  }
  return sumList;
}

LinkedList addLists(LinkedList l1, LinkedList l2) {
  int sum = getListSum(l1) + getListSum(l2);
  cout << "List sum is: " << sum << '\n';
  return buildSumList(sum);
}

int main() {
  LinkedList l1 = LinkedList(), l2 = LinkedList(), sumList;
  l1.addNode(6);
  l1.addNode(1);
  l1.addNode(7);
  l2.addNode(2);
  l2.addNode(9);
  l2.addNode(5);
  l1.print();
  l2.print();
  sumList = addLists(l1, l2);
  sumList.print();

  return 0;
}