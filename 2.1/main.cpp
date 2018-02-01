// Remove duplicates from linked list
#include <iostream>
#include <map>
#include "../LinkedList/LinkedList.h"

using namespace std;

// this method removes nodes with duplicate data
// it will remove the first duplicate item
// n = # nodes in list
// O(n) time
// O(n) space
void LinkedList::removeDupes() {
  // build a hash map of the values and their number of occurences
  map<int, int> occurencesMap;
  cur = head;
  while(cur) {
    if (occurencesMap[cur->data]) {
      occurencesMap[cur->data]++;
    } else {
      occurencesMap[cur->data] = 1;
    }
    cur = cur->next;
  }
  // outer loop is worst case O(n) time
  // if outer loop = O(n) time then the inner loop won't execute because all elements will be unique
  // inner loop is worst case O(n) time
  // if inner loop = O(n) time then the outer loop will only execute once because all elements are the same
  // so this nested loop is O(n) time
  for (map<int, int>::iterator it = occurencesMap.begin(); it != occurencesMap.end(); it++) {
    if (it->second > 1) {
      for(int i = it->second; i > 1; i--) {
        deleteNode(it->first);
      }
    }
  }
}

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(10);
  list.addNode(100);
  list.addNode(10);
  list.print();
  list.removeDupes();
  list.print();

  return 0;
}