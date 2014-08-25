#include <iostream>
#include <vector>
using namespace std;

void find(int v, vector<int> a) {
  int l = 0, h = a.size(), m;
  do {
    m = (l+h)/2;
    if (a[m] == v) {
      cout << m << endl;
      return;
    } else if (a[m] > v) {
      h = m-1;
    } else {
      l = m+1;
    }
  } while (true);
}

int main() {
  int v, n, x;
  cin >> v >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = x;
  }
  find(v, a);
}
