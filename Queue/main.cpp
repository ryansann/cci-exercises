#include <iostream>
#include "Queue.h"
#include "QueueNode.h"

using namespace std;

int main() {
  Queue<int> q = Queue<int>();
  QueueNode<int> *qn1, *qn2;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.print();
  qn1 = q.dequeue();
  cout << "dequeued: " << qn1->data << '\n';
  q.print();
  qn2 = q.dequeue();
  cout << "dequeued: " << qn2->data << '\n';
  q.print();
  q.clear();
  q.print();

  return 0;
}