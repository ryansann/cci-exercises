// Check if strings are one edit away from one another
// return true from checkEdits if they are one edit away, otherwise return false
// Assumptions:
// - ASCII character set
// - Capital and lowercase are different (implied by ASCII)
// O(n) time
// O(1) space
#include <iostream>
#include <string> // std::string
#include <bitset> // std::bitset
#include <cmath> // std::abs()

using namespace std;

int main() {

  return 0;
}

bool checkEdits(string str1, string str2) {
  // more than one character length difference implies > 1 edit away
  if ((abs((double)str1.length() - (double)str2.length()) / 1) > 1) {
    return false;
  }
  // if more than one character is different then we are not one edit away
  // bit vetor is the way to go here
  bitset<128> bitVec (0x0); // initialize all bits to 0
  for(char c : str1) {
    (int) c
  }
  return true; 
}