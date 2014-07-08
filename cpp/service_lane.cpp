#include <iostream>
#include <array>

using namespace std;

int N, T;
array<int, 100000> widths;

void solve() {
  int s, e;
  for (int i = 0; i < T; i++) {
    int v = 3;
    cin >> s >> e;
    while (s <= e) {
      if (v > widths.at(s)) v = widths.at(s);
      s++;
    }
    cout << v << endl;
  }
}

void dump() {
  cout << N << endl;
  cout << T << endl;
  for (int i = 0; i < N; i++) cout << widths[i] << endl;
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> widths[i];
  // dump();
  solve();
  return 0;
}
