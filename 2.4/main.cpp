// Partition list around a integer x
#include <iostream>
#include <vector>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// this overwrites the data in list
// could build a new list as another solution
// leftPartition will have all numbers strictly less than x (unsorted)
// rightPartition will have all numbers greater than or equal to x (unsorted)
// O(n) time
// O(n) space
void LinkedList::partitionList(int x) {
  if (length < 2) {
    cout << "List needs to be at least 2 Nodes long to partition" << '\n';
    return;
  }

  // create two partitions
  // O(n)
  vector<int> leftPartition;
  vector<int> rightPartition;
  cur = head;
  while(cur) {
    if (cur->data < x) {
      leftPartition.push_back(cur->data);
    } else {
      rightPartition.push_back(cur->data);
    }
    cur = cur->next;
  }

  // overwrite current data with the partition based ordering
  // O(n)
  cur = head;
  while(cur) {
    if (leftPartition.size() > 0) {
      cur->data = leftPartition.back();
      leftPartition.pop_back();
    } else {
      cur->data = rightPartition.back();
      rightPartition.pop_back();
    }
    cur = cur->next;
  }
}

using namespace std;

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(2);
  list.addNode(10);
  list.addNode(5);
  list.addNode(8);
  list.addNode(5);
  list.addNode(3);
  list.print();
  list.partitionList(5);
  list.print();

  return 0;
}