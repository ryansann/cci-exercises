// Convert spaces to url encoded '%20'
// Done in C++
// Could easily be implemented with std::string and replace method
// or in Javascript with sting.replace()
#include <iostream>

using namespace std;

void urlify(char* str, int strLen);

int main() {
  char name[40] = "Mr John Smith";
  urlify(name, strlen(name));
  for (int i = 0; i < strlen(name); i++) {
    cout << name[i];
  }
  return 0;
}

void urlify(char* str, int realLength) {
  // count the spaces in the string
  int numSpaces = 0, i;
  for (i = 0; i < realLength; i++) {
    if (str[i] == ' ') {
      numSpaces++;
    }
  }
  if (numSpaces == 0) {
    return; // if we don't have any spaces, leave str as is
  } else {
    // we need 3 * numSpaces extra slots for urlencoded version
    int index = realLength + numSpaces * 2;
    for(i = realLength - 1; i >= 0; i--) {
      if (str[i] == ' ') {
        str[index - 1] = '0';
        str[index - 2] = '2';
        str[index - 3] = '%';
        index -= 3;
      } else {
        str[index - 1] = str[i];
        index--;
      }
    }
  }
}