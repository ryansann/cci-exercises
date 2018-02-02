#include <iostream>
#include "StackSet.h"

using namespace std;

int main() {
  StackSet<int> ss = StackSet<int>(3);
  ss.push(4);
  ss.push(3);
  ss.push(2);
  ss.push(1);
  ss.print();
  return 0;
}