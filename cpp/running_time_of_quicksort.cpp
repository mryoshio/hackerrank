#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> border;

void d(vector<int> ar, int l, int r) {
  for (int i = l; i <= r; i++)
    cout << ar[i] << " ";
  cout << endl;
}

int insertionSort(vector<int> ar, int ar_size) {
  int cnt = 0;
  for (int i = 1; i < ar_size; i++) {
    int t = ar[i];
    if (ar[i-1] > t) {
      int j = i;
      do {
        ar[j] = ar[j-1];
        j--;
        cnt++;
      } while(ar[j-1] > t && j > 0);
      ar[j] = t;
      cnt++;
    }
  }
  return cnt;
}


int quickSort(vector<int> ar, int ar_size) {
  int cnt = 0;
  stack<border> st;

  st.push(border(0, ar_size-1));

  while (!st.empty()) {
    border b = st.top();
    st.pop();
    int f = b.first;
    int l = b.second;
    int p = l;

    while (f < l) {
      if (ar[f] > ar[p]) {
        l--;
        if (f != l) {
          swap(ar[f], ar[l]);
          cnt++;
        }
        swap(ar[l], ar[p]);
        cnt++;
        p--;
      }
      else f++;
    }
    if (b.first < p-1)
      st.push(border(b.first, p-1));
    if (b.second > p+1)
      st.push(border(p+1, b.second));
  }
  return cnt;
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
  cout << quickSort(_ar, _ar_size) << endl;
  cout << insertionSort(_ar, _ar_size) << endl;
  return 0;
}
