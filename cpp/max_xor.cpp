#include <iostream>

using namespace std;

void solve() {
  int l, r, v = 1;
  cin >> l >> r;
  int x = l ^ r;
  while (x) {
    v <<= 1;
    x >>= 1;
  }
  cout << (v-1) << endl;
}

int main() {
  solve();
  return 0;
}
