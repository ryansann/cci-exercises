#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
  Graph g = Graph();
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.print();
  return 0;
}