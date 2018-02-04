// Graph.h
// Does not allow for nodes with duplicate data
#pragma once

#include <iostream>
#include <vector>
#include "GraphNode.h"

using namespace std;

template <typename T>
class Graph {
  private:
    vector<GraphNode<T>*> nodes;
    int numNodes;
  public:
    Graph();
    ~Graph();
    void addNode(GraphNode<T> *n);
    void addNode(T data);
    void removeNode(GraphNode<T> *n);
    void removeNode(T data);
    GraphNode<T> *search(T data);
    void print();
    void clear();
};

template <typename T>
Graph<T>::Graph() {
  numNodes = 0;
}

template <typename T>
Graph<T>::~Graph() {
  clear();
}

template <typename T>
void Graph<T>::addNode(GraphNode<T> *n) {

} 

template <typename T>
void Graph<T>::addNode(T data) {

}

template <typename T>
void Graph<T>::removeNode(GraphNode<T> *n) {

}

template <typename T>
void Graph<T>::removeNode(T data) {

}

template <typename T>
GraphNode<T> *Graph<T>::search(T data) {

}

template <typename T>
void Graph<T>::print() {

}

template <typename T>
void Graph<T>::clear() {

}