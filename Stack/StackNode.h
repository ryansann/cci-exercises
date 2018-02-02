#pragma once

template <typename T>
struct StackNode {
  T data;
  StackNode<T> *next;
};