

#include <iostream>
#include <vector>
#include <list>
#include <time.h>

using std::cout;
using std::endl;

int main () {

  const int listSize = 100000;

  long start;
  long end;

  std::list<int> list;

  cout << endl;
  cout << "inserting " << listSize << " items at the front of a 'list'" << endl;

  start = clock();

  for (int i = 0; i < listSize; i++)
    list.insert(list.begin(), i);

  end = clock();

  cout << "time: " << (end - start) << endl << endl;

  std::vector<int> vector;

  cout << "inserting " << listSize << " items at the front of a 'vector'" << endl;

  start = clock();

  for (int i = 0; i < listSize; i++)
    vector.insert(vector.begin(), i);

  end = clock();

  cout << "time: " << (end - start) << endl << endl;

}


