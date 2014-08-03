#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void d(vector<int> ar, int l, int r) {
  for (int i = l; i <= r; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void quickSort(vector<int> &ar, int l, int r) {
  vector<int> tmp(ar.size());
  int i, l_idx = l, r_idx = r;
  int piv = ar[l];

  for (i = l+1; i <= r; i++)
    if (ar[i] < piv) tmp[l_idx++] = ar[i];
    else tmp[r_idx--] = ar[i];

  for (i = l; i < l_idx; i++)
    ar[i] = tmp[i];

  ar[l_idx] = piv;

  for (i = r; i > r_idx; i--)
    ar[++l_idx] = tmp[i];

  if (r-l <= 1) {
    if (r-l == 1)
      d(ar, l, r);
    return;
  }
  quickSort(ar, l, r_idx-1);
  quickSort(ar, r_idx+1, r);
  d(ar, l, r);
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
