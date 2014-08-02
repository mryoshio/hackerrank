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

void quickSort(vector<int> ar, int ar_size) {
  stack<pair<int, int> > st;

  st.push(border(0, ar_size-1));

  while (!st.empty()) {
    border b = st.top();
    st.pop();
    int f = b.first;
    int l = b.second;
    int p = f;

    while (f < l) {
      if (ar[p] > ar[l]) {
        f++;
        if (f != l)
          swap(ar[f], ar[l]);
        swap(ar[f], ar[p]);
        p++;
      }
      else l--;
    }
    if (b.first < p-1)
      st.push(border(b.first, p-1));
    if (b.second > p+1)
      st.push(border(p+1, b.second));
  }
  d(ar);
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
