#include "Stack.h"
#include "StackNode.h"

using namespace std;

int main() {
  Stack<int> *s = new Stack<int>();
  s->push(1);
  s->push(2);
  s->push(3);
  s->print();
  StackNode<int> *sn = s->pop();
  s->print();
  return 0;
}