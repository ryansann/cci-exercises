// Detect if the list a palindrome
#include <iostream>
#include <map>
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/Node.h"

using namespace std;

// Maintain a map as we iterate through the list then use map to check for palindrome criteria
// If it is not a permutation of a palindrome then it cannot be a palindrome
// We don't really need this, but it can save us from making a new list when we dont need to
// O(n) time
// O(n) space
bool LinkedList::isPalindromePermutation() {
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

// Build a reverse list
// O(n) time
// O(n) space
LinkedList LinkedList::buildReverseList() {
  LinkedList reverseList = LinkedList();
  cur = head;
  while(cur) {
    reverseList.addNode(cur->data);
    cur = cur->next;
  }
  return reverseList;
}

// Overloading == operator for easy comparison of lists
// if forwardList == reverseList then it is a palindrome
// O(n) time
// O(n) space
bool LinkedList::operator==(const LinkedList &rhs) {
  if (length != rhs.getLength()) return false;
  cur = head;
  Node *rhsCur = rhs.getHead();
  while(cur) {
    if (cur->data != rhsCur->data) return false;
    cur = cur->next;
    rhsCur = rhsCur->next;
  }
  return true;
}

// Check if palindrome permutation first (not really necessary)
// if it is, check if list is the same forward and reverse
// O(n) time
// O(n) space
bool isPalindrome(LinkedList &l) {
  if (!l.isPalindromePermutation()) {
    return false;
  } else {
    LinkedList reverse = l.buildReverseList();
    if (l == reverse) {
      return true;
    } else {
      return false;
    }
  }
}

int main() {
  LinkedList list = LinkedList();
  list.addNode(1);
  list.addNode(2);
  list.addNode(3);
  list.addNode(2);
  list.addNode(1);
  list.print();
  cout << isPalindrome(list) << '\n';

  return 0;
}