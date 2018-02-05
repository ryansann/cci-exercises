// Graph.h
// Simple implementation of unweighted graph using an Adjacency List 
#pragma once

#include <map>
#include <vector>

class Graph {
  private:
    int size;
    std::map<int, std::vector<int> > adjList;
  public:
    Graph();
    void addEdge(int src, int dest);
    void print();
};