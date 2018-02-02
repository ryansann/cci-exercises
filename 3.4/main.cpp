#include <iostream>
#include "MyQueue.h"
#include "../Stack/StackNode.h"

using namespace std;

int main() {

  MyQueue<int> q = MyQueue<int>();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.print();
  StackNode<int> *n = q.dequeue();
  cout << "Dequeued: " << n->data << '\n';
  q.print();
  delete n;
  n = q.dequeue();
  cout << "Dequeued: " << n->data << '\n';
  q.print();
  q.enqueue(10);
  q.print();

  return 0;
}