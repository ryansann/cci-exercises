#include <iostream>
#include "MinStack.h"
#include "../Stack/StackNode.h"

using namespace std;

int main() {
  MinStack<int> ms = MinStack<int>();
  ms.push(5);
  ms.push(4);
  ms.push(2);
  ms.push(1);
  ms.print();
  ms.push(3);
  ms.print();

  return 0;
}