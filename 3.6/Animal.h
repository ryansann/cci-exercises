#pragma once

#include <iostream>
#include <string>

using namespace std;

class Animal {
  private:
    int order; // this is the order it was enqueued at the shelter
    string type;
  public:
    Animal();
    Animal(string t);
    int getOrder() const;
    void setOrder(int o);
    void setType(string t);
    string getType() const;
    bool isCat();
    bool isDog();
    friend ostream& operator<<(ostream& os, Animal const &a);
};