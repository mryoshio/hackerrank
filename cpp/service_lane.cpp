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
    for (; s < e; s++)
      if (v > widths.at(s)) v = widths.at(s);
    cout << v << endl;
  }
}

int main() {
  cin >> N >> T;
  for (int i = 0; i < N; i++) cin >> widths[i];
  solve();
  return 0;
}
