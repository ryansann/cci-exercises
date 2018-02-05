#include <iostream>
#include <vector>
#include <list>
#include <map>
#include "../BasicGraph/Graph.h"

using namespace std;

// BFS
bool Graph::isRouteBetween(int src, int dest) {
  if (src == dest) {
    return true;
  }
  map<int, bool> visited;
  list<int> queue;
  visited[src] = true;
  queue.push_back(src);
  vector<int>::iterator vit;
  while(!queue.empty()) {
    src = queue.front();
    queue.pop_front();
    for(vit = adjList[src].begin(); vit != adjList[src].end(); vit++) {
      if (*vit == dest) {
        return true;
      }
      if (!visited[*vit]) {
        visited[*vit] = true;
        queue.push_back(*vit);
      }
    }
  }
  return false;
}

int main() {
  Graph g = Graph();
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(5, 1);
  g.print();
  cout << g.isRouteBetween(1, 5) << endl;
  return 0;
}