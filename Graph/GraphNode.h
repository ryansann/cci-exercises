#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class GraphNode {
  private:
    T data;
    vector<GraphNode<T>*> adjacentNodes;
  public:
    GraphNode();
    GraphNode(T d);
    void addAdjacentNode(GraphNode<T> *n);
    vector<GraphNode<T>*> getAdjacentNodes();
    T getData();
    void setData(T d);
};

template <typename T>
GraphNode<T>::GraphNode() {
  
}

template <typename T>
GraphNode<T>::GraphNode(T d) {
  data = d;
}

template <typename T>
void GraphNode<T>::addAdjacentNode(GraphNode<T> *n) {
  adjacentNodes.push(n);
}

template <typename T>
vector<GraphNode<T>*> GraphNode<T>::getAdjacentNodes() {
  return adjacentNodes;
}

template <typename T>
T GraphNode<T>::getData() {
  return data;
}

template <typename T>
void GraphNode<T>::setData(T d) {
  data = d;
}