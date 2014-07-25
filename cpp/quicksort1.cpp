#include <iostream>
#include <vector>
using namespace std;
void partition(vector<int> ar) {
  vector<int> lefts, afters;
  vector<int>::iterator it = ar.begin();
  int p = *(it++);
  while(it != ar.end()) {
    if (p > *it) {
      lefts.push_back(*it);
    } else {
      afters.push_back(*it);
    }
    it++;
  }
  for (it = lefts.begin(); it != lefts.end(); it++)
    cout << *it << " ";
  cout << p;
  for (it = afters.begin(); it != afters.end(); it++)
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
  partition(_ar);
  return 0;
}
