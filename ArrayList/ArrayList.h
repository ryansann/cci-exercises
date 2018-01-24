/*

ArrayList.h
Dynamically Resizing Templated Array
Operations:
- construct
- destruct
- copy
- set
- get
- append
- pop
- print

*/

// Include Guard
#ifndef __ARRAYLIST_H_INCLUDED__
#define __ARRAYLIST_H_INCLUDED__

// Class Interface
template <typename T> class ArrayList {
  
  private:
    int size;
    T *arrayList;
    void resize(int newSize);

  public:
    // instance ops
    ArrayList();
    ArrayList(int s);
    ArrayList(const ArrayList<T> &original);
    ~ArrayList();

    // getters setters
    int getSize();
    void setSize(int s);

    // operator overloads
    int &operator[](int index);

    // array ops
    T get(int index);
    void insert(int index, T element);
    void append(T element);
    T pop();
    void print();

};

#endif