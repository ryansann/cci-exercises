// Detect if the list a palindrome
#include <iostream>
#include <map>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// Maintain a map as we iterate through the list then use map to check for palindrome criteria
// O(n) time
// O(n) space
bool LinkedList::isPalindrome() {
  map<int, int> digitOccurences;
  cur = head;
  while(cur) {
    if (digitOccurences[cur->data]) {
      digitOccurences[cur->data]++;
    } else {
      digitOccurences[cur->data] = 1;
    }
    cur = cur->next;
  }

  bool foundOdd = false;
  for (map<int, int>::iterator it = digitOccurences.begin(); it != digitOccurences.end(); it++) {
    if (it->second % 2) {
      if (foundOdd) return false;
      foundOdd = true;
    }
  }

  return true;
}

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(2);
  list.addNode(1);
  list.print();
  cout << "isPalindrome: " << list.isPalindrome() << '\n';

  return 0;
}