#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node *createMinimalBST(int arr[], int start, int end) {
  if (end < start) {
    return 0;
  }
  int mid = (start + end) / 2;
  Node *n = new Node();
  n->data = arr[mid];
  n->left = createMinimalBST(arr, start, mid - 1);
  n->right = createMinimalBST(arr, mid + 1, end);
  return n;
}

// This method creates a BST from a sorted, increasing vector of ints
Node *createMinimalBST(int arr[], int length) {
  return createMinimalBST(arr, 0, length - 1);
}

void printTree(Node *n) {
  if (!n) {
    return;
  }
  cout << n->data << ": ";
  if (n->left) {
    cout << n->left->data;
  } else {
    cout << "-";
  }
  cout << ", ";
  if (n->right) {
    cout << n->right->data;
  } else {
    cout << "-";
  }
  cout << '\n';
  printTree(n->left);
  printTree(n->right);
}

int main() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  Node *root = createMinimalBST(arr, 9);
  printTree(root);
  return 0;
}