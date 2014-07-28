#include <iostream>
#include <vector>
using namespace std;

void d(vector<int> ar) {
  for (vector<int>::iterator it = ar.begin(); it != ar.end(); it++)
    cout << *it << " ";
  cout << endl;
}

void quickSort(vector<int> &ar, int ar_size) {
  d(ar);
  vector<int> lefts, rights;
  vector<int>::iterator it = ar.begin();
  int p = *(it++);
  while(it != ar.end()) {
    if (p > *it) {
      lefts.push_back(*it);
    } else {
      rights.push_back(*it);
    }
    it++;
  }
  if (lefts.size() > 1)
    quickSort(lefts, lefts.size());
  if (rights.size() > 1)
    quickSort(rights, rights.size());
  for (it = lefts.begin(); it != lefts.end(); it++)
    cout << *it << " ";
  cout << p;
    for (it = rights.begin(); it != rights.end(); it++)
      cout << " " << *it;
  cout << endl;
}

int main(void) {
  vector <int>  _ar;
  int _ar_size;
  cin >> _ar_size;
  for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
    int _ar_tmp;
    cin >> _ar_tmp;
    _ar.push_back(_ar_tmp); 
  }
  quickSort(_ar, _ar_size);
  return 0;
}
