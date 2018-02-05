// Graph.h
// Simple implementation of unweighted graph using an Adjacency List 
// No templating here - nodes are represented by integer values
#pragma once

#include <map>
#include <vector>

class Graph {
  private:
    int numEdges;
    std::map<int, std::vector<int> > adjList;
  public:
    Graph();
    void addEdge(int src, int dest);
    void print();
    int getNumEdges();
    int getNumNodes();
};