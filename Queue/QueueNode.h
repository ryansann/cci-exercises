#pragma once

template <typename T>
struct QueueNode {
  T data;
  QueueNode<T> *next, *prev;
};