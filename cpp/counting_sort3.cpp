#include <iostream>
using namespace std;

const int MAX = 100;

void solve() {
  int t, x = 0, a[MAX];
  long n;
  string s;

  fill(a, a+MAX, 0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> t >> s;
    a[t] += 1;
    if (t > x) x = t;
  }

  cout << a[0];
  a[1] += a[0];

  for (int i = 1; i < x; i++) {
    cout << ' ' << a[i];
    a[i+1] += a[i];
  }

  for (int i = x; i < MAX; i++)
    cout << ' ' << n;

  cout << endl;
}

int main() {
  solve();
  return 0;
}
