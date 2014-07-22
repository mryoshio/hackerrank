#include <iostream>
using namespace std;
void solve() {
  int r, v = 1;
  cin.ignore();
  cin >> r;
  while (v <= r) v <<= 1;
  cout << (v-1) << endl;
}

int main() {
  solve();
  return 0;
}
