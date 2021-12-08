

#include <iostream>
#include <string>
#include <set>

#include "print.h"

using namespace std;


int main() {

  set<string> words;

  string word;
  while (cin >> word)
    words.insert(word);

  print(words);

}


