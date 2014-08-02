#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> border;

void d(vector<int> ar) {
  for (vector<int>::iterator it = ar.begin(); it != ar.end(); it++)
    cout << *it << " ";
  cout << endl;
}

void quickSort(vector<int> &ar, int l, int r) {
  if (r-l > 1)
    cout << l << " " << r << endl;

  if (l < r) {
    int i = l;
    int j = r;
    int p = ar[l];
    while (true) {
      while (ar[i] < p) i++;
      while (p < ar[j]) j--;
      if (i >= j) break;
      swap(ar[i], ar[j]);
      i++; j--;
    }
    quickSort(ar, l, i-1);
    quickSort(ar, j+1, r);

  }
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
  quickSort(_ar, 0, _ar_size-1);
  return 0;
}
