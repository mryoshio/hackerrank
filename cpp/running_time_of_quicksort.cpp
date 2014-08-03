#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void d(vector<int> ar, int l, int r) {
  for (int i = l; i <= r; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void quickSort(vector<int> ar, int ar_size) {
  stack<pair<int, int> > st;

  st.push(border(0, ar_size-1));

  while (!st.empty()) {
    border b = st.top();
    st.pop();
    int f = b.first;
    int l = b.second;
    int p = l;

    while (f < l) {
      if (ar[p] > ar[l]) {
        l--;
        if (f != l)
          swap(ar[f], ar[l]);
        swap(ar[l], ar[p]);
        p--;
      }
      else f++;
    }
    if (b.first < p-1)
      st.push(border(b.first, p-1));
    if (b.second > p+1)
      st.push(border(p+1, b.second));
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
