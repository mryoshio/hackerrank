#include <iostream>
using namespace std;
void solve() {
  uint64_t k;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> k;
    int n = k / 2;
    cout << n * (k - n) << endl;
  }
}
int main() {
  solve();
  return 0;
}
