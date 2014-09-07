#include <iostream>
#include <string>
using namespace std;

template<class TargetIt>
void d(TargetIt, TargetIt, string);

template<class TargetIt>
void d(TargetIt first, TargetIt last, string sep) { 
  cout << *first;
  first++;
  for (; first != last; first++)
    cout << sep << *first;
  cout << endl;
}
