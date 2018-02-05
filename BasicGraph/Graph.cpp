#include <map>
#include <vector>
#include <iostream>
#include "Graph.h"

Graph::Graph() {
  numEdges = 0;
}

// this method adds an entry for dest into src's adj list
// if src does not exist as a node, it will be created
// if dest does not exist as a node, it will be created
void Graph::addEdge(int src, int dest) {
  if (adjList.find(src) != adjList.end()) { // we have an entry for src in adj list
    adjList[src].push_back(dest);
  } else {
    std::vector<int> srcAdjList;
    srcAdjList.push_back(dest);
    adjList[src] = srcAdjList;
  }
  numEdges++;
  if (adjList.find(dest) == adjList.end()) { // no entry for dest in adjList
    adjList[dest] = std::vector<int>();
  }
}

// print the entire graph
void Graph::print() {
  std::cout << "Graph (nodes = " << getNumNodes() << ", edges = " << getNumEdges() << "):\n";
  for(std::map<int, std::vector<int> >::iterator it = adjList.begin(); it != adjList.end(); it++) {
    std::cout << it->first << " --> ";
    for(std::vector<int>::iterator vit = it->second.begin(); vit != it->second.end(); vit++) {
      std::cout << *vit;
      if (vit != it->second.end() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << '\n';
  }
}

int Graph::getNumEdges() {
  return numEdges;
}

int Graph::getNumNodes() {
  return adjList.size();
}