#include <iostream>
#include <vector>
using namespace std;

void sort(int n, vector<pair<int, string> > &s, int offset) {
  if (n < 2) return;
  int m = n/2;

  sort(m, s, offset);
  sort(n-m, s, offset+m);

  vector<pair<int, string> > buf(m);
  int i;
  
  for (i = 0; i < m; i++)
    buf[i] = s[offset+i];

  int j = m;
  int k = i = 0;

  while (i < m && j < n) {
    if (buf[i].first <= s[offset+j].first) {
      s[offset+k] = buf[i];
      i++;
    } else {
      s[offset+k] = s[offset+j];
      j++;
    }
    k++;
  }
  while (i < m) {
    s[offset+k] = buf[i];
    k++;
    i++;
  }
}

void solve() {
  int x;
  string s;
  long n;

  cin >> n;

  vector<pair<int, string> > v(n);

  for (int i = 0; i < n/2; i++) {
    cin >> x >> s;
    v[i] = pair<int, string>(x, "-");
  }

  for (int i = n/2; i < n; i++) {
    cin >> x >> s;
    v[i] = pair<int, string>(x, s);
  }

  sort(n, v, 0);

  cout << v[0].second;

  for (int i = 1; i < n; i++)
    cout << ' ' << v[i].second;

  cout << endl;
}

int main() {
  solve();
  return 0;
}
